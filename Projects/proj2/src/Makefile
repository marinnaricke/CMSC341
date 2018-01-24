FLAGS = -Wall

all: Driver.o Commodity.o Game.o CommodityStore.o Objective.o Player.o Card.o
	g++ $(FLAGS) $^ -o Driver.out

Commodity.o: Commodity.cpp Commodity.h
	g++ $(FLAGS) Commodity.cpp -c

Game.o: Game.cpp Game.h Player.h Player.cpp CommodityStore.h CommodityStore.cpp
	g++ $(FLAGS) Game.cpp -c

CommodityStore.o: CommodityStore.cpp CommodityStore.h Commodity.h Commodity.cpp
	g++ $(FLAGS) CommodityStore.cpp -c

Objective.o: Objective.cpp Objective.h Commodity.cpp Commodity.h
	g++ $(FLAGS) Objective.cpp -c

Player.o: Player.cpp Player.h Card.cpp Card.h
	g++ $(FLAGS) Player.cpp -c

Card.o: Card.cpp Card.h Objective.cpp Objective.h
	g++ $(FLAGS) Card.cpp -c

Driver.o: Driver.cpp
	g++ $(FLAGS) Driver.cpp -c

run:
	./Driver.out $(CARDS) $(COMMODITIES) $(PLAYERS) $(STRATEGY)

.PHONY: clean valCheck

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#

valCheck: Driver.out
	valgrind ./Driver.out $(CARDS) $(COMMODITIES) $(PLAYERS) $(STRATEGY)