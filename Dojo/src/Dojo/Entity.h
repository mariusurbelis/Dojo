#pragma once

#include "Core.h"
#include <SFML/Graphics.hpp>

namespace Dojo
{
	class DOJO_API Entity
	{
	public:
		Entity() {}
		~Entity() {}
		sf::Vector2<float> GetPosition();
		void SetPosition(sf::Vector2<float> position);
		float speed = 0;
		sf::Texture* texture;
		sf::Sprite* sprite;
	};
}