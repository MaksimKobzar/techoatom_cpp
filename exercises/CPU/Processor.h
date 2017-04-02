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
#include "Switcher.h"

//#define NDEBUG

//------------------------------------------------------------
//! @namespace
//! Processor name space
//------------------------------------------------------------
namespace cpuns
{

    template<
    	typename T,
    	class StackType = std::stack<T>
    >class Processor
		{
			using REG_NUM = 32;
			using value_type = T;
			using MEM_WIDTH = 256;
		public:
			explicit Processor();
			Processor &Processor(const Processor &other);
			~Processor();

			bool fillMemory();
			bool run();


		private:
			std::array<type_value, REG_NUM> 	*regs_;
			std::deque<type_value> 				*cmdMemory_;
			StackType 							*stack_;
			Switcher<type_value> 				*switcher_;
		};

} // end cpuns

template <typename value_type, class StackType>
Processor<value_type, StackType>::Processor()
{
	regs_ 		= new std::array<type_value, REG_NUM>;
	cmdMemory_ 	= new std::deque<type_value>(MEM_WIDTH);
	stack_ 		= new StackType(10);
	switcher_ 	= new StaSwitcher<type_value>(cmdMemory_, stack_, regs_);
}

template <typename value_type, class StackType>
Processor<value_type, StackType>::~Processor()
{
	delete switcher_;
	delete cmdMemory_;
	delete stack_;
	delete regs_;
}

template <typename value_type, class StackType>
bool Processor<value_type, StackType>::fillMemory()
{
	switcher_->run();
}

template <typename value_type, class StackType>
bool Processor<value_type, StackType>::run()
{
	switcher_->run();
}

#endif //_PROCESSOR_H_