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
	return new Dojo::Application(windowWidth, windowHeight, "Sprite Render Test");
}

void Dojo::Application::Start()
{
	Dojo::Application::SetIcon("res/img/dojo.png");

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(125, 125));
	rectangle.setOutlineColor(sf::Color(163, 190, 140));
	rectangle.setFillColor(sf::Color(76, 86, 106));
	rectangle.setOutlineThickness(25);
	rectangle.setPosition(windowWidth / 2, windowHeight / 2);
	myRectangle = Dojo::Application::CreateShape(rectangle);

	entity = Dojo::Application::CreateEntity("res/img/player.png");
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
		rectangles[0].setPosition(Vector2(sf::Mouse::getPosition(*Dojo::Application::windowReference).x, sf::Mouse::getPosition(*Dojo::Application::windowReference).y));
	}

	//DOJO_CLIENT_INFO("Player pos ({0}, {1})", player.position.x, player.position.y);
}

void Dojo::Application::KeyPressed(sf::Keyboard::Key keyCode)
{
	//if (keyCode == sf::Keyboard::Space)
}

void Dojo::Application::EndOfFrame() {}
Sandbox::~Sandbox() {}