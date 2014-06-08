CC = gcc

SDLLIBS = $(shell sdl-config --libs)
SDLCFLAGS = $(shell sdl-config --cflags)
CFLAGS= -g3


minhoca: minhoca.o fonte.o ai.o snake.o
	$(CC) -o $@ $^ $(SDLLIBS) $(CFLAGS)

snake.o: snake.c snake.h
	$(CC) -c $^ $(SDLCFLAGS) $(CFLAGS)

fonte.o: fonte.c fonte.h
	$(CC) -c $^ $(SDLCFLAGS) $(CFLAGS)

ai.o: ai.c ai.h
	$(CC) -c $^ $(SDLCFLAGS) $(CFLAGS)

minhoca.o: minhoca.c basicdefs.h
	$(CC) -c $^ $(SDLCFLAGS) $(CFLAGS)

clean:
	rm -rf minhoca *.o *.gch
