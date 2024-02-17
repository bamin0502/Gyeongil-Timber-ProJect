#include "pch.h"
#include "MultiPlayer.h"
#include "./Scene/ScenePlayer2Mode.h"
#include "Tree.h"


MultiPlayer::MultiPlayer(const std::string& name , 
	const std::string& tree) : SpriteGo(name) , treeName(tree)
{

}

void MultiPlayer::SetSide(Sides s)
{
	side = s;
	SetScale(scale);
	SetPosition(position);
}

void MultiPlayer::OnDie()
{
	isAlive = false;
	isChopping = false;

	SetTexture(texIdRip);
	SetScale(scale);
}

void MultiPlayer::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	sf::Vector2f spritePos = position;
	switch (side)
	{
	case Sides::LEFT:
		spritePos.x -= offsetPositionX;
		break;
	case Sides::RIGHT:
		spritePos.x += offsetPositionX;
		break;
	}
	sprite.setPosition(spritePos);
	sf::Vector2f axePos = spritePos;
	switch (side)
	{
	case Sides::LEFT:
		axePos.x -= axeLocalPosition.x;
		axePos.y += axeLocalPosition.y;
		break;
	case Sides::RIGHT:
		axePos.x += axeLocalPosition.x;
		axePos.y += axeLocalPosition.y;
		break;
	}
	spriteAxe.setPosition(axePos);
}

void MultiPlayer::SetScale(const sf::Vector2f& s)
{
	scale = s;
	sf::Vector2f playerScale = scale;
	sf::Vector2f axeScale = scale;

	bool playerFilpX = playerSide != side;
	bool axeFilpX = axeSide != side;

	if (playerFilpX)
	{
		playerScale.x = -scale.x;
	}
	if (axeFilpX)
	{
		axeScale.x = -scale.x;
	}

	if (isFlipY)
	{
		playerScale.y = -scale.y;
		axeScale.y = -scale.y;
	}

	if (isAlive)
	{
		sprite.setScale(playerScale);
	}
	else
	{
		sprite.setScale(scale);
	}
	spriteAxe.setScale(axeScale);
}

void MultiPlayer::Init()
{
	RES_MGR_SOUND_BUFFER.Load("sound/chop.wav");
	RES_MGR_SOUND_BUFFER.Load("sound/death.wav");

	SpriteGo::Init();
	SetTexture(texIdPlayer);
	spriteAxe.setTexture(ResourceMgr<sf::Texture>::Instance().Get(texIdAxe));

	SetOrigin(Origins::BC);
	Utils::SetOrigin(spriteAxe, Origins::ML);

	sfxChop.setBuffer(RES_MGR_SOUND_BUFFER.Get("sound/chop.wav"));
	sfxDeath.setBuffer(RES_MGR_SOUND_BUFFER.Get("sound/death.wav"));
}

void MultiPlayer::Release()
{
	SpriteGo::Release();
}

void MultiPlayer::Reset()
{
	SpriteGo::Reset();

	SetTexture(texIdPlayer);
	isAlive = true;
	isChopping = false;

	sceneGame = dynamic_cast<ScenePlayer2Mode*>(SCENE_MGR.GetCurrentScene());
	tree = dynamic_cast<Tree*>(sceneGame->FindGo(treeName));

	SetSide(Sides::RIGHT);

}

void MultiPlayer::Update(float dt)
{
	//if (sceneGame->GetStatus() != ScenePlayer2Mode::Status::Game)
	//	return;

	//Sides inputSide = Sides::NONE;

	//if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	//{
	//	inputSide = Sides::LEFT;
	//}
	//if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	//{
	//	inputSide = Sides::RIGHT;
	//}

	//if (inputSide != Sides::NONE)
	//{
	//	isChopping = true;
	//	sfxChop.play();

	//	Sides branchSide = tree->Chop(inputSide);
	//	sceneGame->PlayEffectLog(inputSide);
	//	SetSide(inputSide);

	//	if (side != branchSide)
	//	{
	//		sceneGame->OnChop();
	//	}
	//	else
	//	{
	//		sceneGame->OnPlayerDie();
	//		OnDie();
	//		sfxDeath.play();
	//	}
	//}

	//if (InputMgr::GetKeyUp(sf::Keyboard::Left) || InputMgr::GetKeyUp(sf::Keyboard::Right))
	//{
	//	isChopping = false;
	//}
}

void MultiPlayer::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	if (isChopping)
	{
		window.draw(spriteAxe);
	}
}

void MultiPlayer::MoveChop(Sides inputSide)
{
	
}
