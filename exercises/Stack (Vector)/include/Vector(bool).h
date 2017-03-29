//---------------------------------------------
//! @file Vector(bool).h
//! Header file with Vector<bool> class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _VECTOR_BOOL_H_
#define _VECTOR_BOOL_H_

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include "BoolOperation.h"


//------------------------------------------------------------
//! @namespace
//! Stack name space
//------------------------------------------------------------
namespace sns
{

    template<>
    class Vector<bool>
    {
        const size_t UNS_BIT_NUM = 8*sizeof(unsigned);
        // using wordNum_ = size_/UNS_BIT_NUM;
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
        bool is_valid() const;
        std::string dump(std::string fileName, std::string funcName, int lineNumber) const;

    private:
        size_t      size_;
        unsigned    *data_;
    };

    //----------------------------------------------------------
    // Definitions for Vector<bool>
    //----------------------------------------------------------
        Vector<bool>::Vector(size_t size)
            : size_(size)
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - start default constructor");
            #endif

            data_ = new unsigned[size_/UNS_BIT_NUM + 1];
            for (size_t i = 0; i != size_/UNS_BIT_NUM; ++i)
            {
                data_[i] = 0;
            }

            #ifdef NDEBUG
                DEBUG_INFO("Vector - end default constructor");
            #endif
        }

        Vector<bool>::Vector(const Vector<bool> &other)
            : size_(other.size_)
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - start constructor of copy");
            #endif

            data_ = new unsigned[size_/UNS_BIT_NUM];
            for (size_t i = 0; i != size_/UNS_BIT_NUM; ++i)
            {
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

        BoolOperation Vector<bool>::operator[](const size_t index)
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - operator[]");
            #endif

            CHECK_RANGE(index, size_, Vector<bool>);
            return BoolOperation(index%UNS_BIT_NUM, &data_[index/UNS_BIT_NUM]);
        }

        bool Vector<bool>::operator==(Vector<bool> const &other) const
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - operator==");
            #endif

            if(this == &other) {
                return true;
            }
            if(size_ != other.size_) {
                return false;
            }
            for (size_t i = 0; i != size_/UNS_BIT_NUM; ++i) {
                if(data_[i] != other.data_[i]) {
                    return false;
                }
            }
            return true;
        }

        void Vector<bool>::swap(Vector<bool> &other)
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - start swap");
            #endif

            std::swap(size_, other.size_);
            std::swap(data_, other.data_);

            #ifdef NDEBUG
                DEBUG_INFO("Vector - end swap");
            #endif
        }

        size_t Vector<bool>::size() const
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - size");
            #endif

            return size_;
        }

        bool Vector<bool>::is_valid() const
        {   
            #ifdef NDEBUG
                DEBUG_INFO("Vector - is_valid");
            #endif // NDEBUG
            return true;
        }


        std::string Vector<bool>::dump(std::string fileName, std::string funcName, int lineNumber) const
        {
            std::ostringstream oss;
            oss << "DUMP. Crash in "<< fileName << ", line " << lineNumber << ", function "
                << funcName << ".Internal vars: size = " << this->size() << ".";
            return(oss.str());
        }

}
#endif // _VECTOR_BOOL_H_
