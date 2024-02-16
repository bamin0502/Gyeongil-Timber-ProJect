#pragma once

// 1. �ʱ���� / ���η��� / �޸� ����
// 2. �ð� ���� ��� / SFML ������ ����
// 3. Framework �Ŵ��� ���� 

class Framework : public Singleton<Framework>
{
	friend Singleton<Framework>;

protected:
	// ������
	Framework() = default;
	virtual ~Framework();

	sf::RenderWindow window;
	sf::Vector2i windowSize; // �ػ�

	// �ð�
	sf::Clock clock;
	float timeScale = 1.f;

	sf::Time time; // ���� ���ۺ��� ����ð� (timeScale ����)
	sf::Time realDeltaTime; //
	sf::Time realTime; // ���� ���ۺ��� ��� �ð�
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