#pragma once
#include "GameObject.h"
class TextGo : public GameObject
{
 protected:
	sf::Text text;

public:
	TextGo(const std::string& name);

	void Set(const sf::Font& texture, const std::string str ,
		const int size, const sf::Color color);

	void SetString(const std::string& str);

	void SetFont(const sf::Font& font);
	void SetFont(const std::string& fontId);

	void Draw(sf::RenderWindow& window) override; // GameObject 상속메서드

	void SetPosition(const sf::Vector2f& pos) override;
	void SetScale(const sf::Vector2f& pos) override;
	void SetFlipX(bool flip) override;
	void SetFlipY(bool flip) override;

	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetOrigin(Origins preset) override;
};



