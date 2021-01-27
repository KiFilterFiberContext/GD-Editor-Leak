#pragma once

#include <stdint.h>
#include <signal.h>

#ifdef __i386__
struct sigcontext {
	__u16				gs, __gsh;
	__u16				fs, __fsh;
	__u16				es, __esh;
	__u16				ds, __dsh;
	__u32				edi;
	__u32				esi;
	__u32				ebp;
	__u32				esp;
	__u32				ebx;
	__u32				edx;
	__u32				ecx;
	__u32				eax;
	__u32				trapno;
	__u32				err;
	__u32				eip;
	__u16				cs, __csh;
	__u32				eflags;
	__u32				esp_at_signal;
	__u16				ss, __ssh;
	struct _fpstate __user		*fpstate;
	__u32				oldmask;
	__u32				cr2;
};
#elif __arm__
struct sigcontext {
	unsigned long trap_no;
	unsigned long error_code;
	unsigned long oldmask;
	unsigned long arm_r0;
	unsigned long arm_r1;
	unsigned long arm_r2;
	unsigned long arm_r3;
	unsigned long arm_r4;
	unsigned long arm_r5;
	unsigned long arm_r6;
	unsigned long arm_r7;
	unsigned long arm_r8;
	unsigned long arm_r9;
	unsigned long arm_r10;
	unsigned long arm_fp;
	unsigned long arm_ip;
	unsigned long arm_sp;
	unsigned long arm_lr;
	unsigned long arm_pc;
	unsigned long arm_cpsr;
	unsigned long fault_address;
};
#endif

typedef struct sigcontext mcontext_t;
typedef struct ucontext {
  unsigned long uc_flags;
  struct ucontext* uc_link;
  stack_t uc_stack;
  mcontext_t uc_mcontext;
  sigset_t uc_sigmask;
  // Android has a wrong (smaller) sigset_t on ARM.
  uint32_t __padding_rt_sigset;
  // The kernel adds extra padding after uc_sigmask to match glibc sigset_t on ARM.
  char __padding[120];
  unsigned long uc_regspace[128] __attribute__((__aligned__(8)));
} ucontext_t;

typedef struct ucontext {
  uint32_t          uc_flags;
  struct ucontext*  uc_link;
  stack_t           uc_stack;
  mcontext_t        uc_mcontext;
  /* Only expose the 32 non-realtime signals in Bionic's 32-bit sigset_t
   * The _unused field is required padding from the kernel. */
  sigset_t          uc_sigmask;
  int               _unused[32 - sizeof(sigset_t)/sizeof(int)];
  uint32_t          uc_regspace[128] __attribute__((__aligned__(8)));
} ucontext_t;