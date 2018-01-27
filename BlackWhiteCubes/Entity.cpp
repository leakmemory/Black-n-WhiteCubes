#include "Entity.h"



Entity::Entity() : _life(true), _position(620, 100), _speedX(0), _speedY(0)
{
}

void Entity::SetLife(bool life)
{
	_life = life;
}


Entity::~Entity()
{
}
