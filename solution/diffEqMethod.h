#ifndef DIFFEQMETHOD_H
#define DIFFEQMETHOD_H

#include <storage.h>

namespace solutions
{
	class diffEqMeth
	{
	public:

		diffEqMeth() {};
		~diffEqMeth() {};

		answer::dataArray* storage; // Change to type of parcel
		anwser::orderVec orders;

	protected:

		void checkStorage ( ) {
			if( typeid( storage ) !=  answer::dataArray* ) {
				throw typeid ( storage );
			}
		}

	};
}

#endif // DIFFEQMETHOD_H
