#include <iostream>
#include "springTest_system.h"


int main()
{
    using namespace problem;

    springTest_system derp;

    const unsigned int vecSize = springTest_system::varCount*springTest_system::derivePower;

    y_vec y(2);
    y[0]=0;
    y[1]=1;

    y_vec y_dot(2);
    y_dot[0] = 0;
    y_dot[1] = 0;

    using namespace std;

    cout << y[0] << "\t" << y[1] << endl;
    cout << y_dot[0] << "\t" << y_dot[1] << endl;

    derp.derivative(y, y_dot);

    cout << y[0] << "\t" << y[1] << endl;
    cout << y_dot[0] << "\t" << y_dot[1] << endl;


    return 0;
}

