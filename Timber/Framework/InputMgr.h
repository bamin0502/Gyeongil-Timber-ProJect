#pragma once

class InputMgr
{
private:
	static std::list<sf::Keyboard::Key> downList;
	static std::list<sf::Keyboard::Key> upList;
	static std::list<sf::Keyboard::Key> ingList;
	static std::list<sf::Mouse::Button> mouseDownList; 
	static std::list<sf::Mouse::Button> mouseUpList;
	static std::list<sf::Mouse::Button> mouseIngList;
public:
	static void UpdateEvent(const sf::Event& ev);
	static void Clear();

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	static bool GetMouseButtonDown(sf::Mouse::Button button);
	static bool GetMouseButton(sf::Mouse::Button button);
	static bool GetMouseButtonUp(sf::Mouse::Button button);
	static sf::Vector2i GetMousePosition();

};

