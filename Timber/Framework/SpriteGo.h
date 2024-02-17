#pragma once
#include <functional>

class SpriteGo : public GameObject
{
public:
	void SetOnClickCallback(const function<void(GameObject*)>& callback) {
		onClickCallback = callback; 
	}
private:
	function<void(GameObject*)> onClickCallback;

	bool isMouseButtonDown = false;
	Glsl::Vec2 mousePosition;
protected:
	Sprite sprite;

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

	void Draw(sf::RenderWindow& window) override;
	void Update(float dt) override
	{
		// 마우스 입력 상태 업데이트
		isMouseButtonDown = GetMouseButtonState(); 
		mousePosition = GetMousePosition();
	}
	// 마우스 버튼 상태를 가져오는 함수
	bool SpriteGo::GetMouseButtonState() {
		// 플랫폼 별 마우스 입력 처리
		
	}

	// 마우스 위치를 가져오는 함수  
	Glsl::Vec2 SpriteGo::GetMousePosition() {
		// 플랫폼 별 마우스 입력 처리
		
	}
};

