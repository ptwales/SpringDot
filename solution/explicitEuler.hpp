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
 *
 ! Use zip iterator
 ! http://www.boost.org/doc/libs/1_46_0/libs/iterator/doc/zip_iterator.html
 *
 * Euler's Method:
 *
 * 	
 */
#ifndef EXPLICITEULER_H
#define EXPLICITEULER_H

//will need to rename this.
#include "diffEqMeth.hpp"
#include <iostream>

using namespace storage;

namespace solutions
{
    class explicitEuler :public diffEqMeth
    {
    public:
        explicitEuler ( problem::diffEq& _system, problem::dFunc_p _deriveFuncP, packable& _writeTo )
            : diffEqMeth(_system, _deriveFuncP, _writeTo ) {}



        void solve ( y_vec& y, user_prec tFin, user_prec tStep, user_prec t=0 );
    };
}

#endif //EXPLICITEULER_H
