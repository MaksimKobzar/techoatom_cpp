#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;
class  inT
{


private:

	typedef  int value_type;
	value_type number;

public:
	~inT();
	inT():number(0)
	{}
	inT(int example) : number(example)
	{}
	inT operator=( inT );
	inT operator+( value_type );
	inT operator+( inT );
	inT operator*( value_type );
	inT operator*( inT );
	inT operator-( value_type );
	inT operator-( inT );
	inT operator/( value_type );
//	inT operator/(value_type);
	inT operator/( inT );
	inT operator++(int);
	inT operator++();
	inT operator--(int);
	inT operator--();
	void show();

};

