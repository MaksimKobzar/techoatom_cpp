//---------------------------------------------
//! @IDE CLion
//! @file Array.hpp
//! Header file with Array class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#define DEBUG
#include <iostream>
#include <cassert>
#include <string>


//----------------------------------------------------------------------
//! Macros to check validity of index ranges
//----------------------------------------------------------------------
#define CHECK_RANGE( index_value, size_value ) {\
    if (index_value < 0 || index_value >= size_value) {\
        dump(__FILE__, __func__, __LINE__);\
        assert(!"Invalid index");\
        throw std::exception();\
    }\
}\

//----------------------------------------------------------------------
//! Debug macros
//----------------------------------------------------------------------
#ifdef DEBUG \
    #define DEBUG_INFO( message ) {\
        while(1) {\
            std::cout << "DEBUG_INFO: " << message << "(file "<< __FILE__ <<" ,line " << __LINE__ << "."<< std::endl;\
            break;\
        }\
    }
#endif


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
        std::string dump(std::string fileName, std::string funcName, std::string lineNumber) const;

    private:
        size_t      size_;
        value_type *data_;
    };

    //----------------------------------------------------------
    // Definitions
    //----------------------------------------------------------
    template<typename value_type>
    Array<value_type>::Array(size_t size)
            : size_(size) {
        // DEBUG_INFO("Array - start default constructor");

        data_ = new value_type[size_];
        #ifdef DEBUG
        for (size_t i = 0; i != size_; ++i) {
            data_[i] = 0;
        }
        #endif
        
        // DEBUG_INFO("Array - end default constructor");
    }

    template<typename value_type>
    Array<value_type>::Array(Array<value_type> const &other)
            : size_(other.size_) {
        // DEBUG_INFO("Array - start constructor of copy");

        data_ = new value_type[size_];
        for (size_t i = 0; i != size_; ++i) {
            data_[i] = other.data_[i];
        }
        
        // DEBUG_INFO("Array - end constructor of copy");
    }

    template<typename value_type>
    Array<value_type>::~Array() {
        // DEBUG_INFO("Array - start destructor");

        delete [] data_;
        
        // DEBUG_INFO("Array - end destructor");
    }

    template<typename value_type>
    Array<value_type> &Array<value_type>::operator=(Array<value_type> const &other) {
        // DEBUG_INFO("Array - start operator=");
        
        if(this != &other) {
            Array(other).swap(*this);
        }

        // DEBUG_INFO("Array - end operator=");
        return *this;
    }

    // What if func would get index out of valid range?
    template<typename value_type>
    value_type &Array<value_type>::operator[](int index) {
        // DEBUG_INFO("Array - operator[]");
        
        CHECK_RANGE(index, size_);
        return data_[index];
    }

    // Compilation error with const Array a;
    template<typename value_type>
    value_type const &Array<value_type>::operator[](int index) const {
        // DEBUG_INFO("Array - const operator[]");
        
        CHECK_RANGE(index, size_);
        return data_[index];
    }

    template<typename value_type>
    bool Array<value_type>::operator==(Array<value_type> const &other) const {
        // DEBUG_INFO("Array - operator==");

        if(this == &other) {
            return true;
        }
        if(this.size_ != other.size_) {
            return false;
        }
        for (size_t i = 0; i != size_; ++i) {
            if(data_[i] != other.data_[i]) {
                return false;
            }
        }
        return true;
    }

    template<typename value_type>
    void Array<value_type>::swap(Array &other) {
        // DEBUG_INFO("Array - start swap");
        
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
        
        // DEBUG_INFO("Array - end swap");
    }

    template<typename value_type>
    size_t Array<value_type>::size() const {
        // DEBUG_INFO("Array - size");
        
        return size_;
    }

    template<typename value_type>
    std::string Array<value_type>::dump(std::string fileName, std::string funcName, std::string lineNumber) const {
        std::string dumpText; // TODO
        // dumpText << "DUMP: size_ = " << size_ << std::endl; // TODO
        return dumpText;
    }


} // end sns

#endif // _ARRAY_HPP_
