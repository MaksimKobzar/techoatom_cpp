//---------------------------------------------
//! @IDE CLion
//! @file Stack.hpp
//! Header file with Stack class
//!
//! @author Maksim_Kobzar, 2017
// TODO
// - operator new
// - copy constructor
// - operator ==
//---------------------------------------------

#ifndef _STACK_HPP_
#define _STACK_HPP_

#include "Vector.hpp"
#include <iostream>
#include <cassert>
#include <string>

//#define NDEBUG

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
        using container = Vector<T>;
        using value_type =  T;
        const int POISON_VALUE = 1322;
    public:
        //---------------------------------------------
        //! @Constructor
        //---------------------------------------------
        explicit Stack(int capacity);

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
        bool    empty()     const;
        bool    full()      const;
        int     size()      const;
        int     capacity()  const;

        //---------------------------------------------
        //! @Modifiers
        //---------------------------------------------
        bool push(const value_type &value);
        bool pop();
        void swap(Stack &other);

        //---------------------------------------------
        //! @Operators
        //! 1) operator=
        //! 2) operator==
        //---------------------------------------------
        Stack &operator=(Stack const &other);
        bool   operator==(Stack const &other) const;
        
        void  *operator new(size_t size, void *pdst);
        void operator delete(void*);

        //---------------------------------------------
        //! @Debug
        //---------------------------------------------
        bool is_valid() const;
        bool dump(std::string fileName, std::string funcName, int lineNumber) const;

    private:
        int         size_;
        container   data_;
    };


    template <typename value_type>
    Stack<value_type>::Stack(int capacity)
        : size_(0), data_(container(capacity)) { }

    template <typename value_type>
    Stack<value_type>::Stack(const Stack &other)
    {
      void * p = static_cast<void*>(data_);
      new (p) Vector(*reinterpret_cast<const Vector *>(other.data_));
    }

    template <typename value_type>
    Stack<value_type>::~Stack() {
    # ifdef NDEBUG
        size_ = POISON_VALUE;
    # endif
    }

    template <typename value_type>
    const value_type *Stack<value_type>::top() const {
       if(size_ == 0) {
           return nullptr;
       }
       else {
            return &data_[size_-1];
       }
    }

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
    int Stack<value_type>::size() const {
        return size_;
    }

    template <typename value_type>
    int Stack<value_type>::capacity() const {
        return data_.size();
    }

    template <typename value_type>
    bool Stack<value_type>::push(const value_type &value) {
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
    Stack<value_type> &Stack<value_type>::operator=(const Stack<value_type> &other) {
        if(this != &other) {
            Stack<value_type>(other).swap(*this);
        }
        return *this;
    }

    template <typename value_type>
    bool Stack<value_type>::operator==(const Stack<value_type> &other) const {
        if( this->size()       == other.size()       &&
            this->capacity()   == other.capacity()   &&
            this->data_        == other.data_        ) {
            return true;
        }
        return false ;
    }

    template <typename value_type>
    void  *operator new(int size, void *placement) {

    }

    template <typename value_type>
    bool Stack<value_type>::is_valid() const {
        if(size() <= capacity()) {
            return true;
        }
        return false;
    }

    template <typename value_type>
    bool Stack<value_type>::dump(std::string fileName, std::string funcName, int lineNumber) const {
        std::ostringstream oss;
        oss << "DUMP. Crash in "<< fileName << ", line " << lineNumber << ", function "
            << funcName << ".Internal vars: size = " << this->size() << ", capacity = " << this->capacity() << ".";
        return(oss.str());
    }

} // end sns

#endif //_STACK_HPP_
