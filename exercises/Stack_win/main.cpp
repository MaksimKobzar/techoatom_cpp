//---------------------------------------------
//! @IDE CLion
//! @file main.cpp
//! Works with stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include <iostream>
#include "Stack.hpp"

//---------------------------------------------

//#define TEST(what, case)
//			bool case () {
//
//			}
//			cout << "TEST " << case << case() endl;
//---------------------------------------------


int main() {
    // Stack * someStack0 = new Stack(0, 100);
    Stack someStack;

    // std::cout << "Capacity of Stack0 is " << someStack0->capacity() << std::endl;
    std::cout << "Capacity of Stack1 is " << std::endl;

    return 0;
};

//    TEST (Stack, CannotPushMore) {
//	    for (int i = 0; i < 60; ++i)
//	    {
//	    	if(someStack1->push(2*i))
//	    		countSuccess++;
//	    	ASSERT_EQ(countSuccess == 50);
//	    }
//	  }
//
//	  TEST (Stack, WrongData) {
//	    for (int i = 0; i < 50; ++i)
//	    	if(someStack1->push(2*i));
//	   	for (int i = 0; i < 50; ++i) {}
//	    	ASSERT_EQ(someStack1->pop() == 1);
//	    	ASSERT_EQ(someStack1->top() == 2*i);
//	    }
//	  }
//
//	  TEST (Stack, WrongData) {
//	    for (int i = 0; i < 50; ++i)
//	    	if(someStack1->push(2*i));
//	   	for (int i = 0; i < 50; ++i) {}
//	    	ASSERT_EQ(someStack1->pop() == 1);
//	    	ASSERT_EQ(someStack1->top() == 2*i);
//	    }
//	  }

