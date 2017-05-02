//---------------------------------------------
//! @file LandscapObject.h
//! Header file LandscapObject structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __LANDSCAPE_OBJECT_H__
#define __LANDSCAPE_OBJECT_H__

#include <iostream>
#include <string>
#include "Coordinates.h"

// static position on map moved
class LandscapObject: public GameObject
{
public:
	LandscapObject();
	~LandscapObject();

	void accept(Visitor *v)
	{
		v->visit(this);
	}
};

#endif // __LANDSCAPE_OBJECT_H__