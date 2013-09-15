/*
 * Copyright 2013 Philip Taber Wales
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *	
 *   http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
