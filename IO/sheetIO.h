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
 !
 !  All of this will NOT WORK WITH GMP
 !
 * SHEET IO:
 *  classes defined:
 *    - sheetCIO 
 *    - - template < cout, cerr, clog >
 *    - sheetDBIO
 *    - - to SQL DB
 *    - 
 */

#ifndef SHEETIO_H
#define SHEETIO_H 

#include <iostream>
#include <fstream>
#include "../storage/twoDVec.h"

namespace IO
{
    // output to console
    // maybe file aswell
    class oSheet
    {
    public:
        oSheet ( std::ostream _outStream=cout ) {
            outStream = _outStream;
        }

        printSheet ( const storage::twoDVec& Sheet ) const
        {
           size_t vecSize = Sheet.vecSize();
           size_t subVecSize = Sheet.subVecSize();
           for ( size_t y = 0; y < vecSize; y++ ) {
               for ( size_t x = 0; x < subVecSize; x++ ) {
                   outStream << Sheet.at( y, x ) <<" ";
               }
               outStream << endl;
           }
        }
        
        void operator << ( const storage::twoDVec& Sheet ) const
        { printSheet ( Sheet ); }

    protected:
        std::ostream outStream;
    };

}
#endif // SHEETIO_H
