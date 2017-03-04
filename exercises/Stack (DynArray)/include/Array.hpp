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
#include <cassert>
#include <string>


//----------------------------------------------------------------------
//! Macros to check validity of index ranges
//----------------------------------------------------------------------
#define CHECK_RANGE( index_value, size_value ) {\
    if (index_value < 0 || index_value >= size_value) {\
        dump(__func__);\
        assert(!"Invalid index");\
        // throw std::exception();\
    }\
}

//----------------------------------------------------------------------
//! Debug macros
//----------------------------------------------------------------------
#define DEBUG_INFO ( message ) {\
    #ifndef NDEBUG \
    std::cout << "DEBUG_INFO: " << message << std::end \
    #endif \
} \

//------------------------------------------------------------
//! @namespace
//! Stack name space
//------------------------------------------------------------
namespace sns
{

    template<
        typename T = int
    >class Array
    {
        typedef T value_type;
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
        Array &operator=(Array const &other);
        value_type &operator[](int const index);
        value_type const &operator[](int const index) const;
        bool operator==(Array const &other) const;

        //---------------------------------------------
        //! @Modifiers
        //! Swaps the contents
        //---------------------------------------------
        void swap(Array &other);
        //---------------------------------------------

        //---------------------------------------------
        //! @Access functions
        //! Return size of Array
        //---------------------------------------------
        size_t size() const;

        //---------------------------------------------
        //! @Debug
        //! Return pointer to dumped text
        //---------------------------------------------
        string *dump();

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
        DEBUG_INFO("Array - start default constructor");
        std::cout << "Default constructor" << std::endl;
        for (size_t i = 0; i != size_; ++i) {
            data_[i] = 0;
        }
        DEBUG_INFO("Array - end default constructor");
    }

    template<typename value_type>
    Array<value_type>::Array(Array<value_type> const &other)
            : size_(other.size_), data_(new value_type[size_]) {
        DEBUG_INFO("Array - start constructor of copy");
        std::cout << "Copy constructor" << std::endl;
        for (size_t i = 0; i != size_; ++i) {
            data_[i] = other.data_[i];
        }
        DEBUG_INFO("Array - end constructor of copy");
    }

    template<typename value_type>
    Array<value_type>::~Array() {
        DEBUG_INFO("Array - start destructor");
        delete [] data_;
        DEBUG_INFO("Array - end destructor");
    }

    template<typename value_type>
    Array<value_type> &Array<value_type>::operator=(Array<value_type> const &other) {
        DEBUG_INFO("Array - start operator=");
        std::cout << "Operator =" << std::endl;
        if(this != &other) {
            Array(other).swap(*this);
        }
        DEBUG_INFO("Array - end operator=");
        return *this;
    }

    // What if func would get index out of valid range?
    template<typename value_type>
    value_type &Array<value_type>::operator[](int index) {
        CHECK_RANGE(index, size_);
        DEBUG_INFO("Array - operator[]");
        return data_[index];
    }

    // Compilation error with const Array a;
    template<typename value_type>
    value_type const &Array<value_type>::operator[](int index) const {
        CHECK_RANGE(index, size_);
        DEBUG_INFO("Array - const operator[]");
        return data_[index];
    }

    template<typename value_type>
    bool Array<value_type>::operator==(Array<value_type> const &other) const {
        DEBUG_INFO("Array - operator==");
        if(this.size_ == other.size_) {
            for (size_t i = 0; i != size_; ++i) {
                if(data_[i] != other.data_[i]) {
                    return 0;
                }
            }
            return 1;
        } 
        return 0;
    }

    template<typename value_type>
    void Array<value_type>::swap(Array &other) {
        DEBUG_INFO("Array - start swap");
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
        DEBUG_INFO("Array - end swap");
    }

    template<typename value_type>
    size_t Array<value_type>::size() const {
        DEBUG_INFO("Array - size");
        return size_;
    }

    template<typename value_type>
    string *Array<value_type>::dump() const {
        string *dumpText = new [100]; // TODO
        dumpText << "DUMP: size_ = " << size_ << std::endl; // TODO
        return dumpText;
    }


} // end sns

#endif // _ARRAY_HPP_
