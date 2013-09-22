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
#ifndef EULER_H
#define EULER_H

//will need to rename this.

using namespace storage;

namespace solution
{
	class euler :public diffEqMeth
	{
	public:
		void solve ( y_vec y, const user_prec tFin
				, user_prec tStep, user_prec t=0)
		{
			//Assert If t < tFin then tStep > 0
			// or if t > tFin then tStep < 0
			size_t vecSize = y.size();
			//assert vecSize = varCount * vecSize
			y_vec y_d ( vecSize, filler );
			/*
			 * y_vec::iterator y_it;
			 * y_vec::iterator yd_it;
			 */

			while ( tInit != tStep )
			{
				(*deriveFunc) ( y, y_d, t );
				//I DONT LIKE THIS FOR LOOP
				//I DONT LIKE IT AT ALL
				//use for each derp...
				for ( size_t n = 0; n < vecSize; n++ ) 
					y[n] += y_d[n] * tStep;
					//(*y_it) += (*y_dot) * tStep;
				t += tStep;
			}
		}
	}
}

#endif //EULER_H
