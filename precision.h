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

#ifndef PRECISION_H
#define	PRECISION_H

#include <vector>

namespace storage
{
	typedef double user_prec;
	typedef std::vector<user_prec> y_vec;	//If vectors don't apply this should somehow change to not a vector
	const static user_prec filler = 0;  // value used to initialize vectors and sheets
}

#endif //PRECISION_H
