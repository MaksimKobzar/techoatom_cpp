//---------------------------------------------
//! @IDE CLion
//! @file Stack.hpp
//! Header file with Stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _STACK_HPP_
#define _STACK_HPP_

#include "Array.hpp"

//------------------------------------------------------------
//! @namespace
//! Stack name space
//------------------------------------------------------------
namespace sns
{

    template<
        typename T = int
    >class Stack
    {
        using value_type =  T;
        using container = Array<value_type>;
        using value_type = *reference;
        using const value_type = *const_reference;
    public:
        //---------------------------------------------
        //! @Constructor
        //---------------------------------------------
        explicit Stack(size_t capacity);

        //---------------------------------------------
        //! Constructor of copy
        //---------------------------------------------
        Stack(Stack const &other);

        //---------------------------------------------
        //! @Destructor
        //---------------------------------------------
        ~Stack();

        //---------------------------------------------
        //! @Element_access
        //---------------------------------------------
        reference top();
        const_reference top() const;

        //---------------------------------------------
        //! @Access functions
        //---------------------------------------------
        bool   empty()     const;
        bool   full()      const;
        size_t size()      const;
        size_t capacity()  const;

        //---------------------------------------------
        //! @Modifiers
        //---------------------------------------------
        bool push(value_type &value);
        bool pop();
        void swap(Stack &other);

        //---------------------------------------------
        //! @Operators
        //! 1) operator=
        //! 2) operator==
        //---------------------------------------------
        Stack &operator=(Stack const &other);
        bool operator==(Stack const &other) const;

        //---------------------------------------------
        //! @Debug
        //---------------------------------------------
        // bool ok();
        // bool dump();

    private:
        value_type capacity_;
        size_t     size_;
        container *data_;
    };


    template <typename value_type>
    Stack<value_type>::Stack(size_t capacity)
    : capacity_(capacity), size_(0), data_(new container(capacity)) { }

    template <typename value_type>
    Stack<value_type>::Stack(Stack<value_type> const &other)
    : capacity_(other.capacity_), size_(other.size_), data_(new container(other.capacity_)) { }

    template <typename value_type>
    Stack<value_type>::~Stack() { }

    template <typename value_type>
    reference Stack<value_type>::top() {
//        if(size_ == 0) {
//            return nullptr;
//        }
//        else {
            return data_[size_];
//        }
    }

    template <typename value_type>
    const_reference Stack<value_type>::top() const {
//        if(size_ == 0) {
//            return nullptr;
//        }
//        else {
            return data_[size_];
//        }
    }

    template <typename value_type>
    bool Stack<value_type>::empty() const {
        return size_ == 0;
    }

    template <typename value_type>
    bool Stack<value_type>::full() const {
        return size_ == capacity_;
    }

    template <typename value_type>
    size_t Stack<value_type>::size() const {
        return size_;
    }

    template <typename value_type>
    size_t Stack<value_type>::capacity() const {
        return capacity_;
    }

    template <typename value_type>
    bool Stack<value_type>::push(value_type &value) {
        if(size_ == capacity_) {
            return 0;
        }
        else {
            data_[size_++] = value;
            return 1;
        }
    }

    template <typename value_type>
    bool Stack<value_type>::pop() {
        if(size_ == 0)
            return 0;
        else {
            size_--;
            return 1;
        }
    }

    template <typename value_type>
    void Stack<value_type>::swap(Stack<value_type> &other) {
        std::swap(capacity_, other.capacity_);
        std::swap(size_,     other.size_);
        std::swap(data_,   other.data_);
    }

    template <typename value_type>
    Stack<value_type> &Stack<value_type>::operator=(Stack<value_type> const &other) {
        if(this != &other) {
            Stack<value_type>(other).swap(*this);
        }
        return *this;
    }

    template <typename value_type>
    bool Stack<value_type>::operator==(Stack<value_type> const &other) const {
        return( this.size_       == other.size_ &&
                this.capacity_   == other.capacity_ && // Do we need to check capacity?
                this.data_       == other.data_);
    }

} // end sns

#endif //_STACK_HPP_
