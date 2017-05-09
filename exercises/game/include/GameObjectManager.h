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


	void createLevel(int levelNumber)
	{
		if(containerGameObject.find("GameMap"))
		{	
			throw std::unexpected_error("Map has already created.");
		}
		else
		{
			containerGameObject["Map"] = new GameMap("Map");
			switch(levelNumber)
			{
				0: containerGameObject["Turret"] = new Turret("Turret");
				break;
			}
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

	void step(PhysicEngine *gamePhysicEngine)
	{
		for (std::map<std::string, GameObject*>::iterator it = containerGameObject.begin(); it != containerGameObject.end(); ++it)
		{
			(*gamePhysicEngine)->accept(&it);
		}
	}

	void step(GraphicEngine *gameGraphicEngine)
	{
		for (std::map<std::string, GameObject*>::iterator it = containerGameObject.begin(); it != containerGameObject.end(); ++it)
		{
			(*it)->accept(&gameGraphicEngine);
		}
	}

	void step(AudioEngine *gameAudioEngine)
	{
		gameAudioEngine->playSound();
	}

private:
	GameObjectManager() { }
	GameObjectManager(GameObjectManager const&) = delete;
	void operator=(GameObjectManager const&) = delete;

	/* TODO Мб хранить не указатели на объекты, а умные указатели? */
	std::map<std::string, GameObject*> containerGameObject;
};


#endif //__GAME_OBJECT_MANAGER_H__
