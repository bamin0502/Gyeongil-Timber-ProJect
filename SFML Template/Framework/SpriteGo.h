#pragma once

class SpriteGo : public GameObject
{
protected:
	sf::Sprite sprite;

public:
	SpriteGo(const std::string& name);

	void SetTexture(const sf::Texture& texture);
	void SetTexture(const std::string& textureId);

	void Draw(sf::RenderWindow& window) override; // GameObject 상속메서드

	void SetPosition(const sf::Vector2f& pos) override;
	void SetScale(const sf::Vector2f& pos) override;
	void SetFlipX(bool flip) override;
	void SetFlipY(bool flip) override;

	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetOrigin(Origins preset) override;

};

