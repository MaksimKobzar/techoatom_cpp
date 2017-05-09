//---------------------------------------------
//! @file Turret.h
//! Header file Turret structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __Turret_H__
#define __Turret_H__

#include <iostream>
#include <string>
#include "Coordinates.h"

/*
*	контролируется только CPU
*/
class Turret: public Enemy
{
public:
	Turret();
	~Turret();

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
		coordinates_ = gameAIEngine->getCoordinate();
		velocity_	 = gameAIEngine->getVelocity();
	}
};

#endif // __Turret_H__