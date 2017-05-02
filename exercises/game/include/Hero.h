//---------------------------------------------
//! @file Hero.h
//! Header file Hero structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __HERO_H__
#define __HERO_H__

#include <iostream>
#include <string>
#include "Coordinates.h"

// could be control only by USER
class Hero: public CharacterObject
{
public:
	Hero();
	~Hero();

	void accept(Visitor *v)
	{
		v->visit(this);
	}
};

#endif // __HERO_H__