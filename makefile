PROJECT=pacman
CC=gcc
OBJECTS=gfx.c draw.c pacman.c
CFLAGS=-lX11 -lm

all: $(PROJECT)

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) $(PROJECT) $(CFLAGS)

clean:
	rm $(PROJECT)
