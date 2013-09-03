/*
 * This file is to be edited at need of the user
 */
#ifndef USER_SYSTEM_H
#define USER_SYSTEM_H

// Feel free to uncomment all but the used parent class

//#include "diffEq.h"
#include "hamiltonian.h"

namespace problem
{
	class user_system	:public hamiltonian
	{
		public:
			void derivative( y_vec& y, y_vec& y_dot );

			static const unsigned int varCount = 1;
//			static const unsigned int derivePower;
			
		private:
			static double k = 0.1;
			static double m = 1;
	};
}

#endif // USER_SYSTEM_H
