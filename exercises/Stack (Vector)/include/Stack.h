//---------------------------------------------
//! @IDE CLion
//! @file Stack.h
//! Header file with Stack class
//!
//! @author Maksim_Kobzar, 2017
// TODO: Move constructors
//---------------------------------------------

#ifndef _STACK_H_
#define _STACK_H_

#include "Vector.h"
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
        #ifdef NDEBUG
            const size_t POISON_VALUE = 1322;
        #endif // NDEBUG
    public:
        //---------------------------------------------
        //! @Constructor
        //---------------------------------------------
        explicit Stack(size_t capacity);

        //---------------------------------------------
        //! Constructor of copy
        //---------------------------------------------
        Stack(const Stack &other);

        //---------------------------------------------
        //! Move constructor
        //---------------------------------------------
        explicit Stack(container&& otherContainer);
        Stack(Stack&& other);

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
        size_t  size()      const;
        size_t  capacity()  const;

        //---------------------------------------------
        //! @Modifiers
        //---------------------------------------------
        bool push(const value_type &value);
        bool pop();
        void swap(Stack &other);
        bool resize(size_t size);

        //---------------------------------------------
        //! @Operators
        //! 1) operator=
        //! 2) operator==
        //! 3) placement new
        //---------------------------------------------
        const Stack &operator=(const Stack &other);
        bool         operator==(const Stack &other) const;
        void* operator new(size_t, void* where);

        //---------------------------------------------
        //! @Debug
        //---------------------------------------------
        bool is_valid() const;
        bool dump(std::string fileName, std::string funcName, int lineNumber) const;

    private:
        size_t      size_;
        container   data_;
    };


    template <typename value_type>
    Stack<value_type>::Stack(size_t capacity)
        : size_(0), data_(container(capacity)) { }

    template <typename value_type>
    Stack<value_type>::Stack(const Stack<value_type> &other)
        : size_(other.size_), data_(container(other.capacity()))
    {
        for (size_t i = 0; i != size(); ++i)
        {
            data_[i] = other.data_[i];
        }
    }

    template <typename value_type>
    Stack<value_type>::Stack(Stack&& other)
    {
        /* TODO */
    }

    template <typename value_type>
    Stack<value_type>::Stack(container&& otherContainer)
    {
        /* TODO */
    }

    template <typename value_type>
    Stack<value_type>::~Stack() {
        #ifdef NDEBUG
            size_ = POISON_VALUE;
        #endif
    }

    template <typename value_type>
    const value_type *Stack<value_type>::top() const
    {
       if(size_ == 0)
       {
           return nullptr;
       }
       else
       {
            return &data_[size_-1];
       }
    }

    template <typename value_type>
    bool Stack<value_type>::empty() const
    {
        if(size_ == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename value_type>
    bool Stack<value_type>::full() const
    {
        if(size_ == data_.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename value_type>
    size_t Stack<value_type>::size() const
    {
        return size_;
    }

    template <typename value_type>
    size_t Stack<value_type>::capacity() const
    {
        return data_.size();
    }

    template <typename value_type>
    bool Stack<value_type>::push(const value_type &value)
    {
        if(size_ == data_.size())
        {
            return false;
        }
        else
        {
            data_[size_++] = value;
            return true;
        }
    }

    template <typename value_type>
    bool Stack<value_type>::pop()
    {
        if(size_ == 0)
        {
            return false;
        }
        else
        {
            size_--;
            return true;
        }
    }

    template <typename value_type>
    void Stack<value_type>::swap(Stack<value_type> &other)
    {
        std::swap(size_,     other.size_);
        std::swap(data_,     other.data_);
    }

    template <typename value_type>
    bool Stack<value_type>::resize(size_t size)
    {
        if(size > size_)
        {
            return false;
        }
        else if(size == size_)
        {
            return true;
        }
        else
        {
            container newData(size);
            std::copy(data_.begin(), data_.end(), newData.begin());
            newData.swap(data_);
        }
    }


    template <typename value_type>
    const Stack<value_type> &Stack<value_type>::operator=(const Stack<value_type> &other)
    {
        if(this != &other)
        {
        //     Stack<value_type>(other).swap(*this);
            ~Stack();
            new (this) Stack(other);
        }
        return *this;
    }

    template <typename value_type>
    void* Stack<value_type>::operator new(size_t, void* where)
    {
       return where;
    }

    template <typename value_type>
    bool Stack<value_type>::operator==(const Stack<value_type> &other) const
    {
        if(size()       == other.size()     &&
           capacity()   == other.capacity() &&
           data_        == other.data_      )
        {
            return true;
        }
        return false ;
    }

    template <typename value_type>
    bool Stack<value_type>::is_valid() const {
        if(0 <= size_ && size_ <= capacity() && data_.is_valid())
        {
            return true;
        }
        return false;
    }

    template <typename value_type>
    bool Stack<value_type>::dump(std::string fileName, std::string funcName, int lineNumber) const
    {
        std::ostringstream oss;
        oss << "DUMP. Crash in "<< fileName << ", line " << lineNumber << ", function "
            << funcName << ".Internal vars: size = " << this->size() << ", capacity = " << this->capacity() << ".";
        return(oss.str());
    }

} // end sns

#endif //_STACK_H_
