CC = gcc
CFLAGS = -I./include -Wall -Wextra -std=c11 -Dmain=SDL_main
LDFLAGS = -L./lib -lmingw32 -lSDL2main -lSDL2 -lm -mwindows

SRC = src/main.c src/game.c
OBJ = $(SRC:.c=.o)
EXEC = game

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)

run: $(EXEC)
	./$(EXEC)
	$(MAKE) clean

.PHONY: all clean run