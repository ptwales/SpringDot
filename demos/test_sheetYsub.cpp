#include <iostream>
#include "../storage/sheetYsub.hpp"

void printTest( bool condition ) {
    std::cout << ( condition ? "pass" : "fail" ) << std::endl;
}

int main ()
{
    //test default constructor
    std::cout << "Test Default Constructor . . . ";
    storage::sheetYSub *test = new storage::sheetYSub;
    printTest( (*test)[0][0] == storage::filler 
                && test->vecSize == 1 
                && test->subVecSize == 1 );

    std::cout << "Test Destructor . . . ";
    delete test;
    std::cout << "pass \n";

    size_t length = 10;
    size_t width = 6;
    storage::user_prec phil = 12.34;
    storage::boolVec_t myBoolVec(width, true);

    //test filler constructor
    std::cout << "Test filler constructor . . . ";
    test = new storage::sheetYSub(length, myBoolVec );
    printTest( test->vecSize == length
               && (*test)[length-1].size() == width
               && (*test)[length-1][width-1] == storage::filler);
    delete test;

    //test element constructor
    std::cout << "Test element constructor . . . ";
    test = new storage::sheetYSub(length
            , vector<bool>( true,width )
            , phil );
    printTest( (*test)[0][0] == phil );
    delete test;

    //test vector constructor
    std::cout << "Test boolean constructor . . . ";
    for ( size_t s = 0; s < width/2; s++) 
        myBoolVec[s] = false;

    test = new storage::sheetYSub( length, myBoolVec, phil );
    printTest( test->subVecSize == width - width/2 );

    //test packing
    std::cout << "Test packing . . . ";
    storage::y_vec myVec;
    for ( int n = 1; n <= width; n++ ) 
        myVec.push_back(n);

    test->pack(myVec);

    cout << endl;

    test->printTo();

    delete test;

    return EXIT_SUCCESS;
}

