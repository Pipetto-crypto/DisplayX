CXX := g++ 
CXXFLAGS := -std=c++17 -fPIC -lX11-xcb -lxcb -landroid -target aarch64-linux-android30 -g
LDFLAGS := -shared
PREFIX := /usr
JSON := displayx_layer.json
JSON_INSTALL := $(PREFIX)/share/vulkan/implicit_layer.d
INSTALL := $(PREFIX)/lib/x86_64-linux-gnu

SOURCES := src/displayx_layer.cpp \
		   src/id.cpp \
		   src/logger.cpp

HEADERS := src/displayx_layer.hpp \
		   src/logger.hpp \
		   src/id.hpp \
		   src/vulkan/vk_layer.h
	      
OUTPUT := displayx_layer.so

all : $(OUTPUT)
	
$(OUTPUT) : $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SOURCES) -o $(OUTPUT)

.PHONY: clean install

install: $(OUTPUT)
	install -d $(INSTALL)
	install -m 755 $(OUTPUT) $(INSTALL)
	install -d $(JSON_INSTALL)
	install -m 755 $(JSON) $(JSON_INSTALL)

clean:
	rm -rf $(OUTPUT)
