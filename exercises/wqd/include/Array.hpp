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
        typename Tvalue = int
    >class Array
    {
        typedef value_type = Tvalue;
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
        value_type &operator[] (int const index);
        value_type const &operator[] (int const index) const;
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
        size_t      size_;
        value_type *data_;
    };

    //----------------------------------------------------------
    // Definitions
    //----------------------------------------------------------
    template<typename value_type>
    Array<value_type>::Array(size_t size)
            : size_(size), data_(new value_type[size_]) {
        std::cout << "Default constructor" << std::endl;
        for (int i = 0; i != size_; ++i) {
            data_[i] = 0;
        }
    }

    template<typename value_type>
    Array<value_type>::Array(Array<value_type> const &other)
            : size_(other.size_), data_(new value_type[size_]) {
        std::cout << "Copy constructor" << std::endl;
        for (int i = 0; i != size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    template<typename value_type>
    Array<value_type>::~Array() {
        std::cout << "Destructor" << std::endl;
        delete [] data_;
    }

    template<typename value_type>
    Array<value_type> &Array<value_type>::operator=(Array<value_type> const &other) {
        std::cout << "Operator =" << std::endl;
        if(this != &other) {
            Array(other).swap(*this);
        }
        return *this;
    }

    // What if func would get index out of valid range?
    template<typename value_type>
    value_type &Array<value_type>::operator[](int const index) {
        assert()
        return data_[index];
    }

    // Compilation error with const Array a;
    template<typename value_type>
    value_type const &Array<value_type>::operator[](int const index) const {
        assert()
        return data_[index];
    }

    template<typename value_type>
    void Array<value_type>::swap(Array &other) {
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }

    template<typename value_type>
    size_t Array<value_type>::size() const {
        return size_;
    }


} // end sns

#endif // _ARRAY_HPP_
