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

#include <iostream>     //cout
#include <unistd.h>     //getopt()
#include <stdexcept>
#include <string>

#include "springTest_system.hpp"
#include "../solution/explicitEuler.hpp"
#include "../storage/sheetYsub.hpp"


using namespace storage;

struct Controls_s 
{
    user_prec k, m, x, v;           //-k, -m, -x, -v
    user_prec t0, tFin, tStep;      //-t, -T, -h
    size_t outCount;                //-c
    FILE *outFile;                  //-f
} controls;

static const char *optString = "k:m:x:v:t:T:d:c:f:h?";

void display_usage(void)
{
    std::cout << "Hooke's law spring demo for springDot \n\
        \n USAGE:\
        \t -k: double: Spring stiffness. Default 5\
        \t -m: double: Mass. Default 0.5\
        \t -x: double: Initial distance from Equilibrium. Default 1\
        \t -v: double: Initial velocity. Default 0\
        \t -t: double: Initial time. Default 0\
        \t -T: double: Final time. Default 1\
        \t -d: double: time step. Default 0.005\
        \t -f: double: Output destination File. Default stdout\
        \n";
    exit( EXIT_FAILURE );
}


int main( int argc, char* argv[])
{
    /* defaults */
    controls.k = 5;
    controls.m = 0.5;
    controls.x = 1;
    controls.v = 0;
    controls.outCount = 100;
    controls.t0 = 0;
    controls.tFin = 1;
    controls.tStep = 0.005;
    controls.outFile = stdout;
    int opt = 0;
    opt = getopt(argc, argv, optString);
    while ( opt != -1 )
    {
        switch ( opt )
        {
            case 'k':
                controls.k = atof(optarg);
                break;
            case 'm':
                controls.m = atof(optarg);
                break;
            case 'x':
                controls.x = atof(optarg);
                break;
            case 'v':
                controls.v = atof(optarg);
                break;
            case 't':
                controls.t0 = atof(optarg);
                break;
            case 'T':
                controls.tFin = atof(optarg);
                break;
            case 'd':
                controls.tStep = atof(optarg);
                break;
            case 'f':
                controls.outFile = fopen(optarg, "w");
            case 'c':
                controls.outCount = atof(optarg);
                break;
            case 'h':
            case '?':
                display_usage();
                break;
            default:
                std::string unknownArgMsg("Default Case reached when reading Options \n");
                std::string unknownArgMsg("This might help: opt = ");
                unknownArgMsg.push_back(opt);
                unknownArgMsg.push_back(", optarg = " );
                unknownArgMsg.push_back(optarg);
                throw std::invalid_argument(unknownArgMsg);
                return EXIT_FAILURE;
                break;
        }
        opt = getopt( argc, argv, optString );
    }
    problem::springTest_system mySystem( controls.k, controls.m );
    const size_t vecSize = mySystem.diffPow * mySystem.varCount;
    y_vec y(vecSize);
    y[0] = controls.x;
    y[1] = controls.v;
    boolVec_t orders( vecSize, true );
    sheetYSub mySheet( controls.outCount, orders );
    solutions::explicitEuler myLittleEuler( mySystem, &problem::diffEq::derivative, mySheet );
    myLittleEuler.solve( y, controls.tFin, controls.tStep, controls.t0);
    if( mySheet.isFull() ) {
        mySheet.printTo();
    } else {
        std::cout << "Sheet is not full" << std::endl;
    }
    return EXIT_SUCCESS;
}

