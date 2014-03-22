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
 * SHEETINTERFACES
 *
 * packable
 * ======== 
 * interfaces:
 * 	void pack ( y_vec )
 * 	void reset ( )
 * 	void packCount ( ) 
 *
 * 	Many methods will store vectors as they work their way through. The packable interface allows them to simply pass a vector to the `packable` with the `pack()` method and let the `packable` deal with how to store it.
 *
 * selective
 * =========
 * protected field:
 * 	std::vector<bool> orders
 * interface:
 * 	void reOrder ( boolVec_t, user_prec reInit=filler )
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

#ifndef SHEETINTERFACES_H
#define SHEETINTERFACES_H

#include "twoDVec.hpp"
#include <stdio.h>

namespace storage
{

    // packable interface
    template<class T>
    class packable
    {
        public:
            virtual void pack(std::vector<T>) =0;
            virtual void reset() =0;
            virtual size_t packLimit() =0;
            virtual bool isFull() =0;
    };

    // selective interface
    typedef std::vector<bool> boolVec_t;

    template<class T>
    class selective :public twoDVec<T>
    {
        public:
            selective(size_t Size, size_t subSize, 
                      boolVec_t Orders, T init_fill=0)
                : twoDVec<T>(Size, subSize, init_fill)
            {orders = Orders;}

            virtual void reOrder(boolVec_t newOrders, T reInit=filler) =0;
           
        protected:
            boolVec_t orders;
    };

    class printable
    {
        public:
            virtual void printTo(FILE* dest=stdout,
                                 char format='g',
                                 char elDelim='\t',
                                 char vecDelim='\n') =0;
    };
}
#endif // SHEETINTERFACES_H
