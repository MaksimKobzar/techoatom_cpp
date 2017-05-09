//---------------------------------------------
//! @file PhysicEngine.h
//! Header file PhysicEngine structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef	_PHYSIC_ENGINE_H_
#define	_PHYSIC_ENGINE_H_

#include "Visitor.h"

class PhysicEngine : public Visitor
{
public:
	virtual void visit(GameMap *)
	{
		/* TODO */
	}
	virtual void visit(Hero *)
	{
		/* TODO */
	}
	virtual void visit(Enemy *)
	{
		/* TODO */
	}
	virtual void visit(Bullet *)
	{
		/* TODO */
	}
	virtual void visit(Bomb *)
	{
		/* TODO */
	}
	virtual void visit(HealHeart *)
	{
		/* TODO */
	}
	virtual void visit(HealHeart *)
	{
		/* TODO */
	}
};

#endif // _PHYSIC_ENGINE_H_

