#include "Entity.h"

namespace Dojo
{
	sf::Vector2<float> Entity::GetPosition()
	{
		return sprite->getPosition();
	}
	
	void Entity::SetPosition(sf::Vector2<float> position)
	{
		sprite->setPosition(position);
	}
}