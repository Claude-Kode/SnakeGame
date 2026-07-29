#pragma once

#include  <random> 
#include  <vector>

#include "Snake.hpp"

class GameMap {
private: 
  std::vector<std::vector<bool>> map;
public: 
  GameMap() = default;
  GameMap();
  std::pair<int, int> getBound();
  bool hasFood(Position pos);
  void spawnFood(Snake& snake);
};