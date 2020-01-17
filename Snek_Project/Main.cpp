#include "MainMenu.h"

int main () {
	sf::RenderWindow window (sf::VideoMode (800, 800), "Snek", sf::Style::Close);
	game::MainMenu menu;
	menu.start (&window);
	return 0;
}