#pragma once

// 1. 초기ㅗ하 / 메인루프 / 메모리 정리
// 2. 시간 관련 기능 / SFML 윈도우 정보
// 3. Framework 매니저 관리 

class Framework : public Singleton<Framework>
{
	friend Singleton<Framework>;

protected:
	// 윈도우
	Framework() = default;
	virtual ~Framework();

	sf::RenderWindow window;
	sf::Vector2i windowSize; // 해상도

	// 시간
	sf::Clock clock;
	float timeScale = 1.f;

	sf::Time time; // 게임 시작부터 경과시간 (timeScale 적용)
	sf::Time realDeltaTime; //
	sf::Time realTime; // 게임 시작부터 경과 시간
	sf::Time deltaTime;

public:
	sf::RenderWindow& GetWindow(){ return window;}
	const sf::Vector2i GetWindowSize() { return windowSize; }

	float GetDT() const {return deltaTime.asSeconds();}
	float GetRealDT() const {return realDeltaTime.asSeconds();}

	float GetTime() const {return time.asSeconds();}
	float GetRealTime() const {return realTime.asSeconds();}

	float GetTimeScale() const {return timeScale; }
	void SetTimeScale(float scale) { timeScale = scale; }

	virtual void Init(int width, int height , 
		const std::string& name = "");
	virtual void Do();
	virtual void Release();
	
};

#define FRAMEWORK (Singleton<Framework>::Instance())