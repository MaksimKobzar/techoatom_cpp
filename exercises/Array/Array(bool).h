//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! @file Array.h
//! Implements a array class
//!
//! @author Gerasimchuk Aleksey, 2017
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Array class
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

#include "stdafx.h"
#include<iostream>
#include<assert.h>
#include"Iterator.h"

#define ASSERT_OK_ARR()				\
	if (!ok())						\
		{							\
		dump();						\
		assert(!"Object is OK (Array)");	\
		}

template <const size_t capacity>
class Array<bool, capacity>
{
	const size_t UNS_BIT_NUM = 8*sizeof(unsigned);
	using wordNum_ = size_/UNS_BIT_NUM;
public:
	using iterator = T*;

	typedef size_t size_type;
	typedef std::ptrdiff_t difference_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Constructor which set size of the array to max_size and fill it with zeroes
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	Array();

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Constructor which set size of the array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	Array(const size_type size);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Copy constructor
	//! @param other Array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	Array(const Array &other);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Destructor
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	~Array();

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Fill the Array with specified value
	//! @param value is the value to assign to the elements
	//! @return void
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void fill(const bool& value);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns a reference to the element
	//! @param n is position of the element to return
	//! @return reference to the requested element
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	BoolOperation   operator[](const size_t index);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Assignment operator
	//! @param other Array
	//! @return other Array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	Array &operator=(Array const &other);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Equal operator
	//! @param other Array
	//! @return true if the contents of the Arrays are equal, false otherwise
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool operator==(Array const &other) const;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Exchanges Array with the given Array
	//! @param other Array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void swap(Array &other);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Check if the Array valid
	//! @param valid of the Arary
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool ok() const;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Size getter
	//! @param size of the Arary
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_type get_size() const;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns an iterator to the beginning
	//! @return iterator
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	iterator begin();

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns an iterator to the end
	//! @return iterator
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	iterator end();

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Shows the current state of the Array
	//! @return in console size, capacity and all elements of the Array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void dump() const;

private:
	unsigned data_[capacity];
	bool valid_;
};

const int POISON_INT = 100500;
const size_t POISON_SIZE = 100500;

template <typename value_type, const size_t capacity>
Array<bool, capacity>::Array()
	valid_(true)
{
	for (size_type i = 0; i != capacity; ++i)
		data_[i] = 0;
}

template <typename value_type, const size_t capacity>
Array<bool, capacity>::Array(const size_type size)
	valid_(true)
{
	if (size > capacity)
		valid_ = false;

	ASSERT_OK_ARR();

	for (size_type i = 0; i != size; ++i)
		data_[i] = 0;
	for (size_type i = size; i != capacity; ++i)
		data_[i] = POISON_INT;
}

template <typename value_type, const size_t capacity>
Array<bool, capacity>::Array(const Array<bool, capacity> &other)
	valid_(other.valid_)
{
	for (int i = 0; i != size_; ++i)
		data_[i] = other.data_[i];
}

template <typename value_type, const size_t capacity>
Array<bool, capacity>::~Array()
{
	for (size_type i = 0; i != capacity; ++i)
	{
		data_[i] = POISON_INT;
	}
	valid_ = false;
}

template <typename value_type, const size_t capacity>
void Array<bool, capacity>::fill(const bool& value)
{
	ASSERT_OK_ARR();

	for (size_t i = 0; i != capacity; ++i)
	{
		if(value)
		{
			data_[i/UNS_BIT_NUM] |= 1 << i;
		}
		else
		{
			data_[i/UNS_BIT_NUM] &= 0 << i;
		}
	}
}

template<typename value_type, const size_t capacity>
BoolOperation Array<bool, capacity>::operator[](const size_t index)
{
	ASSERT_OK_ARR();

	#ifdef NDEBUG
	    DEBUG_INFO("Vector - operator[]");
	#endif

	valid_ = false;
  CHECK_RANGE(index, size_);
  return BoolOperation(index%UNS_BIT_NUM, &data_[index/UNS_BIT_NUM]);
}

template<typename value_type, const size_t capacity>
Array<bool, capacity> &Array<bool, capacity>::operator=(Array<bool, capacity> const &other)
{
	if (this != &other) {
		Array(other).swap(*this);
	}
	return *this;
}

template<typename value_type, const size_t capacity>
bool Array<bool, capacity>::operator==(Array const &other) const
{
	if(size() != other.size())
	{
		return false;
	}

	for (int i = 0; i != wordNum_; ++i)
	{
		if (this->data_[i] != other.data_[i])
		{
			return false;
		}
	}
	return true;
}

template<typename value_type, const size_t capacity>
void Array<bool, capacity>::swap(Array<bool, capacity> &other)
{
	std::swap(data_, other.data_);
	std::swap(valid_, other.valid_);
}

template<typename value_type, const size_t capacity>
bool Array<bool, capacity>::ok() const
{
	return valid_;
}

template<typename value_type, const size_t capacity>
typename Array<bool, capacity>::iterator Array<bool, capacity>::begin()
{
	return data_;
}

template<typename value_type, const size_t capacity>
typename Array<bool, capacity>::iterator Array<bool, capacity>::end()
{
	return data_ + capacity;
}

template<typename value_type, const size_t capacity>
void Array<bool, capacity>::dump() const
{
	std::cout << "size_ = " << size_ << std::endl;
	std::cout << "capacity_ = " << capacity << std::endl;
	std::cout << "data [" << capacity << "]:" << std::endl;
	for (int i = 0; i != size_; i++)
	{
		std::cout << "[" << i << "] = " << data_[i] << std::endl;
	}
}