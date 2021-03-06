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
 * sheetYSub:
 * sub vectors are y(t)
 * So if vector y is <a,b,c,d> then shetByTime is:
 * < <a(1), b(1), c(1), d(1)>
 * , <a(2), b(2), c(2), d(2)>
 * , <a(3), b(3), c(3), d(3)>
 * , ... >
 *
 * sheet_t::iterator last;
 * In constructor last will point to the first subvector of the sheet
 *
 * sheetYSub can be packed vecSize times
 * 
 */

#ifndef SHEETYSUB_H
#define SHEETYSUB_H

#include "sheetInterfaces.hpp"
#include <algorithm>

namespace storage 
{
    template<class T>
    class sheetYSub	:public selective<T>, public printable, public packable<T>
    {
        public:
            sheetYSub(size_t length = 1,
                      boolVec_t Orders = boolVec_t(1, true),
                      T init_fill=0)
                : selective<T>(length,
                               std::count(Orders.begin(), Orders.end(), true),
                               Orders, init_fill)
            {last = sheet.begin();}

            //Default Copy should be good enough

            /*  PACKABLE INTERFACE */
            //Throws errors
            void pack(y_vec);
            void reset()          {last = sheet.begin();}
            size_t packLimit()    {return vecSize;}
            bool isFull()         {return (last == sheet.end());}

            /* selective interface */
            void reOrder(boolVec_t newOrders, T reInit=0);

            /* printable interface */ 
            void printTo(FILE* dest=stdout, char format='g', char elDelim='\t'
                    , char vecDelim='\n');

        protected:
            sheet_t::iterator last;

    };
}

#endif // SHEETY_SUB
