#pragma once
#include "Cube.h"

class WhiteCube : public Cube
{
public:
	WhiteCube();
	virtual void Update(std::vector<sf::String>& map, const float& dt) override; // обновление состояния квадрата
	~WhiteCube();
private:
	virtual void MoveX(const float& dt) override; // перемещение квадрата по X
	virtual void MoveY(const float& dt) override; // перемещение квадрата по Y
};

