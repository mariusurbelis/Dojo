#include "Application.h"

namespace Dojo
{
	Application::~Application()
	{
	}

	void Application::KeyPressed(sf::Keyboard::Key key)
	{
	}

	void Application::EndOfFrame()
	{
	}

	void Application::Start()
	{
	}

	void Application::Update()
	{
	}

	void Application::Draw(sf::RenderWindow& windowReference)
	{
	}

	void Application::Run()
	{
		//DOJO_CORE_INFO("Run started");

		sf::RenderWindow window(sf::VideoMode(width, height), programName);
		window.setFramerateLimit(5);

		Start();

		bool keyIsPressed = false;

		while (window.isOpen())
		{
			//DOJO_CORE_INFO("Is open");

			// EVENT POLLING
			sf::Event event;
			while (window.pollEvent(event))
			{
				//DOJO_CORE_WARN("Event was polled");

				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					keyIsPressed = true;
					if (event.key.code == sf::Keyboard::Escape)
						window.close();
					// GENERAL INPUT HANDLING
					break;
				case sf::Event::KeyReleased:
					keyIsPressed = false;
					break;
				}

				if (keyIsPressed)
					KeyPressed(event.key.code);
			}


			Update();

			window.clear(sf::Color::Red);

			Draw(window);
			
			for (sf::Drawable* d : drawables)
			{
				// Does not work
				window.draw(*d);
			}


			window.display();

			EndOfFrame();
		}
	}
}