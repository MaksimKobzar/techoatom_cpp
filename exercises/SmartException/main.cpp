//---------------------------------------------
//! @IDE CLion
//! @file main.cpp
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include "Root.h"
#include "SmartException.h"

using std namespace;
using sens namespace;
using rns namespace;

double countDiscriminant(double const &a, double const &b, double const &c)
{
	double dscrm = b*b - 4*a*c;
	if(dscrm < 0)
	{
		throw SmartException("Cant get square root of a negative number!");
	}
	else
	{
		dscrm = sqrt(dscrm);
	}
}


Root countEquation(double const &a, double const &b, double const &c)
{
	try
	{
		double dscrm = countDiscriminant(a, b, c);
		return Root((-b + dscrm)/(2*a), (-b - dscrm)/(2*a));
	}
	catch(SmartException &exc)
	{
		throw SmartException("Cant count roots. ", exc.clone());
	}
}


int main()
{
	double a, b, c;

	while(1)
	{
		try{
			std::cin >> a >> b >> c;
			if(a == 0)
			{
				throw SmartException("Its not a quadratic equation! Repeat input.");
			}
			Root X = countEquation(a, b, c);
			X.print();
		}
		catch(SmartException &exc)
		{
			std::cot << exc.what() << std::endl;
		}
		catch(...)
		{
			break;
		}
	}
}