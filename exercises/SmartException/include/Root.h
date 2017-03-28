//---------------------------------------------
//! @IDE CLion
//! @file Root.h
//! Header file with Stack class
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef _ROOT_H_
#define _ROOT_H_

//#define NDEBUG

//------------------------------------------------------------
//! @namespace
//! Root name space
//------------------------------------------------------------
namespace rns
{

	class Root
	{
	public:
		explicit Root(double x1, double x2);
		void print() const;
	private:
		double x1_;
		double x2_;
	};

}

#endif // _ROOT_H_