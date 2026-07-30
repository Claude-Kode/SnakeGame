#include <conio.h> 
#include <iostream>

#include "Input.hpp"

Direction Input::getInputDirection() {
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