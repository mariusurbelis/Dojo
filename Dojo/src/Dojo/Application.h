#pragma once

#include "Core.h"
#include <SFML/Graphics.hpp>
#include "Log.h"
#include "Entity.h"
#include <vector>
#include <chrono>
#include <string>

namespace Dojo
{
	class DOJO_API Application
	{

	public:
		std::vector<sf::RectangleShape> rectangles;
		std::vector<sf::Sprite> sprites;
		std::vector<Entity*> entities;
		Entity* CreateEntity(std::string texturePath);
		sf::RectangleShape* CreateShape(sf::RectangleShape s);
		sf::Sprite* CreateSprite(std::string path);
		
		Application(int _width, int _height, std::string _programName) : width(_width), height(_height), programName(_programName) {}
		virtual ~Application();
		virtual void Start();
		virtual void KeyPressed(sf::Keyboard::Key key);
		virtual void Update(double frameTime);
		virtual void EndOfFrame();
		
		void Run();
		void SetIcon(std::string path);
		void DestroyAll(); // FREE MEMORY USED BY ALL ENTITIES

	private:
		int width, height;
		sf::RenderWindow* windowReference;
		std::string programName;
		sf::Texture texture;
		sf::Event event;
	};

	Application* CreateApplication();
}