#include "id.hpp"

ID::ID() {
	for (uint32_t i = 0; i < 256; i++)
		ids.push_back(static_cast<uint8_t>(i));
}

uint8_t ID::generate() {
	if (ids.empty())
		throw std::runtime_error("No IDs available");
	
	uint8_t id = ids.front();
	ids.pop_front();
	return id;
}

void ID::destroy(uint8_t id) {
	ids.push_back(id);
}
