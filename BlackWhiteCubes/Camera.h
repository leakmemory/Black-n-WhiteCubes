#pragma once
#include <SFML/Graphics.hpp>
#include "WhiteCube.h"
#include"Map.h"

class Camera
{
public:
	Camera(const int& width, const int& height); // в конструкторе задается ширина и высота камеры
	void Update(WhiteCube& whiteCube, Map& map); // обновление позиции камеры
	sf::View& GetView(); // возврат камеры
	~Camera();
private:
	sf::View _view; // сама камера
	sf::Vector2f _position; // позиция камеры
	int _width, _height; // ширина и высота камеры
};

