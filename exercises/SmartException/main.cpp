//---------------------------------------------
//! @IDE CLion
//! @file main.cpp
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#include <cmath>
#include "Root.h"
#include "SmartException.h"

using namespace std;
using namespace sens;
using namespace rns;


double countDiscriminant(double const &a, double const &b, double const &c)
{
	double dscrm = b*b - 4*a*c;
	if(dscrm < 0)
	{
		throw SmartException("countDiscriminant: Cant get square root of a negative number!");
	}
	else
	{
		dscrm = std::sqrt(dscrm);
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
		std::cout << "Catch exc" << std::endl;
		throw SmartException("countEquation: Cant count roots. ", exc); /* TODO clone() */
	}
}


int main()
{
	double a, b, c;

	while(1)
	{
		try{
			std::cout << "Enter the coefficients of the quadratic equation: a , b , c." << std::endl;
			std::cin >> a >> b >> c;
			if(a == 0)
			{
				throw SmartException("Its not a quadratic equation! Repeat input.");
			}
			Root X = countEquation(a, b, c);
			X.print();
			break;
		}
		catch(SmartException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
		catch(...)
		{
			break;
		}
	}
}