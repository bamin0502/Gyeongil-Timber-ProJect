#include "pch.h"
#include "ResourceMgr.h"
#include "Utils.h"
#include "Singleton.h"
#include <sstream>

void InitGame();
void UpdateBranches();
int updateBranchesCount = 0;
const int NUM_OF_BRANCEHS = 6;

sf::Vector2f timeBarSize(400.f, 80.f);
sf::Vector2f timeBarCurrentSize = timeBarSize;
sf::Sprite branches[NUM_OF_BRANCEHS];
Sides brancheSides[NUM_OF_BRANCEHS];
Sides playerSide;
int score = 0;

int main()
{
    srand(time(NULL));

    float windowWidth = 1920;
    float windowHeight = 1080;

    //SceneMgr::Instance().Init(); 생성 
    //SceneMgr::Instance().Release(); 제거

    SceneMgr& scenMgr = SceneMgr::Instance();
    scenMgr.Init();


    sf::VideoMode vm(windowWidth, windowHeight);
    sf::RenderWindow window(vm, "SFML works!", sf::Style::Default);
    scenMgr.Draw(window);
    auto& textMgr = ResourceMgr<sf::Texture>::Instance();
    auto& fontMgr = ResourceMgr<sf::Font>::Instance();

    textMgr.Load("graphics/background.png");
    textMgr.Load("graphics/cloud.png");
    textMgr.Load("graphics/bee.png");
    textMgr.Load("graphics/tree.png");
    textMgr.Load("graphics/branch.png");

    textMgr.Load("graphics/player.png");
    textMgr.Load("graphics/axe.png");

    sf::Sprite spirteBackground;
    spirteBackground.setTexture(*textMgr.Get("graphics/background.png"));
    spirteBackground.setPosition(0, 0);

    sf::Sprite spriteCloud1;
    spriteCloud1.setTexture(*textMgr.Get("graphics/cloud.png"));
    spriteCloud1.setPosition(1920 / 2, 1080 / 2);
    spriteCloud1.setOrigin(0.f, 0.f);
    sf::Sprite spriteCloud2;
    spriteCloud2.setTexture(*textMgr.Get("graphics/cloud.png"));
    spriteCloud2.setPosition(0, 200);
    sf::Sprite spriteCloud3;
    spriteCloud3.setTexture(*textMgr.Get("graphics/cloud.png"));
    spriteCloud3.setPosition(0, 400);
    sf::Sprite spriteBee;
    spriteBee.setTexture(*textMgr.Get("graphics/bee.png"));
    spriteBee.setPosition(1920 / 2, 1080 / 2);

    Utils::SetOrigin(spriteBee, Origins::MC);

    sf::Sprite spriteTree;
    spriteTree.setTexture(*textMgr.Get("graphics/tree.png"));
    spriteTree.setPosition(1920 / 2, 0);
    spriteTree.setOrigin(300 / 2, 0);

    float beeSpeed = 100.f;
    sf::Vector2f beeDirection(1.f, 0.f);
    spriteBee.setScale(-1.0, 1.f);

    float cloud1Speed = rand() % 201 + 100; // 100 ~ 300
    sf::Vector2f cloud1Direction(1.f, 0.f);

    sf::Transform rotation;
    float zeroToOne = (float)rand() / RAND_MAX; // 0.0 ~ 1.0
    float angle = zeroToOne * 360.f; // 0.0 ~ 360.0
    rotation.rotate(angle);
    cloud1Direction = rotation * cloud1Direction;

    float beeDirChangeDuration = 1.f;
    float beeChangeTime = beeDirChangeDuration;

    for (int i = 0; i < NUM_OF_BRANCEHS; ++i)
    {
        branches[i].setTexture(*textMgr.Get("graphics/branch.png"));
        Utils::SetOrigin(branches[i], Origins::ML);
    }

    InitGame();

    sf::Vector2f playerPos[2] =
    {
        {
            windowWidth * 0.5f - 300,
            spriteTree.getLocalBounds().height
        },
        {
            windowWidth * 0.5f + 300,
            spriteTree.getLocalBounds().height
        },
    };
    sf::Vector2f playerScale[2] =
    {
        { -1.f, 1.f },
        { 1.f, 1.f },
    };

    sf::Vector2f axePos[2] =
    {
        {
            playerPos[0].x + 60,
            playerPos[0].y - 65,
        },
        {
            playerPos[1].x - 60,
            playerPos[1].y - 65,
        },
    };
    sf::Vector2f axeScale[2] =
    {
        { 1.f, 1.f },
        { -1.f, 1.f },
    };

    sf::Sprite spritePlayer;
    spritePlayer.setTexture(*textMgr.Get("graphics/player.png"));
    Utils::SetOrigin(spritePlayer, Origins::BC);
    spritePlayer.setPosition(playerPos[(int)playerSide]);
    spritePlayer.setScale(playerScale[(int)playerSide]);
    fontMgr.Load("fonts/KOMIKAP_.ttf");

    sf::Sprite spriteAxe;
    spriteAxe.setTexture(*textMgr.Get("graphics/axe.png"));
    Utils::SetOrigin(spriteAxe, Origins::ML);
    spriteAxe.setPosition(axePos[(int)playerSide]);
    spriteAxe.setScale(axeScale[(int)playerSide]);

    sf::Text textMessage;
    textMessage.setFont(*fontMgr.Get("fonts/KOMIKAP_.ttf"));
    textMessage.setString("Press Enter to Start!");
    textMessage.setCharacterSize(75);
    textMessage.setFillColor(sf::Color::White);
    Utils::SetOrigin(textMessage, Origins::MC);
    textMessage.setPosition(1920 / 2, 1080 / 2);

    
    std::stringstream ss;
    ss << "Score : " << score;

    sf::Text textScore;
    textScore.setFont(*fontMgr.Get("fonts/KOMIKAP_.ttf"));
    textScore.setString(ss.str());
    textScore.setCharacterSize(40);
    textScore.setFillColor(sf::Color::White);
    textScore.setPosition(50, 50);


    sf::RectangleShape timeBar;
    timeBar.setSize(timeBarCurrentSize);
    timeBar.setFillColor(sf::Color::Red);
    Utils::SetOrigin(timeBar, Origins::MC);
    timeBar.setPosition(1920 / 2, 1080 - 80);

    float timeBarDuration = 3.f;
    float timeBarSpeed = -timeBarSize.x / timeBarDuration;

    sf::Clock clock;
    float realTime = 0.f;
    float realDeltaTime = 0.f;

    float time = 0.f;
    float deltaTime = 0.f;
    bool isPause = true;
    float timeScale = isPause ? 0.f : 1.f;

    while (window.isOpen())
    {
        InputMgr::Clear();

        sf::Time dt = clock.restart();
        realDeltaTime = dt.asSeconds();
        realTime += realDeltaTime;

        deltaTime = realDeltaTime * timeScale;
        time += deltaTime;

        scenMgr.Update(realDeltaTime);

        sf::Event event;
        while (window.pollEvent(event))
        {
            InputMgr::UpdateEvent(event);

            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }


        if (!isPause)
        {
            bool isMove = false;
            Sides prevPlayerSide = playerSide;
            if (InputMgr::GetKeyDown(sf::Keyboard::Left))
            {
                playerSide = Sides::LEFT;
                isMove = true;
                UpdateBranches();
            }

            if (InputMgr::GetKeyDown(sf::Keyboard::Right))
            {
                playerSide = Sides::RIGHT;
                isMove = true;
                UpdateBranches();
            }

            if (prevPlayerSide != playerSide)
            {
                spritePlayer.setPosition(playerPos[(int)playerSide]);
                spritePlayer.setScale(playerScale[(int)playerSide]);
                spriteAxe.setPosition(axePos[(int)playerSide]);
                spriteAxe.setScale(axeScale[(int)playerSide]);
            }

            if (isMove)
            {
                if (playerSide == brancheSides[NUM_OF_BRANCEHS - 1])
                {
                    isPause = true;
                    timeScale = 0.f;
                    textMessage.setString("Game Over. Press Enter to Restart!");
                    Utils::SetOrigin(textMessage, Origins::MC);
                }
                else
                {
                    score += 10;

                    timeBarCurrentSize.x += 50;
                    if (timeBarCurrentSize.x > timeBarSize.x)
                    {
                        timeBarCurrentSize.x = timeBarSize.x;
                    }
                }
            }
        }
        else
        {
            if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
            {
                isPause = !isPause;
                timeScale = isPause ? 0.f : 1.f;
                if (playerSide == brancheSides[NUM_OF_BRANCEHS - 1]
                    || timeBarCurrentSize.x == 0.f)
                {
                    InitGame();
                }
            }
        }

        //std::cout << deltaTime << std::endl;
        if (time > beeChangeTime)
        {
            sf::Transform rotation;
            float zeroToOne = (float)rand() / RAND_MAX; // 0.0 ~ 1.0
            float angle = zeroToOne * 360.f; // 0.0 ~ 360.0
            rotation.rotate(angle);
            beeDirection = rotation * beeDirection;
            if (beeDirection.x > 0.f)
            {
                spriteBee.setScale(-1.f, 1.f);
            }
            else if (beeDirection.x < 0.f)
            {
                spriteBee.setScale(1.f, 1.f);
            }

            beeChangeTime = time + beeDirChangeDuration;
        }

        sf::Vector2f beePos = spriteBee.getPosition();
        beePos += beeDirection * beeSpeed * deltaTime;
        spriteBee.setPosition(beePos);

        sf::Vector2f cloud1Pos = spriteCloud1.getPosition();
        cloud1Pos += cloud1Direction * cloud1Speed * deltaTime;
        spriteCloud1.setPosition(cloud1Pos);

        float treeHalfWidth = spriteTree.getLocalBounds().width * 0.5f;
        float centerX = windowWidth * 0.5f;

        for (int i = 0; i < NUM_OF_BRANCEHS; ++i)
        {
            float y = i * 150.f;
            switch (brancheSides[i])
            {
            case Sides::LEFT:
                branches[i].setScale(-1.f, 1.f);
                branches[i].setPosition(centerX - treeHalfWidth, y);
                break;
            case Sides::RIGHT:
                branches[i].setScale(1.f, 1.f);
                branches[i].setPosition(centerX + treeHalfWidth, y);
                break;
            default:
                branches[i].setPosition(-2000, -2000);
                break;
            }
        }

        // UI
        timeBarCurrentSize.x += timeBarSpeed * deltaTime;
        if (timeBarCurrentSize.x < 0)
        {
            timeBarCurrentSize.x = 0.f;
            isPause = true;
            timeScale = 0.f;
            textMessage.setString("Game Over. Press Enter to Restart!");
            Utils::SetOrigin(textMessage, Origins::MC);
        }

        timeBar.setSize(timeBarCurrentSize);

        std::string str = "Score: ";
        str += std::to_string(score);
        textScore.setString(str);

        window.clear();

        // Draw
        window.draw(spirteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        for (int i = 0; i < NUM_OF_BRANCEHS; ++i)
        {
            window.draw(branches[i]);
        }
        window.draw(spriteTree);
        window.draw(spritePlayer);
        window.draw(spriteAxe);
        window.draw(spriteBee);

        // ---
        if (isPause)
        {
            window.draw(textMessage);
        }
        window.draw(textScore);
        window.draw(timeBar);

        window.display();
    }

    return 0;
}

void InitGame()
{
    for (int i = 0; i < NUM_OF_BRANCEHS; ++i)
    {
        UpdateBranches();
    }
    brancheSides[NUM_OF_BRANCEHS - 1] = Sides::NONE;
    brancheSides[NUM_OF_BRANCEHS - 2] = Sides::NONE;
    playerSide = Sides::RIGHT;
    timeBarCurrentSize.x = timeBarSize.x;
    score = 0;
}

void UpdateBranches()
{
    ++updateBranchesCount;

    for (int i = NUM_OF_BRANCEHS - 1; i > 0; --i)
    {
        brancheSides[i] = brancheSides[i - 1];
    }

    //int side = (updateBranchesCount % 2 == 0) ? (int)Sides::NONE : rand() % 3;
    int side = rand() % 3;
    switch (side)
    {
    case 0:
        brancheSides[0] = Sides::LEFT;
        break;
    case 1:
        brancheSides[0] = Sides::RIGHT;
        break;
    default:
        brancheSides[0] = Sides::NONE;
        break;
    }
}
