#include "pch.h"
#include "InputMgr.h"


std::list<sf::Keyboard::Key> InputMgr::downList;
std::list<sf::Keyboard::Key> InputMgr::upList;
std::list<sf::Keyboard::Key> InputMgr::ingList;
std::list<sf::Mouse::Button> InputMgr::mouseDownList;
std::list<sf::Mouse::Button> InputMgr::mouseUpList;
std::list<sf::Mouse::Button> InputMgr::mouseIngList;
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
    case sf::Event::MouseButtonPressed:
        if(!GetMouseButton(ev.mouseButton.button))
        {
            mouseIngList.push_back(ev.mouseButton.button);
            mouseDownList.push_back(ev.mouseButton.button);
        }
        break;
    case sf::Event::MouseButtonReleased:
        mouseIngList.remove(ev.mouseButton.button);
        mouseUpList.push_back(ev.mouseButton.button);
        break;
    }
}

void InputMgr::Clear()
{
    downList.clear();
    upList.clear();
    mouseDownList.clear();
    mouseUpList.clear();
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


bool InputMgr::GetMouseButtonDown(Mouse::Button button)
{
    return find(mouseDownList.begin(), mouseDownList.end(), button) != mouseDownList.end();
}

bool InputMgr::GetMouseButton(Mouse::Button button)
{
    return find(mouseIngList.begin(), mouseIngList.end(), button) != mouseIngList.end();
}

bool InputMgr::GetMouseButtonUp(sf::Mouse::Button button)
{
    return find(mouseUpList.begin(), mouseUpList.end(), button) != mouseUpList.end();
}

sf::Vector2i InputMgr::GetMousePosition()
{
    return sf::Mouse::getPosition();
}
