//---------------------------------------------
//! @file GameObjectManager.h
//! Header file GameObjectManager structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __GAME_OBJECT_MANAGER_H__
#define __GAME_OBJECT_MANAGER_H__

#include <iostream>
#include <string>


class GameObjectManager
{
public:
	static GameObjectManager* getInstance()
	{
		static GameObjectManager instance;
		return instance;
	}


	void createLevel()
	{
		if(containerGameObject.find("GameMap"))
		{	
			throw std::unexpected_error("Map has already created.");
		}
		else
		{
			containerGameObject["Map"] = new GameMap("Map");
		}
	}
	
	void createHero()
	{	
		if(containerGameObject.find("Hero0"))
		{	
			if(containerGameObject.find("Hero1"))
			{
				throw std::unexpected_error("Try create more heroes than allows.");
			}
			else
			{
				containerGameObject["Hero1"] = new Hero("Hero1");
			}
		}
		else
		{
			containerGameObject["Hero0"] = new Hero("Hero0");
		}
	}

	void moveAll()
	{
		for (std::map<std::string, GameObject*>::iterator it = containerGameObject.begin(); it != containerGameObject.end(); ++it)
		{
			(*it)->accept(&gamePhEn_);
		}
	}

	void drawAll()
	{
		for (std::map<std::string, GameObject*>::iterator it = containerGameObject.begin(); it != containerGameObject.end(); ++it)
		{
			(*it)->accept(&gameGrEn_);
		}
	}

private:
	GameObjectManager() { }
	GameObjectManager(GameObjectManager const&) = delete;
	void operator=(GameObjectManager const&) = delete;

	/* Мб хранить не указатели на объекты, а умные указатели? */
	std::map<std::string, GameObject*> containerGameObject;

	PhysicEngine	gamePhEn_;
	GraphicEngine	gameGrEn_;
};


#endif //__GAME_OBJECT_MANAGER_H__
