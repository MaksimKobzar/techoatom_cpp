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

private:
	static bool isExiting();
	static void gameLoop();
	static void showGameLogo();
	static void showMainMenu();
	static void showMenu();
	static void GameLoop();
	static void playGame();

	enum GameState { Uninitialized, ShowingLogo, Paused, ShowingMenu, ShowingMainMenu, Playing, Exiting, LoadSaving };

	static GameState gameState_;
	static sf::RenderWindow mainWindow_;
	GameObjectManager GameObjectManager_;
	/* TODO Сделать статическим, чтобы видеть везде? */
};


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
	gameManager.clearAll();
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
		/* Я тут возвращаю ссылку. Как мне это сделать синтксически?! */
		GameObjectManager_ = GameObjectManager::getInstance();
		// GameObjectManager_.Registrate("Hero0", &Hero::Create);
		GameObjectManager_.createLevel();
		GameObjectManager_.createHero();
		gameState_ = Game::Playing;
	}
	else if(gameState_ == MainMenu::LoadSaving)
	{
		gameState_ = Game::LoadSaving;
	}
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

void Game::GameLoop()
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
	GameObjectManager_.moveAll();
	GameObjectManager_.drawAll();
}

void Game::playGame()
{
	sf::Event currentEvent;
	while(mainWindow_.GetEvent(currentEvent))
	{
		mainWindow_.Clear(sf::Color(sf::Color(0,0,0)));
		mainWindow_.Display();

		if(currentEvent.Type == sf::Event::Closed)
		{
			gameState_ = Game::Exiting;
		}
		/*
		*	TODO Как круто обрабатыать нажатия клавиш?
		*	Нажатие любой кнопки имеет смысл лишь в стадии PLAYING крмое кнопки ESCAPE
		*	Нажатием клавиш идет управление только объекта Hero
		*/
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