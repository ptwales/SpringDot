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
#ifndef DIFFEQMETHOD_H
#define DIFFEQMETHOD_H

#include <sheetYsub.h>

namespace solutions
{

	typedef void (dFunc_t) ( const y_vec&, y_vec& );

	class diffEqMeth
	{
	public:

		diffEqMeth ( dFunc_t& _deriveFunc, storage::selectiveSheet& _writeTo ) {
			deriveFunc = _deriveFunc;
			writeTo = _writeTo;
		};

		~diffEqMeth() {};

		virtual void solve ( user_prec _dt ) = 0;

	protected:
		storage::selectiveSheet &writeTo;
		dFunc_t& deriveFunc;
	};
}

#endif // DIFFEQMETHOD_H
