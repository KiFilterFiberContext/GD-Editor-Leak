#pragma once

#include "utils.h"
#include "mem.h"

#include <thread>

enum arm_inspect_reg
{
	R0,
	R1,
	R2,
	R3,
	R4,
	LR
};

enum reg_op
{
	rd, // read
	wr // write
};

struct mid_hook_info_t
{
	arm_inspect_reg reg;
	uintptr_t instr_offset;

	reg_op op;
	void* write_value;

	bool is_string;
};


struct trap_info_t
{
	uintptr_t address;

	mid_hook_info_t midinfo;
	bool is_mid;

	void* callback;

	uint8_t instruction[ 4 ];
};

struct hook_list_t
{
	trap_info_t list[ 16 ];
	size_t size;

	bool active;
	int prev_index;
};


hook_list_t hook_list;


namespace photon::core
{
	struct softbp
	{
		static constexpr inline uint8_t AARCH64_BKPT[] = { 0x00, 0x00, 0x20, 0xD4 };	// BRK #0
		static constexpr inline uint8_t ARM_THUMB_BKPT[ ] = { 0x1, 0xDE };				// UDF #1
		static constexpr inline uint8_t ARM_BKPT[ ] = { 0xF1, 0x00, 0xF0, 0xE7 };		// UDF #1

		typedef void (*sighandler_t)(int, siginfo_t*, void*);

		static void* hook_watchdog( void* arg )
		{
			while ( true )
			{
				if ( !hook_list.active && hook_list.prev_index != -1 )
				{
					vm_write( hook_list.list[ hook_list.prev_index ].address, ARM_THUMB_BKPT );
					hook_list.prev_index = -1;

					/*
					if ( hook_list.list[ hook_list.prev_index ].is_mid &&
						hook_list.list[ hook_list.prev_index ].midinfo.op == reg_op::wr )
					{
						hook_list.prev_index = -1;
						continue;
					}
					*/
				}
			}

			return nullptr;
		}

		static void sig_handler( int sig, siginfo_t* info, void* context )
		{
			ucontext_t* ctx = ( ucontext_t* ) context;
			mcontext_t mctx = ctx->uc_mcontext;

			uintptr_t arm_pc = get_thumb_address( ctx->uc_mcontext.arm_pc );

			while ( hook_list.prev_index != -1 )
				;;

			utils::debug_print( "SIGNAL: %i PC: 0x%08x", sig, arm_pc );

			for ( size_t i = 0; i < hook_list.size; ++i )
			{
				trap_info_t trap_info = hook_list.list[ i ];

				if ( arm_pc == trap_info.address )
				{
					if ( trap_info.is_mid )
					{
						//
						// register write operations are not fully supported as I disbanded the project prior to finishing
						// there may be some instability as not everything was fully tested
						//

						if ( trap_info.midinfo.op == reg_op::rd )
						{
							// read
							uintptr_t reg_value = -1;

							// for reads we have to execute the original instruction
							// however, for writes we substitue the register value so we can likely skip the instruction and not restore the original bytes

							vm_write( trap_info.address, trap_info.instruction );

							hook_list.active = true;
							hook_list.prev_index = i;

							switch ( trap_info.midinfo.reg )
							{
							case arm_inspect_reg::R0:
								reg_value = mctx.arm_r0;
								break;

							case arm_inspect_reg::R1:
								reg_value = mctx.arm_r1;
								break;

							case arm_inspect_reg::R2:
								reg_value = mctx.arm_r2;
								break;

							case arm_inspect_reg::R3:
								reg_value = mctx.arm_r3;
								break;

							case arm_inspect_reg::R4:
								reg_value = mctx.arm_r4;
								break;

							case arm_inspect_reg::LR:
								reg_value = mctx.arm_lr;
								break;

							default:
								break;
							}

							if ( trap_info.midinfo.is_string )
								utils::print( "READ TRAP @ 0x%08x: %i -> %s", arm_pc, trap_info.midinfo.reg, ( const char* ) reg_value );
							else
								utils::print( "READ TRAP @ 0x%08x: %i -> 0x%08x", arm_pc, trap_info.midinfo.reg, reg_value );

						}
						else
						{
							// write
							vm_write( trap_info.address, trap_info.instruction );

							hook_list.active = true;
							hook_list.prev_index = i;

							utils::print( "WRITE TRAP @ 0x%08x: %i -> %s", arm_pc, trap_info.midinfo.reg, ( const char* ) trap_info.midinfo.write_value );

							switch ( trap_info.midinfo.reg )
							{
							case arm_inspect_reg::R0:
								ctx->uc_mcontext.arm_r0 = (uintptr_t) trap_info.midinfo.write_value;
								break;

							case arm_inspect_reg::R1:
								ctx->uc_mcontext.arm_r1 = ( uintptr_t ) trap_info.midinfo.write_value;
								break;

							case arm_inspect_reg::R2:
								ctx->uc_mcontext.arm_r2 = ( uintptr_t ) trap_info.midinfo.write_value;
								break;

							case arm_inspect_reg::R3:
								ctx->uc_mcontext.arm_r3 = ( uintptr_t ) trap_info.midinfo.write_value;
								break;

							case arm_inspect_reg::R4:
								ctx->uc_mcontext.arm_r4 = ( uintptr_t ) trap_info.midinfo.write_value;
								break;

							case arm_inspect_reg::LR:
								ctx->uc_mcontext.arm_lr = ( uintptr_t ) trap_info.midinfo.write_value;
								break;

							default:
								break;
							}
						}
					}
					else
					{
						vm_write( trap_info.address, trap_info.instruction );

						hook_list.active = true;
						hook_list.prev_index = i;

						ctx->uc_mcontext.arm_pc = ( uintptr_t ) trap_info.callback;
					}

					break;
				}
			}

			hook_list.active = false;
		}

