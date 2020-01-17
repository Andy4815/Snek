#pragma once

#define SS_GAME_H

#include "Snake.h"
#include "Food.h"

#include <SFML/Graphics.hpp>
#include <random>
#include <list>

#define BOX_SIZE 20

namespace game {
	const std::string MenuStrings[5] = {
		"Game Over!",
		"Do you wish to continue?",
		"Yes",
		"No",
		"Exit"
	};

	enum MenuText {
		GameOver,
		Continue,
		Yes,
		No,
		Exit
	};

	enum Fonts {

	};

	class GameController {
	public:		
		GameController (sf::RenderWindow* w);

		void start ();

		sf::Font* getFont (Fonts font);
	private:
		void gameLoop ();
		void setupScene ();
		void gameOver ();
		void loadResources ();

		Snake snake;
		sf::RenderWindow* screen;
		float scale;
		int score;

		sf::Font fontList[3];
	};
}