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
		if(containerGameObject_.find("GameMap"))
		{
			throw std::unexpected_error("Map has already created.");
		}
		else
		{
			containerGameObject_["Map"] = new GameMap("Map");
		}
	}

	void createHero()
	{
		if(containerGameObject_.find("Hero0"))
		{
			if(containerGameObject_.find("Hero1"))
			{
				throw std::unexpected_error("Try create more heroes than allows.");
			}
			else
			{
				containerGameObject_["Hero1"] = new Hero("Hero1");
			}
		}
		else
		{
			containerGameObject_["Hero0"] = new Hero("Hero0");
		}
	}

	void moveAll()
	{
		for (std::map<std::string, GameObject*>::iterator it = containerGameObject_.begin(); it != containerGameObject_.end(); ++it)
		{
			(*it)->accept(&gamePhEn_);
		}
	}

	void drawAll()
	{
		for (std::map<std::string, GameObject*>::iterator it = containerGameObject_.begin(); it != containerGameObject_.end(); ++it)
		{
			(*it)->accept(&gameGrEn_);
		}
	}

	void clearAll()
	{
		containerGameObject_.clear();
	}

private:
	GameObjectManager() { }
	GameObjectManager(GameObjectManager const&) = delete;
	void operator=(GameObjectManager const&) = delete;

	/* TODO Мб хранить не указатели на объекты, а умные указатели? */
	std::map<std::string, GameObject*> containerGameObject_;

	PhysicEngine	gamePhEn_;
	GraphicEngine	gameGrEn_;
};


#endif //__GAME_OBJECT_MANAGER_H__
