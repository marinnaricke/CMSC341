FLAGS = -Wall

all: Heap.o PinHit.o MaxHeap.o MinHeap.o Driver.o
	g++ $(FLAGS) $^ -o Driver.out

Heap.o: Heap.cpp Heap.h
	g++ $(FLAGS) Heap.cpp -c

PinHit.o: PinHit.cpp PinHit.h
	g++ $(FLAGS) PinHit.cpp -c

MaxValueHeap.o: MaxHeap.cpp MaxHeap.h Heap.h Heap.cpp
	g++ $(FLAGS) MaxHeap.cpp -c

MinValueHeap.o: MinHeap.cpp MinHeap.h Heap.h Heap.cpp
	g++ $(FLAGS) MinHeap.cpp -c

Driver.o: Driver.cpp
	g++ $(FLAGS) Driver.cpp -c

run:	
	./Driver.out $(INPUT) $(FLAG)

.PHONY: clean make

make:
	emacs Makefile

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
