#include <deque>
#include <algorithm>

#include "Snake.hpp"
#include "GameMap.hpp"

int dirs[4][2] = {
  {-1, 0}, {0, -1}, {1, 0}, {0, 1}
};  

Position::Position(int _x, int _y):   
  x(_x), y(_y) {};

Snake::Snake() {
  Snake::lastDirIdx = Direction::RIGHT;
  for (int i = 1; i < 6; i++) {
    Snake::SnakeBody.push_front(Position(1, i));
  }
}

bool Snake::isSnake(Position pos) {
  return find(Snake::SnakeBody.begin(), Snake::SnakeBody.end(), pos) != Snake::SnakeBody.end(); 
}

void Snake::grow(GameMap& map) {
  Snake::SnakeBody.push_back(Position(0, 0));
}

void Snake::move(Direction dir, GameMap& map) {
  auto [x, y] = *Snake::SnakeBody.begin();
  auto [dx, dy] = dirs[static_cast<int>(dir)];
  Position next = Position(x + dx, y + dy);
  if (map.hasFood(next)) {
    Snake::grow(map);
  }
  Snake::SnakeBody.push_front(next);
  Snake::SnakeBody.pop_back();
}

bool Snake::chkAlive(GameMap& map) {
  auto head = *Snake::SnakeBody.begin();
  if (find(Snake::SnakeBody.begin() + 1, Snake::SnakeBody.end(), head) != Snake::SnakeBody.end()) {
    return false;
  }

  auto [x, y] = head;
  auto [lim_x, lim_y] = map.getBound();
  if (x < 1 or x > lim_x or y < 1 or y > lim_y) {
    return false;
  }

  return true;
}

