# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -I. -I./headers
TFLAGS = -DTEST

# Archive and flags
AR = ar
ARFLAGS = rcs

# Directories
SRC_DIR = functions
OBJ_DIR = obj
TEST_DIR = tests

# Library name and output
LIB_NAME = s21_decimal
LIB = $(LIB_NAME).a

TEST_EXEC = test_s21_decimal

# Source files
SRCS = $(shell find $(SRC_DIR)  -name "*.c")
TESTS_SRCS = $(shell find $(TEST_DIR)  -name "*.c")

# Object files
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
TESTS_OBJS = $(SRCS:%.c=$(TESTS_OBJS)/%.o)

# Phony targets
.PHONY: all clean

# Default target: build the library
all: $(LIB)

# Build the library from object files
$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: %.c $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the object directory exists
$(OBJ_DIR):
	mkdir -p $@

# Clean up the build directory
clean:
	rm -rf $(OBJ_DIR)

clear: clean
	rm -f $(LIB)
	rm -f $(TEST_EXEC)

# Rebuild the project from scratch
rebuild: clean all

# Build the project
build: all

test: $(LIB)
	$(CC) $(CFLAGS) $(TFLAGS) $(TESTS_SRCS) $(LIB) -o $(TEST_EXEC)
	./$(TEST_EXEC)