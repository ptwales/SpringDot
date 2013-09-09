#ifndef STORAGE_H
#define STORAGE_H
#include <vector>
#include <precision.h>
//#include "fUNroll.h"

namespace answer
{
	using namespace std;
	typedef vector<bool> orderVec;
	/*
	 * Each subvector is y at time t
	 * y(t)
	 * <yVec, yVec, yVec, ... >
	 * 		y is the subvector
	 */
	typedef vector<problem::yVec> ySequence;
	/*
	 * Each subvector is the series of values of an element
	 * <y_1(t), y_2(t), ... >
	 * 		y goes across subvectors
	 */
	typedef vector<vector<problem::user_prec> valSequence;

	class dataArray
	{
	public:
		dataArray( long unsigned int _limit, orderVec _orders )
		{
			limit = _limit;
			iterator = 0;
			orders = _orders;
			rememberCount = 0;

			for ( orderVec::iterator it = orders.begin(); it != orders.end(); ++it )
			{
				rememberCount += (*it)? 1 : 0;
			}

			2DVec = new ySequence(
		}
		~dataArray()
		{
			delete orders;
			delete storage;
		}
		
		void clear() { iterator = 0; }

		virtual void pack( problem::yVec y )
		{
			unsigned int 
		}

	private:
		orderVec orders;
		unsigned int varCount;
		unsigned int rememberCount;

		long unsigned int limit;
		long unsigned int iterator;
	};
}
#endif // STORAGE_H
