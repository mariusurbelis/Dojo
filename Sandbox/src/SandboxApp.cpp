//#include "..\..\Dojo\src\Dojo\Application.h"
#include <Dojo.h>
#include <memory>

class Sandbox : public Dojo::Application
{
	Sandbox();
	~Sandbox();
};

static bool drawSquare;
static sf::Text text;

static sf::RectangleShape* myRectangle;
static sf::Vector2 position = sf::Vector2(0, 0);

Dojo::Application* Dojo::CreateApplication()
{
	DOJO_CLIENT_TRACE("Creating app");
	return new Dojo::Application(2000, 800, "Sandbox Test");
}

void Dojo::Application::Start()
{
	position.x = 0;
	position.y = 0;

	DOJO_CLIENT_INFO("Start function ran");

	/*
	sf::Image icon;
	icon.loadFromFile("res/img/icon.png");
	Dojo::Application::GetWindow().setIcon(256, 256, icon.getPixelsPtr());
	*/

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
	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(10, 20);

	myRectangle = Dojo::Application::CreateShape(rectangle);

	rectangle.setSize(sf::Vector2f(100, 100));
	rectangle.setOutlineColor(sf::Color::Green);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(300, 200);

	//Dojo::Application::rectangles.push_back(rectangle);
}

void Dojo::Application::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		rectangles[0].setPosition(sf::Vector2(rectangles[0].getPosition().x + 15, rectangles[0].getPosition().y));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		rectangles[0].setPosition(sf::Vector2(rectangles[0].getPosition().x - 15, rectangles[0].getPosition().y));
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		rectangles[0].setPosition(sf::Vector2(rectangles[0].getPosition().x, rectangles[0].getPosition().y - 15));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		rectangles[0].setPosition(sf::Vector2(rectangles[0].getPosition().x, rectangles[0].getPosition().y + 15));
}

void Dojo::Application::Draw(sf::RenderWindow& window)
{
	if (drawSquare)
	{
		DOJO_CLIENT_INFO("Drawing it");

		//window.draw(text);

		//window.draw(toDraw);
	}
	DOJO_CLIENT_WARN("Done draw");
}

void Dojo::Application::KeyPressed(sf::Keyboard::Key keyCode)
{
	if (keyCode == sf::Keyboard::Space)
		drawSquare = true;

}

void Dojo::Application::EndOfFrame()
{
	drawSquare = false;
}

Sandbox::~Sandbox()
{
}