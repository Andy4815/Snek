#pragma once
#include <SFML/Graphics.hpp>

namespace game {
	bool checkCollision (const sf::RectangleShape, const sf::RectangleShape&);
	sf::RectangleShape getRectangleAt (sf::Vector2f location, sf::Color);
}