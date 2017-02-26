//---------------------------------------------
//! @IDE CLion
//! @file main.cpp
//! Works with stack class
//!
//! @author Maksim_Kobzar, 2017

// вопросы
// - иерархия пректа
// - дефиниция вперед декларации
// - изменение статических параметров стека
// -
//---------------------------------------------

#include <iostream>
#include "src.h"

int main()
{
    Stack::size_type stackSize = 100;
    Stack * someStack = new Stack;
    Stack::value_type someValue = 10;
    if(someStack->push(someValue) == 0)
        std::cout << "Failed push" << std::endl;
    std::cout << "Size of Stack is " << someStack->size() << std::endl;
    std::cout << "Top of Stack is " << *someStack->top() << std::endl;


};