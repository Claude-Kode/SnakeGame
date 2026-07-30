#pragma onece

#include "Snake.hpp"
#include "GameMap.hpp"

class Controller {
public: 
  Controller() = default;
  Direction getInputDirection();
  void print(GameMap& gameMap, Snake& snake);
  void start();
  void pause();
  void exit();
};