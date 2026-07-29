#include <iostream>

#include "Snake.hpp"
#include "GameMap.hpp"

int main() {
  Snake snake;
  GameMap gameMap(snake);
  std::cout << "I'm a Snake!!!" << "\n";
  return 0;
} 