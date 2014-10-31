rsvp.out: course.o rsvp.o vector.o
	g++ -Wall -ansi -g -o rsvp.out course.o rsvp.o vector.o 

course.o: course.c course.h vector.h 
	g++ -Wall -ansi -g -c course.c

rsvp.o: rsvp.c course.h vector.h 
	g++ -Wall -ansi -g -c rsvp.c

vector.o: vector.c vector.h 
	g++ -Wall -ansi -g -c vector.c

clean:
	rm -f rsvp.out course.o rsvp.o vector.o 
