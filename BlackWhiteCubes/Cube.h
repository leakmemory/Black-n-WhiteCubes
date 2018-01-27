#pragma once
#include <SFML/Graphics.hpp>
#include "Variables.h"
#include "Entity.h"

class Cube : public Entity
{
public:
	Cube();
	sf::RectangleShape& GetBody(); // возврат квадрата
	virtual void Update(std::vector<sf::String>& map, const float& dt) = 0; // обновление состояния квадрата
	virtual ~Cube();
protected:
	virtual void CheckCollision(std::vector<sf::String>& map, char orientation) override; // проверка на столкновения
	virtual void MoveX(const float& dt) = 0; // перемещение квадрата по X
	virtual void MoveY(const float& dt)= 0; // перемещение квадрата по Y
protected:
	sf::RectangleShape _body; // сам квадрат
	enum State { NORMAL, JUMP, FALL }; // состояние (на земле, в прыжке, в падении)
	State _state;
};

