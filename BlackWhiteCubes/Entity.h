#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
	void SetLife(bool life); // задание жизни
	sf::Vector2f GetPosition(); // возврат позиции на карте
	virtual void Update(std::vector<sf::String>& map, const float& dt) = 0; // обновление состояния
	virtual ~Entity();
protected:
	virtual void CheckCollision(std::vector<sf::String>& map, char orientation) = 0; // проверка на столкновения
	virtual void MoveX(const float& dt) = 0; // перемещение по X
	virtual void MoveY(const float& dt) = 0; // перемещение по Y
protected:
	sf::Vector2f _position; // положение на карте
	bool _life; // жив (виден) персонаж или нет
	float _speedX, _speedY; // скорость перемещения по X и Y
};

