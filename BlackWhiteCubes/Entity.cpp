#include "Entity.h"



Entity::Entity() : _life(true), _position(620, 100), _speedX(0), _speedY(0)
{
}

void Entity::SetLife(bool life)
{
	_life = life;
}

sf::Vector2f Entity::GetPosition()
{
	return _position;
}


Entity::~Entity()
{
}
