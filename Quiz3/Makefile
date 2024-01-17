all: exec

exec:
	gcc -std=c99 -g quiz.c -o quiz

test: exec
	valgrind ./quiz

report: exec
	valgrind ./quiz 2>> Valgrind_output.txt

.PHONY: clean

clean:
	-rm quiz Valgrind_output.txt
