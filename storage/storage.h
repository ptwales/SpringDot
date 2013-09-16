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

	/*
	 * Introduces pack(y_vec), clear (), orders and last
	 * Derived sheets are meant to be intialized as empty twoDVec with preAllocated space
	 * std::vector<bool> orders; will deterimine the dimensions of the vector depending on the subclass and it must be the same size as the y_vec used
	 *
	 * Only TRUE elements of orders will be stored and have space allocated to it.
	 * So if, 
	 * 	orders = < 1, 0, 0, 1, 1>
	 * then the sheet will be either (3 x length) or (length x 3) depending on the subclass.
	 *
	 * pack(y_vec)
	 * Assuming same orders as above then y_vec[0], y_vec[3], y_vec[4] are stored.  How it is stored is determined by subclass. pack(y_vec) assigns the next value
	 *
	 * clear()
	 * 
	 */
	class abstractSheet	:public twoDVec
	{
	public:
		typedef std::vector<bool> boolVec_t;
		virtual void pack ( y_vec ) = 0;
		void clear ( ) = 0;
	protected:
		boolVec_t orders;
	};


	/*
	 * sheetByTime:
	 * sub vectors are y(t)
	 * So if vector y is <a,b,c,d> then shetByTime is:
	 * < <a(2), b(2), c(2), d(2)>, <a(2), b(2), c(2), d(2)>, ... >
	 *
	 * sheet_t::iterator last;
	 * In constructor last will point to the first subvector of the sheet
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
	protected:
		sheet_t::iterator last;
	};
	/*
	 * sheetByEl:
	 * sub vectors are  y_n(t)
	 * Each sub vector is an element of vector y as a function of time
	 * so if y is <a,b,c,d>
	 * sheetByEl could be 
	 * < <a(1),a(2),a(3),...> , <b(1),b(2),b(3),...>, ... >
	 * Some elements can be ignored according to the boolVec passed to it
	 */
/*
	class sheetByEl		:public twoDVec
	{
	};
*/

}
#endif // STORAGE_H
