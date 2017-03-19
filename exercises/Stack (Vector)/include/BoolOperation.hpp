
    struct BoolOperation
    {
        //---------------------------------------------
        //! @Constructor
        //! Create class BoolOperation
        //---------------------------------------------
        explicit BoolOperation(size_t index, Vector<bool> &vec);

        //---------------------------------------------
        //! @Operators:
        //! operator =
        //---------------------------------------------
        bool BoolOperation::operator=(bool value)

    private:
        size_t        index_;
        Vector<bool>  &vec_;
    };