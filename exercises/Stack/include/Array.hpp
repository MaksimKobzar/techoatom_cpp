//---------------------------------------------
//! @IDE CLion
//! @file Array.hpp
//! Header file with Array class.
//!
//! @author Maksim Kobzar, 2017
//---------------------------------------------

#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

template <
    typename Ttype = int
>class Array
{
public:
    //---------------------------------------------
    //! @Constructor
    //! Create class Array with dynamic allocation of memory.
    //---------------------------------------------
    explicit Array(size_t size);

    //---------------------------------------------
    //! Constructor of copy.
    //---------------------------------------------
    Array(Array const &that);

    //---------------------------------------------
    //! @Destructor
    // Free memory.
    //---------------------------------------------
    ~Array();

    //---------------------------------------------
    //! @Operators:
    //! 1) operator = 
    //! 2) operator + 
    //! 3) operator - 
    //---------------------------------------------
    &Array operator= (Array const &that);
    // &Array operator+ (const &Array);
    // &Array operator- (const &Array);

    //---------------------------------------------
    //! @Swap
    //! Swap 2 examplar of class Array 
    //---------------------------------------------
    void swap(&Array that);

    //---------------------------------------------
    //! @Size
    //! Return size of Array.
    //---------------------------------------------
    size_t size() const;

private:
    size_t   size_;
    Ttype   *data_;

};




template<typename Ttype>
explicit Array<Ttype>::Array(size_t size)
: size_(size), data_(new <Ttype>[size_]) {
    for (int i = 0; i != size_; ++i) {
        data_[i] = 0;
    }
}

template<typename Ttype>
Array<Ttype>::Array(Array<Ttype> const &that) 
: size_(that.size_), data_(new <Ttype>[size_]) {
    for (int i = 0; i != size_; ++i) {
        data_[i] = that.data_[i];
    }
}

template<typename Ttype>
Array<Ttype>::~Array() {
    delete [] data_;
}

template<typename Ttype>
Array<Ttype> &Array<Ttype>::operator=(Array<Ttype> const &that) {
    if(this != &that) {
        Array(that).swap(*this);            
    }
    return *this;
}

template<typename Ttype>
size_t Array<Ttype>::size() const {
    return size_;
}



#endif //Array_HPP_
