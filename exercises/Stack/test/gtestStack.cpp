//---------------------------------------------
//! @IDE CLion
//! @file main.cpp
//! Works with stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include <iostream>
#include "gtest/gtest.h"
#include "Stack.hpp"

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     // Stack::size_type size = 0;
//     // Stack::size_type capacity = 50;
//     Stack someStack1;
//     std::cout << "Capacity of Stack1 is " << someStack1->capacity() << std::endl;

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

    // return RUN_ALL_TESTS();
// }