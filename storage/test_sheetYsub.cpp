#include <iostream>
#include "twoDVec.h"


using namespace std;
int main ()
{
	cout << "Compiles and Runs!" << endl;
	storage::twoDVec *test;


	cout<<endl<<endl;
	//test default constructor
	cout << "Test Default Constructor\ntest = new twoDVec;"<<endl;
	test = new storage::twoDVec;
	cout << "Test accesor\ntest->sheet[0][0] = "<< test->sheet[0][0] << endl;


	cout<<endl<<endl;
	//test Destructor
	cout << "Test Destructor\ndelete test;"<<endl;
	delete test;


	cout<<endl<<endl;
	//test filler constructor
	cout << "Test filler constructor\ntest = new twoDVec(5,5);"<<endl;
	test = new storage::twoDVec(5,5);
	cout << "Test accesor\ntest->sheet[4][4] = "<< test->sheet[4][4] << endl;
	delete test;

	cout<<endl<<endl;
	//test element constructor
	cout << "Test element constructor\ntest = new twoDVec(5,5,3);" <<endl;
	test = new storage::twoDVec(5,5,3);
	cout << "Test accesor\ntest->sheet[4][4] = "<< test->sheet[4][4] << endl;

	cout<<endl<<endl;
	//test vector constructor
	cout << "Test vector constructor\nuser_prec mySequence[] = {1,2,3,4,5};\nyVec myVec(mySequence, mySequence + sizeof(mySequence) / sizeof(user_prec));\ntest = new twoDVec(5,5,myVec);"<<endl;


	storage::user_prec mySequence[] = {1,2,3,4,5};
	storage::y_vec myVec(mySequence, mySequence + sizeof(mySequence) / sizeof(storage::user_prec));
	test = new storage::twoDVec( 5, myVec );
	
	cout << "Test accesor"<<endl;;

	for(int n = 0; n < 5; n++)
	{
		for(int m = 0; m < 5; m++)
		{
			cout << test->sheet[m][n] << "\t";
		}
		cout<<endl;
	}
	
	cout<<endl<<endl;
	//test copy constructer
	cout<< "Test copy constructor\ntwoDVec copy(test)"<<endl;
	storage::twoDVec copy(*test);

	cout << "Test accesor"<<endl;

	for(int n = 0; n < 5; n++)
	{
		for(int m = 0; m < 5; m++)
		{
			cout << copy.sheet[m][n] << "\t";
		}
		cout<<endl;
	}
	return EXIT_SUCCESS;
}

