all: build run clean

build: main
	gcc main.c -o main 

run: main
	./main

clean: main
	rm ./main
