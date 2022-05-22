make: run
	./run
run: Combat.cpp Monster.cpp Player.cpp testmain.cpp
	g++ Combat.cpp GameStats.cpp Monster.cpp Player.cpp testmain.cpp -o run 