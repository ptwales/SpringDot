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
 *
 * sheetYSub:
 * sub vectors are y(t)
 * So if vector y is <a,b,c,d> then shetByTime is:
 * < <a(2), b(2), c(2), d(2)>, <a(2), b(2), c(2), d(2)>, ... >
 *
 * sheet_t::iterator last;
 * In constructor last will point to the first subvector of the sheet
 */

#ifndef SHEETYSUB_H
#define SHEETYSUB_H

namespace storage 
{
	class sheetYSub	:public abstractSheet 
	{
	public:
		sheetYSub ( unsigned int length, boolVec_t _orders, user_prec init_fill=filler) : twoDVec ( length, _orders.size(), filler )
		{
			orders = _orders;
			last = sheet.begin();
		}

		//Default Copy should be good enough


		void pack ( y_vec )
		{
			
		}

		void clear ( )
		{

		}
	protected:
		sheet_t::iterator last;

	};

}

#endif // SHEETY_SUB
