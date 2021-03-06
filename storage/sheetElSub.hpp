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
 * sheetElsub:
 * sub vectors are  y_n(t)
 * Each sub vector is an element of vector y as a function of time
 * so if y is <a,b,c,d>
 * sheetElsub could be 
 * 
 * < <a(1),a(2),a(3),...> 
 * , <b(1),b(2),b(3),...>
 * , <c(1),c(2),c(3),...>
 * , <d(1),d(2),d(3),...> >
 *
 * Some elements can be ignored according to the boolVec passed to it
 *
 * if orders is <0,1,1,0>
 * then the sheetElsub
 */

#ifndef SHEETELSUB_H
#define SHEETELSUB_H

namespace storage
{
    class sheetElSub	:public twoDVec
    {

    };
}
#endif // SHEETELSUB_H

