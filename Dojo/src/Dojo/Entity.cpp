#include "Entity.h"

namespace Dojo
{
	Vector2 Entity::GetPosition()
	{
		return sprite->getPosition();
	}

	void Entity::SetPosition(sf::Vector2<float> position)
	{
		sprite->setPosition(position);
	}

	void Entity::Move(float x, float y, double frameTime)
	{
		SetPosition(Vector2(GetPosition().x + x * speed * (float)frameTime, GetPosition().y + y * speed * (float)frameTime));
	}
}