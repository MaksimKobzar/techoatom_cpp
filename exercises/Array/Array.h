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
		/*dump(); TODO:dump*/		\
		assert(!"Object is OK");	\
		}

template <typename T, const size_t capacity>
class Array
{
public:
	using iterator = T*;
	
	typedef T value_type;
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
	void fill(const value_type& value);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns a reference to the element
	//! @param n is position of the element to return
	//! @return reference to the requested element
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	value_type &operator[](size_type const n);

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
	//! Size setter
	//! @param size of the Arary
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void set_size(size_type s);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Size getter
	//! @param size of the Arary
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_type get_size() const;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Max size getter
	//! @param max size of the Arary
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_type max_size() const;

	iterator begin();
	iterator end();

private:
	size_t size_;
	value_type data_[capacity];
	bool valid_;
};

const int POISON_INT = 100500; //???
const size_t POISON_SIZE = 100500; //???

template <typename value_type, const size_t capacity>
Array<value_type, capacity>::Array()
	:size_(capacity),
	valid_(true)
{
	for (size_type i = 0; i != capacity; ++i)
		data_[i] = 0;
}

template <typename value_type, const size_t capacity>
Array<value_type, capacity>::Array(const size_type size)
	:size_(size),
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
Array<value_type, capacity>::Array(const Array<value_type, capacity> &other)
	:size_(other.size_),
	valid_(other.valid_)
{
	for (int i = 0; i != size_; ++i)
		data_[i] = other.data_[i];
}

template <typename value_type, const size_t capacity>
Array<value_type, capacity>::~Array()
{
	for (size_type i = 0; i != capacity; ++i)
		data_[i] = POISON_INT;
	
	size_ = POISON_SIZE;
	valid_ = false;
}

template <typename value_type, const size_t capacity>
void Array<value_type, capacity>::fill(const value_type& value)
{
	ASSERT_OK_ARR();

	for (int i = 0; i != capacity; ++i)
		data_[i] = value;
}

template<typename value_type, const size_t capacity>
typename  Array<value_type, capacity>::value_type &Array<value_type, capacity>::operator[](size_type const n)
{
	if (n >= size_)
		valid_ = false;

	ASSERT_OK_ARR();

	return data_[n];
}

template<typename value_type, const size_t capacity>
Array<value_type, capacity> &Array<value_type, capacity>::operator=(Array<value_type, capacity> const &other)
{
	if (this != &other) {
		Array(other).swap(*this);
	}
	return *this;
}

template<typename value_type, const size_t capacity>
bool Array<value_type, capacity>::operator==(Array const &other) const
{
	if (this -> size_ != other.size_)
		return false;

	for (int i = 0; i != size_; ++i)
		if (this->data_[i] != other.data_[i])
			return false;

	return true;
}

template<typename value_type, const size_t capacity>
void Array<value_type, capacity>::swap(Array<value_type, capacity> &other)
{
	std::swap(size_, other.size_);
	std::swap(data_, other.data_);
	std::swap(valid_, other.valid_);
}

template<typename value_type, const size_t capacity>
void Array<value_type, capacity>::set_size(size_type s)
{
	if (s > capacity)
		valid_ = false;

	size_ = s;
}

template<typename value_type, const size_t capacity>
typename Array<value_type, capacity>::size_type Array<value_type, capacity>::get_size() const
{
	return size_;
}

template<typename value_type, const size_t capacity>
typename Array<value_type, capacity>::size_type Array<value_type, capacity>::max_size() const
{
	return capacity;
}

template<typename value_type, const size_t capacity>
bool Array<value_type, capacity>::ok() const
{
	return valid_;
}

template<typename value_type, const size_t capacity>
typename Array<value_type, capacity>::iterator Array<value_type, capacity>::begin()
{
	return data_;
}

template<typename value_type, const size_t capacity>
typename Array<value_type, capacity>::iterator Array<value_type, capacity>::end()
{
	return data_+size_;
}