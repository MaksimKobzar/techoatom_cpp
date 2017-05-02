#ifndef	_GRAPHIC_ENGINE_H_
#define	_GRAPHIC_ENGINE_H_

#include "Visitor.h"

class GraphicEngine : public Visitor
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
};

#endif // _GRAPHIC_ENGINE_H_

