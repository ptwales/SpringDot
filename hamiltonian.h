#ifndef HAMILTONIAN_H
#define HAMILTONIAN_H

#include "diffEq.h"

namespace problem
{
class hamiltonian	:public diffEq
	{
	public:
		static const unsigned int derivePower = 2;

		virtual user_prec netEngery( y_vec& y ) {};

		virtual user_prec netAngMom( y_vec& y ) {};
		
		virtual user_prec netLinMom( y_vec& y ) {};
	};
}

#endif // HAMILTONIAN_H
