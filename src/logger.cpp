#include "logger.hpp"

namespace Logger {

	static struct displayx_log displayx_log_options[] = {
	    {"info", DISPLAYX_LOG_INFO},
	    {"error", DISPLAYX_LOG_ERROR},
	    {"trace", DISPLAYX_LOG_TRACE},
	    {"", 0}
	};
	
	uint64_t displayx_log_mask;
	static bool initialized = false;

	static unsigned long long get_debug_flag(const char *option) {
    	int index = 0;

        while (!displayx_log_options[index].name.empty()) {
        	if (!std::strcmp(displayx_log_options[index].name.c_str(), option))                      
         		return displayx_log_options[index].value;
                                                                                                   
         	index++;
        }

        return 0;
    }
      
	static bool get_displayx_log_level(const std::string& option) {
		uint64_t flag = get_debug_flag(option.c_str());

		if (displayx_log_mask & flag)
			return true;

		return false;
	}
	
	void log (const std::string& log_level, const char *format, ...) {
		init();
		
		if (!get_displayx_log_level(log_level.c_str()))
			return;
			
		constexpr size_t BUFFER_SIZE = 1024;
		char buffer[BUFFER_SIZE];
		
		va_list args;
		va_start(args, format);
		vsnprintf(buffer, BUFFER_SIZE, format, args);
		va_end(args);
		
		std::cerr << "[" << log_level << "]: " << buffer << std::endl;
	}

	void init() {
		if (initialized)
			return;
			
		char *displayx_log_env = std::getenv("DISPLAYX_LOG_LEVEL");
		if (!displayx_log_env) {
			displayx_log_mask = 0;
			return;
		}

		const char *option = std::strtok(displayx_log_env, ",");

		while (option != nullptr) {
			displayx_log_mask |= get_debug_flag(option);
			option = std::strtok(nullptr, ",");
		}

		initialized = true;
	}
}
