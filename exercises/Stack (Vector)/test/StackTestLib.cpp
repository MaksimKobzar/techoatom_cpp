//---------------------------------------------
//! @IDE CLion
//! @StackTestLib main.cpp
//! Stack StackTestLib Library
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#define NDEBUG

#include <iostream>
#include "debug_macros.h"
#include "Stack.h"
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

TEST(Stack, WrongReadedData) {
	Stack<int> someStack(50);

    for (int i = 0; i < 50; ++i) {
    	someStack.push(2*i);
    }
	for (int i = 49; i >= 0; --i) {
		ASSERT_EQ(*someStack.top(), 2*i);
		someStack.pop();
    }
}

TEST(Stack, PushMoreThanHave) {
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

TEST(Stack, WrongEmptyResult) {
	Stack<int> someStack(50);

  ASSERT_EQ(someStack.empty(), 1);
	someStack.push(2203);
	someStack.push(2203);
	someStack.pop();
  ASSERT_EQ(someStack.empty(), 0);
	someStack.pop();
	ASSERT_EQ(someStack.empty(), 1);
}

TEST(Stack, WrongReturnedType) {
	Stack<double> someStack(50);

	someStack.push(5.23);
    ASSERT_EQ(*someStack.top(), 5.23);
}

TEST(Stack, WrongCapacityResult) {
	Stack<double> 	someStack1(3);
	Stack<int> 		someStack2(1);

	ASSERT_EQ(someStack1.capacity(), 3);
	ASSERT_EQ(someStack2.capacity(), 1);
	someStack1.push(12.1);
	ASSERT_EQ(someStack2.size(), 0);
	ASSERT_EQ(someStack1.capacity(), 3);
	ASSERT_EQ(someStack2.capacity(), 1);

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

TEST(Stack, WrongResizeWorking) {
	Stack<double> 	someStack(3);

	for (int i = 0; i != 3; ++i)
	{
		someStack.push(i*1.12);
	}
	ASSERT_EQ(someStack.resize(6), 1);
	for (int i = 3; i != 6; ++i)
	{
		someStack.push(i*1.12);
	}
	ASSERT_EQ(someStack.full(), 1);

	for (int i = 0; i + 6; ++i)
	{
		ASSERT_EQ(*someStack.top(), i*1.12);
		ASSERT_EQ(someStack.pop(), 1);
	}
	ASSERT_EQ(someStack.empty(), 1);
}

TEST(Stack, FailedCopyConstructor) {
	Stack<int> 	someStack1(3);
	someStack1.push(12);
	Stack<int> 	someStack2(someStack1);
	ASSERT_EQ(someStack2.size(), 3);
	ASSERT_EQ(*someStack2.top(), 12);
}

TEST(Stack, FailedMoveConstructors) {

}

TEST(Stack, FailedCommonFuntionsForVectorBool) {
	Stack<bool> someStack1(100);
	ASSERT_EQ(someStack1.capacity(), 100);
	someStack1.push(0);
	someStack1.push(1);
	someStack1.push(0);
	someStack1.push(1);
	ASSERT_EQ(someStack1.size(), 4);

	Stack<bool> someStack2(someStack1);
	ASSERT_EQ(someStack2.size(), 4);
	ASSERT_EQ(someStack2.resize(3), 0);
	ASSERT_EQ(someStack2.resize(4), 1);
	for (int i = 0; i != 4; ++i)
	{
		ASSERT_EQ(*someStack2.top(), i%2 + 1);
		ASSERT_EQ(someStack2.pop(), 1);
	}
	ASSERT_EQ(someStack2.size(), 0);
	someStack1.swap(someStack2);
	ASSERT_EQ(someStack1.size(), 0);
	ASSERT_EQ(someStack2.size(), 4);
}

/*TEST(Stack, FailedPlacementOperator=) {

}*/



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
