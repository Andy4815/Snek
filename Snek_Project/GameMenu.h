#pragma once

#include <SFML/Graphics.hpp>
#include <memory>


namespace gameMenu {

	class Action {
	public:

		virtual bool start () = 0;
	};

	struct MenuItem{
		//Action* action;
		//std::string title;
		std::shared_ptr<Action> action;
		std::string title;
	};

	enum Layout {
		TitleCentre = 1 << 0,
		TitleRight = 1 << 1,
		TitleLeft = 1 << 2,

		ItemCentre = 1 << 3,
		ItemRight = 1 << 4,
		ItemLeft = 1 << 5,

		Default = TitleCentre | ItemCentre,
	};

	struct Style {
		sf::Font& TitleFont;
		sf::Font& ItemFont;

		sf::Color TitleColor = sf::Color::Green;
		sf::Color ItemColor = sf::Color::Red;
		sf::Color Selected = sf::Color::Blue;

		unsigned int TitleFontSize = 50;
		unsigned int ItemFontSize = 20;

		struct {
			signed int top, left;
		}PaddingItems, PaddingTitle;

		int layout = Layout::Default;
		Style(sf::Font &mf, sf::Font &itmf):
			TitleFont (mf), ItemFont (itmf), PaddingTitle{ 10,0 }, PaddingItems{ 0,0 }{
		}
	};

	class Menu {
	private:

		struct{
			MenuItem* entries;
			int8_t size;
		}menu_items;

		struct coordinates {
			coordinates () { x = y = 0.f; size = 0; }
			float x;
			float y;
			int size;
		}*menu_location, title_location;

		int currently_selected_item = 0;

		Style& style;

		sf::Font MenuItemFont;
		sf::Font MenuTitleFont;
		sf::RenderWindow* window;

		std::vector<MenuItem> menuItems;
		std::vector<MenuItem> item_location;
		std::string menu_title;

		float MenuTitleScaleFactor = 0.125f;
		float MenuItemScaleFactor = 0.25f;

		void WriteText (std::string, sf::Font font, unsigned int size, float x, float y, const sf::Color color = sf::Color::White);
		void SetMenu ();
		void DrawMenu ();

	public:

		/*Menu (sf::RenderWindow* wnd) {
			window = wnd;
			if (!MenuItemFont.loadFromFile ("sansation.ttf")) {
				exit (0);
			}
			MenuTitleFont.loadFromFile ("sansation.ttf");
		}

		Menu (sf::RenderWindow* window, std::string title) :Menu (window) {
			SetTitle (title);
		}

		Menu (sf::RenderWindow* window, std::string title, MenuItem* items, int8_t length) : Menu (window, title) {
			SetMenuItems (items, length);
		}*/

		Menu (sf::RenderWindow* wnd, std::string title, std::vector<MenuItem> items, Style& st) :
			style (st), window (wnd) {
			menu_title = title;
			menuItems = items;
		}

		//void SetMenuItems (MenuItem*, int8_t);
		void SetMenuItems (std::vector<MenuItem> items);
		void SetTitle (std::string title);
		void CreateMenu ();
	};

	template<class T> inline T operator~(T a) {
		return (T)~(int)a;
	}
	template<class T> inline T operator| (T a, T b) {
		return T ((int)a | (int)b);
	}
	template<class T> inline T operator& (T a, T b) {
		return (T)((int)a & (int)b);
	}
	template<class T> inline T operator^ (T a, T b) {
		return (T)((int)a ^ (int)b);
	}
	template<class T> inline T& operator|= (T& a, T b) {
		return (T&)((int&)a |= (int)b);
	}
	template<class T> inline T& operator&= (T& a, T b) {
		return (T&)((int&)a &= (int)b);
	}
	template<class T> inline T& operator^= (T& a, T b) {
		return (T&)((int&)a ^= (int)b);
	}
}