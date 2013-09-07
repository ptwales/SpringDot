#include "springTest_system.h"

namespace problem
{
	void springTest_system::derivative ( y_vec& y, y_vec& y_dot )
	{
		y_dot[0] = y[1];
		y_dot[1] = (k*y[0])/m;
	}
}
