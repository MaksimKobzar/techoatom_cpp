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


    template<
        typename Ttype,
        class Container = Array<Ttype>
    >class Stack
    {
    public:
        //---------------------------------------------
        //! @Constructor
        //---------------------------------------------
        explicit Stack(Ttype capacity);

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
        Ttype *top() const; 

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
        bool push(Ttype& value);
        bool pop();
        void swap(Stack &other);

        //---------------------------------------------
        //! @Operator
        //---------------------------------------------
        Stack &operator=(Stack const &other) {
            if(this != &other) {
                Stack(other).swap(*this);            
            }
            return *this;
        }
        
        //---------------------------------------------
        //! @Debug
        //---------------------------------------------
        // bool ok();
        // bool dump();

    private:
        Ttype capacity_; // TODO init capacity via template
        size_t     size_;
        Container *data_;
    };

    template <typename Ttype, class Container>
    explicit Stack<typename Ttype, class Container>::Stack(<Ttype> capacity)
    : capacity_(capacity), size_(0), data_(Container<Ttype>(capacity)) { }

    template <typename Ttype, class Container>
    Stack<typename Ttype, class Container>::Stack(Stack<typename Ttype, class Container> const &other)
    : capacity_(other.capacity_), size_(other.size_), data_(Container<Ttype>(capacity)) { }

    template <typename Ttype, class Container>
    Stack<typename Ttype, class Container>::~Stack() { }

    template <typename Ttype, class Container>
    Ttype *Stack<typename Ttype, class Container>::top() const {
        if(size_ == 0) {
            return nullptr;
        }
        else {
            return &data_[size_];
        }
    }

    template <typename Ttype, class Container>
    bool *Stack<typename Ttype, class Container>::empty() const {
        return size_ == 0;
    }

    template <typename Ttype, class Container>
    bool *Stack<typename Ttype, class Container>::full() const {
        return size_ == capacity_;
    }

    template <typename Ttype, class Container>
    size_t *Stack<typename Ttype, class Container>::size() const {
        return size_;
    }

    template <typename Ttype, class Container>
    size_t *Stack<typename Ttype, class Container>::capacity() const {
        return capacity_;
    }

    template <typename Ttype, class Container>
    bool *Stack<typename Ttype, class Container>::push(Ttype& value) {
        if(size_ == capacity_) {
            return 0;
        }
        else {
            data_[size_++] = value;
            return 1;
        }
    }

    template <typename Ttype, class Container>
    bool *Stack<typename Ttype, class Container>::pop() {
        if(size_ == 0)
            return 0;
        else {
            size_--;
            return 1;
        }
    }

    template <typename Ttype, class Container>
    bool *Stack<typename Ttype, class Container>::swap(Stack<typename Ttype, class Container> const &other) {
        
    }


} // end sns

#endif //_STACK_HPP_
