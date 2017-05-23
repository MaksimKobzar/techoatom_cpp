//---------------------------------------------сторона
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

	void shoot(Coordinates targetCoordinates, GameObjectManager *gameObjectManager_);
private:
	enum FaceSide { Left, Right /* TODO мб когда нибудь появится еще вверх/вниз. */ };
	FaceSide 	faceSide_;
	bool 		friendly_;

	// fire Characteristics
	enum WeaponType { Tears, Laser, Gun }; 
	WeaponType	weapon_;
	double 		fireRate_; // shot per sec
	double 		shotDamage_;
	
	double 		healPoints_;
};

#endif // __GHARACTER_OBJECT_H__