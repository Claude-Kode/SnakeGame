#pragma once

#include  <random> 
#include  <vector>

#include "Snake.hpp"

class Snake;

class GameMap {
private: 
  int height;
  int width;
  std::vector<std::vector<bool>> map;
public: 
  GameMap(Snake& snake);
  std::pair<int, int> getBound();
  bool hasFood(Position pos);
  void spawnFood(Snake& snake);
};