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
		const size_t REG_NUM 	= 32,
    	class StackType = std::stack<T>
    >class Processor
		{
			using value_type 		= T;
		public:
			explicit Processor(size_t memWidth, size_t stackDepth);
			~Processor();

			bool fillMemory(std::string filePath);
			void run();

			const T &getRegValue(size_t num) const;

		private:
			std::array<value_type, REG_NUM> 		*regs_;
			std::deque<value_type> 					*cmdMemory_;
			StackType 								*stack_;
			Switcher<value_type, REG_NUM, StackType> *switcher_;
		};


	template <typename value_type, const size_t REG_NUM, class StackType>
	Processor<value_type, REG_NUM, StackType>::Processor(size_t memWidth, size_t stackDepth)
	{
		regs_ 		= new std::array<value_type, REG_NUM>;
		cmdMemory_ 	= new std::deque<value_type>(memWidth);
		stack_ 		= new StackType;
		switcher_ 	= new Switcher<value_type, REG_NUM>(*cmdMemory_, *stack_, *regs_);
	}

	template <typename value_type, const size_t REG_NUM, class StackType>
	Processor<value_type, REG_NUM, StackType>::~Processor()
	{
		delete switcher_;
		delete cmdMemory_;
		delete stack_;
		delete regs_;
	}

	template <typename value_type, const size_t REG_NUM, class StackType>
	bool Processor<value_type, REG_NUM, StackType>::fillMemory(std::string filePath)
	{
		#ifdef NDEBUG
	        unsigned cmd = 0x9000000A;
			cmdMemory_->push_back(cmd); // PSI_CMD 10
	        cmd = 0x90000003;
			cmdMemory_->push_back(cmd); // PSI_CMD 3
	        cmd = 0x04400000;
			cmdMemory_->push_back(cmd); // ADD summ of 2 num to $r2
		#else
		// load from Text/Bin file
		#endif
	}

	template <typename value_type, const size_t REG_NUM, class StackType>
	void Processor<value_type, REG_NUM, StackType>::run()
	{
		while(!switcher_->run());
	}


	template <typename value_type, const size_t REG_NUM, class StackType>
	const value_type &Processor<value_type, REG_NUM, StackType>::getRegValue(size_t num) const
	{
		if(0 <= num && num < REG_NUM)
		{
			return regs_[num];
		}
		else
		{
            throw std::out_of_range("Try get reg of Processor with index more than existed.");
		}
	}

} // end cpuns

#endif //_PROCESSOR_H_