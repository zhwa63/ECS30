rsvp.out:vector.o course.o rsvp.o
	gcc -Wall -g -o rsvp.out vector.o rsvp.o course.o
vector.o:vector.c vector.h 
	gcc -Wall -g -c  vector.c
course.o: course.c course.h vector.h
	gcc -Wall -g -c course.c
rsvp.o: rsvp.c course.h vector.h
	gcc -Wall -g -c rsvp.c
clean:
	rm -f rsvp.out *.o
