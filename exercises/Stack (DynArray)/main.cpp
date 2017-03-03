//---------------------------------------------
//! @IDE CLion
//! @file main.cpp
//! Empty test file
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include "Stack.hpp"

using namespace sns;

int main() {
    Stack<double> stack1(10);
    Stack<double> stack2(10);

    stack1.push(2.5);
    stack2 = stack1;
    if(stack2.top() == 2.5) {
        std::cout << "All right!" << std::endl;
    }
}