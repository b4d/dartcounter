all: tools.o cricket.o cricket21.o three01.o dart.o cricketr.o
	gcc tools.o cricket.o cricket21.o cricketr.o three01.o dart.o -o dart
dart.o: tools.o cricket.o cricket21.o three01.o cricketr.o
	gcc -c dart.c
tools.o: tools.c tools.h
	gcc -c tools.c
cricket.o: tools.o cricket.c cricket.h
	gcc -c cricket.c
cricket21.o: tools.o cricket21.c cricket21.h
	gcc -c cricket21.c
three01.o: tools.o three01.c three01.h
	gcc -c three01.c
cricketr.o: tools.o cricketr.c cricketr.h
	gcc -c cricketr.c
clean:
	rm *.o
