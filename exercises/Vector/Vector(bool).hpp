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
//#ifndef DATA_WIDTH
//#define DATA_WIDTH 32
//#endif // DATA_WIDTH
const size_t DATA_WIDTH = 32;

//------------------------------------------------------------
//! @namespace
//! Stack name space
//------------------------------------------------------------
namespace sns
{


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
    public:
        //---------------------------------------------
        //! @Constructor
        //! Create class Vector with dynamic allocation of memory
        //---------------------------------------------
        explicit Vector(size_t size);

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
        Vector         &operator=(Vector const &other);
        bool            operator[](const size_t index) const;
        BoolOperation   operator[](const size_t index);
        bool            operator==(Vector const &other) const;

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

        //---------------------------------------------
        //! @Debug
        //! Return pointer to dumped text
        //---------------------------------------------
        std::string dump(std::string fileName, std::string funcName, int lineNumber) const;

    private:
        int          size_;
        unsigned    *data_;
    };

    //----------------------------------------------------------
    // Definitions for Vector<bool>
    //----------------------------------------------------------
        Vector<bool>::Vector(size_t size)
                : size_(size/DATA_WIDTH + 1) {
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

            data_ = new unsigned[size_];
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
        bool Vector<bool>::operator[](const size_t index) const
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - const operator[]");
            #endif

            CHECK_RANGE(index/DATA_WIDTH, size_);
            return !!(data_[index/DATA_WIDTH] & (1 << index%DATA_WIDTH) );
        }

        // lvalue
        // Vetor a(20);
        // Vetor b(20);
        // bool c;
        // a[10] = b[6];
        // a[10] = c;
        BoolOperation Vector<bool>::operator[](const size_t index)
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - operator[]");
            #endif

            CHECK_RANGE(index/DATA_WIDTH, size_);
            return BoolOperation(index%DATA_WIDTH, & data_[index/DATA_WIDTH]);
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

        size_t Vector<bool>::size() const {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - size");
        #endif

            return size_;
        }

        std::string Vector<bool>::dump(std::string fileName, std::string funcName, int lineNumber) const {
            std::ostringstream oss;
            DEBUG_INFO("Vector - dump function");
            oss << "DUMP. Crash in "<< fileName << ", line " << lineNumber << ", function "
                << funcName << ".Internal vars: size = " << this->size() << ".";
            return(oss.str());
        }


} // end sns

#endif // _VECTOR_BOOL_HPP_
