//---------------------------------------------
//! @IDE CLion
//! @file Vector.hpp
//! Header file with Vector class
//!
//! @author Maksim_Kobzar, 2017
// TODO
// - dump
//---------------------------------------------

#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>

#define NDEBUG


//----------------------------------------------------------------------
//! Macros to check validity of index ranges
//----------------------------------------------------------------------
#define CHECK_RANGE( index_value, size_value ) \
    if (0 >= index_value || index_value > size_value) {\
        Vector::dump(__FILE__, __func__, __LINE__);\
        assert(!"Invalid index");\
        throw std::exception();\
    }

//----------------------------------------------------------------------
//! Print debug macros
//----------------------------------------------------------------------
#define DEBUG_INFO( message )\
do {\
    std::cout << "DEBUG_INFO: " << message << "(file "<< __FILE__ <<" ,line " << __LINE__ << ")."<< std::endl;\
} while (0)


//------------------------------------------------------------
//! @namespace
//! Stack name space
//------------------------------------------------------------
namespace sns
{


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
        // void *operator new(size_t size, void *where_to_create);

        //---------------------------------------------
        //! Move constructor
        //---------------------------------------------
        Vector(const Vector &&other);

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
        value_type &operator[](const size_t index);
        value_type const &operator[](const size_t index) const;
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
        size_t size() const;
        value_type *begin() const;
        value_type *end() const;

        //---------------------------------------------
        //! @Debug
        //! Return pointer to dumped text
        //---------------------------------------------
        bool is_valid();
        std::string dump(std::string fileName, std::string funcName, size_t lineNumber) const;

    private:
        size_t      size_;
        value_type *data_;
    };


    //----------------------------------------------------------
    // Definitions
    //----------------------------------------------------------
    template<typename value_type>
    Vector<value_type>::Vector(int size) :
        size_(size) {
        #ifdef NDEBUG
            DEBUG_INFO("Vector -- constructor: create empty object");
        #endif // NDEBUG

        data_ = new value_type[size_];

        #ifdef NDEBUG
            for (int i = 0; i != size_; ++i) {
                data_[i] = 0;
            }
            DEBUG_INFO("Vector - end default constructor");
        #endif // NDEBUG
    }

    template<typename value_type>
    Vector<value_type>::Vector(const Vector<value_type> &other) :
        size_(other.size_) {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - start constructor of copy");
        #endif // NDEBUG

        data_ = new value_type[size_];
        for (int i = 0; i != size_; ++i) {
            data_[i] = other.data_[i];
        }

        #ifdef NDEBUG
            DEBUG_INFO("Vector - end constructor of copy");
        #endif // NDEBUG
    }

    template<typename value_type>
    Vector<value_type>::Vector(const Vector<value_type> &&other) :
        size_(other.size_) {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - start move constructor");
        #endif // NDEBUG

        data_ = new value_type[size_];
        for (int i = 0; i != size_; ++i) {
            data_[i] = other.data_[i];
        }

        #ifdef NDEBUG
            DEBUG_INFO("Vector - end move constructor");
        #endif // NDEBUG
    }





/*
    template<typename value_type>
    void *Vector<value_type>::Vector(const Vector<value_type> &other)
    {
        char buf[sizeof(other)]; // выделяю на стеке память под вектор
        new (buf) Vector;        // вызываю переопрделенный указатель ниже
        Vector *v = (Vector *)buf;
    }

    template<typename value_type>
    void *Vector<value_type>::operator new(void *where_to_create)
    {
        return where_to_create;
    }*/








    template<typename value_type>
    Vector<value_type>::~Vector()
    {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - start destructor");
        #endif // NDEBUG

        delete [] data_;

        #ifdef NDEBUG
            DEBUG_INFO("Vector - end destructor");
        #endif // NDEBUG
    }

    template<typename value_type>
    Vector<value_type> &Vector<value_type>::operator=(Vector<value_type> const &other)
    {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - start operator=");
        #endif // NDEBUG

        if(this != &other) {
            Vector(other).swap(*this);
        }

        #ifdef NDEBUG
            DEBUG_INFO("Vector - end operator=");
        #endif // NDEBUG
        return *this;
    }

    template<typename value_type>
    value_type &Vector<value_type>::operator[](const size_t index)
    {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - operator[]");
        #endif // NDEBUG

        CHECK_RANGE(index, size_);
        return data_[index];
    }

    template<typename value_type>
    value_type const &Vector<value_type>::operator[](const size_t index) const
    {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - const operator[]");
        #endif // NDEBUG

        CHECK_RANGE(index, size_);
        return data_[index];
    }

    template<typename value_type>
    bool Vector<value_type>::operator==(Vector<value_type> const &other) const
    {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - operator==");
        #endif // NDEBUG

        if(this == &other) {
            return true;
        }
        if(size_ != other.size_)
        {
            return false;
        }
        for (int i = 0; i != size_; ++i)
        {
            if(data_[i] != other.data_[i])
            {
                return false;
            }
        }
        return true;
    }

    template<typename value_type>
    void Vector<value_type>::swap(Vector<value_type> &other)
    {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - start swap");
        #endif // NDEBUG

        std::swap(size_, other.size_);
        std::swap(data_, other.data_);

        #ifdef NDEBUG
            DEBUG_INFO("Vector - end swap");
        #endif // NDEBUG
    }

    template<typename value_type>
    size_t Vector<value_type>::size() const
    {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - size");
        #endif // NDEBUG

        return size_;
    }

    template<typename value_type>
    value_type *Vector<value_type>::begin() const
    {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - start");
        #endif // NDEBUG
        return &data_[0];
    }

    template<typename value_type>
    value_type *Vector<value_type>::end() const
    {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - end");
        #endif // NDEBUG
        return &data_[size_];
    }

    template<typename value_type>
    bool Vector<value_type>::is_valid()
    {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - is_valid");
        #endif // NDEBUG
        return true;
    }

    template<typename value_type>
    std::string Vector<value_type>::dump(std::string fileName, std::string funcName, size_t lineNumber) const
    {
        std::ostringstream oss;
        oss << "DUMP. Crash in "<< fileName << ", line " << lineNumber << ", function "
            << funcName << ".Internal vars: size = " << this->size() << ".";
        return(oss.str());
    }


} // end sns

#include "Vector(bool).hpp"

#endif // _VECTOR_HPP_
