#include "WhiteCube.h"

WhiteCube::WhiteCube()
{
	_body.setFillColor(sf::Color::White);
	_speedX = SPEED_X;
}

void WhiteCube::MoveX(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		_position.x -= _speedX * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		_position.x += _speedX * dt;
	}
}

void WhiteCube::MoveY(const float & dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && _state == NORMAL) {
		_state = JUMP;
		_speedY = SPEED_Y;
		_position.y = _position.y + _speedY * dt;
	}
	else if (_state == JUMP || _state == FALL) {
		_speedY += ACCELERATION * dt;
		_position.y = _position.y + _speedY * dt;
	}
}

void WhiteCube::Update(std::vector<sf::String>& map, const float& dt)
{
	MoveX(dt);
	CheckCollision(map, 'x');
	MoveY(dt);
	CheckCollision(map, 'y');
	_body.setPosition(_position);
}


WhiteCube::~WhiteCube()
{
}
