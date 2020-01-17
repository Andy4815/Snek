#include "Game.h"

#include <random>
#include <iostream>

namespace game {

	GameController::GameController (sf::RenderWindow* w) : snake (w) {
		screen = w;
		score = 0;
	}

	void GameController::start () {
		loadResources ();
		gameLoop ();
	}

	void GameController::gameLoop (){
		bool loopInvarient = true;

		sf::Vector2<int> direction (-1, 0);
		scale = 5;

		Food* food = new Food (screen, snake.getNextFoodLocation ());

		while (loopInvarient) {
			setupScene ();
			food->DrawFood ();
			sf::Event event;

			while (screen->pollEvent (event)) {
				if (event.type == sf::Event::KeyReleased) {
					if (event.key.code == sf::Keyboard::Up) {
						direction.y = -1;
						direction.x = 0;
					}

					else if (event.key.code == sf::Keyboard::Down) {
						direction.y = 1;
						direction.x = 0;
					}

					else if (event.key.code == sf::Keyboard::Left) {
						direction.x = -1;
						direction.y = 0;
					}

					else if (event.key.code == sf::Keyboard::Right) {
						direction.x = 1;
						direction.y = 0;
					}
				}

				if (event.type == sf::Event::Closed) {
					exit (0);
				}
			} //event loop

			snake.moveSnake (direction);

			if (snake.died ()) {
				loopInvarient = false;
			}

			if (snake.ateFood (food)) {
				score++;
				delete food;
				food = new Food (screen, snake.getNextFoodLocation ());
			}

			screen->display ();
			screen->setFramerateLimit (60);
		}
	} //gameLoop()

	void GameController::setupScene () {
		screen->clear ();
		snake.drawSnake ();
	}

	bool checkCollision (const sf::RectangleShape& a, const sf::RectangleShape& b) {
		return a.getGlobalBounds ().intersects (b.getGlobalBounds ());
	}

	sf::RectangleShape getRectangleAt (sf::Vector2f location, sf::Color color) {
		sf::RectangleShape box;
		box.setSize (sf::Vector2f (BOX_SIZE, BOX_SIZE));
		box.setFillColor (color);
		return box;
	}

	void GameController::loadResources () {
		//To be done
	}

	sf::Font* GameController::getFont (Fonts font) {
		return &fontList[font];
	}
}