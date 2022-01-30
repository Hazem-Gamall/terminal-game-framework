CC = g++
Linker_Flags = -lncurses
texManager = Rendering/TextureManager.cpp
texObject = Rendering/TextureObject.cpp Rendering/GraphicObject.cpp
termHandler = Rendering/TerminalHandler.cpp
inpHandler = Input/InputHandler.cpp
Snake = Units/Snake.cpp
SnakeBlock = Units/SnakeBlock.cpp
Dot = Units/Dot.cpp
Level = Level/Level.cpp
StateM = StateMachine/StateMachine.cpp StateMachine/PlayGameState.cpp StateMachine/MenuGameState.cpp StateMachine/LostGameState.cpp StateMachine/WonGameState.cpp
main = main.cpp
Game = Game.cpp
Collission = Collision/CollisionHandler.cpp


all:
	$(CC) $(main) $(Game) $(Collission) $(texManager) $(texObject) $(termHandler) $(inpHandler) $(Snake) $(SnakeBlock) $(Dot) $(Level) $(StateM) $(Linker_Flags) -g -Wall -o main 
