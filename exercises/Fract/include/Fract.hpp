//---------------------------------------------
//! @IDE CLion
//! @file Fract.hpp
//! Header file with Fract class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _FRACT_HPP_
#define _FRACT_HPP_

#include <iostream>
#include <cassert>
#include <string>

//#define NDEBUG

//------------------------------------------------------------
//! @namespace
//! Fract name space
//------------------------------------------------------------
namespace fns
{


class  Fract
{


private:

	typedef  Fract value_type;
	value_type number;

public:

	//---------------------------------------------
    //! @Default Constructor
    //---------------------------------------------
	Fract();

	//---------------------------------------------
    //! @Constructor
    //---------------------------------------------
	Fract(int numerator, int denominator);

	//---------------------------------------------
    //! @Constructor of copy
    //---------------------------------------------
	Fract(const &Fract other);

	//---------------------------------------------
    //! @Destructor
    //---------------------------------------------
	~Fract();

	//---------------------------------------------
    //! @Access functions
    //---------------------------------------------
    std::string show() const;
	double toDouble() const;

	//---------------------------------------------
    //! @Modifiers
    //---------------------------------------------
	void neg();
	void swap(Fract &other);

	//---------------------------------------------
    //! @Operators
    //! 1) operator=
    //! 2) operator+
    //! 3) operator*
    //! 4) operator-
    //! 5) operator/
    //! 6) operator++
    //! 7) operator--
    //! 8) operator==
    //! 9) operator<
    //! 10) operator>
    //! 11) operator-(Fract)
    //! 12) operator+(Fract)
    //---------------------------------------------
	const Fract &operator=(const Fract &other);
	const Fract &&Fract::operator+(Fract other);
	Fract operator-() const;
    Fract operator+() const;


private:
	int numerator_;
	int denominator_;

};

#endif // _FRACT_HPP_

