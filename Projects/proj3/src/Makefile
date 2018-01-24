FLAGS = -Wall

all: AVLTreeBase.h AVLTree.o AVLNode.o AVLForest.o Driver.o 
	g++ $(FLAGS) $^ -o Driver.out

AVLTree.o: AVLTree.cpp AVLTree.h AVLTreeBase.h 
	g++ $(FLAGS) AVLTree.cpp -c

AVLNode.o: AVLNode.cpp AVLNode.h 
	g++ $(FLAGS) AVLNode.cpp -c

AVLForest.o: AVLForest.cpp AVLForest.h AVLTree.h AVLTree.cpp 
	g++ $(FLAGS) AVLForest.cpp -c

Driver.o: Driver.cpp
	g++ $(FLAGS) Driver.cpp -c

run:
	./Driver.out $(INPUT) $(RANGE)

.PHONY: clean make

make:
	emacs Makefile

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
