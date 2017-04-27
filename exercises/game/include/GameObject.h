#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <iostream>
#include <string>

/*
	TODO необходимо делать явно на движимые и недвижимые объекты? 
	с одной стороны это очень характерный признак по которому можно делать,
	а с другой стороны очень сложно и дорого будет делать из движимого объекта недвижимый и наоборот
*/
class GameObject
{
public:
	GameObject(std::string name);
	virtual ~GameObject();
	
	virtual void draw() const;
	virtual void move();
	virtual void setVelocity();
	virtual double getVelocity();
	virtual void setVisibility();
	virtual bool getVisibility();
	virtual std::string getName() const;
private:
	std::string 		name_;
	double 				velicity_;
	bool 				visible_;
};

class GameMap: public GameObject
{
public:
	GameMap(std::string name);
	virtual ~GameMap();
	
	virtual void draw() const;
	virtual void move();
	virtual void setVelocity();
	virtual double getVelocity();
	virtual void setVisibility();
	virtual bool getVisibility();
	virtual bool getFriendly();
	virtual std::string getName() const;
private:
	std::string 		name_;
	double 				velicity_;
	bool 				visible_;
	bool 				friendly_;
};


class CharacterObject: public GameObject
{
public:
	CharacterObject(std::string name);
	virtual ~CharacterObject();
	
	virtual void draw() const;
	virtual void move();
	virtual void setVelocity();
	virtual double getVelocity();
	virtual void setVisibility();
	virtual bool getVisibility();
	virtual bool getFriendly();
	virtual std::string getName() const;
private:
	std::string 		name_;
	double 				velicity_;
	bool 				visible_;
	bool 				friendly_;
};

// could be control only by USER
class HeroObject: public CharacterObject
{
public:
	HeroObject();
	~HeroObject();

	/*
		TODO показать явно какие функции будут переписываться/дописываться относительно базовой реализации
		а какие появились только в текущем классе.
	*/
	void shoot();
	void invis();
	virtual void draw() const;
	virtual void move();
private:
	std::vector ammo;
	std::vector artefact;
};

// control only by CPU
class EnemyObject: public CharacterObject
{
public:
	EnemyObject();
	~EnemyObject();

	/*
		TODO показать явно какие функции будут переписываться/дописываться относительно базовой реализации
		а какие появились только в текущем классе.
	*/
	void shoot();
	void invis();
	virtual void draw() const;
	virtual void move();
};

// static position on map moved
class LandscapObject: public GameObject
{
public:
	LandscapObject();
	~LandscapObject();

	virtual void draw() const;
	virtual void move() = delete;
};

#endif //__GAME_OBJECT_H__