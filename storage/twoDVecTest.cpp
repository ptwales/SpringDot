#include <iostream>
#include "twoDVec.h"


int main ()
{
	std::cout << "Compiles and Runs!" << std::endl;
	storage::twoDVec *test;


	std::cout<<std::endl<<std::endl;
	//test default constructor
	std::cout << "Test Default Constructor\ntest = new twoDVec;"<<std::endl;
	test = new storage::twoDVec;
	std::cout << "Test accesor\ntest->sheet[0][0] = "<< test->sheet[0][0] << std::endl;


	std::cout<<std::endl<<std::endl;
	//test Destructor
	std::cout << "Test Destructor\ndelete test;"<<std::endl;
	delete test;


	std::cout<<std::endl<<std::endl;
	//test filler constructor
	std::cout << "Test filler constructor\ntest = new twoDVec(5,5);"<<std::endl;
	test = new storage::twoDVec(5,5);
	std::cout << "Test accesor\ntest->sheet[4][4] = "<< test->sheet[4][4] << std::endl;
	delete test;

	std::cout<<std::endl<<std::endl;
	//test element constructor
	std::cout << "Test element constructor\ntest = new twoDVec(5,5,3);" <<std::endl;
	test = new storage::twoDVec(5,5,3);
	std::cout << "Test accesor\ntest->sheet[4][4] = "<< test->sheet[4][4] << std::endl;

	std::cout<<std::endl<<std::endl;
	//test vector constructor
	std::cout << "Test vector constructor\nuser_prec mySequence[] = {1,2,3,4,5};\nyVec myVec(mySequence, mySequence + sizeof(mySequence) / sizeof(user_prec));\ntest = new twoDVec(5,5,myVec);"<<std::endl;


	storage::user_prec mySequence[] = {1,2,3,4,5};
	storage::y_vec myVec(mySequence, mySequence + sizeof(mySequence) / sizeof(storage::user_prec));
	test = new storage::twoDVec( 5, myVec );
	
	std::cout << "Test accesor"<<std::endl;;

	for(int n = 0; n < 5; n++)
	{
		for(int m = 0; m < 5; m++)
		{
			std::cout << test->sheet[m][n] << "\t";
		}
		std::cout<<std::endl;
	}
	
	std::cout<<std::endl<<std::endl;
	//test copy constructer
	std::cout<< "Test copy constructor\ntwoDVec copy(test)"<<std::endl;
	storage::twoDVec copy(*test);

	std::cout << "Test accesor"<<std::endl;

	for(int n = 0; n < 5; n++)
	{
		for(int m = 0; m < 5; m++)
		{
			std::cout << copy.sheet[m][n] << "\t";
		}
		std::cout<<std::endl;
	}
	return EXIT_SUCCESS;
}
