#pragma once

#include <SFML/Graphics.hpp>

#include "GameMenu.h"

namespace game {
	class MainMenu {
	public:

		void Start (sf::RenderWindow* w);

	private:

		gameMenu::MenuItem menuItems[4];
		gameMenu::Action* action[4];

		char MenuText[4][15] = {
			"Start",
			"High Score",
			"Options",
			"Exit"
		};
	};

	class StartGameAction :public gameMenu::Action {
	public:

		StartGameAction (sf::RenderWindow*);
		bool start ();

	private:

		sf::RenderWindow* window;
	};

	class HighScoreAction :public gameMenu::Action {
	public:

		HighScoreAction (sf::RenderWindow*);
		bool start ();

	private:

		sf::RenderWindow* window;
	};

	class OptionsAction :public gameMenu::Action {
	public:

		OptionsAction (sf::RenderWindow*);
		bool start ();

	private:

		sf::RenderWindow* window;
	};

	class ExitAction :public gameMenu::Action {
	public:

		ExitAction (sf::RenderWindow*);
		bool start ();

	private:

		bool getConfirmation ();
		sf::RenderWindow* window;

		class ConfirmationMenuAction :public gameMenu::Action {
			bool* confirm;
		public:

			ConfirmationMenuAction (bool* val) {
				confirm = val;
			}

			bool start () {
				*confirm = true;
				return false;
			}
		};

		class DeclineMenuAction :public gameMenu::Action {
			bool* confirm;
		public:

			DeclineMenuAction (bool* val) {
				confirm = val;
			}

			bool start () {
				*confirm = false;
				return false;
			}
		};
	};
}