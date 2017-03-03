//---------------------------------------------
//! @IDE CLion
//! @file Stack.hpp
//! Header file with Stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _STACK_HPP_
#define _STACK_HPP_

//------------------------------------------------------------
//! @namespace
//! Stack name space
//------------------------------------------------------------
namespace sns
{
    typedef Tcontainer Array<Tvalue>;

    template<
        typename Tvalue = int
    >class Stack
    {
        typedef value_type Tvalue;
    public:
        //---------------------------------------------
        //! @Constructor
        //---------------------------------------------
        explicit Stack(Tvalue capacity);

        //---------------------------------------------
        //! Constructor of copy
        //---------------------------------------------
        Stack(Stack const &other);

        //---------------------------------------------
        //! @Destructor
        //---------------------------------------------
        ~Stack();

        //---------------------------------------------
        //! @Element_access
        //---------------------------------------------
        Tvalue *top() const;

        //---------------------------------------------
        //! @Capacity functions
        //---------------------------------------------
        bool   empty()     const;
        bool   full()      const;
        size_t size()      const;
        size_t capacity()  const;

        //---------------------------------------------
        //! @Modifiers
        //---------------------------------------------
        bool push(Tvalue& value);
        bool pop();
        void swap(Stack &other);

        //---------------------------------------------
        //! @Operators
        //! 1) operator=
        //! 2) operator==
        //---------------------------------------------
        Stack &operator=(Stack const &other);
        bool operator==(Stack<value_type> &lhs, Stack<value_type> &rhs);

        //---------------------------------------------
        //! @Debug
        //---------------------------------------------
        // bool ok();
        // bool dump();

    private:
        Tvalue capacity_;
        size_t     size_;
        Tcontainer *data_;
    };

    template <typename value_type>
    explicit Stack<typename value_type>::Stack(<Tvalue> capacity)
    : capacity_(capacity), size_(0), data_(Tcontainer<Tvalue>(capacity)) { }

    template <typename value_type>
    Stack<typename value_type>::Stack(Stack<typename value_type> const &other)
    : capacity_(other.capacity_), size_(other.size_), data_(Tcontainer<Tvalue>(capacity)) { }

    template <typename value_type>
    Stack<typename value_type>::~Stack() { }

    template <typename value_type>
    Tvalue *Stack<typename value_type>::top() const {
        if(size_ == 0) {
            return nullptr;
        }
        else {
            return &data_[size_];
        }
    }

    template <typename value_type>
    bool *Stack<typename value_type>::empty() const {
        return size_ == 0;
    }

    template <typename value_type>
    bool *Stack<typename value_type>::full() const {
        return size_ == capacity_;
    }

    template <typename value_type>
    size_t *Stack<typename value_type>::size() const {
        return size_;
    }

    template <typename value_type>
    size_t *Stack<typename value_type>::capacity() const {
        return capacity_;
    }

    template <typename value_type>
    bool *Stack<typename value_type>::push(Tvalue& value) {
        if(size_ == capacity_) {
            return 0;
        }
        else {
            data_[size_++] = value;
            return 1;
        }
    }

    template <typename value_type>
    bool *Stack<typename value_type>::pop() {
        if(size_ == 0)
            return 0;
        else {
            size_--;
            return 1;
        }
    }

    template <typename value_type>
    bool *Stack<typename value_type>::swap(Stack<typename value_type> const &other) {
        std::swap(capacity_, other.capacity_);
        std::swap(size_,     other.size_);
        std::swap(data_,     other.data_);
    }

    template <typename value_type>
    Stack<value_type> &Stack<value_type>::operator=(Stack<value_type> const &other) {
        if(this != &other) {
            Stack(other).swap(*this);
        }
        return *this;
    }

    template <typename value_type>
    bool operator==(Stack<value_type> &lhs, Stack<value_type> &rhs) {
        return( lhs.size_       == rhs.size_ &&
            // lhs.capacity_   == rhs.capacity_ && // Do we need to check capacity?
                lhs.data_ == rhs.data_);
    }

} // end sns

#endif //_STACK_HPP_
