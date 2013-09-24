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
 * hamiltonian interface:
 * 	If a system implements this interface then it is a closed system
 * 	with constant total Energy, and Momentum which can be used for
 *	error analysis
 */
#ifndef HAMILTONIAN_H
#define HAMILTONIAN_H

namespace problem
{
    class hamiltonian
    {
        public:
            static const unsigned int derivePower = 2;

            virtual user_prec netEngery( y_vec& y ) =0;

            virtual user_prec netAngMom( y_vec& y ) =0;

            virtual user_prec netLinMom( y_vec& y ) =0;
    };
}

#endif // HAMILTONIAN_H
