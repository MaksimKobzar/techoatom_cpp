//---------------------------------------------
//! @IDE CLion
//! @file Array.hpp
//! Header file with Array class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#define NDEBUG
#include <iostream>

//------------------------------------------------------------
//! @namespace
//! Stack name space
//------------------------------------------------------------
namespace sns
{


    template<
            typename Ttype = int
    >class Array
    {
    public:
        //---------------------------------------------
        //! @Constructor
        //! Create class Array with dynamic allocation of memory
        //---------------------------------------------
        explicit Array(size_t size);

        //---------------------------------------------
        //! Constructor of copy
        //---------------------------------------------
        Array(Array const &other);

        //---------------------------------------------
        //! @Destructor
        // Free memory
        //---------------------------------------------
        ~Array();

        //---------------------------------------------
        //! @Operators:
        //! 1) operator =
        //! 2) operator []
        //! 3) operator ==
        //---------------------------------------------
        Array &operator=  (Array const &other);
        Ttype &operator[] (int const index);
        Ttype const &operator[] (int const index) const;
        // &Array operator== (Array const &other);

        //---------------------------------------------
        //! @Swap
        //! Swaps the contents
        //---------------------------------------------
        void swap(Array &other);

        //---------------------------------------------
        //! @Size
        //! Return size of Array
        //---------------------------------------------
        size_t size() const;

    private:
        size_t   size_;
        Ttype   *data_;
    };

    //----------------------------------------------------------
    // Definitions
    //----------------------------------------------------------
    template<typename Ttype>
    Array<Ttype>::Array(size_t size)
            : size_(size), data_(new Ttype[size_]) {
        std::cout << "Default constructor" << std::endl;
        for (int i = 0; i != size_; ++i) {
            data_[i] = 0;
        }
    }

    template<typename Ttype>
    Array<Ttype>::Array(Array<Ttype> const &other)
            : size_(other.size_), data_(new Ttype[size_]) {
        std::cout << "Copy constructor" << std::endl;
        for (int i = 0; i != size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    template<typename Ttype>
    Array<Ttype>::~Array() {
        std::cout << "Destructor" << std::endl;
        delete [] data_;
    }

    template<typename Ttype>
    Array<Ttype> &Array<Ttype>::operator=(Array<Ttype> const &other) {
        std::cout << "Operator =" << std::endl;
        if(this != &other) {
            Array(other).swap(*this);
        }
        return *this;
    }

    // What if func would get index out of valid range?
    template<typename Ttype>
    Ttype &Array<Ttype>::operator[](int const index) {
        return data_[index];
    }

    // Compilation error with const Array a; 
    template<typename Ttype>
    Ttype const &Array<Ttype>::operator[](int const index) const {
        return data_[index];
    }

    template<typename Ttype>
    void Array<Ttype>::swap(Array &other) {
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }

    template<typename Ttype>
    size_t Array<Ttype>::size() const {
        return size_;
    }


} // end sns

#endif // _ARRAY_HPP_
