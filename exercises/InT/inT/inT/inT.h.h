#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;
class  inT
{


private:

	typedef  int value_type;
	value_type n,temp;
	//value_type stop = 3;
	//value_type count = 0;

public:
	inT() { };
	inT (value_type value) 
	{
		n = value;

	}
	~inT();
	inT operator=(const value_type &);
	inT operator+(const value_type &);
	inT operator+(const inT &);
	inT operator*(const value_type &);
	inT operator*(const inT &);
	inT operator-(const value_type &);
	inT operator-(const inT &);
	inT operator/(const value_type &);
	inT operator/(const inT &);

};

 inT::~ inT()
{
	 //delete ;
}

 inT inT::operator=(const value_type &number)
 {
	 n = number;
	 return (*this);

 }

  inT inT::operator+(const value_type &number)
  {
	  temp = number + n;
	  return temp;
  }

  inT inT::operator+( const inT &number)
  {
	  temp = number.n + n;
	  return temp;
  }

 
  inT inT::operator*(const value_type &number)
  {
	 temp = n * number;
	 return temp;
  }




  inT inT::operator*(const inT &number)
  {
	  temp = n * number.n;
	  return temp;
  }


  inT inT::operator-(const value_type &number)
  {
	  temp = n - number;
	  return temp;
  }


  inT inT::operator-(const inT &number)
  {
	  temp = n - number.n;
	  return temp;
  }
  
  inT inT::operator/(const value_type &number)
  {
	  temp = n / number;
	  return temp;
  }


  inT inT::operator/(const inT &number)
  {
	  temp = n / number.n;
	  return temp;
  }

  