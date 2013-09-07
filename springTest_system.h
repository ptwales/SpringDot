/*
 * This file is to be edited at need of the user
 */
#ifndef SPRINGTEST_SYSTEM_H
#define SPRINGTESt_SYSTEM_H

// Feel free to uncomment all but the used parent class

#include <ode.h>
#include <hamiltonian.h>

namespace problem
{
	class springTest_system	:public ode, hamiltonian
	{
		public:
			void derivative( y_vec& y, y_vec& y_dot );

			const unsigned int varCount = 1;
			
		private:
			double k = 0.1;
			double m = 1;
	};
}

#endif // SPRINGTEST_SYSTEM_H
