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

/*
* TODO Размеры статических объектов могут быть просто захардкожены?
*/

class GameMap: public GameObject
{
public:
	GameMap(std::string name);
	virtual ~GameMap();

	void accept(Visitor *v)
	{
		v->visit(this);
	}
};


#endif //__GAME_MAP_H__