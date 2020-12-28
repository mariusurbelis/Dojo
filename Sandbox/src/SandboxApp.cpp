//#include "..\..\Dojo\src\Dojo\Application.h"
#include <Dojo.h>
#include <memory>
#include <SFML/Window.hpp>

class Sandbox : public Dojo::Application
{
	Sandbox();
	~Sandbox();
};

class Entity
{
public:
	sf::Vector2<float> position = sf::Vector2(0.f, 0.f);
	sf::Sprite* sprite;
};

static Entity player;

static sf::Text text;
static int windowWidth, windowHeight;
static sf::RectangleShape* myRectangle;

Dojo::Application* Dojo::CreateApplication()
{
	windowWidth = sf::VideoMode::getDesktopMode().width * 0.8;
	windowHeight = sf::VideoMode::getDesktopMode().height * 0.8;
	return new Dojo::Application(windowWidth, windowHeight, "Rectangle Render Test");
}


void Dojo::Application::Start()
{
	/*
	sf::Image icon;
	icon.loadFromFile("res/img/icon.png");
	Dojo::Application::GetWindow().setIcon(256, 256, icon.getPixelsPtr());
	*/

	player.sprite = Dojo::Application::CreateSprite("res/img/player.png");
	player.sprite->setPosition(player.position);


	Dojo::Application::SetIcon("res/img/dojo.png");

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(125, 125));
	rectangle.setOutlineColor(sf::Color(163, 190, 140));
	rectangle.setFillColor(sf::Color(76, 86, 106));
	rectangle.setOutlineThickness(25);
	rectangle.setPosition(windowWidth / 2, windowHeight / 2);
	myRectangle = Dojo::Application::CreateShape(rectangle);
}

static double speed = 0.5;

void Dojo::Application::Update(double frameTime)
{
	//DOJO_CLIENT_INFO("Frame time {0}", frameTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		rectangles[0].setPosition(sf::Vector2(rectangles[0].getPosition().x + (int)(speed * frameTime), rectangles[0].getPosition().y));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		rectangles[0].setPosition(sf::Vector2(rectangles[0].getPosition().x - (int)(speed * frameTime), rectangles[0].getPosition().y));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		rectangles[0].setPosition(sf::Vector2(rectangles[0].getPosition().x, rectangles[0].getPosition().y - (int)(speed * frameTime)));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		rectangles[0].setPosition(sf::Vector2(rectangles[0].getPosition().x, rectangles[0].getPosition().y + (int)(speed * frameTime)));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		player.position.x = (float)sf::Mouse::getPosition(*Dojo::Application::windowReference).x;
		player.position.y = (float)sf::Mouse::getPosition(*Dojo::Application::windowReference).y;

		rectangles[0].setPosition(sf::Vector2((float)sf::Mouse::getPosition(*Dojo::Application::windowReference).x, (float)sf::Mouse::getPosition(*Dojo::Application::windowReference).y));
	}

	//DOJO_CLIENT_INFO("Player pos ({0}, {1})", player.position.x, player.position.y);

	Dojo::Application::sprites[0].setPosition(player.position);
}

void Dojo::Application::KeyPressed(sf::Keyboard::Key keyCode)
{
	//if (keyCode == sf::Keyboard::Space)
}

void Dojo::Application::EndOfFrame() {}
Sandbox::~Sandbox() {}