CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -I include/

SRCS=src/game/game.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: bin/main run

run:
	./bin/main

bin/main: game.o main.o
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o bin/main game.o main.o $(LDLIBS) `sdl2-config --cflags --libs`

game.o: src/game/game.cpp src/game/game.h
	$(CXX) $(CPPFLAGS) -c src/game/game.cpp

main.o: src/main.cpp src/game/game.h
	$(CXX) $(CPPFLAGS) -c src/main.cpp

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) tool
