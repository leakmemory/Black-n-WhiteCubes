#include "Map.h"
#include "Variables.h"

Map::Map(const int level)
{
	_texture.loadFromFile("atlases/map_atlas.png");
	_sprite.setTexture(_texture);

	// создаем карту, опираясь на уровень
	switch (level)
	{
		case 1:
			_height = 20;
			_width = 30;
			_map.push_back("000000000000000000000000000000");
			_map.push_back("0          2                 0");
			_map.push_back("0           2                0");
			_map.push_back("0            2               0");
			_map.push_back("0                            0");
			_map.push_back("0                            0");
			_map.push_back("0                            0");
			_map.push_back("0                            0");
			_map.push_back("0                            0");
			_map.push_back("0                            0");
			_map.push_back("0                            0");
			_map.push_back("0000111                      0");
			_map.push_back("0                            0");
			_map.push_back("0                        01120");
			_map.push_back("0                 333        0");
			_map.push_back("0             1222           0");
			_map.push_back("0             2              0");
			_map.push_back("0             2              0");
			_map.push_back("0           3 1 3            0");
			_map.push_back("000000000000000000000000000000");
			break;
		default:
			break;
	}
}

int Map::GetHeight()
{
	return _height * MIDDLE_TILE_SIZE;
}

int Map::GetWidth()
{
	return _width * MIDDLE_TILE_SIZE;
}

std::vector<sf::String>& Map::GetMap()
{
	return _map;
}

bool Map::ContinueDraw(char tile, bool dark)
{
	if (dark) {
		// если не находим данный тайл в списке тайлов, не предназначенных для
		// темного квадрата, то отрисовку можно продолжать
		if (NOT_FOR_DARK.find(tile) == NOT_FOR_DARK.end()) {
			return true;
		}
		else return false;
	}
	else {
		if (NOT_FOR_WHITE.find(tile) == NOT_FOR_WHITE.end()) {
			return true;
		}
		else return false;
	}
}

void Map::Draw(sf::RenderWindow& window, bool dark)
{
	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
			if (ContinueDraw(_map[i][j], dark)) {
				switch (_map[i][j])
				{
				case '0':
					_sprite.setTextureRect(sf::IntRect(0 * MIDDLE_TILE_SIZE, 0, MIDDLE_TILE_SIZE, MIDDLE_TILE_SIZE));
					break;
				case '1':
					_sprite.setTextureRect(sf::IntRect(1 * MIDDLE_TILE_SIZE, 0, MIDDLE_TILE_SIZE, MIDDLE_TILE_SIZE));
					break;
				case '2':
					_sprite.setTextureRect(sf::IntRect(2 * MIDDLE_TILE_SIZE, 0, MIDDLE_TILE_SIZE, MIDDLE_TILE_SIZE));
					break;
				case '3':
					_sprite.setTextureRect(sf::IntRect(3 * MIDDLE_TILE_SIZE, 0, MIDDLE_TILE_SIZE, MIDDLE_TILE_SIZE));
					break;
				default:
					break;
				}
				_sprite.setPosition(j * MIDDLE_TILE_SIZE, i * MIDDLE_TILE_SIZE);
				window.draw(_sprite);
			}
		}
	}
}


Map::~Map()
{
}
