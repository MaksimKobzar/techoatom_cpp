//---------------------------------------------
//! @file Game.h
//! Header file Game structure
//!
//! @author Maksim_Kobzar, 2017
//---------------------------------------------

#ifndef __GAME_H__
#define __GAME_H__

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameObjectManager.h"

class Game
{
public:
	static void startGame();
	static Game& getGame()
	{
		return game_;
	}

	GameLogger& getGameLogger()
	{
		return *gameLogger_;
	}
	ObjectManager& getObjectManager()
	{
		return *ObjectManager_;
	}

private:
	static Game game_;

	bool isExiting();
	void gameLoop();
	void showGameLogo();
	void showMainMenu();
	void showMenu();
	void gameLoop();
	void playGame();

	enum GameState { Uninitialized, ShowingLogo, Paused,
			ShowingMenu, ShowingMainMenu, Playing, Exiting, LoadSaving };

	static GameState gameState_;

	GameObjectManager 	*gameObjectManager_;
	PhysicEngine		*gamePhysicEngine_;
	GraphicEngine		*gameGraphicEngine_;
	AudioEngine			*gameAudioEngine_;
	AIEngine			*gameAIEngine_;
	Logger				*gameLogger_;

	static sf::RenderWindow mainWindow_;
};

// ----------------------------------------------------------------------------------
// Implementation
// ----------------------------------------------------------------------------------
void Game::startGame()
{
	mainWindow_.Create(sf::VideoMode(1024,768,32),"Pang!");

	gameState_ = Game::ShowingLogo;
	showGameLogo();

	gameState_ = Game::ShowingMainMenu;
	while(!isExiting())
	{
		gameLoop();
	}
	gameObjectManager_.clear();
	mainWindow_.close();
}

void Game::showGameLogo()
{
	GameLogo gameLogo;
	gameLogo.show(mainWindow_);
	sleep(2);
}

void Game::showMainMenu()
{	
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.show(mainWindow_);

	if(result == MainMenu::Exit)
	{
		gameState_ = Game::Exiting;
	}
	else if(result == MainMenu::Play)
	{	
		createGame();
		gameState_ = Game::Playing;
	}
	else if(gameState_ == MainMenu::LoadSaving)
	{
		gameState_ = Game::LoadSaving;
	}
}

void Game::createGame()
{	
	GameObjectManager_ 	= new GameObjectManager();
	gamePhysicEngine_ 	= new PhysicEngine();
	gameGraphicEngine_ 	= new GraphicEngine();
	gameAudioEngine_ 	= new AudioEngine();
	gameAIEngine_ 		= new AIEngine();
	gameLogger_ 		= new Logger();

	GameObjectManager_.createLevel(0);
	GameObjectManager_.createHero();
}

void Game::showMenu()
{	
	Menu menu;
	Menu::MenuResult result = menu.show(mainWindow_);

	if(result == Menu::Exit)
	{
		gameState_ = Game::Exiting;
	}
	else if(result == Menu::Continue)
	{
		gameState_ = Game::Playing;
	}
	else if(gameState_ == Menu::Save)
	{
		gameState_ = Game::Saving;
	}
	else if(gameState_ == Menu::MainMenu)
	{
		gameState_ = Game::showMainMenu;
	}
}

bool Game::isExiting()
{
	if(gameState_ == Game::Exiting)
	{
		return true;
	} 
	else
	{
		return false;
	} 
}

void Game::gameLoop()
{
	switch(gameState_)
	{	
		case Game::ShowingMainMenu:
			ShowMainMenu();
			break;
		case Game::ShowingMenu:
			ShowMenu();
			break;
		case Game::Playing:
			playGame();
			break;
		case Game::LoadSaving:
			loadSaving();
			break;
	}
	GameObjectManager_.step(gameAIEngine_);
	GameObjectManager_.step(gamePhysicEngine_);
	GameObjectManager_.step(gameAudioEngine_);
	GameObjectManager_.step(gameGraphicEngine_);
	sleep(2 - dqwsewqed);
}

void Game::playGame()
{	

	// press Keys
	sf::Event currentEvent;
	while(mainWindow_.GetEvent(currentEvent))
	{
		mainWindow_.Clear(sf::Color(sf::Color(0,0,0)));
		mainWindow_.Display();

		if(currentEvent.Type == sf::Event::Closed)
		{
			gameState_ = Game::Exiting;
		}
		else if(currentEvent.Type == sf::Event::KeyPressed)
		{
			if(currentEvent.Key.Code == sf::Key::Escape){
				gameState_ = GameState::Paused;
				ShowMenu();
			}

		}
	}
}

#endif // __GAME_H__