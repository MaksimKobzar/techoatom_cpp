//---------------------------------------------
//! @file GameObject.h
//! Header file GameObject structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <iostream>
#include <string>
#include "Coordinates.h"

/*
	TODO необходимо делать явно на движимые и недвижимые объекты? 
	с одной стороны это очень характерный признак по которому можно делать,
	а с другой стороны очень сложно и дорого будет делать из движимого объекта недвижимый и наоборот
*/

class GameObject
{
public:
	GameObject(std::string name, Coordinates coordinates = 0, bool mobile = false, int velocity_ = 0, bool visible_ = true)
		: name_(name), coordinates_(coordinates), mobile_(mobile), velocity_(velocity), visible_(visible) {}

	virtual ~GameObject();


	virtual std::string getName() const
	{
		return name_;
	}

	//------------------------------------------------------------------------------
	//! Velocity
	//------------------------------------------------------------------------------
	virtual void setVelocity(Coordinates velocity)
	{
		velocity_ = velocity;
	}
	virtual Coordinates getVelocity() const
	{
		return velocity_; 
	}
	
	//------------------------------------------------------------------------------
	//! Visibility
	//------------------------------------------------------------------------------
	virtual void setVisibility(bool visible)
	{
		visible_ = visible;
	}
	virtual bool getVisibility() const
	{
		return visible_;
	}

	//------------------------------------------------------------------------------
	//! Mobility
	//------------------------------------------------------------------------------
	virtual bool getMobility() const
	{
		return mobile_;
	}

	/*
	*	Если я хочу, чтобы только PhysicEngine мог двигать мои объекты, как это сделать?
	*	Чтобы фактически методы были для всех приватные кроме одного единственного класса, friend?
	*/
	//------------------------------------------------------------------------------
	//! Coordinates
	//------------------------------------------------------------------------------
	virtual inline void setCoordinates(Coordinates coordinates)
	{
		coordinates_ = coordinates;
	}
	virtual inline Coordinates getCoordinates() const
	{
		return Coordinates;
	}
	virtual inline void setNewCoordinates()
	{
		coordinates_ = getNewCoordinates();
	}
	virtual inline Coordinates getNewCoordinates() const
	{
		return Coordinates(coordinates_ + velocity_);
	}

	virtual void accept(Visitor *v) = delete;

private:
	std::string 		name_;
	bool 				mobile_;
	Coordinates 		coordinates_;
	Coordinates 		velocity_;
	bool 				visible_;
};

#endif //__GAME_OBJECT_H__