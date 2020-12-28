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
	sf::Texture texture;
	sf::Sprite* sprite;
};

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


	Entity player;

	//player.sprite = Dojo::Application::CreateSprite("res/img/player.png");
	//player.sprite->setPosition(player.position);
	

	Dojo::Application::SetIcon("res/img/dojo.png");

	sf::Font font;

	if (!font.loadFromFile("res/fonts/ka1.ttf"))
	{
		// ERROR LOADING TEXT
		DOJO_CLIENT_CRITICAL("ERROR LOADING FONT");
	}

	text.setFont(font);
	text.setString("REEEEEEEEE!!!");
	text.setCharacterSize(100);
	text.setPosition(100, 300);

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
		rectangles[0].setPosition(sf::Vector2((float)sf::Mouse::getPosition(*Dojo::Application::windowReference).x, (float)sf::Mouse::getPosition(*Dojo::Application::windowReference).y));
	}
}

void Dojo::Application::KeyPressed(sf::Keyboard::Key keyCode)
{
	//if (keyCode == sf::Keyboard::Space)
}

void Dojo::Application::EndOfFrame() {}
Sandbox::~Sandbox() {}