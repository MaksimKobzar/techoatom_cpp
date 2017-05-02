//---------------------------------------------
//! @file Enemy.h
//! Header file Enemy structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <iostream>
#include <string>
#include "Coordinates.h"

/*
*	контролируется только CPU
*/
class Enemy: public CharacterObject
{
public:
	Enemy();
	~Enemy();

	/*
		TODO показать явно какие функции будут переписываться/дописываться относительно базовой реализации
		а какие появились только в текущем классе.
	*/
	void shoot();
	void invis();

	void accept(Visitor *v)
	{
		v->visit(this);
	}
};

#endif // __ENEMY_H__