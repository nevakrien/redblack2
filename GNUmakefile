# Compiler and flags
# CC = $(shell which gcc-14 || echo gcc) #this is to get the best preformance
# CXX =$(shell which g++-14 || echo g++) #clang fails... but nicer error messages
CC = gcc
Flags = -Wall -Wextra -Iinclude -g2 #-fprofile-arcs -ftest-coverage #-fsanitize=address #-fopenmp
CFLAGS = $(Flags) -std=gnu99 

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)
TARGET = $(BIN_DIR)/main

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR) $(BIN_DIR)

-include $(DEPS)

check: clean
	make all -j


.PHONY: all clean check
