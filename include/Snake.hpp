#pragma once

#include <deque>

enum class Direction {
  UP,
  LEFT,
  DOWN,
  RIGHT
};

int dirs[4][2] = {
  {0, 1}, {0, -1}, {0, -1}, {1, 0}
};

struct Position{
  int x;
  int y;
  Position() = default;
};

class Snake {
private:
  int lastDirIdx;
  std::deque<Position> SnakeBody;
public: 
  Snake() = default;
  Snake();
  void move(Direction dir);
  void grow();
  bool chkAlive();
  bool isSnake();
};
