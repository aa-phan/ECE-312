all: a.out

a.out: Exercise1.o
	gcc Exercise1.o # Link

Exercise1.o: Exercise1.s
	gcc -c Exercise1.s # Assemble

Exercise1.s: preproc.c
	gcc -S preproc.c -o Exercise1.s # Compile

preproc.c: Exercise1.c
	gcc -E Exercise1.c -o preproc.c # Preprocess

clean:
	rm -f a.out Exercise1.o Exercise1.s preproc.c
