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
	Enemy()
	: CharacterObject(, 0 /*friendly*/)
	{
	}
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

	void move(AIEngine *gameAIEngine, const GameObjectManager *gameObjectManager_)
	{
		gameAIEngine->reset();
		gameAIEngine->setCoordinate(coordinates_);
		gameAIEngine->setVelocity(velocity_);
		gameAIEngine->setHeroRange(gameObjectManager_->getHeroRange(coordinates_));
		gameAIEngine->run();
		while(!gameAIEngine->idle());
		velocity_	 = gameAIEngine->getVelocity();
		if(gameAIEngine)
	}
};

#endif // __ENEMY_H__