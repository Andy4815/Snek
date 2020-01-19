#include "MainMenu.h"
#include "Game.h"

void game::MainMenu::Start (sf::RenderWindow* w)
{
	gameMenu::Menu menu (w);
	action[0] = new StartGameAction (w);
	action[3] = new ExitAction (w);
	gameMenu::MenuItem items[4];

	for (int i = 0; i < 4; ++i) {
		items[i].title = MenuText[i];
		items[i].action = action[0];
	}

	items[3].action = action[3];
	menu.SetMenuItems (items, 4);
	menu.SetTitle ("Snek");
	menu.CreateMenu ();
}

game::StartGameAction::StartGameAction (sf::RenderWindow* w) {
	window = w;
}

bool game::StartGameAction::start () {
	game::GameController gameController (window);
	gameController.Start ();
	return true;
}

game::HighScoreAction::HighScoreAction (sf::RenderWindow* w) {
	window = w;
}

bool game::HighScoreAction::start () {
	return false;
}

game::OptionsAction::OptionsAction (sf::RenderWindow* w) {
	window = w;
}

bool game::OptionsAction::start () {
	return false;
}

game::ExitAction::ExitAction (sf::RenderWindow* w) {
	window = w;
}

bool game::ExitAction::start () {
	if (getConfirmation ()) {
		return false;//exit
	}

	return true;//no exit
}

bool game::ExitAction::getConfirmation () {
	bool confirm = true;
	gameMenu::MenuItem items[2];

	items[0].title = "Yes";
	items[0].action = new ConfirmationMenuAction (&confirm);
	items[1].title = "No";
	items[1].action = new DeclineMenuAction (&confirm);

	gameMenu::Menu dialog (window, "Are you sure?", items, 2);
	dialog.CreateMenu ();

	return confirm;
}