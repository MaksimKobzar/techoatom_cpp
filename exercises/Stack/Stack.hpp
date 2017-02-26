//---------------------------------------------
//! @IDE CLion
//! @file Stack.hpp
//! Header file with Stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP
#endif //STACK_STACK_HPP


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
