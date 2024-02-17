#pragma once

class InputMgr
{
private:
	static std::list<sf::Keyboard::Key> downList;
	static std::list<sf::Keyboard::Key> upList;
	static std::list<sf::Keyboard::Key> ingList;

public:
	static void UpdateEvent(const sf::Event& ev);
	static void Clear();

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);
<<<<<<< HEAD

=======
	static bool GetMouseButtonDown(sf::Mouse::Button button);
	static bool GetMouseButton(sf::Mouse::Button button);
	static sf::Vector2i GetMousePosition();
>>>>>>> fa46320 (일단 버튼구역 클릭하면 넘어가는거 도무지 못하겠어서 포기하고 마우스 왼쪽 오른쪽으로 넘어가게 수정)
};

