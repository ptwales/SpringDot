#include <iostream>
#include "user_system.h"

using namespace problem;

int main()
{
	user_system derp;

	const unsigned int vecSize = user_system::varCount*user_system::derivePower;

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

