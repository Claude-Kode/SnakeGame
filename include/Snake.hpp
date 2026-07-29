#pragma once

#include <deque>

// #include "GameMap.hpp"

class GameMap;

enum class Direction {
  UP,
  LEFT,
  DOWN,
  RIGHT
};

struct Position{
  int x;
  int y;
  Position(int _x, int _y);
  bool operator==(const Position& o) const { return x == o.x && y == o.y; }
};

class Snake {
private:
  Direction lastDirIdx;
  std::deque<Position> SnakeBody;
public: 
  Snake();
  void move(Direction dir, GameMap& map);
  void grow(GameMap& map);
  bool chkAlive(GameMap& map);
  bool isSnake(Position pos);
};
