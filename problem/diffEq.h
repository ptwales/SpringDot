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
#include "precision.h"

namespace problem
{

class diffEq
{
public:

    virtual void derivative( y_vec& y, y_vec& y_dot ) { };

    const unsigned int varCount;
    const unsigned int derivePower;

protected:
	
};
}
#endif // DIFFEQ_H
