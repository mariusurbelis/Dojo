#include "Application.h"

namespace Dojo
{
	// TODO: Shared textures. LOADING DUPLICATE TEXTUERS IS INEFFICIENT
	Entity* Application::CreateEntity(std::string texturePath)
	{
		Entity* entity = new Dojo::Entity();

		entity->texture = new sf::Texture();
		entity->sprite = new sf::Sprite();

		entity->texture->loadFromFile(texturePath);
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
	void Application::DestroyAll()
	{
		for (Entity* e : entities)
		{
			delete e->sprite;
			delete e->texture;
			delete e;
		}
	}

	// TODO: General cleanup needed
	void Application::Run()
	{
		//DOJO_CORE_INFO("Run started");

		sf::RenderWindow window(sf::VideoMode(width, height), programName + " | Powered By: DOJO ONE", sf::Style::Close | sf::Style::Titlebar);
		windowReference = &window;

		window.setFramerateLimit(60); // FPS CAP

		auto firstTime = std::chrono::high_resolution_clock::now();

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
				Update(elapsed.count());
			}

			// CLEAR THE SCREEN DRAW AND DISPLAY
			window.clear(sf::Color::White);

			for (sf::RectangleShape d : rectangles)
				window.draw(d);

			for (sf::Sprite s : sprites)
				window.draw(s);

			//DOJO_CORE_TRACE("Entity created {0}", entities[0]->sprite->getPosition().x);

			for (Entity* e : entities)
				window.draw(*(e->sprite));

			window.display();
			// ---------------------------------

			EndOfFrame(); // END OF FRAME
		}
	}
}