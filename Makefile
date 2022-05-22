make: run
	./run
run: Combat.cpp Monster.cpp Player.cpp testmain.cpp
	g++ GameStats.cpp Combat.cpp Monster.cpp Player.cpp testmain.cpp -o run 