# Makefile for SDL2 game

# Compiler and flags
CC = gcc
CFLAGS = $(shell pkg-config --cflags sdl2) -Wall
LIBS = $(shell pkg-config --libs sdl2)

# Source files and executable name
SRCS = $(wildcard src/*.c)
EXEC = game.exe

# Default target
all: $(EXEC)

# Compile the game
$(EXEC): $(SRCS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

# Run the game
run: $(EXEC)
	./$(EXEC)

# Clean build artifacts
clean:
	rm -f $(EXEC)

# Phony targets
.PHONY: all run clean
