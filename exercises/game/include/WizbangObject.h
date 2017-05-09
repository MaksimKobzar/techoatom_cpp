//---------------------------------------------сторона
//! @file WhizbangObject.h
//! Header file WhizbangObject structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __WIZBANG_OBJECT_H__
#define __WIZBANG_OBJECT_H__

#include <iostream>
#include <string>
#include "Coordinates.h"

class WhizbangObject: public GameObject
{
public:
	WhizbangObject(std::string name);
	virtual ~WhizbangObject();

	void shoot(Coordinates targetCoordinates, GameObjectManager *gameObjectManager_);
private:

	friend void PhysicEngine::visit(WhizbangObject *);

	enum FaceSide { Left, Right /* TODO мб когда нибудь появится еще вверх/вниз. */ };
	FaceSide 	faceSide_;
	bool 		friendly_;
};

#endif // __WIZBANG_OBJECT_H__