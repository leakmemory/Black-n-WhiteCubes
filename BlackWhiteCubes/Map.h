#pragma once
#include <SFML/Graphics.hpp>

class Map
{
public:
	Map(const int level);
	int GetHeight(); // возвращаем высоту карты в пикселях
	int GetWidth(); // возвращаем ширину карты в пикселях
	std::vector<sf::String>& GetMap(); // возвращаем карту
	void Draw(sf::RenderWindow& window); // отрисовка
	~Map();
private:
	int _height, _width; // высота и ширина карты
	std::vector<sf::String> _map; // сама карта, как двумерный массив
	sf::Texture _texture; // атлас карты
	sf::Sprite _sprite; // спрайт для отрисовки каждой текстуры
};

