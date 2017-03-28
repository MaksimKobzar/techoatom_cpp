//---------------------------------------------
//! @IDE CLion
//! @file SmartException.h
//! Header file with Stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _SMART_EXCEPTION_H_
#define _SMART_EXCEPTION_H_

#include <iostream>
#include <string>

//#define NDEBUG

//------------------------------------------------------------
//! @namespace
//! Smart Exception name space
//------------------------------------------------------------
namespace sens
{

	class SmartException: public std::exception
	{
	public:
		//---------------------------------------------
    	//! @Constructor
    	//---------------------------------------------
		explicit SmartException(std::string errorMess);

		//---------------------------------------------
    	//! @Constructor based on Copy Constructor
    	//---------------------------------------------
		explicit SmartException(std::string errorMess, const exception &exc);

		virtual const char* what();
	private:
		std::string errorMess_;
	};

} // end sens

#endif //_SMART_EXCEPTION_H_