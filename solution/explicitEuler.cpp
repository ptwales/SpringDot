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
#include "explicitEuler.hpp"

using namespace storage;

namespace solutions
{
    void explicitEuler::solve ( y_vec& y, user_prec tFin, user_prec tStep, user_prec t )
    {
        size_t leap = calcLeap ( t, tFin, tStep );

        //Assert If t < tFin then tStep > 0
        // or if t > tFin then tStep < 0

        size_t vecSize = y.size();

        y_vec y_d ( vecSize, filler );

        y_vec::iterator y_it;
        y_vec::iterator yd_it;

        size_t n;
        do {
            writeTo->pack(y);
            // Sacrifice some run time for memory management
            for ( n = 0; n < leap; n++)
            {
                (system->*deriveFuncP) ( y, y_d, t );
#ifndef BOOST_FOREACH
                for ( y_it = y.begin(), yd_it = y_d.begin();
                        y_it < y.end(),	    yd_it < y_d.end();
                        y_it++,             yd_it++ )
                    (*y_it) += (*yd_it) * tStep;
#else
                //BOOST FOREACH with zip_iterator
#endif
                t += tStep;
            }
        } while ( t <= tFin );
    }
}
