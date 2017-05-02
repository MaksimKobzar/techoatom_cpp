//---------------------------------------------
//! @file CharacterObject.h
//! Header file CharacterObject structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __GHARACTER_OBJECT_H__
#define __GHARACTER_OBJECT_H__

#include <iostream>
#include <string>
#include "Coordinates.h"

class CharacterObject: public GameObject
{
public:
	CharacterObject(std::string name);
	virtual ~CharacterObject();

	void accept(Visitor *v)
	{
		v->visit(this);
	}
};

#endif // __GHARACTER_OBJECT_H__