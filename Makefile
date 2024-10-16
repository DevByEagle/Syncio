CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -g

SRC_DIR=src
BUILD_DIR=build
SRC_FILES=$(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

HDR_DIR=include
HDR_FILES=$(wildcard $(HDR_DIR)/**/*.h $(HDR_DIR)/*.h)

LIB_NAME=libsync.so

all: $(LIB_NAME)
	@echo "(DONE) $@"

$(LIB_NAME): $(OBJ_FILES) | $(BUILD_DIR)
	@echo "(AR) $@"
	@ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDR_FILES) | $(BUILD_DIR)
	@echo "(COMP) $@"
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -I$(HDR_DIR) -c -o $@ $<

$(BUILD_DIR):
	@echo "(INIT)"
	@mkdir -p $@

clean:
	@echo "(CLEAN)"
	@rm -rf $(BUILD_DIR)
	@rm -f $(LIB_NAME)

.PHONY: all clean