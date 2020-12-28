#pragma once

#include "Core.h"
#include <SFML/Graphics.hpp>
typedef sf::Vector2<float> Vector2;

namespace Dojo
{
	class DOJO_API Entity
	{
	public:
		// TODO: Uninitialized texture and sprite here
		Entity() {}
		~Entity() {}
		sf::Texture* texture;
		sf::Sprite* sprite;
		float speed = 1;
		Vector2 GetPosition();
		void SetPosition(Vector2 position);
		void Move(float x, float y, double frameTime);
	};
}