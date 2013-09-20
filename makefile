Objects = sheetYsub.o
Tests = test_twoDVec test_sheetYsub

sheetYsub.o: storage/twoDVec.h storage/selectiveSheet.h storage/sheetYsub.h storage/sheetYsub.cpp
	g++ -c storage/sheetYsub.cpp

testall: $(Tests)

# define folder as variable later
test_twoDVec: storage/twoDVec.h storage/test_twoDVec.cpp
	g++ storage/test_twoDVec.cpp -o test_twoDVec
	./test_twoDVec

test_sheetYsub: storage/test_sheetYsub.cpp sheetYsub.o 
	g++ storage/test_sheetYsub.cpp sheetYsub.o -o test_sheetYsub
	./test_sheetYSub

clean:
	rm $(Objects) $(Tests)



