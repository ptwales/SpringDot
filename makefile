springTest: main.o user_system.o
	g++ main.cpp user_system.o -o springTest

main.o: main.cpp
	g++ -c main.cpp

user_system.o: user_system.cpp
	g++ -c user_system.cpp

clean:
	rm *.o
