#include <iostream>
#include "sheetYsub.h"


using namespace std;
int main ()
{
	//test default constructor
	cout << "Test Default Constructor . . . ";
	storage::sheetYSub *test = new storage::sheetYSub;
	cout << ( ( (*test)[0][0] == storage::filler 
				&& test->size() == 1 
				&& test->subSize() == 1 )? 
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
	cout << ( (	test->size() == length
				&& (*test)[length-1].size() == width
				&& (*test)[length-1][width-1] == storage::filler)? 
			"pass \n" : "fail \n" );
	delete test;

	//test element constructor
	cout << "Test element constructor . . . ";
	test = new storage::sheetYSub(length
			, vector<bool>( true,width )
			, phil );
	cout << ( ( (*test)[0][0] == phil )?
			"pass \n" : "fail \n" );
	delete test;

	//test vector constructor

	cout << "Test boolean constructor . . . ";
	for ( size_t s = 0; s < width/2; s++) 
		myBoolVec[s] = false;

	test = new storage::sheetYSub( length, myBoolVec, phil );
	cout << ( ( test->subSize() == width - width/2 )?
			"pass \n" : "fail \n" );

	//test packing
	cout << "Test packing . . . ";
	storage::y_vec myVec;
	for ( int n = 1; n <= width; n++ ) 
		myVec.push_back(n);

	test->pack(myVec);

	cout << endl;
	for ( size_t y = 0; y < test->subSize(); y++ )
	{
		for ( size_t x = 0; x < length; x++ )
		{
			cout << (*test)[x][y] << "\t";
		}
		cout << endl;
	}

	delete test;


	return EXIT_SUCCESS;
}