		static void setup( sighandler_t handler, bool sigsegv )
		{
			struct sigaction sa;
			sa.sa_flags = SA_SIGINFO | SA_RESTART;

			sigemptyset( &sa.sa_mask );
			sa._u._sa_sigaction = handler;

			sigaction( SIGTRAP, ( struct sigaction* ) &sa, nullptr );
			sigaction( SIGILL, ( struct sigaction* ) &sa, nullptr );

			if ( sigsegv )
				sigaction( SIGSEGV, ( struct sigaction* ) &sa, nullptr );

			utils::debug_print( "[*] setup signal handler!" );

			hook_list.prev_index = -1;
			hook_list.active = false;

			pthread_t tid;
			pthread_create( &tid, nullptr, hook_watchdog, nullptr );
		}

		static int add_entry( const uintptr_t address, void* callback )
		{
			trap_info_t trap { 0 };

			uintptr_t real_addr = TEST_BIT0( address ) ? CLEAR_BIT0( address ) : address;

			trap.callback = callback;
			trap.address = real_addr;
			trap.is_mid = false;			// not a instruction hook
			
			memcpy( ( void* ) trap.instruction, ( void* ) real_addr, sizeof( trap.instruction ) );

			utils::debug_print( "First Byte: 0x%x", trap.instruction[ 0 ] );
			utils::debug_print( "Callback: 0x%08x",(uintptr_t) callback );
			utils::debug_print( "Address: 0x%08x", trap.address );

			if ( hook_list.size >= 16 )
			{
				utils::debug_print( "Maximum amount of hooks reached!" );
				return -1;
			}

			hook_list.list[ hook_list.size ] = trap;
			hook_list.size++;

			utils::debug_print( "Size: %i", hook_list.size );

			return 0;
		}

		static int hook_with_entry( const char* sym, void* callback )
		{
			uintptr_t address = (uintptr_t) get_lib_symbol( sym );
			if ( address == 0 )
				return -1;

			// likely not an individual instruction hook
			add_entry( address, callback );

			if ( vm_write( address, softbp::ARM_THUMB_BKPT ) < 0 )
			{
				utils::debug_print( "Error with protection: %s\n", strerror( errno ) );
				return -2;
			}

			return 0;
		}

		static int add_mid_entry( const uintptr_t address, mid_hook_info_t minfo )
		{
			trap_info_t trap { 0 };

			uintptr_t real_addr = TEST_BIT0( address ) ? CLEAR_BIT0( address ) : address;

			trap.midinfo = minfo;
			trap.is_mid = true;

			trap.callback = nullptr; // no PC callbacks for inline hooks 
			trap.address = real_addr;

			memcpy( ( void* ) trap.instruction, ( void* ) real_addr, sizeof( trap.instruction ) );

			if ( hook_list.size >= 16 )
			{
				utils::debug_print( "Maximum amount of hooks reached!" );
				return -1;
			}

			hook_list.list[ hook_list.size ] = trap;
			hook_list.size++;

			return 0;
		}

		static int midhook_with_entry( const char* sym, mid_hook_info_t minfo )
		{
			uintptr_t address = ( uintptr_t ) get_lib_symbol( sym ) + minfo.instr_offset;
			if ( address == 0 )
				return -1;

			if ( minfo.instr_offset == 0 )
				return -2;

			if ( minfo.op == reg_op::wr && minfo.write_value == nullptr )
				return -3;

			//
			// likely not an individual instruction hook
			//
			add_mid_entry( address, minfo );

			if ( vm_write( address, softbp::ARM_THUMB_BKPT ) < 0 )
			{
				utils::debug_print( "Error with protection: %s\n", strerror( errno ) );
				return -2;
			}

			return 0;
		}
	};
}
