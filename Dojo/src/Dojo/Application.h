#pragma once

#include "Core.h"
#include <SFML/Graphics.hpp>
#include "Log.h"
#include "test/EpilepsySampleTest.h"
#include <vector>

namespace Dojo
{
	class DOJO_API Application
	{

	public:
		std::vector<sf::RectangleShape> rectangles;
		sf::RectangleShape rectgg;
		sf::RectangleShape* CreateShape(sf::RectangleShape s);
		Application(int _width, int _height, std::string _programName) : width(_width), height(_height), programName(_programName) {}
		virtual ~Application();
		virtual void KeyPressed(sf::Keyboard::Key key);
		virtual void EndOfFrame();
		virtual void Start();
		virtual void Update();
		virtual void Draw(sf::RenderWindow& windowReference);
		void Run();

	private:
		int width, height;
		std::string programName;
	};

	Application* CreateApplication();
	//void HandleInput();
}