#actual build stuff


clean:
	rm *.o
	rm springTest

#TESTING MAKES
springTest: springTest.o springTest_system.o
	g++ springTest.cpp springTest_system.o -o springTest

springTest.o: springTest.cpp
	g++ -c springTest.cpp

springTest_system.o: springTest_system.cpp
	g++ -c springTest_system.cpp

#testall: twoDVec
#	./twoDVec

# define folder as variable later
twoDVec: storage/twoDVec.h answer/twoDVecTest.cpp
	g++ twoDVecTest.cpp -o twoDVecTest
