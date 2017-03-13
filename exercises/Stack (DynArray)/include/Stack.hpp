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
//        using size_t POISON_INT = 1322;
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
        const value_type *top() const;

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
        // bool operator==(value_type const &rhs) const;

        //---------------------------------------------
        //! @Debug
        //---------------------------------------------
        // bool is_valid();
        // bool dump();

    private:
        size_t      size_;
        container   data_;
    };


    template <typename value_type>
    Stack<value_type>::Stack(size_t capacity)
    : size_(0) {
        container data_(capacity);
    }

    template <typename value_type>
    Stack<value_type>::Stack(Stack<value_type> const &other)
        : size_(other.size()) {
        container data_(other.capacity());
        for (size_t i = 0; i != data_.size(); ++i) {
            ASSERT_TRUE(other.pop());
            data_.push(other.top());
        }
    }

    template <typename value_type>
    Stack<value_type>::~Stack() {
        size_ = 1322;
    }

    template <typename value_type>
    const value_type *Stack<value_type>::top() const {
       if(size_ == 0) {
           return nullptr;
       }
       else {
            return &data_[size_];
       }
    }

//     template <typename value_type>
//     value_type const Stack<value_type>::top() const {
// //        if(size_ == 0) {
// //            return nullptr;
// //        }
// //        else {
//             return data_[size_];
// //        }
//     }

    template <typename value_type>
    bool Stack<value_type>::empty() const {
        if(size_ == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    template <typename value_type>
    bool Stack<value_type>::full() const {
        if(size_ == data_.size()) {
            return true;
        }
        else {
            return false;
        }
    }

    template <typename value_type>
    size_t Stack<value_type>::size() const {
        return size_;
    }

    template <typename value_type>
    size_t Stack<value_type>::capacity() const {
        return data_.size();
    }

    template <typename value_type>
    bool Stack<value_type>::push(value_type &value) {
        if(size_ == data_.size()) {
            return false;
        }
        else {
            data_[size_++] = value;
            return true;
        }
    }

    template <typename value_type>
    bool Stack<value_type>::pop() {
        if(size_ == 0)
            return false;
        else {
            size_--;
            return true;
        }
    }

    template <typename value_type>
    void Stack<value_type>::swap(Stack<value_type> &other) {
        std::swap(size_,     other.size_);
        std::swap(data_,     other.data_);
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
