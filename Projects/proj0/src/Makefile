FLAGS = -Wall

all: Driver.o Country.o Continent.o
	g++ $(FLAGS) Driver.o Country.o Continent.o -o Driver.out

Country.o: Country.cpp Country.h
	g++ $(FLAGS) Country.cpp -c

Continent.o: Continent.cpp Continent.h Country.cpp Country.h
	g++ $(FLAGS) Continent.cpp -c

Driver.o: Driver.cpp
	g++ $(FLAGS) Driver.cpp -c

run: 
	./Driver.out

clean: 
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#