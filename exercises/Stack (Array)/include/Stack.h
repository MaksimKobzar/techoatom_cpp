//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! @file Stack.h
//! Implements a stack class
//!
//! @author Gerasimchuk Aleksey, 2017
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Stack class
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

#include "stdafx.h"
#include"Array.h"
#include<iostream>
#include<assert.h>


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Macro to test object integrity
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
#define ASSERT_OK()							\
	if (!ok())								\
		{									\
		dump();								\
		assert(!"Object is OK (Stack)");	\
		}

template<typename T, const size_t capacity>
class Stack
{
public:
	typedef T value_type;							//!< Element type
	using Container = Array<value_type, capacity>;
	typedef size_t size_type;						//!< Size type
	typedef value_type& reference;					//!< Reference element type
	typedef const value_type& const_reference;		//!< Const reference element type

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Constructor
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	Stack();

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Destructor
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	~Stack();

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Pushes a value to the stack
	//! @param value is an element to be pushed
	//! @return success of operation
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool push(const_reference value);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Pop a value from the stack
	//! @return Return the top element from the stack
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	value_type pop();

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Return the top element from the stack
	//! @return Return the top element from the stack
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	value_type top();

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Checks if the stack has no elements
	//! @return true if stack empty
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool empty();

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Return the size of the stack
	//! @return Return the size of the stack
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_type size() const;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Return the capacity of the stack
	//! @return Return the capacity of the stack
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_type capacity() const;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Check if size <= capacity
	//! @return Return true if size <= capacity
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool ok() const;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Shows the current state of the Stack
	//! @return in console size, capacity and all elements of the stack
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void dump() const;

private:
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Stack array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	Container data_;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Size of the stack
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_type size_;
};

//const Stack::size_type POISON_INT = 100500;
template<typename value_type, const size_t capacity>
Stack<value_type, capacity>::Stack() : size_(0)
{

}

template<typename value_type, const size_t capacity>
Stack<value_type, capacity>::~Stack()
{
	size_ = POISON_INT;
}

template<typename value_type, const size_t capacity>
bool Stack<value_type, capacity>::push(const_reference value)
{
	ASSERT_OK();
	if (size_ >= data_.max_size())
		return false;

	data_[size_++] = value;
	ASSERT_OK();
	return true;
}

template<typename value_type, const size_t capacity>
value_type Stack<value_type, capacity>::pop()
{
	ASSERT_OK();
	if (empty())
	{
		std::cout << "WARNING: STACK IS EMPTY. POP() IS NOT AVAILABLE. RETURN 0" << std::endl;
		return 0;
	}

	ASSERT_OK();
	return data_[--size_];
}

template<typename value_type, const size_t capacity>
typename Stack<value_type, capacity>::value_type Stack<value_type, capacity>::top()
{
	ASSERT_OK();
	if (empty())
	{
		std::cout << "WARNING: STACK IS EMPTY. TOP() IS NOT AVAILABLE. RETURN 0" << std::endl;
		return 0;
	}

	return data_[size_ - 1];
}

template<typename value_type, const size_t capacity>
bool Stack<value_type, capacity>::empty()
{
	ASSERT_OK();
	if (size_ == 0)
		return true;
	else
		return false;
}

template<typename value_type, const size_t capacity>
typename Stack<value_type, capacity>::size_type Stack<value_type, capacity>::size() const
{
	ASSERT_OK();
	return size_;
}

template<typename value_type, const size_t capacity>
typename Stack<value_type, capacity>::size_type Stack<value_type, capacity>::capacity() const
{
	ASSERT_OK();
	return data_.max_size();
}

template<typename value_type, const size_t capacity>
bool Stack<value_type, capacity>::ok() const
{
	return size_ <= data_.max_size();
}

template<typename value_type, const size_t capacity>
void Stack<value_type, capacity>::dump() const
{
	std::cout << "size_ = " << size_ << std::endl;
	std::cout << "capacity_ = " << data_.max_size() << std::endl;
	std::cout << "data [" << data_.max_size() << "]:" << std::endl;
	for (int i = 0; i != data_.max_size(); i++)
		std::cout << "[" << i << "] = " << data_[i] << std::endl;
}