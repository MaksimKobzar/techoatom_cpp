//---------------------------------------------
//! @IDE CLion
//! @file SlackTestSuite.cpp
//! Test suite for Stack
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include <iostream>
#include "gtest/gtest.h"
#include "Stack.hpp"

    TEST(Stack, CannotPushMore) {
    	int countSuccess = 0;
    	Stack::value_type someValue = 0;
    	Stack someStack;
    	
	    for (int i = 0; i < 60; ++i) {	
		    someValue = 2*i;
		    if(someStack.push(someValue))
		    	countSuccess++;
		}
		ASSERT_EQ(countSuccess, 50);
	}

	TEST(Stack, CannotPopMore) {
    	int countSuccess = 0;
    	Stack::value_type someValue = 0;
    	Stack someStack;
    	
	    for (int i = 0; i < 50; ++i) {	
		    someValue = 2*i;
		    if(someStack.push(someValue))
		    ASSERT_EQ(countSuccess, 50);
		}
		for (int i = 0; i < 60; ++i) {	
		    if(someStack.pop())
		    	countSuccess++;
		}
		ASSERT_EQ(countSuccess, 50);
	}

	TEST(Stack, WrongData) {
    	Stack::value_type someValue = 0;
    	Stack someStack;
    	
	    for (int i = 0; i < 50; ++i) {	
		    	someValue = 2*i;
		    	someStack.push(someValue);
		    	ASSERT_EQ(countSuccess, 50);
		    }
		}
		for (int i = 0; i < 50; ++i) {	
	    	someStack.pop();
	    	someValue = 2*i;
	    	ASSERT_EQ(someStack.top(), someValue);
	    }
	}

	TEST(Stack, WrongSize) {
		Stack::size_type countSize = 0;
    	Stack::value_type someValue = 0;
    	Stack someStack;
    	
	    for (int i = 0; i < 60; ++i) {	
		    	someValue = 2*i;
		    	if(someStack.push(someValue))
		    		countSize++;
		    }
		    if(i < 50) ASSERT_EQ(countSize, i+1);
		}
		for (int i = 0; i < 60; ++i) {	
	    	if(someStack.pop())
	    		countSize--;
	    	else
	    		countSize++;

	    }
	    ASSERT_EQ(countSize, 10);
	}

	TEST(Stack, WrongEmpty) {
		Stack::size_type countSize = 0;
    	Stack::value_type someValue = 0;
    	Stack someStack;
    	
	    ASSERT_EQ(someStack.empty(), 1);
	    someValue = 2*i;
		someStack.push(someValue);
		someStack.pop();
	    ASSERT_EQ(someStack.empty(), 1);
	}

	int main(int argc, char* argv[]) {
	    ::testing::InitGoogleTest(&argc, argv);
	    return RUN_ALL_TESTS();
	}