sheetYsub.o: storage/twoDVec.h storage/abstractVec.h storage/sheetYsub.h storage/sheetYsub.cpp
	g++ -c 


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
test_twoDVec: storage/twoDVec.h storage/twoDVecTest.cpp
	g++ storage/twoDVecTest.cpp -o twoDVecTest



