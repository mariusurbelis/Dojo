#include "EpilepsySampleTest.h"
#include <SFML/Graphics.hpp>

namespace Dojo
{
	void EpilepsySampleTest::RunTest()
	{
		sf::RenderWindow window(sf::VideoMode(1200, 800), "EPILEPSY INDUCER | Powered by: Dojo One");
		window.setFramerateLimit(60);

		sf::Image icon;
		icon.loadFromFile("res/img/icon.png");
		window.setIcon(256, 256, icon.getPixelsPtr());

		sf::Font font;

		if (!font.loadFromFile("res/fonts/ka1.ttf"))
		{
			// ERROR LOADING TEXT
		}

		bool havoc = false;

		sf::Color clearColor = sf::Color::Black;

		sf::Text text;
		text.setFont(font);
		text.setString("REEEEEEEEE!!!");
		text.setCharacterSize(100);
		text.setPosition(100, 300);
		text.setFillColor(sf::Color::Black);

		while (window.isOpen())
		{
			// EVENT POLLING
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape)
						window.close();
					// GENERAL INPUT HANDLING
					break;
				}
			}

			// CONSTANT INPUT HANDLING

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				DOJO_CRITICAL("Button press {0}", havoc);
				havoc = !havoc;
			}

			if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				havoc = false;
			}

			if (!havoc)
			{
				clearColor = sf::Color::Black;
				text.setFillColor(sf::Color::Black);
			}
			else
			{
				clearColor = sf::Color::White;
			}

			window.clear(clearColor);
			window.draw(text);
			window.display();
		}

		return;
	}

}