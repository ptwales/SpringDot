#ifndef STORAGE_H
#define STORAGE_H

#include "twoDVec.h"

namespace storage
{

	class abstractSheet	:public twDVec
	{
	public:
		typedef std::vector<bool> boolVec_t;
		virtual void pack ( y_vec ) = 0;
		void clear ( ) { last = sheet.begin(); }

	protected:
		boolVec_t orders;
		sheet_t::iterator last;
	};

	/*
	 * sheetByTime:
	 * sub vectors are y(t)
	 */
	class sheetByTime	:public abstractSheet 
	{
	public:
		sheetByTime ( unsigned int length, boolVec_t _orders, user_prec init_fill=filler) : twoDVec ( length, _orders.size(), filler )
		{
			orders = _orders;
			last = sheet.begin();
		}

		sheetByTime ( const sheetByTime& original, boolVec _orders ) : twoDVec ( original )
		{
			// twoDVec copy constructer has copied the sheet
			// now remove undesired elements
			// This can be a pain with this method
		}

		void pack ( y_vec )
		{
			return;
		}

	};
	/*
	 * sheetByEl:
	 * sub vectors are  
	 */
/*
	class sheetByEl		:public twoDVec
	{
	};
*/

}
#endif // STORAGE_H
