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
    //! @Test
    //---------------------------------------------
    bool ok();
    bool dump();

private:
    const size_type capacity_;
    value_type data_ [capacity_];
    size_type size_;

};

#endif //STACK_STACK_HPP
