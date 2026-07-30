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

// 我要是想 move 的时候直接自动判断然后触发 GameMap 的 spawn food 怎么做啊
bool Snake::move(Direction dir, GameMap& map) {
  if (dir == Direction::NONE or ((int)dir + (int)Snake::lastDirIdx) % 2 == 0) dir = Snake::lastDirIdx;
  auto [x, y] = *Snake::SnakeBody.begin();
  auto [dx, dy] = dirs[static_cast<int>(dir)];
  Position next = Position(x + dx, y + dy);
  bool eat = map.hasFood(next);
  if (eat) {
    Snake::grow(map);
    map.eraseFood(next);
  }
  Snake::SnakeBody.push_front(next);
  Snake::SnakeBody.pop_back();
  Snake::lastDirIdx = dir;
  return eat;
}

bool Snake::chkAlive(GameMap& map) {
  Position head = *Snake::SnakeBody.begin();
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

Direction Snake::getLastDirection() {
  return Snake::lastDirIdx;
}

std::deque<Position>& Snake::getBody() {
  return Snake::SnakeBody;
}