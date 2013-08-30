#include <iostream>
#include "user_system.h"

using namespace problem;

int main()
{
//	user_system derp;


	const unsigned int vecSize = user_system::varCount*user_system::derivePower;

	std::cout << vecSize << std::endl;

	y_vec y(vecSize);
	y[0]=0;
	y[1]=1;

	std::cout << y[0] << std::endl;

	y_vec y_dot(vecSize);
	y_dot[0] = y[1];
	y_dot[1] = 0;

	std::cout << y_dot[0] << std::endl;

    return 0;
}

