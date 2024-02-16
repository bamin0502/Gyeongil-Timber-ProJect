#pragma onc
class TimeBar : public GameObject
{
public:
	TimeBar(const std::string& name);
	virtual ~TimeBar();
	void Init() override;
	void Release() override;
	void Reset() override;
	void AddHp();

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	void PlayTimeOutSound();

public:
	sf::RectangleShape _timeBar;
	sf::Vector2f _timeBarSize = {400.f , 80.f};
    sf::Vector2f _timeBarCurrentSize = _timeBarSize;
	bool _isDead = false;

	float _timeBarDuration = 3.f; 
    float _timeBarSpeed = -_timeBarSize.x / _timeBarDuration;

	sf::SoundBuffer _outTimeSoundBuffer;
	sf::Sound _outTimeSound;
};

