#include <Dojo.h>
#include <memory>
#include <SFML/Graphics.hpp>
#include <algorithm>

typedef sf::Vector2<float> Vector2;

class Sandbox : public Dojo::Application
{
	Sandbox();
	~Sandbox();
};

static sf::Text text;
static int windowWidth, windowHeight;
static sf::RectangleShape* myRectangle;

static std::shared_ptr<Dojo::Entity> player;
static std::vector<std::shared_ptr<Dojo::Entity>> enemies;

Dojo::Application* Dojo::CreateApplication()
{
	windowWidth = sf::VideoMode::getDesktopMode().width * 0.8;
	windowHeight = sf::VideoMode::getDesktopMode().height * 0.8;
	return new Dojo::Application(windowWidth, windowHeight, "Pumpkin Vanisher");
}

long score = 0;
sf::Text* enemyCounter;
sf::Text* totalScore;

void FillScreenWithPumpkins()
{
	std::shared_ptr<Dojo::Entity> jack;

	for (int i = -8; i < windowWidth; i += 5)
	{
		for (int j = -8; j < windowHeight; j += 5)
		{
			jack = Dojo::Application::GetInstance()->CreateEntity("res/img/jack-small.png");
			jack->SetPosition(Vector2(i, j));
			enemies.push_back(jack);
		}
	}
}

void Dojo::Application::Start()
{
	Dojo::Application::SetIcon("res/img/dojo.png");

	FillScreenWithPumpkins();

	player = Dojo::Application::CreateEntity("res/img/player.png");
	player->SetPosition(Vector2(windowWidth / 2 - player->texture->getSize().x, windowHeight / 2 - player->texture->getSize().y));
	player->speed = 0.5f;

	// TEXT
	int yOffset = 60;
	sf::Text* text = Dojo::Application::CreateText("Dojo Engine - Pumpkin Vanisher");
	text->setPosition(Vector2(15, 10));
	text = Dojo::Application::CreateText("- Sprites");
	text->setPosition(Vector2(15, yOffset));
	text->setScale(Vector2(0.5f, 0.5f));
	text = Dojo::Application::CreateText("- Movement W A S D");
	text->setPosition(Vector2(15, yOffset += 20));
	text->setScale(Vector2(0.5f, 0.5f));
	enemyCounter = Dojo::Application::CreateText("Pumpkins: " + enemies.size());
	enemyCounter->setPosition(Vector2(15, yOffset += 40));
	enemyCounter->setScale(Vector2(0.5f, 0.5f));
	totalScore = Dojo::Application::CreateText("Total Score: " + std::to_string(score));
	totalScore->setPosition(Vector2(15, yOffset += 20));
	totalScore->setScale(Vector2(0.5f, 0.5f));
	/*text = Dojo::Application::CreateText("- Mouse Click");
	text->setPosition(Vector2(10, yOffset += 20));
	text->setScale(Vector2(0.5f, 0.5f));*/
	// ----
}

void Dojo::Application::Update(double frameTime)
{
	//DOJO_INFO("Entity count {0}", entities.size());

	if (enemies.size() < 1)
	{
		DOJO_INFO("Repopulating");
		FillScreenWithPumpkins();
	}

	//DOJO_INFO("Frame time {0}", frameTime);

	for (std::shared_ptr<Dojo::Entity> e : enemies)
	{
		if (e == NULL) continue;
		if (e->sprite == NULL) continue;

		if (this == NULL) continue;

		if (player->sprite->getGlobalBounds().intersects(e->sprite->getGlobalBounds()))
		{
			enemies.erase(std::remove(enemies.begin(), enemies.end(), e), enemies.end());

			score++;

			Application::DestroyEntity(e);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player->Move(1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player->Move(-1, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player->Move(0, -1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player->Move(0, 1);

	/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		player->SetPosition(Vector2(
			sf::Mouse::getPosition(*Dojo::Application::windowReference).x - player->texture->getSize().x / 2,
			sf::Mouse::getPosition(*Dojo::Application::windowReference).y - player->texture->getSize().y / 2)
		);
	}*/

	//DOJO_CLIENT_INFO("Player pos ({0}, {1})", player.position.x, player.position.y);
	enemyCounter->setString("Pumpkins: " + std::to_string(enemies.size()));
	totalScore->setString("Total Score: " + std::to_string(score));
}

void Dojo::Application::KeyPressed(sf::Keyboard::Key keyCode)
{
	if (keyCode == sf::Keyboard::Space)
	{
		for (std::shared_ptr<Dojo::Entity> e : enemies)
		{
			enemies.erase(std::remove(enemies.begin(), enemies.end(), e), enemies.end());
			Application::DestroyEntity(e);
		}

		FillScreenWithPumpkins();
	}
}

void Dojo::Application::EndOfFrame() {}
Sandbox::~Sandbox() {}