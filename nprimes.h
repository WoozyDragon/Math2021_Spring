// nprimes.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#ifndef NPRIMES_H
#define NPRIMES_H

#include <iostream>
#include <cmath>
#include <vector>

#include "tclap/CmdLine.h"

extern int g_totalString;
extern int g_numberOfString;
extern bool g_noAutoReturn;

//returns true if value is prime, false otherwise
bool isPrime(int value);

#endif
