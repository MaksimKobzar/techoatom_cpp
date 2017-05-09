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

/*
* 1) constant position on map
* 2) when colide with other weak object he is destroy
* 3) cant go throw that object
*/
class LandscapObject: public GameObject
{
public:
	LandscapObject(std::string name, Coordinates coordinates = 0, bool visible = true)
		: GameObject(name, coordinates, false, 0, visible)
	{ }

	virtual ~LandscapObject();

	void accept(Visitor *v)
	{
		v->visit(this);
	}
};

#endif // __LANDSCAPE_OBJECT_H__