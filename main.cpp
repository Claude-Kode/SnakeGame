#include <iostream>
#include <windows.h>

#include "Snake.hpp"
#include "Input.hpp"
#include "GameMap.hpp"

int main() {

  std::cout << R"(
    ███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗       ██████╗  █████╗ ███╗   ███╗███████╗
    ██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔════╝
    ███████╗██╔██╗ ██║███████║█████╔╝ █████╗        ██║  ███╗███████║██╔████╔██║█████╗
    ╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝        ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝
    ███████║██║ ╚████║██║  ██║██║  ██╗███████╗      ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗
    ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝
                                                                                by GoryK
  )";
  std::cout << std::endl;

  Snake snake;
  GameMap gameMap(snake);
  Input controller = Input();


  while (true) {
    Direction curDirection = controller.getInputDirection();
    snake.move(curDirection, gameMap);
    bool die = not snake.chkAlive(gameMap);  
    if (die) {

    }

    
    Sleep(200); 
  }

  return 0;
} 