#pragma once

#include  <random> 
#include  <vector>

#include "Snake.hpp"  

class Snake;

class GameMap {
private: 
  int height;
  int width;
  std::vector<std::vector<int>> map;
public: 
  GameMap(Snake& snake);
  std::pair<int, int> getBound();
  bool hasFood(Position pos);
  void spawnFood(Snake& snake);
  std::vector<std::vector<int>> getMap();
  void eraseFood(Position pos);
};