#include <conio.h> 
#include <iostream>

#include "Snake.hpp"
#include "GameMap.hpp"
#include "Controller.hpp"

Direction Controller::getInputDirection() {
  if (not _kbhit()) return Direction::NONE;

  int key = _getch();     
  if (key == 224) {
    int arrow = _getch();    
    switch (arrow) {
      case 72:
        return Direction::UP; 
      case 80:
        return Direction::DOWN; 
      case 75:
        return Direction::LEFT; 
      case 77:
        return Direction::RIGHT; 
      default: break;
    }
  } else {
    if (key == 119 or key == 87) {
      return Direction::UP; 
    } else if (key == 115 or key == 83) {
      return Direction::DOWN; 
    } else if (key == 97 or key == 65) {
      return Direction::LEFT; 
    } else if (key == 100 or key == 68) {
      return Direction::RIGHT; 
    } 
  } 
  
  return Direction::NONE;
}

void Controller::print(GameMap& gameMap, Snake& snake) {
  auto map = gameMap.getMap();
  auto snakeBody = snake.getBody();
  auto [lim_x, lim_y] = gameMap.getBound();
  for (auto& [x, y] : snakeBody) {
    map[x][y] = 2;
  }

  for (int i = 1; i <= lim_y + 2; i++) {
    std::cout << '#';
  } 
  std::cout << "\n";

  for (int x = 1; x <= lim_x; x++) {
    std::cout << "#";
    for (int y = 1; y <= lim_y; y++) {
      int t = map[x][y];
      if (t == 0) {
        std::cout << ' ';
      } else if (t == 1) {
        std::cout << '@';
      } else if (t == 2) {
        std::cout << "o";
      }
    }
    std::cout << "#\n";
  }

  for (int i = 1; i <= lim_y + 2; i++) {
    std::cout << '#';
  } 
  std::cout << "\n";
}