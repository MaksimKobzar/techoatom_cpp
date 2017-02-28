//---------------------------------------------
//! @IDE CLion
//! @StackTestLib main.cpp
//! Stack StackTestLib Library
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include <iostream>
#include "gtest/gtest.h"
#include "Stack.hpp"

    TEST(Stack, CannotPushMore) {
    	int countSuccess = 0;
    	Stack::value_type someValue = 0;
    	Stack someStack1;

    	std::cout << "Capacity of Stack1 is " << someStack1.capacity() << std::endl;
	    for (int i = 0; i < 60; ++i) {
		    	someValue = 2*i;
		    	if(someStack1.push(someValue))
		    		countSuccess++;
		    	ASSERT_EQ(countSuccess, 50);
		    }
		}
