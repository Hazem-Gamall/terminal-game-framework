# terminal-game-framework
Mini framework for helping with simple 2D text-based terminal games.

## About the project
 A simple C++ framework to help with building simple 2D text-based games, developed and tested on Ubuntu 20.04.2 LTS.
## The framework supports:
  * The ability to have different game levels.
  * Sound Handling (work in progress).
  * Rendering **textures** to the terminal.
  * Collision Handling between different Units.
  * A Unit interface for creating custom Units.
  * Input Handling.

  
  ## Games made using this framework:
  * [breakout](https://github.com/Hazem-Gamall/terminal-game-framework/tree/master/breakout)
 
      ![breakout gif](https://github.com/Hazem-Gamall/terminal-game-framework/blob/master/gifs/breakout.gif)
 
  * [avoid the cats!](https://github.com/Hazem-Gamall/terminal-game-framework/tree/master/avoid_the_cats)
 
      ![avoid cats gif](https://github.com/Hazem-Gamall/terminal-game-framework/blob/master/gifs/avoid_cats.gif)
  
  * [terminal_snake](https://github.com/Hazem-Gamall/terminal-game-framework/tree/master/terminal_snake)
 
      ![snake gif](https://github.com/Hazem-Gamall/terminal-game-framework/blob/master/gifs/terminal_snake.gif)

  ## Future plans
  * Refactor the code to rely more on stack objects and smart pointers instead of C pointers for better memory managment.
  * Add audio support.
  * Improve the Design of the code and employ more Design patterns and OOP principles.
  
  
  ## Libraries used:
  * [ncurses](https://invisible-island.net/ncurses) -for interfacing with the terminal.
