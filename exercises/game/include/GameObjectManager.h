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
			if(levelNumber == 0)
			{
				containerGameObject["Turret"] = new Turret("Turret");
				containerGameObject["Rock"] = new Rock("Rock", Coordinates(40, 100)/*Centre*/, Coordinates(10, 20)/*Size*/);
			}
			else if(levelNumber == 1){
				containerGameObject["Slug"] = new Slug("Slug");
			}
			else if(levelNumber == 2){
				containerGameObject["Slug0"] = new Slug("Slug0");
				containerGameObject["Slug1"] = new Slug("Slug1");
			}
		}
	}

	//-----------------------------------------------------------------------------------------------------------
	// Function delete all GameObjects from containerGameObject except Hero and Game Map.
	//-----------------------------------------------------------------------------------------------------------
	void deleteLevel()
	{
		for (std::map<std::string, GameObject*>::iterator it = containerGameObject.begin(); it != containerGameObject.end(); ++it)
		{
			key = ????;
			if(!(key == "Hero" || key == "GameMap"))
			{
				delete gamePhysicEngine;
				containerGameObject.erase(key); 
			}
		}
	}
	
	void createHero()
	{	
		if(containerGameObject.find("Hero"))
		{
			throw std::unexpected_error("Try create more heroes than allows.");
		}
		else
		{
			containerGameObject["Hero"] = new Hero("Hero");
		}
	}

	void deleteHero()
	{
		if(containerGameObject.find("Hero"))
		{
			containerGameObject.erase("Hero");
		}
		else
		{
			throw std::unexpected_error("Couldnt find 'Hero' in GameMap.");
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
