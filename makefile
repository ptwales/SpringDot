CC = c++
Objects = sheetYsub.o
Tests = test_twoDVec test_sheetYsub
TestDir = test_bin

sheetYsub.o: storage/twoDVec.h storage/selectiveSheet.h storage/sheetYsub.h storage/sheetYsub.cpp
	$(CC) -c storage/sheetYsub.cpp

testall: $(Tests)

# define folder as variable later
test_twoDVec: storage/twoDVec.h storage/test_twoDVec.cpp
	$(CC) storage/test_twoDVec.cpp -o test_twoDVec
	./test_twoDVec

test_sheetYsub: storage/test_sheetYsub.cpp sheetYsub.o 
	$(CC) storage/test_sheetYsub.cpp sheetYsub.o -o test_sheetYsub
	./test_sheetYSub

clean:
	rm $(Objects) $(Tests)



