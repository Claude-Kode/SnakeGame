#include <vector>
#include <random>
#include <chrono>

#include "GameMap.hpp"
#include "Snake.hpp"

std::mt19937_64 rng(
  std::chrono::steady_clock::now().time_since_epoch().count()
);

int rand_int(int l, int r) {
  return std::uniform_int_distribution<int>(l, r)(rng);
}

GameMap::GameMap(Snake& snake): height(20), width(50) {
  map.assign(height + 10, std::vector<int> (width + 10, 0));
  for (int i = 1; i < 6; i++) {
    GameMap::spawnFood(snake);
  }
}

bool GameMap::hasFood(Position pos) {
  auto [x, y] = pos;
  // 是这里导致食物莫名其妙增加吗
  return GameMap::map[x][y] == 1;
}

void GameMap::spawnFood(Snake& snake) {
  int x = 0, y = 0;
  do {
    x = rand_int(1, height);
    y = rand_int(1, width);
  } while (GameMap::hasFood(Position(x, y)) or snake.isSnake(Position(x, y)));
  map[x][y] = 1;
}

std::pair<int, int> GameMap::getBound() {
  return {height, width};
}

std::vector<std::vector<int>> GameMap::getMap() {
  return GameMap::map;
}

void GameMap::eraseFood(Position pos) {
  auto[x, y] = pos;
  GameMap::map[x][y] = 0;
}