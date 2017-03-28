	//---------------------------------------------
//! @file SmartException.cpp
//! Implementation of SmartException class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include "SmartException.h"
#include <iostream>
#include <cstring>

using namespace sens;

SmartException::SmartException(std::string errorMess)
	: errorMess_(errorMess) {	}

SmartException::SmartException(std::string errorMess, const std::exception &exc)
	: errorMess_(errorMess), std::exception(exc) {	}

const char* SmartException::what()
{
	std::string result;
	result.append(errorMess_);
	result.append(std::exception::what());
	return  result.c_str();
	/* TODO what doesnt return what i need*/
}