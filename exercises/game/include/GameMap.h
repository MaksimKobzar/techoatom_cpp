//---------------------------------------------
//! @file GameMap.h
//! Header file GameMap structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __GAME_MAP_H__
#define __GAME_MAP_H__

#include <iostream>
#include <string>
#include "Coordinates.h"

class GameMap: public LandscapObject
{
public:
	GameMap(std::string name)
		: LandscapObject(name)
	{}

	virtual ~GameMap();
	
	void accept(Visitor *v)
	{
		v->visit(this);
	}
};


#endif //__GAME_MAP_H__