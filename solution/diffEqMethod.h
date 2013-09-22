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
#ifndef DIFFEQMETH_H
#define DIFFEQMETH_H

#include <sheetYsub.h>

using namespace storage;

namespace solutions
{
	typedef void (dFunc_t) ( const y_vec&, y_vec&, const user_prec& );	//y, ydot, t

	class diffEqMeth
	{
	public:

		diffEqMeth ( dFunc_t& _deriveFunc, selectiveSheet& _writeTo
				, const size_t _varCount, const size_t _diffPow ) 
			: varCount(_varCount) , diffPow(_diffPow)	// because const
		{
			deriveFunc = _deriveFunc;
			writeTo = _writeTo;
		};

		virtual void solve ( y_vec yInit, const user_prec tFin
				, user_prec tStep , user_prec t=0) = 0;

	protected:
		selectiveSheet* writeTo;
		dFunc_t* deriveFunc;
		const size_t varCount, diffPow;
	};
}

#endif // DIFFEQMETH_H
