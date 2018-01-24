FLAGS = -Wall

all: Driver.o LlamaNode.o Llama.o
	g++ $(FLAGS) Driver.o LlamaNode.o Llama.o -o Driver.out

LlamaNode.o: LlamaNode.cpp LlamaNode.h 
	g++ $(FLAGS) LlamaNode.cpp -c

Llama.o: Llama.cpp Llama.h LlamaNode.cpp LlamaNode.h
	g++ $(FLAGS) Llama.cpp -c

Driver.o: Driver.cpp Llama.h Llama.cpp
	g++ $(FLAGS) Driver.cpp -c

run:
	./Driver.out

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#