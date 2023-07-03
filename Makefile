all: build run

build: main
	gcc main.c -o main 

run: main
	./main
