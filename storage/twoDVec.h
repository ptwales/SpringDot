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
#ifndef TWODVEC_H
#define TWODVEC_H

#include "../precision.h"

namespace storage
{
    typedef std::vector<y_vec> sheet_t;

    class twoDVec
    {
        public:

            twoDVec ( size_t length=1, size_t height=1, user_prec init_fill=filler)
            {
                sheet.resize( length, y_vec( height, init_fill) );
                vecSize = length;
                subVecSize = height;
            }

            twoDVec ( size_t length, y_vec init_vec )
            { 
                sheet.resize( length, init_vec ); 
                vecSize = length;
                subVecSize = init_vec.size();
            }

            twoDVec ( const twoDVec& original )
            { 
                sheet = original.sheet;
                vecSize = sheet.size();
                subVecSize = sheet[0].size();
            }

            virtual y_vec operator [] ( size_t n ) const
            { return sheet[n]; }

            const user_prec get ( size_t subvec, size_t subVecEl ) const
            { return sheet[subVec][subVecEl]; }

            const user_prec& at ( size_t subvec, size_t subVecEl ) const
            { return &(sheet[subVec][subVecEl]); }

            const size_t size() const { return vecSize; }
            const size_t subSize() const { return subVecSize; }

        protected:
            sheet_t sheet;
            size_t vecSize, subVecSize;
    };
}

#endif //TWODVEC_H
