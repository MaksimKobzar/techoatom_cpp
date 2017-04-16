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
#include <stack>
#include <deque>
#include <string>
#include <array>

#include "debug_macros.h"
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
		const size_t REG_NUM = 32,
    	class StackType = std::stack<T>
    >class Processor
		{
			using value_type 		= T;
		public:
			explicit Processor(size_t memWidth, size_t stackDepth);
			~Processor();

			bool fillMemory(std::string filePath);
			void run();

			value_type getRegValue(size_t num) const;

		private:
			std::array<value_type, REG_NUM> 		*regs_;
			std::deque<value_type> 					*cmdMemory_;
			StackType 								*stack_;
			Switcher<value_type, REG_NUM, StackType> *switcher_;
		};


	template <typename value_type, const size_t REG_NUM, class StackType>
	Processor<value_type, REG_NUM, StackType>::Processor(size_t memWidth, size_t stackDepth)
	{
		DEBUG_INFO("PROCESSOR: Start constructor.");
		regs_ 		= new std::array<value_type, REG_NUM>;
		regs_->fill(0);
		cmdMemory_ 	= new std::deque<value_type>(memWidth);
		stack_ 		= new StackType;
		switcher_ 	= new Switcher<value_type, REG_NUM>(*cmdMemory_, *stack_, *regs_);
		DEBUG_INFO("PROCESSOR: End constructor.");
	}

	template <typename value_type, const size_t REG_NUM, class StackType>
	Processor<value_type, REG_NUM, StackType>::~Processor()
	{
		DEBUG_INFO("PROCESSOR: Start destructor.");
		delete switcher_;
		delete cmdMemory_;
		delete stack_;
		delete regs_;
	}

	template <typename value_type, const size_t REG_NUM, class StackType>
	bool Processor<value_type, REG_NUM, StackType>::fillMemory(std::string filePath)
	{
		DEBUG_INFO("PROCESSOR: Fill Memory.");
		#ifdef NDEBUG
			cmdMemory_->push_front(0x09E00100); // ADDI summ of 2 num to $r15
			cmdMemory_->push_front(0x88440000); // LW from $r2 to Stack
			cmdMemory_->push_front(0x04400000); // ADD summ of 2 num to $r2
			cmdMemory_->push_front(0x9000000A); // PSI_CMD 10
			cmdMemory_->push_front(0x90000003); // PSI_CMD 3
		#else
		// load from Text/Bin file
		#endif
		DEBUG_INFO("PROCESSOR: Memory size = ");
		DEBUG_INFO(cmdMemory_->size());
		DEBUG_INFO("PROCESSOR: [0] = ");
		DEBUG_INFO(cmdMemory_->front());
		DEBUG_INFO(cmdMemory_->back());
	}

	template <typename value_type, const size_t REG_NUM, class StackType>
	void Processor<value_type, REG_NUM, StackType>::run()
	{
		char retCode = switcher_->run();
		DEBUG_INFO("PROCESSOR: Start run.");
		if(retCode)
		{
			throw std::runtime_error("Failed run.");
		}
		DEBUG_INFO("PROCESSOR: End run.");
	}


	template <typename value_type, const size_t REG_NUM, class StackType>
	value_type Processor<value_type, REG_NUM, StackType>::getRegValue(size_t num) const
	{
		DEBUG_INFO("PROCESSOR: Get reg value.");
		if(0 <= num && num < REG_NUM)
		{
			return regs_->at(num);
		}
		else
		{
            throw std::out_of_range("Try get reg of Processor with index more than existed.");
		}
	}

} // end cpuns

#endif //_PROCESSOR_H_