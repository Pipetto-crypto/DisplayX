#pragma once

#include <sstream>
#include <string>
#include <iostream>
#include <stdarg.h>

namespace Logger {
	#define DISPLAYX_LOG_INFO (1ull << 0)
	#define DISPLAYX_LOG_ERROR (1ull << 1)
	#define DISPLAYX_LOG_TRACE (1ull << 2)
	
	struct displayx_log {
	    std::string name;
	    unsigned long long value;
	};
	
	void log(const std::string& log_level, const char *format, ...);
	void init();
}
