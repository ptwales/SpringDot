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

#ifndef SPRINGTEST_SYSTEM_H
#define SPRINGTESt_SYSTEM_H

// Feel free to uncomment all but the used parent class

#include "../problem/diffEq.hpp"

namespace problem
{
    class springTest_system	:public diffEq
    {
        public:
            springTest_system ( storage::user_prec _k, storage::user_prec _m )
                : diffEq (1,2) {
                    k = _k;
                    m = _m;
                }
            ~springTest_system() {}

            void derivative ( const storage::y_vec&, storage::y_vec&, const storage::user_prec& );


        private:
            double k;
            double m;
    };
}

#endif // SPRINGTEST_SYSTEM_H
