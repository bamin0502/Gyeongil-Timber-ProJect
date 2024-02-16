#pragma once
class GameObject
{
protected:
	bool active = true;
	sf::Vector2f position = { 0.f, 0.f };
	sf::Vector2f scale = { 1.f, 1.f };
	sf::Vector2f origin = { 0.f, 0.f };

	Origins originPreset = Origins::TL;

	bool isFlipX = false;
	bool isFlipY = false;

public:
	GameObject(const std::string& name = "");
	virtual ~GameObject();
	
	virtual void Init();
	virtual void Release();

	virtual bool GetFlipX() const {return isFlipX ;}
	virtual void SetFlipX(bool flip)
	{
		isFlipX = flip;
	}
	virtual bool GetFlipY() const {return isFlipY ;}

	virtual void SetFlipY(bool flip)
	{
		isFlipY = flip;
	}

	virtual void SetPosition(const sf::Vector2f& pos)
	{
		position = pos;
	}
	sf::Vector2f GetPosition()
	{
		return position;
	}

	virtual void SetScale(const sf::Vector2f& pos)
	{
		scale = pos;
	}

	virtual sf::Vector2f GetScale()
	{
		return scale;
	}

	virtual void SetOrigin(Origins preset);

	// origin
	virtual void SetOrigin(const sf::Vector2f& newOrigin)
	{
		originPreset = Origins::CUSTOM;
		origin = newOrigin;
	}
	sf::Vector2f Getorigin()
	{
		return origin;
	}

	virtual void Reset();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

	virtual bool GetActive()
	{
		return active;
	}

	virtual void SetActive(bool active)
	{
		this->active = active;
	}

	// vector3 position , scale , rotation

	std::string name = "";
	int sortLayer = 0; // 레이어 
	int sortOrder = 0; // 같은레이어에서 구분
};



