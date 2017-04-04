all: build run clean
build:
	gcc -o game main.c
run:
	./game
clean:
	rm -f game
