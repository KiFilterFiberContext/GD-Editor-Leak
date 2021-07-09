#pragma once

namespace photon::utils
{
	constexpr bool debug_log = true;

	template <typename... Args>
	static inline void debug_print( Args... args )
	{
		if constexpr ( !debug_log )
			return;

		__android_log_print( ANDROID_LOG_DEBUG, "[DEBUG] photon -- ", args... );
	}

	template <typename... Args>
	static inline void print( Args... args )
	{
		__android_log_print( ANDROID_LOG_INFO, "photon -- ", args... );
	}

	static bool str_replace( std::string& str, const std::string& from, const std::string& to )
	{
		size_t start_pos = str.find( from );
		if ( start_pos == std::string::npos )
			return false;
		str.replace( start_pos, from.length( ), to );
		return true;
	}

	typedef struct handle
	{
		Elf64_Ehdr* ehdr;
		Elf64_Phdr* phdr;
		Elf64_Shdr* shdr;
		uint8_t* mem;
		char* symname;
		Elf64_Addr symaddr;
		char* exec;
	} handle_t;
}
