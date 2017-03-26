	//---------------------------------------------
//! @file SmartException.cpp
//! Implementation of SmartException class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include "SmartException.h"
#include <iostream>


SmartException::SmartException(std::string errorMess)
	: errorMess_(error) {	}

SmartException::SmartException(std::string errorMess, const exception &exc)
	: errorMess_(error), exc_(exc) {	}

virtual const char* SmartException::what()
{
 	return strcat(errorMess_.c_str(), exc_.what());
}