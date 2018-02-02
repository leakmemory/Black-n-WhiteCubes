#pragma once
#include <set>

const int
CUBE_SIZE = 50, // размер квадрата (персонаж)
MIDDLE_TILE_SIZE = 32, // размер тайла
SPEED_X = 200, // скорость игрока по X
SPEED_Y = -450, // скорость игрока по Y (при прыжке)
WINDOW_WIDTH = 600, // ширина экрана
WINDOW_HEIGHT = 640, // высота экрана
ACCELERATION = 800; // ускорение

const std::set<char> NOT_FOR_WHITE = {' ', '3'}, NOT_FOR_DARK = { ' ', '2' }; // список номеров тайлов, которые не предназначены для белого и темного квадратов