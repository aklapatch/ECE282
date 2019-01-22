all: hello

clean:
	rm main.o f1.o f2.o
	rm hello

hello: main.o f1.o f2.o
	gcc -o hello main.o f1.o f2.o

main.o: main.c
	gcc -c main.c

f1.o: f1.c
	gcc -c f1.c

f2.o: f2.c
	gcc -c f2.c
