all: edit
edit : main.o actions.o diary.o string_utils.o
     gcc -o edit main.o actions.o diary.o string_utils.o
main.o : main.c diary.h
     gcc -c main.c
actions.o : actions.c actions.h
     gcc -c actions.c
diary.o : diary.c diary.h actions.h
     gcc -c diary.c
string_utils.o : string_utils.c diary.h
     gcc -c string_utils.c
clean :
     rm edit main.o actions.o diary.o string_utils.o