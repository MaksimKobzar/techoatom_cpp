#include "stdafx.h"

template <typename T>
class shared_ptr
{
public:
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Element type
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	typedef T value_type;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Constructor
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	shared_ptr();

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Constructor with pointer
	//! @param pointer
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	shared_ptr(value_type* pointer);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Copy constructor
	//! @param other shared_ptr
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	shared_ptr(shared_ptr<value_type>& other);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Destructor
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	~shared_ptr();

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Operator =, shares ownership with other shared_ptr
	//! @param other shared_ptr
	//! @return other shared_ptr
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	shared_ptr<value_type> operator=(shared_ptr<value_type>& other);

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Operator *, dereferences the shared_ptr
	//! @return result of dereferencing the shared_ptr
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	value_type operator*() const;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns the stored pointer
	//! @return stored pointer
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	value_type* get() const;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns the number of shared_ptr objects referring to the same managed object
	//! @return number of shared_ptr objects
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	long use_count() const;

	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Checks whether the managed object is managed only by the current shared_ptr instance
	//! @return true if is the only shared_ptr instance managing the current object
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool unique() const;
private:
	value_type* ptr_;
	long *count_;
};

template<typename value_type>
shared_ptr<value_type>::shared_ptr()
	: ptr_(nullptr), count_(nullptr) {}

template<typename value_type>
shared_ptr<value_type>::shared_ptr(value_type* pointer)
	: ptr_(pointer), count_(new long(1)) {}

template<typename value_type>
shared_ptr<value_type>::shared_ptr(shared_ptr<value_type>& other)
	: count_(other.count_), ptr_(other.ptr_)
{
	(*count_)++;
}

template<typename value_type>
shared_ptr<value_type>::~shared_ptr()
{
	if (count_)
	{
		if (*count_ == 1)
		{
			delete count_;
			delete ptr_;
		}
		else (*count_)--;
	}
}

template<typename value_type>
shared_ptr<value_type> shared_ptr<value_type>::operator=(shared_ptr<value_type>& other)
{
	if (this != &other)
	{
		if (count_)
		{
			if (*count_ == 1)
			{
				delete count_;
				delete ptr_;
			}
			else (*count_)--;
		}

		ptr_ = other.ptr_;
		count_ = other.count_;
		(*count_)++;
	}
	return *this;
}

template<typename value_type>
typename shared_ptr<value_type>::value_type shared_ptr<value_type>::operator*() const
{
	return *ptr_;
}

template<typename value_type>
typename shared_ptr<value_type>::value_type* shared_ptr<value_type>::get() const
{
	return ptr_;
}

template<typename value_type>
long shared_ptr<value_type>::use_count() const
{
	return (count_) ? *count_ : 0;
}

template<typename value_type>
bool shared_ptr<value_type>::unique() const
{
	return (*count_ == 1);
}