//---------------------------------------------
//! @IDE CLion
//! @file main.cpp
//! Empty test file
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------


#define NDEBUG

#include "Processor.h"

using namespace sns;

int main() {
   /* Stack<double> stack1(10);
    Stack<double> stack2(10);

    std::cout << "Is stack1 is empty -  " << stack1.empty() << "." << std::endl;

    if(stack1.push(2.5)) {
        stack2 = stack1;
        std::cout << "Top element of stack2: " << *stack2.top() << "." << std::endl;
    }


    if(stack1 == stack2) {
    	std::cout << "2 stacks are equal!" << std::endl;
    }
    else {
    	std::cout << "2 stacks arent equal!" << std::endl;
    }

    std::cout << "Capacity of stack is " << stack1.capacity() << std::endl;

    stack2.push(3.1);
    stack2.push(8.9);
    stack2.swap(stack1);
    std::cout << "Top element of stack1: " << *stack1.top() << "." << std::endl;*/


    // for Bool
    Processor<unsigned> proc(256, 32);
    proc.fillMemory();
    proc.run();
    std::cout << "Reg[2] = " << *(proc.regs_)[2] << std::endl;
}
