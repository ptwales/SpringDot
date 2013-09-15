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
#ifndef TWODVEC_H
#define TWODVEC_H

#include <precision.h>

namespace storage
{
	class twoDVec
	{
	public:
		typedef std::vector<y_vec> sheet_t;

		twoDVec ( unsigned int length=1, unsigned int height=1, user_prec init_fill=filler) 
		{
			sheet.resize( length, y_vec( length, init_fill) );
		}

		twoDVec ( unsigned int length, y_vec init_vec ) 
		{
			sheet.resize( length, init_vec );
		}

		twoDVec ( const twoDVec& original )
		{
			sheet = original.sheet;
		}

		sheet_t sheet;
	};
}

#endif //TWODVEC_H
