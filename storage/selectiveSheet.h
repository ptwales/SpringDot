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
 * SELECTIVE SHEET 
 !
 !	This abstrac class needs to be split into `packable' and `selective'
 !  twoDVec will inherit packable
 ! 	sheetYsub will inherit selective
 !
 * Introduces:
 * 	std::vector<bool> orders
 *
 * and pure virtuals:
 * 	void pack ( y_vec )
 * 	void reset ( )
 * 	void reOrder ( boolVec_t, user_prec reInit=filler )
 * 	void packCount ( ) 
 * 	
 * Derived sheets are meant to be intialized as empty twoDVec with preAllocated space
 * std::vector<bool> orders; will deterimine the dimensions of the vector depending on the subclass and it must be the same size as the y_vec used
 *
 * Only TRUE elements of orders will be stored and have space allocated for it.
 * So if, 
 * 	orders = < 1, 0, 0, 1, 1>
 * then the sheet will be either (3 x length) or (length x 3) depending on the subclass.
 *
 * pack(y_vec)
 * Assuming same orders as above then y_vec[0], y_vec[3], y_vec[4] are stored.  How it is stored is determined by subclass. pack(y_vec) assigns the next value
 *
 * reset()
 * 	Does not unallocate space or clear elements
 * 	Only
 * 
 */

#ifndef SELECTIVESHEET_H
#define SELECTIVESHEET_H

#include "twoDVec.h"

namespace storage
{
    typedef std::vector<bool> boolVec_t;

    class selectiveSheet	:public twoDVec
    {
        public:
            selectiveSheet ( size_t _vecSize
                    , size_t _subVecSize
                    , boolVec_t _orders
                    , user_prec init_fill=filler )
                : twoDVec ( _vecSize
                        , _subVecSize
                        , init_fill )
        {
            orders = _orders;
        }
            virtual void pack ( y_vec ) = 0;
            virtual void reset ( ) = 0;
            virtual void reOrder ( boolVec_t, user_prec reInit=filler ) = 0;
            virtual size_t packLimit ( ) = 0;

        protected:
            boolVec_t orders;
    };
}
#endif // SELECTIVESHEET_H
