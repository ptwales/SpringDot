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

#include <../problem/diffEq.h>
#include <../problem/hamiltonian.h>

namespace problem
{
    class springTest_system	:public diffEq, hamiltonian
    {
        public:
            void derivative( y_vec& y const, y_vec& y_dot );

            const size_t varCount = 1;

        private:
            double k = 0.1;
            double m = 1;
    };
}

#endif // SPRINGTEST_SYSTEM_H
