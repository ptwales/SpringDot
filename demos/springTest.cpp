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

#include <iostream>

#include "springTest_system.hpp"
#include "../solution/explicitEuler.hpp"
#include "../storage/sheetYsub.hpp"


int main()
{

    problem::springTest_system mySystem(100,0.5);

    const size_t vecSize = mySystem.diffPow * mySystem.varCount;

    storage::y_vec y(vecSize);
    y[0]=1;
    y[1]=0;

    storage::boolVec_t orders( vecSize, true );
    
    storage::sheetYSub mySheet( 100, orders );

    solutions::explicitEuler myLittleEuler( mySystem, &problem::diffEq::derivative, mySheet );

    storage::user_prec t0, tFin, tStep;
    t0 = 0;
    tFin = 1;
    tStep = 0.005;

    myLittleEuler.solve(y, tFin, tStep, t0);

    if( mySheet.isFull() ) {
        mySheet.printTo();
    } else {
        std::cout << "Sheet is not full" << std::endl;
    }
    
    return 0;
}

