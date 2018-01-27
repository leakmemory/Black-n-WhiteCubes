#include "Cube.h"

Cube::Cube() : _body(sf::Vector2f(CUBE_SIZE, CUBE_SIZE))
{
	_body.setOrigin(CUBE_SIZE / 2, CUBE_SIZE / 2); // задание центра квадрата, как точку позиции
	_state = FALL; // изначально квадрат падает
}

sf::RectangleShape& Cube::GetBody()
{
	return _body;
}

void Cube::CheckCollision(std::vector<sf::String>& map, char orientation)
{
	// проверка на столкновение по X
	if (orientation == 'x') {
		for (int i = (_position.y - CUBE_SIZE / 2) / MIDDLE_TILE_SIZE; i < (_position.y + CUBE_SIZE / 2) / MIDDLE_TILE_SIZE; i++) {
			if (map[i][(_position.x - CUBE_SIZE / 2) / MIDDLE_TILE_SIZE] != ' ') {
				_position.x = (static_cast<int>((_position.x - CUBE_SIZE / 2) / MIDDLE_TILE_SIZE) + 1) * MIDDLE_TILE_SIZE + CUBE_SIZE / 2;
				break;
			}
			else if (map[i][(_position.x + CUBE_SIZE / 2) / MIDDLE_TILE_SIZE] != ' ') {
				_position.x = static_cast<int>((_position.x + CUBE_SIZE / 2) / MIDDLE_TILE_SIZE) * MIDDLE_TILE_SIZE - CUBE_SIZE / 2;
				break;
			}
		}
	}
	// проверка на столкновение по Y
	if (orientation == 'y') {
		// если квадрат в воздухе, то проверяем на столкновение сверху и снизу
		if (_state != NORMAL) {
			for (int i = (_position.x - CUBE_SIZE / 2) / MIDDLE_TILE_SIZE; i < (_position.x + CUBE_SIZE / 2) / MIDDLE_TILE_SIZE; i++) {
				if (map[(_position.y - CUBE_SIZE / 2) / MIDDLE_TILE_SIZE][i] != ' ') {
					_position.y = (static_cast<int>((_position.y - CUBE_SIZE / 2) / MIDDLE_TILE_SIZE) + 1) * MIDDLE_TILE_SIZE + CUBE_SIZE / 2;
					_state = FALL;
					_speedY *= -1;
					break;
				}
				else if (map[(_position.y + CUBE_SIZE / 2) / MIDDLE_TILE_SIZE][i] != ' ') {
					_position.y = static_cast<int>((_position.y + CUBE_SIZE / 2) / MIDDLE_TILE_SIZE) * MIDDLE_TILE_SIZE - CUBE_SIZE / 2;
					_state = NORMAL;
					break;
				}
			}
		}
		// если квадрат на земле, то проверяем, не пора ли падать
		else {
			for (int i = (_position.x - CUBE_SIZE / 2) / MIDDLE_TILE_SIZE; i < (_position.x + CUBE_SIZE / 2) / MIDDLE_TILE_SIZE; i++) {
				//проверяем плитки под квадратом
				if (map[(_position.y + CUBE_SIZE) / MIDDLE_TILE_SIZE][i] == ' ') {
					continue;
				}
				// если есть хоть одна плитка
				else return;
			}
			// если все плитки пустые
			_state = FALL;
			_speedY = 0;
		}
	}
}

Cube::~Cube()
{
}
