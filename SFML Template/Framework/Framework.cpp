#include "pch.h"
#include "Framework.h"
#include "SceneMgr.h"
#include <stdlib.h>
#include <ctime>

Framework::~Framework()
{

}

void Framework::Init(int width, int height, const std::string& name)
{
     srand(std::time(NULL));
     windowSize.x = width;
     windowSize.y = height;

     window.create(sf::VideoMode(windowSize.x, windowSize.y), 
         name);
    //sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

    SceneMgr& scenMgr = SceneMgr::Instance();
    SCENE_MGR.Init(); 
}

void Framework::Do()
{
    while (window.isOpen())
    {
        deltaTime = realDeltaTime = clock.restart();
        deltaTime *= timeScale;

        time += deltaTime;
        realTime += realDeltaTime;

        InputMgr::Clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputMgr::UpdateEvent(event);
        }

        SCENE_MGR.Update(GetDT());

        window.clear();

        SCENE_MGR.Draw(window);

        window.display();
    }
}

void Framework::Release()
{
}
