CC = gcc

SDLLIBS = $(shell sdl-config --libs)
SDLCFLAGS = $(shell sdl-config --cflags)

minhoca: minhoca.o fonte.o ai.o snake.o
	$(CC) -o $@ $^ $(SDLLIBS) -g

snake.o: snake.c snake.h
	$(CC) -c $^ $(SDLCFLAGS) -g

fonte.o: fonte.c fonte.h
	$(CC) -c $^ $(SDLCFLAGS) -g

ai.o: ai.c ai.h
	$(CC) -c $^ $(SDLCFLAGS) -g

minhoca.o: minhoca.c basicdefs.h
	$(CC) -c $^ $(SDLCFLAGS) -g

clean:
	rm -rf minhoca *.o
