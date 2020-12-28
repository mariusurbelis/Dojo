#include "Entity.h"
#include "Application.h"

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

	void Entity::Move(float x, float y)
	{
		SetPosition(Vector2(
			GetPosition().x + x * speed * Dojo::Application::GetInstance()->GetFrameTime(),
			GetPosition().y + y * speed * Dojo::Application::GetInstance()->GetFrameTime())
		);
	}
}