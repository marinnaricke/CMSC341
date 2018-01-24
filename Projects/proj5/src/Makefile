FLAGS = -Wall

#all: words.h Pinball.o Driver.o
#	g++ $(FLAGS) $^ -o Driver.out

all: words.h Pinball.o mediumtest.o
	g++ $(FLAGS) $^ -o Driver.out

Pinball.o: Pinball.cpp Pinball.h
	g++ $(FLAGS) Pinball.cpp -c

#OldDriver.o: OldDriver.cpp
#	g++ $(FLAGS) OldDriver.cpp -c

Driver.o: Driver.cpp
	g++ $(FLAGS) Driver.cpp -c

mediumtest.o: mediumtest.cpp
	g++ $(FLAGS) mediumtest.cpp -c

#smalltest.o: smalltest.cpp
#	g++ $(FLAGS) smalltest.cpp -c

run:
	./Driver.out 

.PHONY: clean make

make:
	emacs Makefile

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
