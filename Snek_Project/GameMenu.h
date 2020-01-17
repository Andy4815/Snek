#pragma once
#include <SFML/Graphics.hpp>
namespace gmenu {

	class Action {
	public:
		virtual bool start () = 0;
	};

	struct MenuItem {
		Action* action;
		std::string title;
	};

	class Menu {
	private:

		struct {
			MenuItem* entries;
			int8_t size;
		} menu_items;

		struct coordinates {
			coordinates () { x = y = 0.f; size = 0; }
			float x;
			float y;
			int size;
		} *menu_location, title_location;


		int currently_selected_item = 0;

		sf::Font MenuItemFont;
		sf::Font MenuTitleFont;
		sf::RenderWindow* window;
		std::string menu_title;

		float MenuTitleScaleFactor = 0.125;
		float MenuItemScaleFactor = 0.25;


		void writeText (std::string string, sf::Font font, unsigned int size, float x, float y,
			const sf::Color& color = sf::Color::White);

		void setMenu ();

		void drawMenu ();

	public:
		Menu (sf::RenderWindow* wnd) {
			window = wnd;
			//TODO
			if (!MenuItemFont.loadFromFile ("sansation.ttf"))
				exit (0);
			MenuTitleFont.loadFromFile ("sansation.ttf");
		}

		Menu (sf::RenderWindow* window, std::string title) : Menu (window) {
			setTitle (title);
		}

		Menu (sf::RenderWindow* window, std::string title, MenuItem* items, int8_t length) : Menu (window, title) {
			setMenuItems (items, length);
		}

		void setMenuItems (MenuItem*, int8_t);

		void setTitle (std::string title);

		void createMenu ();

	}; // Menu

}
