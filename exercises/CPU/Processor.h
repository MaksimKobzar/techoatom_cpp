//---------------------------------------------
//! @IDE CLion
//! @file Processor.h
//! Header file with Processor class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _PROCESSOR_H_
#define _PROCESSOR_H_

#include <iostream>

//#define NDEBUG

//------------------------------------------------------------
//! @namespace
//! Processor name space
//------------------------------------------------------------
namespace cpuns
{

    template<
    	class T,
      class StackType = std::stack<T>
    >class Processor
		{
			using REG_NUM = 8;
		public:
			explicit Processor();
			Processor &Processor(const Processor &other);
			~Processor();
			bool fillMemory();



		private:
			StackType 				stack_;
			Switcher 				switcher_;
			T 						reg_[REG_NUM];
			T 						temp_[REG_NUM];
			std::deque<unsigned> 	cmdMemory_;
		};

} // end cpuns

#endif //_PROCESSOR_H_