#pragma once
// 현재 씬 검색기능
// 

class Scene
{
protected:
	Scene(const Scene&) = delete;
	Scene(Scene&&) = delete;

	Scene& operator=(const Scene&) = delete;
	Scene& operator=(Scene&&) = delete;

	ResourceMgr<sf::Texture>& texResMgr;
	ResourceMgr<sf::Font>& fontMgr;

	SceneIds _id;
	std::list<GameObject*> _gameObjects; // _gameObjects 포인터 변수를 담는 리스트 생성

public:
	Scene(SceneIds id);
	virtual ~Scene() = default;

	virtual void Init() = 0; // 자식클래스 초기화
	virtual void Release(); // 

	virtual void Enter(); // 씬 시작 구현
	virtual void Exit() = 0; // 씬 종료 구현

	virtual void Update(float dt); // 프레임 시간
	virtual void Draw(sf::RenderWindow& window);

	virtual GameObject* FindGo(const std::string& name); // name로 찾음
	virtual bool FindGoAll(const std::string& name , 
		std::list<GameObject*>& list); // name로 찾음

	virtual GameObject* AddGo(GameObject* obj);
	virtual void RemoveGo(GameObject* obj);
};

