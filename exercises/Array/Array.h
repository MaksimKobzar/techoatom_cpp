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

#define ASSERT_OK()					\
	if (!ok())						\
		{							\
		/*dump(); TODO:dump*/		\
		assert(!"Object is OK");	\
		}

template <typename T, const size_t capacity>
class Array
{
public:
	typedef T value_type;
	typedef size_t size_type;
	typedef std::ptrdiff_t difference_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	//typedef T* pointer;
	//typedef const T* const_pointer;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Constructor which set size of the array to max_size and fill it with zeroes
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	Array();

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Constructor which set size of the array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	Array(const size_type size);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Destructor
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	~Array();

	//TODO: description
	void fill(const value_type& value);
	value_type &operator[](size_type const n);
	Array &operator=(Array const &other);
	void swap(Array &other);
	bool ok() const;
	size_type size();
	size_type max_size();

private:
	size_t size_;
	value_type data_[capacity];
	bool valid_;
};

const int POISON_INT = 100500; //???
const size_t POISON_SIZE = 100500; //???

template <typename value_type, const size_t capacity>
Array<value_type, capacity>::Array()
{
	for (size_type i = 0; i < capacity; ++i)
		data_[i] = 0;
}

template <typename value_type, const size_t capacity>
Array<value_type, capacity>::Array(const size_type size)
	:size_(size)
{
	if (size > capacity)
		valid_ = false;

	ASSERT_OK();

	for (size_type i = 0; i < size; ++i)
		data_[i] = 0;
	for (size_type i = size; i < capacity; ++i)
		data_[i] = POISON_INT;
}

template <typename value_type, const size_t capacity>
Array<value_type, capacity>::~Array()
{
	for (size_type i = 0; i < capacity; ++i)
		data_[i] = POISON_INT;
	
	size_ = POISON_SIZE;
	valid_ = false;
}

template <typename value_type, const size_t capacity>
void Array<value_type, capacity>::fill(const value_type& value)
{
	ASSERT_OK();

	for (int i = 0; i < capacity; ++i)
		data_[i] = value;
}

template<typename value_type, const size_t capacity>
value_type &Array<value_type, capacity>::operator[](size_type const n)
{
	if (n >= size_)
		valid_ = false;

	ASSERT_OK();

	return data_[n];
}

template<typename value_type, const size_t capacity>
Array<value_type, capacity> &Array<value_type, capacity>::operator=(Array<value_type, capacity> const &other) {

	if (this != &other) {
		Array(other).swap(*this);
	}
	return *this;
}

template<typename value_type, const size_t capacity>
void Array<value_type, capacity>::swap(Array<value_type, capacity> &other) {
	std::swap(size_, other.size_);
	std::swap(data_, other.data_);
	std::swap(data_, other.valid_);
}

template<typename value_type, const size_t capacity>
Array<value_type, capacity>::size_type Array<value_type, capacity>::size()
{
	return size_;
}

template<typename value_type, const size_t capacity>
Array<value_type, capacity>::size_type Array<value_type, capacity>::max_size()
{
	return capacity;
}

template<typename value_type, const size_t capacity>
bool Array<value_type, capacity>::ok() const
{
	return valid_;
}