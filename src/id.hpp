#pragma once

#include <deque>

class ID {
	private:
		std::deque<uint8_t> ids;
	public:
		ID();
		uint8_t generate();
		void destroy(uint8_t);
};
