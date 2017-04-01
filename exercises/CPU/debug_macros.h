//---------------------------------------------
//! @file debug_macros.h
//! Header file cointains convenience macros for debug.
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _DEBUG_MACROS_H_
#define _DEBUG_MACROS_H_

	#include <iostream>
	#include <stdexcept>

	//----------------------------------------------------------------------
	//! Macros to check validity of index ranges
	//----------------------------------------------------------------------
	#ifdef NDEBUG
		#define CHECK_RANGE( index_value, size_value , obj) \
		do {\
		    if (0 > index_value || index_value >= size_value) {\
		        assert(!"Invalid index");\
		    }\
		} while (0)
	#elif
		#define CHECK_RANGE( index_value, size_value , obj) \
		do {\
		    if (0 > index_value || index_value >= size_value) {\
		        obj::dump(__FILE__, __func__, __LINE__);\
		        throw std::out_of_range;
		    }\
		} while (0)
	#endif


	//----------------------------------------------------------------------
	//! Print debug macros
	//----------------------------------------------------------------------
	#ifdef NDEBUG
		#define DEBUG_INFO( message )\
		do {\
		    std::cout << "DEBUG_INFO: " << message << "(file "<< __FILE__ <<" ,line " << __LINE__ << ")."<< std::endl;\
		} while (0)
	#elif
		#define DEBUG_INFO( message )\
		do { } while (0)
	#endif

#endif //_DEBUG_MACROS_H_
