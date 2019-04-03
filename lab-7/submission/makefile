all: sigdemo ouchsig play-again

sigdemo: sigdemoAK.c
	gcc -Wall -g sigdemoAK.c -o demosig.exe

ouchsig: OuchSigAK.c
	gcc -Wall -g OuchSigAK.c -o sigouch.exe

play-again: play-againAK.c
	gcc -Wall -g play-againAK.c -o play-again.exe

clean:
	rm -f *.exe
