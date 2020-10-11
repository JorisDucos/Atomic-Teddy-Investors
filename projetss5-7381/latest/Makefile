CFLAGS = -Wall -Wextra -std=c99 -g

all: code
code: project

project: good.o stockex.o game.o queue.o option.o rules.o tri.o move.o project-0.o rng.o
	gcc $(CFLAGS) -o $@ $^ -lm

project-0.o: src/project-0.c src/stockex.h src/queue.h src/game.h src/option.h src/rules.h src/rng.h
	gcc $(CFLAGS) -c $< -lm 

game.o: src/game.c src/game.h src/stockex.h src/option.h src/rules.h src/tri.h src/rng.h
	gcc $(CFLAGS) -c $< -lm

queue.o: src/queue.c src/queue.h src/stockex.h 
	gcc $(CFLAGS) -c $<

stockex.o: src/stockex.c src/stockex.h src/good.h src/rng.h
	gcc $(CFLAGS) -c $<

good.o: src/good.c src/good.h
	gcc $(CFLAGS) -c $<

option.o: src/option.c src/option.h
	gcc $(CFLAGS) -c $<

rules.o: src/rules.c src/rules.h src/queue.h src/stockex.h
	gcc $(CFLAGS) -c $<

tri.o : src/tri.c src/tri.h src/queue.h
	gcc $(CFLAGS) -c $<

move.o: src/move.c src/move.h src/queue.h src/stockex.h src/rng.h
	gcc $(CFLAGS) -c $<

rng.o: src/rng.c src/rng.h
	gcc $(CFLAGS) -c $<





test : test-0.o good.o stockex.o queue.o game.o option.o rules.o tri.o move.o rng.o
	(gcc $(CFLAGS) -o $@ $^ -lm) && ./test 
test-0.o: tst/test-0.c src/queue.h src/game.h src/stockex.h src/tri.h src/move.h src/option.h src/good.o src/rng.o
	gcc $(CFLAGS) -c $< -lm 
clean:
	rm -f project test *.o src/*.gch
