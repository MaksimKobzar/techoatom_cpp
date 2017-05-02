#ifndef _VISITOR_H_
#define	_VISITOR_H_

class GameMap;
class Hero;
class Enemy;
class Bullet;
class Bomb;
class HealHeart;

class Visitor
{
public:
	virtual void visit(GameMap *) = delete;
	virtual void visit(Hero *) = delete;
	virtual void visit(Enemy *) = delete;
	virtual void visit(Bullet *) = delete;
	virtual void visit(Bomb *) = delete;
	virtual void visit(HealHeart *) = delete;
};

#endif // _VISITOR_H_

