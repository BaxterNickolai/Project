make: run
	./run
	
run: Combat.o Monster.o Player.o GameStats.o testmain.o
	g++ Combat.o GameStats.o Monster.o Player.o testmain.cpp -o run 

Combat.o: Combat.h Combat.cpp
	g++ -c Combat.cpp -o Combat.o
	
Monster.o: Monster.h Monster.cpp
	g++ -c Monster.cpp -o Monster.o
	
GameStats.o: GameStats.h GameStats.cpp
	g++ -c GameStats.cpp -o GameStats.o

Player.o: Player.h Player.cpp
	g++ -c Player.cpp -o Player.o