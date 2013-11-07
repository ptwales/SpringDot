CppC = g++
FLAGS = -std=c++11 -stdlib=libc++
CC = $(CppC) $(FLAGS)
Objects = sheetYsub.o springTest_system.o explicitEuler.o
Tests = test_sheetYsub test_spring
TestDir = test_bin

# OBJECTS
# =========
sheetYsub.o: storage/twoDVec.hpp storage/sheetInterfaces.hpp storage/sheetYsub.hpp storage/sheetYsub.cpp
	$(CC) -c storage/sheetYsub.cpp

## SOLUTION OBJECTS
## ==================
explicitEuler.o: problem/diffEq.hpp solution/diffEqMeth.hpp solution/explicitEuler.hpp solution/explicitEuler.cpp
	$(CC) -c solution/explicitEuler.cpp

## DEMO OBJECTS
## ==============
springTest_system.o: problem/diffEq.hpp demos/springTest_system.hpp demos/springTest_system.cpp
	$(CC) -c demos/springTest_system.cpp

# DEMOS
# ========
testall: $(Tests)

test_sheetYsub: demos/test_sheetYsub.cpp sheetYsub.o 
	$(CC) demos/test_sheetYsub.cpp sheetYsub.o -o test_sheetYsub
	./test_sheetYSub

test_spring: sheetYsub.o springTest_system.o explicitEuler.o demos/springTest.cpp
	$(CC) demos/springTest.cpp sheetYsub.o springTest_system.o explicitEuler.o -o test_spring
	./test_spring

clean:
	rm $(Objects) $(Tests)
