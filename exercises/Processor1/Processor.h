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
#include <sstream>
#include <fstream>
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
			using value_type = T;
		public:
			//---------------------------------------------
	        //! @Constructor
	        //! Create class Processor
	        //! Get 2 arguments:
	        //!	- Instruction memory width,
	        //! - Stack depth.
	        //---------------------------------------------
			explicit Processor(size_t memWidth, size_t stackDepth);
			Processor(Processor &other) = delete;
			
			//---------------------------------------------
	        //! @Destructor
	        //---------------------------------------------
			~Processor();

			//---------------------------------------------
	        //! @fillMemory
	        //! Get string with memory file`s path as argument.
	        //! If memory filling was failed function would return false, otherwise true.
	        //---------------------------------------------
			bool fillMemory(std::string filePath);

			//---------------------------------------------
	        //! @run
	        //! Start process program.
	        //! Return error code if program was failed in runtime.
	        //! Return codes:
	        //! 0 - SUCCESS
	        //! 1 - STACK_UNDERFLOW
	        //! 2 - OUT_OF_MEM_RANGE
	        //---------------------------------------------
			char run();

			//---------------------------------------------
	        //! @getRegValue
	        //! @setRegValue
	        //! Functions to get and to set value of Processor`s registers.
	        //! Throw std::out_of_range exception if index out of range.
	        //---------------------------------------------
			value_type getRegValue(size_t num) const;
			void setRegValue(size_t num, value_type value);

		private:
			std::array<value_type, REG_NUM> 			*regs_;
			std::deque<value_type> 						*cmdMemory_;
			StackType 									*stack_;
			Switcher<value_type, REG_NUM, StackType> 	*switcher_;
	};

	// -----------------------------------------------------------------------------------------------
	// Implementation of methods
	// -----------------------------------------------------------------------------------------------
	template <typename value_type, const size_t REG_NUM, class StackType>
	Processor<value_type, REG_NUM, StackType>::Processor(size_t memWidth, size_t stackDepth)
	{
		DEBUG_INFO("PROCESSOR: Start constructor.");
		regs_ 		= new std::array<value_type, REG_NUM>;
		cmdMemory_ 	= new std::deque<value_type>(memWidth);
		stack_ 		= new StackType;
		switcher_ 	= new Switcher<value_type, REG_NUM>(*cmdMemory_, *stack_, *regs_);
		regs_->fill(0);
		DEBUG_INFO("PROCESSOR: End constructor.");
	}

	template <typename value_type, const size_t REG_NUM, class StackType>
	Processor<value_type, REG_NUM, StackType>::~Processor()
	{
		DEBUG_INFO("PROCESSOR: Destructor.");
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
			std::ifstream in(filePath);
		    std::string buffer << in.rdbuf();
			std::cout << "Print file content: " << buffer << std::endl << std::endl;

		    for(size_t index = 0; index < buffer.len(); ++i)
		    {
		    	cmdMemory_.push_front(buffer[index]);
		    }

		#endif
	}

	template <typename value_type, const size_t REG_NUM, class StackType>
	char Processor<value_type, REG_NUM, StackType>::run()
	{
		DEBUG_INFO("PROCESSOR: Run.");
		return (switcher_->run());
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

	template <typename value_type, const size_t REG_NUM, class StackType>
	void Processor<value_type, REG_NUM, StackType>::setRegValue(size_t num, value_type value)
	{
		DEBUG_INFO("PROCESSOR: Get reg value.");
		if(0 <= num && num < REG_NUM)
		{
			regs_[num] = value;
		}
		else
		{
            throw std::out_of_range("Try get reg of Processor with index more than existed.");
		}
	}

} // end cpuns

#endif //_PROCESSOR_H_