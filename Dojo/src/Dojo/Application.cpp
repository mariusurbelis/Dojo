#include "Application.h"

namespace Dojo
{
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

	sf::RenderWindow* windowReference;

	void Application::SetIcon(std::string path)
	{
		sf::Image icon;
		icon.loadFromFile(path);
		windowReference->setIcon(512, 512, icon.getPixelsPtr());
	}

	void Application::Update(double frameTime)
	{
	}

	void Application::Draw(sf::RenderWindow& windowReference)
	{
	}

	void Application::Run()
	{
		//DOJO_CORE_INFO("Run started");

		sf::RenderWindow window(sf::VideoMode(width, height), programName + " | Powered By: DOJO ONE");
		windowReference = &window;
		window.setFramerateLimit(60);

		auto firstTime = std::chrono::high_resolution_clock::now();

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

			}

			if (keyIsPressed)
				KeyPressed(event.key.code);

			{
				auto secondTime = std::chrono::high_resolution_clock::now();
				using dMsecs = std::chrono::duration<double, std::chrono::milliseconds::period>;
				auto elapsed = dMsecs(secondTime - firstTime);
				firstTime = secondTime;
				Update(elapsed.count());
			}


			window.clear(sf::Color::White);

			//Draw(window);


			for (sf::RectangleShape d : rectangles)
			{
				//DOJO_CORE_WARN("Huh: {0}", *d);
				// Does not work
				window.draw(d);
			}

			window.display();

			EndOfFrame();
		}
	}
}