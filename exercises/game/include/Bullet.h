//---------------------------------------------сторона
//! @file Bullet.h
//! Header file Bullet structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __BULLET_H__
#define __BULLET_H__

#include <iostream>
#include <string>
#include "Coordinates.h"

class Bullet: public WizbangObject
{
public:
	Bullet(std::string name);
	virtual ~Bullet();
private:
};

#endif // __BULLET_H__