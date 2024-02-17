#pragma once

class SpriteGo : public GameObject
{
protected:
	sf::Sprite sprite;

public:
	SpriteGo(const std::string& name = "");

	void SetTexture(const std::string& textureId);
	void SetTexture(const sf::Texture& texture);

	void SetPosition(const sf::Vector2f& pos) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetScale(const sf::Vector2f& scale) override;
	void SetFlipX(bool filp) override;
	void SetFlipY(bool filp) override;
<<<<<<< HEAD

	void Draw(sf::RenderWindow& window) override;
=======
	void GetSize(Vector2f& size) const
	{
		size = Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
	}
	void Draw(RenderWindow& window) override;
	void Update(float dt) override
	{
>>>>>>> fa46320 (일단 버튼구역 클릭하면 넘어가는거 도무지 못하겠어서 포기하고 마우스 왼쪽 오른쪽으로 넘어가게 수정)

};

