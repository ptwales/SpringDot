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
 * DiffEq Method:
 * 	Parent class for Methods of solving differential equations.
 * 	This class is subject to modification if/when any heirarchies develope
 * 	below this class.  As for now all differential equation method descend
 * 	directly from this class.
 */
#ifndef DIFFEQMETH_H
#define DIFFEQMETH_H

//#include <algorithm>
#include "../problem/diffEq.hpp"

using namespace storage;

namespace solutions
{
    /*
     * All diffEqSystems must have a differential equation function (dFunc_t)
     * A dFunc_t calculates y'(t) = f( y(t), t )
     * arguments are ( y(t), y'(t), t )
     */
//    typedef problem::dFunc_t* dFunc_p;

    class diffEqMeth
    {
        public:

            /* 
             * Any method needs to know what the dFunc_t is and where to
             * write the solution to. Solutions are written directly to 
             * the container instead of returned to the system to write to 
             * the container.
             *
             ! packable arg is temporary and will be replaced
             ! with some `packable' interface.
             */
            diffEqMeth ( problem::diffEq& _system, problem::dFunc_p _deriveFuncP, packable& _writeTo )
                : system(&_system), deriveFuncP(_deriveFuncP), writeTo(&_writeTo) {}

            /*
             * solve y(t) from t0 to tF with a step of tStep where y(t0) = yInit
             */
            virtual void solve ( y_vec& yInit, user_prec tF
                    ,user_prec tStep , user_prec tInit=0) = 0;

        protected:
            //Don't know if this is the right way to do it.
            class wrongWay_e :public std::exception {
                const char* what() const throw() {
                    return "(tF - t0)/dt < 0 \n Check signs";
                }
            } wrongWay;

            class noSteps_e :public std::exception {
                const char* what() const throw() {
                    return "(tF - t0)/dt < 1 \n Step size too large for range";
                }
            } noSteps;

            size_t calcLeap ( user_prec start, user_prec stop, user_prec step)
            {
                size_t limit = writeTo->packLimit();
                int stepCount = (stop - start)/step;

                if ( stepCount < 0 ) { 
                    throw wrongWay;
                    exit(EXIT_FAILURE); 
                }
                if ( stepCount == 0 ) { 
                    throw noSteps;
                    exit(EXIT_FAILURE);
                }

                return (size_t) (stepCount/limit);
            }

            packable* writeTo;
            problem::diffEq* system;
            problem::dFunc_p deriveFuncP;
    };
}

#endif // DIFFEQMETH_H
