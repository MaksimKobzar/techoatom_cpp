//---------------------------------------------
//! @IDE CLion
//! @file main.cpp
//! Draft version construct and use Stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include <iostream>
#include "Stack.hpp"

int main() {
    Stack someStack;

    std::cout << "Stack draft run." << std::endl;
    std::cout << "Size of Stack is " <<  someStack.size() << "." <<  std::endl;
    std::cout << "Is Stack empty? " <<  (someStack.empty() ? "Yes." : "No.") << std::endl;

    return 0;
};
