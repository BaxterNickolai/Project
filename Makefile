make: run
	./run
run: Combat.cpp Monster.cpp Player.cpp testmain.cpp
	g++ Combat.cpp Monster.cpp Player.cpp testmain.cpp -o run