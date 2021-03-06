//---------------------------------------------
//! @file Root.cpp
//! Implementation of Root structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include "Root.h"
#include <iostream>

using namespace rns;

Root::Root(double x1, double x2)
	: x1_(x1), x2_(x2) { }

void Root::print() const
{
	std::cout << " Roots: " << x1_ << ", " << x2_ << "." << std::endl;
}