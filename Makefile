connect4.o: connect4.cpp wordle.h wordlestat.h
	g++ -pedantic-errors -std=c++11 -c connect4.cpp
wordle.o: wordle.cpp wordle.h
	g++ -pedantic-errors -std=c++11 -c wordle.cpp
wordlestat.o: wordlestat.cpp wordlestat.h
	g++ -pedantic-errors -std=c++11 -c wordlestat.cpp
connect4: connect4.o wordle.o wordlestat.o
	g++ -pedantic-errors -std=c++11 connect4.o wordle.o wordlestat.o -o connect4

