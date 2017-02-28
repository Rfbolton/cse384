#makefile for hw5
gitsample: gitsample.c
	gcc -o gitsample gitsample.c

clean:
	rm gitsample

tar:
	tar -cf gitsample.tar gitsample.c makefile
