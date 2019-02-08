
all: append.c
	g++ -g append.c -o append.exe

test: all
	./append.exe Commands.txt out.txt

clean:
	rm -f append.exe out.txt
