#include <Dojo.h>
#include <memory>
#include <SFML/Graphics.hpp>

typedef sf::Vector2<float> Vector2;

class Sandbox : public Dojo::Application
{
	Sandbox();
	~Sandbox();
};

static sf::Text text;
static int windowWidth, windowHeight;
static sf::RectangleShape* myRectangle;

static Dojo::Entity* entity;

Dojo::Application* Dojo::CreateApplication()
{
	windowWidth = sf::VideoMode::getDesktopMode().width * 0.8;
	windowHeight = sf::VideoMode::getDesktopMode().height * 0.8;
	return new Dojo::Application(windowWidth, windowHeight, "Sample Program");
}

void Dojo::Application::Start()
{
	Dojo::Application::SetIcon("res/img/dojo.png");

	entity = Dojo::Application::CreateEntity("res/img/player.png");
	entity->SetPosition(Vector2(windowWidth / 2 - 128, windowHeight / 2 - 128));

	// TEXT
	int yOffset = 60;
	sf::Text* text = Dojo::Application::CreateText("Dojo Engine");
	text->setPosition(Vector2(10, 10));
	text = Dojo::Application::CreateText("- Sprites");
	text->setPosition(Vector2(10, yOffset));
	text->setScale(Vector2(0.5f, 0.5f));
	text = Dojo::Application::CreateText("- Movement W A S D");
	text->setPosition(Vector2(10, yOffset += 20));
	text->setScale(Vector2(0.5f, 0.5f));
	text = Dojo::Application::CreateText("- Mouse Click");
	text->setPosition(Vector2(10, yOffset += 20));
	text->setScale(Vector2(0.5f, 0.5f));
	// ----
}

void Dojo::Application::Update(double frameTime)
{
	//DOJO_INFO("Frame time {0}", frameTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		entity->Move(1, 0, frameTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		entity->Move(-1, 0, frameTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		entity->Move(0, -1, frameTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		entity->Move(0, 1, frameTime);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		entity->SetPosition(Vector2(
			sf::Mouse::getPosition(*Dojo::Application::windowReference).x - 128,
			sf::Mouse::getPosition(*Dojo::Application::windowReference).y - 128));
	}

	//DOJO_CLIENT_INFO("Player pos ({0}, {1})", player.position.x, player.position.y);
}

void Dojo::Application::KeyPressed(sf::Keyboard::Key keyCode)
{
	//if (keyCode == sf::Keyboard::Space)
}

void Dojo::Application::EndOfFrame() {}
Sandbox::~Sandbox() {}