//---------------------------------------------
//! @file Slug.h
//! Header file Slug structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __SLUG_H__
#define __SLUG_H__

#include <iostream>
#include <string>
#include "Coordinates.h"

/*
*	контролируется только CPU
*/
class Slug: public Enemy
{
public:
	Slug();
	~Slug();

	/*
		TODO показать явно какие функции будут переписываться/дописываться относительно базовой реализации
		а какие появились только в текущем классе.
	*/
	void shoot() = delete;
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

#endif // __SLUG_H__