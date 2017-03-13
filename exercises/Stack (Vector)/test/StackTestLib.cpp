//---------------------------------------------
//! @IDE CLion
//! @StackTestLib main.cpp
//! Stack StackTestLib Library
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include <iostream>
#include "Stack.hpp"
#include "gtest/gtest.h"

using namespace sns;


TEST(Stack, CannotPushMore) {
	int countSuccess = 0;
	Stack<int> someStack(50);

	for (int i = 0; i < 60; ++i) {
		if(someStack.push(2*i)) {
			countSuccess++;
		}
	}
	ASSERT_EQ(countSuccess, 50);
}

TEST(Stack, CannotPopMore) {
	int countSuccess = 0;
	Stack<int> someStack(50);
	
    for (int i = 0; i < 50; ++i) {	
		someStack.push(2*i);
	}
	for (int i = 0; i < 60; ++i) {	
	    if(someStack.pop()) {
	    	countSuccess++;
	    }
	}
	ASSERT_EQ(countSuccess, 50);
}

TEST(Stack, WrongData) {
	Stack<int> someStack(50);
	
    for (int i = 0; i < 50; ++i) {	
    	someStack.push(2*i);
    }
	for (int i = 49; i >= 0; --i) {
		ASSERT_EQ(*someStack.top(), 2*i);
		someStack.pop();
    }
}

TEST(Stack, WrongSize) {
	int countSize = 0;
	Stack<int> someStack(50);
	
    for (int i = 0; i < 60; ++i) {	
	    if(someStack.push(2*i)) {
	    	countSize++;
	    }
	    if(i < 50) ASSERT_EQ(countSize, i+1);
	}
	for (int i = 0; i < 60; ++i) {	
    	if(someStack.pop()) {
    		--countSize;
    	}
    	else {
    		++countSize;
    	}
    }
    ASSERT_EQ(countSize, 10);
}

TEST(Stack, WrongEmpty) {
	Stack<int> someStack(50);
	
    ASSERT_EQ(someStack.empty(), 1);
	someStack.push(2203);
	someStack.push(2203);
	someStack.pop();
    ASSERT_EQ(someStack.empty(), 0);
	someStack.pop();
	ASSERT_EQ(someStack.empty(), 1);
}

TEST(Stack, WrongType) {
	Stack<double> someStack(50);
	
	someStack.push(5.23);
    ASSERT_EQ(*someStack.top(), 5.23);
}

TEST(Stack, WrongCapacity) {
	Stack<double> 	someStack1(3);
	Stack<int> 		someStack2(1);
	
	ASSERT_EQ(someStack1.capacity(), 3);
	ASSERT_EQ(someStack2.capacity(), 1);
	someStack1.push(12.1);
	ASSERT_EQ(someStack2.size(), 0);
	ASSERT_EQ(someStack1.capacity(), 3);
	ASSERT_EQ(someStack2.capacity(), 1);

}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
