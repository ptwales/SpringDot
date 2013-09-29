CC = c++
Objects = sheetYsub.o
Tests = test_twoDVec test_sheetYsub
TestDir = test_bin

sheetYsub.o: storage/twoDVec.hpp storage/sheetInterfaces.hpp storage/sheetYsub.hpp storage/sheetYsub.cpp
	$(CC) -c storage/sheetYsub.cpp

testall: $(Tests)

# define folder as variable later
test_twoDVec: storage/twoDVec.hpp demos/test_twoDVec.cpp
	$(CC) demos/test_twoDVec.cpp -o test_twoDVec
	./test_twoDVec

test_sheetYsub: demos/test_sheetYsub.cpp sheetYsub.o 
	$(CC) demos/test_sheetYsub.cpp sheetYsub.o -o test_sheetYsub
	./test_sheetYSub

clean:
	rm $(Objects) $(Tests)



