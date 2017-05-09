//---------------------------------------------
//! @file Rock.h
//! Header file Rock structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __ROCK_H__
#define __ROCK_H__

#include <iostream>
#include <string>
#include "Coordinates.h"

class Rock: public LandscapObject
{
public:
	Rock(std::string name)
		: LandscapObject(name)
	{}

	virtual ~Rock();
	
	void accept(Visitor *v)
	{
		v->visit(this);
	}
};


#endif //__ROCK_H__