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
#ifndef DIFFEQ_H
#define DIFFEQ_H

#include <vector>
#include "../storage/sheetInterfaces.hpp"

namespace problem
{
    typedef void (dFunc_t) ( const storage::y_vec&, storage::y_vec&, const storage::user_prec& );	

    class diffEq
    {
        public:
            diffEq(size_t _varCount, size_t _diffPow) 
                : varCount(_varCount), diffPow(_diffPow) {
            }

            virtual void derivative ( const storage::y_vec&, storage::y_vec&, const storage::user_prec& ) =0;

            const size_t varCount;
            const size_t diffPow;

    };
    typedef void (diffEq::*dFunc_p) ( const storage::y_vec&, storage::y_vec&, const storage::user_prec& );	
}
#endif // DIFFEQ_H
