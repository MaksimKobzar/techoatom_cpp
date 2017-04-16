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
			using REG_NUM 		= 32;
			using value_type 	= T;
			using MEM_WIDTH 	= 256;
			using STACK_DEPTH 	= 32;
		public:
			explicit Processor(size_t memWidth, size_t stackDepth);
			Processor &Processor(const Processor &other);
			~Processor();

			bool fillMemory();
			bool run();

			std::array<type_value, REG_NUM> 	*regs_;
		private:
			std::deque<type_value> 				*cmdMemory_;
			StackType 							*stack_;
			Switcher<type_value> 				*switcher_;
		};

} // end cpuns

template <typename value_type, class StackType>
Processor<value_type, StackType>::Processor(size_t memWidth, size_t stackDepth)
{
	regs_ 		= new std::array<type_value, REG_NUM>;
	cmdMemory_ 	= new std::deque<type_value>(memWidth);
	stack_ 		= new StackType(stackDepth);
	switcher_ 	= new StaSwitcher<type_value>(*cmdMemory_, *stack_, *regs_);
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
bool Processor<value_type, StackType>::fillMemory(std::string filePath)
{
	#ifdef NDEBUG
		cmdMemory_->push_back(‭0x‭‭9000000A‬); // PSI_CMD 10
		cmdMemory_->push_back(0x‭‭90000003); // PSI_CMD 3
		cmdMemory_->push_back(‭0x0‭4400000‬); // ADD summ of 2 num to $r2
	#else
	// load from Text/Bin file
	#endif
}

template <typename value_type, class StackType>
bool Processor<value_type, StackType>::run()
{
	while(!switcher_->run());
}

#endif //_PROCESSOR_H_