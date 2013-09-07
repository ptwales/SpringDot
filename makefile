springTest: springTest.o springTest_system.o
	g++ springTest.cpp springTest_system.o -o springTest

springTest.o: springTest.cpp
	g++ -c springTest.cpp

springTest_system.o: springTest_system.cpp
	g++ -c springTest_system.cpp

clean:
	rm *.o
	rm springTest
