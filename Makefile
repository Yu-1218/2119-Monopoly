main : main.o dice.o map.o
	g++ -pedantic-errors -std=c++11 main.o dice.o map.o -o main

main.o : main.cpp dice.h map.h main.h
	g++ -pedantic-errors -std=c++11 -c main.cpp

map.o : map.cpp map.h main.h
	g++ -pedantic-errors -std=c++11 -c map.cpp

dice.o : dice.cpp dice.h
	g++ -pedantic-errors -std=c++11 -c dice.cpp