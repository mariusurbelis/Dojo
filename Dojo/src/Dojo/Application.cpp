#include "Application.h"

namespace Dojo
{
	sf::Text* Application::CreateText(std::string textContent)
	{
		sf::Text* text = new sf::Text();

		text->setFont(font);
		text->setString(textContent);
		text->setColor(sf::Color::Black);
		text->setOutlineColor(sf::Color::White);
		text->setOutlineThickness(10);

		texts.push_back(text);

		return text;
	}

	std::shared_ptr<Entity> Application::CreateEntity(std::string texturePath)
	{
		std::shared_ptr<Entity> entity = std::make_shared<Entity>();

		if (!textures.count(texturePath))
		{
			std::shared_ptr<sf::Texture> newTexture = std::make_shared<sf::Texture>();
			newTexture->loadFromFile(texturePath);
			textures.insert(std::pair<std::string, std::shared_ptr<sf::Texture>>(texturePath, newTexture));
			entity->texture = newTexture;
		}
		else
		{
			entity->texture = textures.at(texturePath);
		}

		entity->sprite = std::make_shared <sf::Sprite>();
		entity->sprite->setTexture(*(entity->texture));

		entities.push_back(entity);

		return entity;
	}

	// TODO: Complete rework or removal required
	sf::RectangleShape* Application::CreateShape(sf::RectangleShape s)
	{
		sf::RectangleShape rect;
		rect.setSize(s.getSize());
		rect.setOutlineThickness(s.getOutlineThickness());
		rect.setOutlineColor(s.getOutlineColor());
		rect.setPosition(s.getPosition());
		rect.setFillColor(s.getFillColor());
		rectangles.push_back(rect);
		return &rect;
	}

	// TODO: Complete rework or removal required
	sf::Sprite* Application::CreateSprite(std::string path)
	{
		texture.loadFromFile(path);

		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
		sprite.setPosition(100, 25);

		sprites.push_back(sprite);

		return &sprite;
	}

	void Application::DestroyEntity(std::shared_ptr<Entity> entityToDestroy)
	{
		entities.erase(std::remove(entities.begin(), entities.end(), entityToDestroy), entities.end());
	}

	Application* Application::instance = NULL;

	Application* Application::GetInstance() { return(instance); }

	Application::~Application() {}

	void Application::Start() { DOJO_CORE_ERROR("Function Start() is not implemented"); }

	// TODO: Figure out the C26812 warning
	void Application::KeyPressed(sf::Keyboard::Key key) { DOJO_CORE_ERROR("Function KeyPressed(sf::Keyboard::Key key) is not implemented"); }

	void Application::EndOfFrame() { DOJO_CORE_ERROR("Function EndOfFrame() is not implemented"); }
	void Application::Update(double frameTime) { DOJO_CORE_ERROR("Function Update(double frameTime) is not implemented"); }

	void Application::SetIcon(std::string path)
	{
		sf::Image icon;
		icon.loadFromFile(path);
		windowReference->setIcon(512, 512, icon.getPixelsPtr());
	}

	// TODO: More testing needed to ensure all memory is being freed
	// Use shared_ptr?
	void Application::DestroyAll()
	{
		for (sf::Text* t : texts)
			delete t;
	}

	double Application::GetFrameTime()
	{
		return lastFrameTime;
	}

	// TODO: General cleanup needed
	void Application::Run()
	{
		//DOJO_CORE_INFO("Run started");

		sf::RenderWindow window(sf::VideoMode(width, height), programName + " | Powered By: DOJO ONE", sf::Style::Close | sf::Style::Titlebar);
		windowReference = &window;

		window.setFramerateLimit(60); // FPS CAP

		auto firstTime = std::chrono::high_resolution_clock::now();

		if (!font.loadFromFile("res/fonts/ka1.ttf")) { DOJO_CORE_CRITICAL("Font loading error"); }

		Start(); // START / INITIALIZATION FUNCTION

		while (window.isOpen())
		{
			//DOJO_CORE_INFO("Is open");

			// EVENT POLLING
			while (window.pollEvent(event))
			{
				//DOJO_CORE_WARN("Event was polled");
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					KeyPressed(event.key.code);
					if (event.key.code == sf::Keyboard::Escape)
						window.close();
					// GENERAL INPUT HANDLING
					break;
				case sf::Event::KeyReleased:
					break;
				}
			}

			{ // FRAME TIMINGS COUNTER
				auto secondTime = std::chrono::high_resolution_clock::now();
				using dMsecs = std::chrono::duration<double, std::chrono::milliseconds::period>;
				auto elapsed = dMsecs(secondTime - firstTime);
				firstTime = secondTime;
				lastFrameTime = elapsed.count();
				Update(lastFrameTime);
			}

			// CLEAR THE SCREEN DRAW AND DISPLAY
			window.clear(sf::Color(30, 30, 30));

			for (sf::RectangleShape d : rectangles)
				window.draw(d);

			for (sf::Sprite s : sprites)
				window.draw(s);

			//DOJO_CORE_TRACE("Entity created {0}", entities[0]->sprite->getPosition().x);

			for (std::shared_ptr<Entity> e : entities)
				window.draw(*(e->sprite));

			for (sf::Text* t : texts)
				window.draw(*t);

			window.display();
			// ---------------------------------

			EndOfFrame(); // END OF FRAME
		}
	}
}