//---------------------------------------------
//! @IDE CLion
//! @file Stack.hpp
//! Header file with Stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

class Stack
{
public:

//    value_type	Container::value_type
//    size_type	Container::size_type
//    reference	Container::reference
//    const_reference	Container::const_reference

    typedef float value_type;
    typedef int size_type;

    //---------------------------------------------
    //! @Constructor
    //---------------------------------------------
    Stack()
    {
        size_ = 0;
    }

    //---------------------------------------------
    //! @Element_access
    //---------------------------------------------
    value_type *top();

    //---------------------------------------------
    //! @Capacity
    //---------------------------------------------
    bool empty();
    size_type size();

    //---------------------------------------------
    //! @Modifiers
    //---------------------------------------------
    bool push(value_type& value);
    bool pop();

private:
    static const size_type capacity_ = 10;
    value_type data_ [capacity_];
    size_type size_;

};

#endif //STACK_STACK_HPP
