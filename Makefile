CC=cc
CFLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -g

SRC_DIR=src
BUILD_DIR=build
SRC_FILES=$(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

HDR_DIR=include
HDR_FILES=$(wildcard $(HDR_DIR)/**/*.h $(HDR_DIR)/*.h)

all: $(BUILD_DIR)/main
	@echo "(DONE) $@"
	@cp $(BUILD_DIR)/main syncio

$(BUILD_DIR)/main: $(OBJ_FILES) | $(BUILD_DIR)
	@echo "(LINK) $@"
	@$(CC) $(CFLAGS) -o $@ $^

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
	@rm -f syncio

.PHONY: all clean 