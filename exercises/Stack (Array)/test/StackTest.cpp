//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! @file StackTest.cpp
//! Tests a stack class
//!
//! @author Gerasimchuk Aleksey, 2017
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! A simple unit‐test
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
#include "stdafx.h"
#include "Stack.h"
#include<iostream>
#include<string>

#define ASSERT_EQ(cond1, cond2)		\
	if (cond1 != cond2)				\
		std::cout << #cond1 " AND " #cond2  " IS NOT EQUAL" << std::endl << "-NOT OK" << std::endl;	\
	else							\
		std::cout << "-OK" << std::endl;

std::string DIV_LINE = "-------------------------------------------";

void test_push()
{
	std::cout << DIV_LINE << std::endl << "PUSH AND POP SINGLE NUMBER:" << std::endl;
	Stack<float, 6> s;
	Stack<float, 6>::value_type num = 3802;
	s.push(num);
	ASSERT_EQ(s.pop(), 0xEDA);

	std::cout << DIV_LINE << std::endl << "CANNOT PUSH MORE:" << std::endl;
	Stack<float, 6> s1;
	for (size_t i = 0; i < s1.capacity(); i++)
		s1.push(100 + i);
	ASSERT_EQ(s1.push(0xF00D), false);
}

void test_pop()
{
	std::cout << DIV_LINE << std::endl << "POP WHEN EMPTY (WARNING):" << std::endl;
	Stack<float, 6> s;
	ASSERT_EQ(s.pop(), 0);
}

void test_top()
{
	std::cout << DIV_LINE << std::endl << "CHECK TOP ELEMENT:" << std::endl;
	Stack<float, 6> s;
	Stack<float, 6>::value_type num = 3802;
	s.push(num);
	ASSERT_EQ(s.top(), 0xEDA);

	std::cout << DIV_LINE << std::endl << "CHECK TOP ELEMENT WHEN EMPTY (WARNING):" << std::endl;
	Stack<float, 6> s1;
	ASSERT_EQ(s1.top(), 0);
}

void test_empty()
{
	std::cout << DIV_LINE << std::endl << "CHECK EMPTY WHEN EMPTY:" << std::endl;
	Stack<float, 6> s;
	Stack<float, 6>::value_type num = 3802;
	s.push(num);
	s.pop();
	ASSERT_EQ(s.empty(), true);

	std::cout << DIV_LINE << std::endl << "CHECK EMPTY WHEN NOT EMPTY:" << std::endl;
	s.push(num);
	ASSERT_EQ(s.empty(), false);
}

void test_size()
{
	std::cout << DIV_LINE << std::endl << "CHECK SIZE GETTER:" << std::endl;
	Stack<float, 6> s;
	Stack<float, 6>::value_type num = 3802;
	s.push(num);
	s.push(num);
	s.push(num);
	s.pop();
	ASSERT_EQ(s.size(), 2);

	std::cout << DIV_LINE << std::endl << "CHECK SIZE GETTER WHEN 0:" << std::endl;
	Stack<float, 6> s1;
	ASSERT_EQ(s1.size(), 0);
}

void test_capacity()
{
	std::cout << DIV_LINE << std::endl << "CHECK CAPACTIY GETTER:" << std::endl;
	Stack<float, 6> s;
	ASSERT_EQ(s.capacity(), 6);
}

int main()
{
	test_push();
	test_pop();
	test_top();
	test_empty();
	test_size();
	test_capacity();
	system("pause");
	return 0;
}
