# makefile
# 2022-02-07

prog : main.o library.0
	cc -o prog main.o library.o
main.0 : main.c library.h
	cc -c main.c
library.o : library.c library.h
	cc -c library.c
.PHONY : clean
clean :
	rm main.o library.o