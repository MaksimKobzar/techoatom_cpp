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
        typename Tvalue = int
    >class Stack
    {
        typedef Tvalue value_type;
        typedef Array<Tvalue> Tcontainer;
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
        value_type *top() const;

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
        // bool operator==(Stack<value_type> &lhs, Stack<value_type> &rhs);

        //---------------------------------------------
        //! @Debug
        //---------------------------------------------
        // bool ok();
        // bool dump();

    private:
        value_type capacity_;
        size_t     size_;
        Tcontainer *data_;
    };


    template <typename value_type>
    Stack<value_type>::Stack(size_t capacity)
    : capacity_(capacity), size_(0), data_(new Tcontainer(capacity)) { }

    template <typename value_type>
    Stack<value_type>::Stack(Stack<value_type> const &other)
    : capacity_(other.capacity_), size_(other.size_), data_(Tcontainer(capacity)) { }

    template <typename value_type>
    Stack<value_type>::~Stack() { }

    template <typename value_type>
    value_type *Stack<value_type>::top() const {
        if(size_ == 0) {
            return nullptr;
        }
        else {
            return &data_[size_];
        }
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
        std::swap(data_,     other.data_);
    }

    template <typename value_type>
    Stack<value_type> &Stack<value_type>::operator=(Stack<value_type> const &other) {
        if(this != &other) {
            Stack(other).swap(*this);
        }
        return *this;
    }

    // template <typename value_type>
    // bool operator==(Stack<value_type> &lhs, Stack<value_type> &rhs) {
    //     return( lhs.size_       == rhs.size_ &&
    //         // lhs.capacity_   == rhs.capacity_ && // Do we need to check capacity?
    //             lhs.data_ == rhs.data_);
    // }

} // end sns

#endif //_STACK_HPP_
