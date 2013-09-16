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

#include <sheetYsub.h>

using namespace storage

void sheetYSub::pack ( y_vec yIn )
{
	boolVec_t::iterator orderIt = orders.begin();
	y_vec::iterator yInIt = yIn.begin();
	y_vec::iterator yOutIt = last->begin();

	if ( last == sheet.end() ) {
		//Throw error
		return;
	}

	while ( orderIt != orders.end() && yInIt != yIn.end() && yOutIt != last->end() ) 
	{
		if ( *orderIt ) {
			*yOutIt = *yInIt;
			yOutIt++;
		}
		yInIt++;
		orderIt++;
	}

	if ( orderIt != orders.end() ) {
		//Throw Error
	}
	if ( yInIt != yIn.end() ) {
		//Throw Error
	}
	if ( yOutIt != last->end() ) {
		//Throw Error
	}

	last++;
}
