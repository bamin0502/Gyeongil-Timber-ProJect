#pragma once
// ���� �� �˻����
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
	std::list<GameObject*> _gameObjects; // _gameObjects ������ ������ ��� ����Ʈ ����

public:
	Scene(SceneIds id);
	virtual ~Scene() = default;

	virtual void Init() = 0; // �ڽ�Ŭ���� �ʱ�ȭ
	virtual void Release(); // 

	virtual void Enter(); // �� ���� ����
	virtual void Exit() = 0; // �� ���� ����

	virtual void Update(float dt); // ������ �ð�
	virtual void Draw(sf::RenderWindow& window);

	virtual GameObject* FindGo(const std::string& name); // name�� ã��
	virtual bool FindGoAll(const std::string& name , 
		std::list<GameObject*>& list); // name�� ã��

	virtual GameObject* AddGo(GameObject* obj);
	virtual void RemoveGo(GameObject* obj);
};

