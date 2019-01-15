
all: moreAK

clean: 
	rm -f moreAK.exe out.txt

moreAK: moreAK.c
	gcc -g moreAK.c -o moreAK.exe

test: moreAK
	./moreAK -o out.txt Commands.txt
