main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o

tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o

main.o: main.cpp profile.h network.h
	g++ -c main.cpp

tests.o: tests.cpp doctest.h profile.h network.h
	g++ -c tests.cpp

profile.o: profile.cpp profile.h
	g++ -c profile.cpp

network.o: network.cpp network.h profile.h
	g++ -c --std=c++11 network.cpp

clean:
	rm -f main tests main.o tests.o profile.o network.o