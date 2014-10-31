rsvp.out: course.o rsvp.o student.o vector.o
	g++ -Wall -ansi  -o rsvp.out course.o rsvp.o student.o vector.o 

course.o: course.c course.h vector.h 
	g++ -Wall -ansi  -c course.c

rsvp.o: rsvp.c course.h vector.h student.h 
	g++ -Wall -ansi  -c rsvp.c

student.o: student.c student.h vector.h 
	g++ -Wall -ansi  -c student.c

vector.o: vector.c vector.h course.h 
	g++ -Wall -ansi  -c vector.c

clean:
	rm -f rsvp.out course.o rsvp.o student.o vector.o 
