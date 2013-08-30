
all : student_message fork project1

CC = gcc
CFLAGS = -g 

fork : fork.o csapp.o
	$(CC) $(CFLAGS) -lpthread -o $@ fork.o csapp.o

%.o : %.c csapp.h
	$(CC) $(CFLAGS) -c $<  

project1 : project1.o csapp.o
	$(CC) $(CFLAGS) -lpthread -o $@ project1.o csapp.o



.phoney : student_message
student_message :
	echo It is YOUR JOB to make sure and maybe reconfigure this Makefile so make builds your Project 01 software!

.phoney : clean
clean :
	rm -f *.o fork project1
