#include "Camera.h"



Camera::Camera(const int& width, const int& height) : _view(sf::FloatRect(0, 0, width, height)), _width(width), _height(height)
{

}

void Camera::Update(Cube& whiteCube, Map& map)
{
	_position = whiteCube.GetPosition(); // позиция камеры равна позиции игрока

	// при подходе к границам карты, не даем камере за них зайти
	if (whiteCube.GetPosition().x < _width / 2) _position.x = _width / 2; // левый край
	else if (whiteCube.GetPosition().x > map.GetWidth() - _width / 2) _position.x = map.GetWidth() - _width / 2; // правый край
	if (whiteCube.GetPosition().y < _height / 2) _position.y = _height / 2; // верхний край
	else if (whiteCube.GetPosition().y > map.GetHeight() - _height / 2) _position.y = map.GetHeight() - _height / 2; // нижний край

	_view.setCenter(_position); // задание центра камеры
}

sf::View & Camera::GetView()
{
	return _view;
}


Camera::~Camera()
{
}
