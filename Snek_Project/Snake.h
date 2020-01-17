#pragma once
#include <SFML/Graphics.hpp>

#include <list>
#include <random>

#include "Food.h"

#define SNAKE_MAX_LENGHT 2000

namespace game {
	class Random {

		std::random_device rd;
		std::mt19937 gen;

	public:

		Random () {
			gen.seed (rd ());
		}

		int getRandomInt (int l, int u) {
			std::uniform_int_distribution<int> dist (l, u);
			return dist (gen);
		}
	};

	class Snake {
	public:
		Snake (sf::RenderWindow*);
		void drawSnake ();
		bool died ();
		bool ateFood (Food* fd);
		void moveSnake (sf::Vector2<int> direction);

		sf::Vector2f getNextFoodLocation ();
	private:

		sf::RenderWindow* screen;
		Random rand;
		
		bool updateLenght;

		float movementScale;

		int snake_lenght;
		std::list<sf::Vector2<int>> snake_direction_list;
		sf::Vector2<int> lastDirection;
		std::vector<sf::RectangleShape> body;

		sf::Color colorBody;
		sf::Color colorHead;
	};
}