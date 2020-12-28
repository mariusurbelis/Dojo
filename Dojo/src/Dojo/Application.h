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
		static Application* GetInstance();

		std::vector<sf::RectangleShape> rectangles;
		std::vector<sf::Sprite> sprites;
		std::vector<std::shared_ptr<Entity>> entities;
		std::vector<sf::Text*> texts;

		std::map<std::string, std::shared_ptr<sf::Texture>> textures;

		sf::Text* CreateText(std::string textContent);
		std::shared_ptr<Entity> CreateEntity(std::string texturePath);
		sf::RectangleShape* CreateShape(sf::RectangleShape s);
		sf::Sprite* CreateSprite(std::string path);

		void DestroyEntity(std::shared_ptr<Entity> entityToDestroy);

		Application(int _width, int _height, std::string _programName) : width(_width), height(_height), programName(_programName) { instance = this; }
		virtual ~Application();
		virtual void Start();
		virtual void KeyPressed(sf::Keyboard::Key key);
		virtual void Update(double frameTime);
		virtual void EndOfFrame();

		void Run();
		void SetIcon(std::string path);
		void DestroyAll(); // FREE MEMORY USED BY ALL ENTITIES / Will be deprecated once all switched to shared_ptr
		double GetFrameTime();

	private:
		static Application* instance;
		int width, height;
		sf::RenderWindow* windowReference;
		std::string programName;
		sf::Texture texture;
		sf::Event event;
		sf::Font font;
		double lastFrameTime = 0;
	};

	Application* CreateApplication();
}