//---------------------------------------------
//! @IDE CLion
//! @file Vector.hpp
//! Header file with Vector class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _VECTOR_BOOL_HPP_
#define _VECTOR_BOOL_HPP_

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include "BoolOperation.hpp"

//#define NDEBUG

//------------------------------------------------------------
//! @namespace
//! Stack name space
//------------------------------------------------------------
namespace sns
{


//----------------------------------------------------------------------
//! Macros to check validity of index ranges
//----------------------------------------------------------------------
#define CHECK_RANGE( index_value, size_value ) \
    if (0 > index_value || index_value >= size_value) {\
        Vector::dump(__FILE__, __func__, __LINE__);\
        assert(!"Invalid index");\
        throw std::exception();\
    }

//----------------------------------------------------------------------
//! Print debug macros
//----------------------------------------------------------------------
# define DEBUG_INFO(message)\
do {\
    std::cout << "DEBUG_INFO: " << message << "(file "<< __FILE__ <<" ,line " << __LINE__ << ")."<< std::endl;\
} while (0)


    template<>
    class Vector<bool>
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
        BoolOperation operator[](int const index);
        BoolOperation const &operator[](const size_t index) const;
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
        char    *data_;
    };

    //----------------------------------------------------------
    // Definitions for Vector<bool>
    //----------------------------------------------------------
        Vector<bool>::Vector(size_t size)
                : size_(size/UNSIGNED_WIDTH + 1) {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - start default constructor");
            #endif

            data_ = new unsigned[size_];
            #ifdef NDEBUG
            for (size_t i = 0; i != size_; ++i)
            {
                data_[i] = 0;
            }
            #endif

            #ifdef NDEBUG
                DEBUG_INFO("Vector - end default constructor");
            #endif
        }

        Vector<bool>::Vector(const Vector<bool> &other)
                : size_(other.size_) {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - start constructor of copy");
            #endif

            data_ = new value_type[size_];
            for (int i = 0; i != size_; ++i) {
                data_[i] = other.data_[i];
            }

            #ifdef NDEBUG
                DEBUG_INFO("Vector - end constructor of copy");
            #endif
        }

        Vector<bool>::~Vector() {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - start destructor");
            #endif

            delete [] data_;

            #ifdef NDEBUG
                DEBUG_INFO("Vector - end destructor");
            #endif
        }

        Vector<bool> &Vector<bool>::operator=(const Vector<bool> &other)
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - start operator=");
            #endif

            if(this != &other) {
                Vector(other).swap(*this);
            }

            #ifdef NDEBUG
                DEBUG_INFO("Vector - end operator=");
            #endif
            return *this;
        }

        // rvalue
        // Vector b(20);
        // Vector c(20);
        // bool a = b[10]
        // b[7] = c[10]
        bool &Vector<bool>::operator[](const size_t index) const
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - const operator[]");
            #endif

            CHECK_RANGE(index, size_);
            return !!(data_[index/sizeof(unsigned)] & (1 << index%sizeof(unsigned)) );
        }

        // lvalue
        // Vetor a(20);
        // Vetor b(20);
        // bool c;
        // a[10] = b[6];
        // a[10] = c;
        BoolOperation Vector<bool>::operator[](const size_t index) const
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - operator[]");
            #endif

            CHECK_RANGE(index, size_);
            return BoolOperation(index, *this);
        }


        bool Vector<bool>::operator==(Vector<bool> const &other) const {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - operator==");
            #endif

            if(this == &other) {
                return true;
            }
            if(this->size_ != other.size_) {
                return false;
            }
            for (int i = 0; i != size_; ++i) {
                if(data_[i] != other.data_[i]) {
                    return false;
                }
            }
            return true;
        }

        void Vector<bool>::swap(Vector<bool> &other) {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - start swap");
            #endif

            std::swap(size_, other.size_);
            std::swap(data_, other.data_);

            #ifdef NDEBUG
                DEBUG_INFO("Vector - end swap");
            #endif
        }

        int Vector<bool>::size() const {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - size");
        #endif

            return size_;
        }

        std::string Vector<bool>::dump(std::string fileName, std::string funcName, int lineNumber) const {
            std::ostringstream oss;
            oss << "DUMP. Crash in "<< fileName << ", line " << lineNumber << ", function "
                << funcName << ".Internal vars: size = " << this->size() << ".";
            return(oss.str());
        }


} // end sns

#endif // _VECTOR_BOOL_HPP_
