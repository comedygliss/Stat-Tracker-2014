/***************************************************************************** 
 * BASEBALL MAIN .h
 *****************************************************************************
 * ALL INCLUDED FILES NEEDED AND PURPOSE:
 * cstdlib = used for basic c functions, in this case "clear screen"
 * iostream = used for console input 
 * iomanip = used for formatting programs
 * fstream = used for file input and output
 * windows.h = used for the sleep function
 * baseballClasses.h = includes the Pitcher and Batter classes
 * batter.h = includes the prototype functions for the batter.cpp
 * pitcher.h = includes the prototype functions for the pitcher.cpp
 * searchStats.h = includes the prototype functions for the searchStats.cpp
 *****************************************************************************/
using namespace std;

#ifndef BASEBALLMAIN_H
#define BASEBALLMAIN_H

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>

#include "baseballClasses.h"
#include "batter.h"
#include "pitcher.h"
#include "searchStats.h"

#endif

void printHeader(string lastModified);
void baseballMainDisplay();
void batterOrPitcher();
void batterInputOrFile();
void pitcherInputOrFile();
