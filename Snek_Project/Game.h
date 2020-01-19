#pragma once

#include <SFML/Graphics.hpp>

#include "Snake.h"
#include "Food.h"

#include <list>
#include <random>

#define BOX_SIZE 20

namespace game {
	const std::string MenuStrings[5] = {
		"Game Over!",
		"Do you wish to continue?",
		"Yes",
		"No",
		"Exit"
	};

	enum MenuText{
		GameOver,
		Continue,
		Yes,
		No,
		Exit
	};

	enum Fonts {
		//todo
	};

	class GameController {
	public:

		GameController (sf::RenderWindow* w);
		void Start ();
		sf::Font* getFont (Fonts font);


	private:

		void GameLoop ();
		void SetupScene ();
		void GameOver ();
		void LoadResources ();
		
		bool checkCollisionB (const sf::RectangleShape& shapeA, const sf::RectangleShape& shapeB);

		Snake snake;

		sf::RenderWindow* screen;
		sf::Font fontList[3];

		float scale;
		int score;
	};
}