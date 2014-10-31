#Author: Angela(Haowen) Zhou

rsvp.out: course.o student.o vector.o rsvp.o
	gcc -Wall -g -o rsvp.out rsvp.o course.o student.o vector.o
course.o:course.c course.h student.h
	gcc -Wall -g -c course.c
student.o:student.c student.h vector.h
	gcc -Wall -g -c student.c
vector.o:vector.c vector.h course.h student.h
	gcc -Wall -g -c vector.c
rsvp.o: rsvp.c course.h student.h vector.h
	gcc -Wall -g -c rsvp.c
clean:
	rm -f rsvp.out *.o	