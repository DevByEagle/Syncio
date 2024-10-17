ifeq ($(shell uname), Darwin)
    CXX = clang++
    CC = clang
else
    CXX = g++
    CC = gcc
endif

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -g -fPIC

# Directories
SRC_DIR = src
BUILD_DIR = build
HDR_DIR = include
PREFIX = /usr

# Source files
CXX_SRC_FILES = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
C_SRC_FILES = $(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c)

# Object files
CXX_OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CXX_SRC_FILES))
C_OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(C_SRC_FILES))
OBJ_FILES = $(CXX_OBJ_FILES) $(C_OBJ_FILES)

# Header files
HDR_FILES = $(wildcard $(HDR_DIR)/**/*.h $(HDR_DIR)/*.h)

# Library name
LIB_NAME = libsync.so

all: $(LIB_NAME)
	@echo "(DONE) $@"

$(LIB_NAME): $(OBJ_FILES) | $(BUILD_DIR)
	@echo "(LINK) $@"
	@$(CXX) -shared -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDR_FILES) | $(BUILD_DIR)
	@echo "(COMP) $<"
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAGS) -I$(HDR_DIR) -c -o $@ $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HDR_FILES) | $(BUILD_DIR)
	@echo "(COMP) $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(HDR_DIR) -c -o $@ $<

$(BUILD_DIR):
	@echo "(INIT)"
	@mkdir -p $@

install: $(LIB_NAME)
	@echo "(INSTALL) Installing $<"
	@mkdir -p $(DESTDIR)$(PREFIX)/lib
	@cp $< $(DESTDIR)$(PREFIX)/lib
	@mkdir -p $(DESTDIR)$(PREFIX)/include/Syncio
	@cp $(HDR_FILES) $(DESTDIR)$(PREFIX)/include/Syncio

uninstall:
	@echo "(UNINSTALL) Removing $<"
	@rm -f $(DESTDIR)$(PREFIX)/lib/$(LIB_NAME)
	@rm -rf $(DESTDIR)$(PREFIX)/include/Syncio

clean:
	@echo "(CLEAN)"
	@rm -rf $(BUILD_DIR)
	@rm -f $(LIB_NAME)

.PHONY: all clean install uninstall
