#include "MainMenu.h"

int main () {

	sf::RenderWindow window (sf::VideoMode (800, 8000), "Snek", sf::Style::Close);
	game::MainMenu menu;
	menu.Start (&window);

	return 0;
}