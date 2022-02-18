OPTIONS=-Wall -Wextra -g
base:
	gcc *.c -o main ${OPTIONS}
	./main
