#include <iostream>
#include "sheetYsub.h"


using namespace std;
int main ()
{
	//test default constructor
	cout << "Test Default Constructor . . . ";
	storage::sheetYSub *test = new storage::sheetYSub;
	cout << ( ( test->sheet[0][0] == storage::filler 
				&& test->sheet.size() == 1 
				&& test->sheet[0].size() == 1 )? 
			"pass \n" : "fail \n" );

	cout << "Test Destructor . . . ";
	delete test;
	cout << "pass \n";

	size_t length = 10;
	size_t width = 6;
	storage::user_prec phil = 12.34;
	storage::abstractSheet::boolVec_t myBoolVec(width, true);

	//test filler constructor
	cout << "Test filler constructor . . . ";
	test = new storage::sheetYSub(length, myBoolVec );
	cout << ( (	test->sheet.size() == length
				&& test->sheet[length-1].size() == width
				&& test->sheet[length-1][width-1] == storage::filler)? 
			"pass \n" : "fail \n" );
	delete test;

	//test element constructor
	cout << "Test element constructor . . . ";
	test = new storage::sheetYSub(length
			, vector<bool>( true,width )
			, phil );
	cout << ( ( test->sheet[0][0] == phil )?
			"pass \n" : "fail \n" );
	delete test;

	//test vector constructor

	cout << "Test boolean constructor . . . ";
	for ( booVec_T 
	test = new storage::sheetYSub( length, myBoolVec, phil );
	
	/*
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
	*/
	return EXIT_SUCCESS;
}

