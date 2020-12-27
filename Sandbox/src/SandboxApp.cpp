//#include "..\..\Dojo\src\Dojo\Application.h"
#include <Dojo.h>

class Sandbox : public Dojo::Application
{
	Sandbox();
	~Sandbox();
};

static bool drawSquare;
static sf::Text text;
static sf::RectangleShape rectangle;

Dojo::Application* Dojo::CreateApplication()
{
	DOJO_CLIENT_TRACE("Creating app");
	return new Dojo::Application(2000, 800, "Sandbox Test");
}

void Dojo::Application::Start()
{
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
	}

	text.setFont(font);
	text.setString("REEEEEEEEE!!!");
	text.setCharacterSize(100);
	text.setPosition(100, 300);

	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(10, 20);

	Dojo::Application::drawables.push_back(&rectangle);
}

void Dojo::Application::Update()
{

}

void Dojo::Application::Draw(sf::RenderWindow& window)
{
	if (drawSquare)
	{
		DOJO_CLIENT_INFO("Drawing it");
		
		//window.draw(text);

		//window.draw(toDraw);
	}
}

void Dojo::Application::KeyPressed(sf::Keyboard::Key keyCode)
{
	if (keyCode == sf::Keyboard::Space)
		drawSquare = true;
	DOJO_CLIENT_TRACE("Key: {0}, Space {1}", keyCode, sf::Keyboard::Space);
}

void Dojo::Application::EndOfFrame()
{
	drawSquare = false;
}

Sandbox::~Sandbox()
{
}