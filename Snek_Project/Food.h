#pragma once
#include <SFML/Graphics.hpp>

#include "Engine.h"

#include <iostream>
#include <random>

namespace game {
	class Food {
	public:

		Food (sf::RenderWindow* w, sf::Vector2f loc);
		sf::RectangleShape getFood ();

		void DrawFood ();

		~Food () {
			std::cout << "Food\n";
		}

	private:

		sf::Color color;
		sf::Vector2f location;
		sf::RectangleShape food;
		sf::RenderWindow* screen;
	};
}