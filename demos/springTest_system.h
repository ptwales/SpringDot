/*
 * This file is to be edited at need of the user
 */
#ifndef SPRINGTEST_SYSTEM_H
#define SPRINGTESt_SYSTEM_H

// Feel free to uncomment all but the used parent class

#include <../problem/diffEq.h>
#include <../problem/hamiltonian.h>

namespace problem
{
	class springTest_system	:public diffEq, hamiltonian
	{
		public:
			void derivative( y_vec& y const, y_vec& y_dot );

			const size_t varCount = 1;
			
		private:
			double k = 0.1;
			double m = 1;
	};
}

#endif // SPRINGTEST_SYSTEM_H
