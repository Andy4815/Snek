#pragma once
#include <SFML/Graphics.hpp>

#include "Food.h"

#include <list>
#include <random>

#define SNAKE_MAX_LENGH 2000

namespace game {
	class Random {
		std::random_device rd;
		std::mt19937 gen;
	public:

		Random () {
			gen.seed (rd());
		}

		int getRandomInt (int l, int u) {
			std::uniform_int_distribution<int> dist (l, u);
			return dist (gen);
		}
	};

	class Snake {
	public:

		Snake (sf::RenderWindow* w);
		
		void DrawSnake ();
		void MoveSnake (sf::Vector2<int> direction);

		bool died ();
		bool ateFood (Food* fd);

		sf::Vector2f getNextFoodLocation ();

	private:

		sf::RenderWindow* screen;
		sf::Vector2<int> lastDirection;
		sf::Color colorBody;
		sf::Color colorHead;

		Random rand;

		bool updateLength;
		float movementScale;
		int snake_length;
		
		std::list<sf::Vector2<int>> snake_direction_list;
		std::vector<sf::RectangleShape> body;
	};
}