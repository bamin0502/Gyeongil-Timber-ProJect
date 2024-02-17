#include "pch.h"
#include "InputMgr.h"


std::list<sf::Keyboard::Key> InputMgr::downList;
std::list<sf::Keyboard::Key> InputMgr::upList;
std::list<sf::Keyboard::Key> InputMgr::ingList;

void InputMgr::UpdateEvent(const sf::Event& ev)
{
    switch (ev.type)
    {
    case sf::Event::KeyPressed:
        if (!GetKey(ev.key.code))
        {
            ingList.push_back(ev.key.code);
            downList.push_back(ev.key.code);
        }
        break;
    case sf::Event::KeyReleased:
        ingList.remove(ev.key.code);
        upList.push_back(ev.key.code);
        break;
    }
}

void InputMgr::Clear()
{
    downList.clear();
    upList.clear();
}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
    //std::list<sf::Keyboard::Key>::iterator it = downList.begin

    //for (auto it = downList.begin(); it != downList.end(); ++it)
    //{
    //    if (*it == key)
    //        return true;
    //}

    //for (auto k : downList)
    //{
    //    if (k == key)
    //        return true;
    //}

    return std::find(downList.begin(), downList.end(), key) != downList.end();
}

bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
    return std::find(upList.begin(), upList.end(), key) != upList.end();
}

bool InputMgr::GetKey(sf::Keyboard::Key key)
{
    return std::find(ingList.begin(), ingList.end(), key) != ingList.end();
}
<<<<<<< HEAD
=======

bool InputMgr::GetMouseButtonDown(Mouse::Button button)
{
    return Mouse::isButtonPressed(button); 
}

bool InputMgr::GetMouseButton(Mouse::Button button)
{
    return Mouse::isButtonPressed(button);
}

sf::Vector2i InputMgr::GetMousePosition()
{
    return Mouse::getPosition();
}







>>>>>>> fa46320 (일단 버튼구역 클릭하면 넘어가는거 도무지 못하겠어서 포기하고 마우스 왼쪽 오른쪽으로 넘어가게 수정)
