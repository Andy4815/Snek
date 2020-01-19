#pragma once

#include <SFML/Graphics.hpp>

namespace game {
	bool checkCollisionA (const sf::RectangleShape shape1, const sf::RectangleShape& shape2);
	sf::RectangleShape getRectangleAt (sf::Vector2f location, sf::Color);
}