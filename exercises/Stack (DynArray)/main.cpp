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
    Stack<int> stack1(10);
    Stack<int> stack2(10);

    if(stack1.push(2)) {
        stack2 = stack1;
//        if(stack2.top() == 2) {
//            std::cout << "All right!" << std::endl;
//        }
    }
    std::cout << "Damn!" << std::endl;


}