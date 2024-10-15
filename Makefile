CC=cc
CFLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -g

SRC_DIR=src
BUILD_DIR=build
SRC_FILES=$(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

HDR_DIR=include
HDR_FILES=$(wildcard $(HDR_DIR)/**/*.h $(HDR_DIR)/*.h)

LIB_NAME=libsync.so

all: $(BUILD_DIR)/$(LIB_NAME)
	@echo "(DONE) $@"

$(BUILD_DIR)/$(LIB_NAME): $(OBJ_FILES) | $(BUILD_DIR)
	@echo "(AR) $@"
	@ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HDR_FILES) | $(BUILD_DIR)
	@echo "(COMP) $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(HDR_DIR) -c -o $@ $<

$(BUILD_DIR):
	@echo "(INIT)"
	@mkdir -p $@

clean:
	@echo "(CLEAN)"
	@rm -rf $(BUILD_DIR)
	@rm -f $(BUILD_DIR)/$(LIB_NAME)

.PHONY: all clean