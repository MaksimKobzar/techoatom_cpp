#ifndef _VISITOR_H_
#define	_VISITOR_H_

class LandscapeObject;
class CharacterObject;
class WhizBangObject;
class MyNewClass;

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

