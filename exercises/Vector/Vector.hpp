//---------------------------------------------
//! @IDE CLion
//! @file Vector.hpp
//! Header file with Vector class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#define NDEBUG
#include <iostream>
#include <cassert>
#include <string>

//------------------------------------------------------------
//! @namespace
//! Stack name space
//------------------------------------------------------------
namespace sns
{


//----------------------------------------------------------------------
//! Macros to check validity of index ranges
//----------------------------------------------------------------------
#define CHECK_RANGE( index_value, size_value ) {\
    if (index_value < 0 || index_value >= size_value) {\
        Vector::dump(__FILE__, __func__, __LINE__);\
        assert(!"Invalid index");\
        throw std::exception();\
    }\
}\

//----------------------------------------------------------------------
//! Debug macros
//----------------------------------------------------------------------
# ifdef NDEBUG
    #define DEBUG_INFO( message ) {\
        while(1) {\
            std::cout << "DEBUG_INFO: " << message << "(file "<< __FILE__ <<" ,line " << __LINE__ << "."<< std::endl;\
            break;\
        }\
    }
# endif


    template<
        typename T = int
    >class Vector
    {
        typedef T value_type;
    public:
        //---------------------------------------------
        //! @Constructor
        //! Create class Vector with dynamic allocation of memory
        //---------------------------------------------
        explicit Vector(int size);

        //---------------------------------------------
        //! Constructor of copy
        //---------------------------------------------
        Vector(const Vector &other);

        //---------------------------------------------
        //! @Destructor
        // Free memory
        //---------------------------------------------
        ~Vector();

        //---------------------------------------------
        //! @Operators:
        //! 1) operator =
        //! 2) operator []
        //! 3) operator ==
        //---------------------------------------------
        Vector &operator=(Vector const &other);
        value_type &operator[](int const index);
        value_type const &operator[](int const index) const;
        bool operator==(Vector const &other) const;

        //---------------------------------------------
        //! @Modifiers
        //! Swaps the contents
        //---------------------------------------------
        void swap(Vector &other);
        //---------------------------------------------

        //---------------------------------------------
        //! @Access functions
        //! Return size of Vector
        //---------------------------------------------
        int size() const;

        //---------------------------------------------
        //! @Debug
        //! Return pointer to dumped text
        //---------------------------------------------
        std::string dump(std::string fileName, std::string funcName, int lineNumber) const;

    private:
        int      size_;
        value_type *data_;
    };

    //----------------------------------------------------------
    // Definitions
    //----------------------------------------------------------
    template<typename value_type>
    Vector<value_type>::Vector(int size)
            : size_(size) {
        // DEBUG_INFO("Vector - start default constructor");

        data_ = new value_type[size_];
        #ifdef NDEBUG
        for (int i = 0; i != size_; ++i) {
            data_[i] = 0;
        }
        #endif

        // DEBUG_INFO("Vector - end default constructor");
    }

    template<typename value_type>
    Vector<value_type>::Vector(const Vector<value_type> &other)
            : size_(other.size_) {
        // DEBUG_INFO("Vector - start constructor of copy");

        data_ = new value_type[size_];
        for (int i = 0; i != size_; ++i) {
            data_[i] = other.data_[i];
        }

        // DEBUG_INFO("Vector - end constructor of copy");
    }

    template<typename value_type>
    Vector<value_type>::~Vector() {
        // DEBUG_INFO("Vector - start destructor");

        delete [] data_;

        // DEBUG_INFO("Vector - end destructor");
    }

    template<typename value_type>
    Vector<value_type> &Vector<value_type>::operator=(Vector<value_type> const &other) {
        // DEBUG_INFO("Vector - start operator=");

        if(this != &other) {
            Vector(other).swap(*this);
        }

        // DEBUG_INFO("Vector - end operator=");
        return *this;
    }

    // What if func would get index out of valid range?
    template<typename value_type>
    value_type &Vector<value_type>::operator[](int index) {
        // DEBUG_INFO("Vector - operator[]");

        CHECK_RANGE(index, size_);
        return data_[index];
    }

    // Compilation error with const Vector a;
    template<typename value_type>
    value_type const &Vector<value_type>::operator[](int index) const {
        // DEBUG_INFO("Vector - const operator[]");

        CHECK_RANGE(index, size_);
        return data_[index];
    }

    template<typename value_type>
    bool Vector<value_type>::operator==(Vector<value_type> const &other) const {
        // DEBUG_INFO("Vector - operator==");

        if(this == &other) {
            return true;
        }
        if(this.size_ != other.size_) {
            return false;
        }
        for (int i = 0; i != size_; ++i) {
            if(data_[i] != other.data_[i]) {
                return false;
            }
        }
        return true;
    }

    template<typename value_type>
    void Vector<value_type>::swap(Vector<value_type> &other) {
        // DEBUG_INFO("Vector - start swap");

        std::swap(size_, other.size_);
        std::swap(data_, other.data_);

        // DEBUG_INFO("Vector - end swap");
    }

    template<typename value_type>
    int Vector<value_type>::size() const {
        // DEBUG_INFO("Vector - size");

        return size_;
    }

    template<typename value_type>
    std::string Vector<value_type>::dump(std::string fileName, std::string funcName, int lineNumber) const {
        std::string dumpText; // TODO
        // dumpText << "DUMP: size_ = " << size_ << std::endl; // TODO
        return dumpText;
    }


} // end sns

#endif // _VECTOR_HPP_
