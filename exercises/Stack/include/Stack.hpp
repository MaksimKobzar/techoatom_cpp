//---------------------------------------------
//! @IDE CLion
//! @file Stack.hpp
//! Header file with Stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _STACK_HPP_
#define _STACK_HPP_


class Stack
{
public:

    typedef float value_type;
    typedef int size_type;

    //---------------------------------------------
    //! @Constructor
    //---------------------------------------------
    Stack();
    //---------------------------------------------
    //! @Destructor
    //---------------------------------------------
    ~Stack();

    //---------------------------------------------
    //! @Element_access
    //---------------------------------------------
    value_type *top();

    //---------------------------------------------
    //! @Capacity
    //---------------------------------------------
    bool empty();
    size_type size();
    size_type capacity();

    //---------------------------------------------
    //! @Modifiers
    //---------------------------------------------
    bool push(value_type& value);
    bool pop();

    //---------------------------------------------
    //! @Debug
    //---------------------------------------------
    bool ok();
    bool dump();

private:
    static const size_type capacity_ = 50;
    value_type data_ [capacity_];
    size_type size_;

};

#endif //_STACK_HPP_
