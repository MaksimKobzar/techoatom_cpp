//---------------------------------------------
//! @IDE CLion
//! @file Vector.hpp
//! Header file with Vector class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>

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
        Vector &operator=(const BitOperation op);

        BitOperation operator[](int const index);                   // lvalue
        BitOperation const &operator[](const size_t index) const;   // rvalue

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

    struct BitOperation
    {
        explicit BitOperation(size_t index, char value = 0);

        size_t  get_index() const;
        bool    get_value() const;

    private:
        size_t      index_;
        bool        value_;
    };

    explicit BitOperation(size_t index, bool value = 0) :
        index_(index), value_(value) { }

    size_t get_index() const
    {
        return index_;
    }

    bool get_value() const
    {
        return value_;
    }



    //----------------------------------------------------------
    // Definitions for Vector<bool>
    //----------------------------------------------------------
        template<>
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

        template<>
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

        template<>
        Vector<bool>::~Vector() {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - start destructor");
            #endif

            delete [] data_;

            #ifdef NDEBUG
                DEBUG_INFO("Vector - end destructor");
            #endif
        }

        template<>
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

        template<>
        Vector<bool> Vector<bool>::operator=(const BitOperation op)
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector<bool> - operator=");
            #endif

            if(op.get_value())
            {
                data_[op.get_index()/sizeof(unsigned)] = data_[op.get_index()/sizeof(unsigned)] |
                                                            (1 << op.get_index()%sizeof(unsigned));
            }
            else {
                data_[op.get_index()/sizeof(unsigned)] = data_[op.get_index()/sizeof(unsigned)] &
                                                            (0 << op.get_index()%sizeof(unsigned));
            }
            return *this;
        }




        template<typename value_type> // rvalue bool a = b[10]
        bool &Vector<bool>::operator[](const size_t index) const
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - const operator[]");
            #endif

            CHECK_RANGE(index, size_);
            return !!(data_[index/sizeof(unsigned)] & (1 << index%sizeof(unsigned)) );
        }

        template<typename value_type> // rvalue Vetor a[10] = b[6]
        const BitOperation Vector<bool>::operator[](const size_t index) const
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - operator[]");
            #endif

            CHECK_RANGE(index, size_);
            return BitOperation(index, this->operator[index]);
        }

        template<typename value_type> // lvalue a[10] = b[6]
        bool &Vector<bool>::operator[](const size_t index) const
        {
            #ifdef NDEBUG
                DEBUG_INFO("Vector - const operator[]");
            #endif

            CHECK_RANGE(index, size_);
            return !!(data_[index/sizeof(unsigned)] & (1 << index%sizeof(unsigned)) );
        }






        template<>
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

        template<>
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

        template<>
        int Vector<bool>::size() const {
        #ifdef NDEBUG
            DEBUG_INFO("Vector - size");
        #endif

            return size_;
        }

        template<>
        std::string Vector<bool>::dump(std::string fileName, std::string funcName, int lineNumber) const {
            std::ostringstream oss;
            oss << "DUMP. Crash in "<< fileName << ", line " << lineNumber << ", function "
                << funcName << ".Internal vars: size = " << this->size() << ".";
            return(oss.str());
        }
    // ---------------------------------------------------------


} // end sns

#endif // _VECTOR_HPP_
