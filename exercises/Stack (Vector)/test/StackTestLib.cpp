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

	std::cout << "Capacity of Stack is " << someStack.capacity() << "." << std::endl;
	for (int i = 0; i < 60; ++i) {
		if(someStack.push(2*i)) {
			countSuccess++;
		}
		ASSERT_EQ(countSuccess, 50);
	}
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
