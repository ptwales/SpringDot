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
 * TODO:
 *  Use templates and not global precision
 *  In short, nullify this file!
 */

#ifndef PRECISION_H
#define	PRECISION_H

#include <vector>
#include <stdlib.h>

namespace storage
{

    /*
     * SpringDot uses global precision
     */
//    typedef double user_prec;

    /*
     * whatever you do to this, it needs to be of type user_prec and have XX::iterator
     */
    
    //typedef std::vector<user_prec> y_vec;

    /* 
     * filler is the default initializer for all containers
     * if for some reason this shouldn't be 0, leave it alone.
     * If you are doing something weird with user_prec, then you might need to use it
     * but then you might break other things so IDK. 
     */
    //const static user_prec filler = 0;		
}

#endif //PRECISION_H
