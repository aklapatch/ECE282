
all: moreAK hello read_file write_file

clean: 
	rm -f moreAK.exe mylog.txt hello.exe readFile.exe writeFile.exe

moreAK: moreAK.c
	gcc -g moreAK.c -o moreAK.exe

hello:
	gcc hello_world.c -o hello.exe 

read_file:
	gcc lab01-readFile.c -o readFile.exe

write_file:
	gcc lab01-writeToFile.c -o writeFile.exe

test: moreAK
	./moreAK.exe -o out.txt Commands.txt
