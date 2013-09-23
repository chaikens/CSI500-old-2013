
all : student_message fork project1 interact medoffice doctor nurse receptionist

CC = gcc
CFLAGS = -g 

interact : interact.o csapp.o
	$(CC) $(CFLAGS) -lpthread -o $@ interact.o csapp.o


medoffice : medoffice.o csapp.o
	$(CC) $(CFLAGS) -lpthread -o $@ medoffice.o csapp.o

doctor : doctor.o
	$(CC) $(CFLAGS) -o $@ doctor.o

nurse : nurse.o 
	$(CC) $(CFLAGS) -o $@ nurse.o 

receptionist : receptionist.o 
	$(CC) $(CFLAGS)  -o $@ receptionist.o 


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
