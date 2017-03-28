//---------------------------------------------
//! @IDE CLion
//! @file Fract.hpp
//! Implementations functions of class Fract
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _FRACT_CPP_
#define _FRACT_CPP_


#include <string.h>
#include "Fract.hpp"


Fract::Fract() :
  numerator_(0), denominator_(1) { }

Fract::Fract(int numerator, int denominator) :
  numerator_(numerator), denominator_(denominator) { }

Fract::Fract(const &Fract other) {
  if(*this != other) {
    numerator_    = other.numerator_;
    denominator_  = other.denominator_;
  }
}

Fract::~Fract() {
  #ifdef NDEBUG
  numerator_    = POISON_VALUE;
  denominator_  = POISON_VALUE;
  #endif
}

std::string Fract::show() const {
	return(numerator_ + "/" + denominator_); 
}

double Fract::toDouble() const {
  return(numerator_ / denominator_); 
}

void Fract::swap(Fract &other) {
  std::swap(numerator_,   other.numerator_);
  std::swap(denominator_, other.denominator_);
}

void Fract::neg() {
  numerator_ = -numerator_;
}

const Fract &Fract::operator=(const Fract &other){
  if(*this != other) {
    Fract(other).swap(*this);
  }
  return *this;
}

const Fract &&Fract::operator+(Fract other) {
  other.numerator_    += numerator_;
  other.denominator_  += denominator_;
  return std::move(other);
}

Fract Fract::operator-() const {
  Fract some(*this);
  return some.neg();
}


Fract Fract::operator+() const {
    return *this;
}

#endif // _FRACT_CPP_