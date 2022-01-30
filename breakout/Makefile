CC = g++
Linker_Flags = -lncurses -ldl -lpthread -lm
texManager = Rendering/TextureManager.cpp
texObject = Rendering/TextureObject.cpp
termHandler = Rendering/TerminalHandler.cpp
inpHandler = Input/InputHandler.cpp
AudHandler = Audio/AudioHandler.cpp
AudObject = Audio/AudioObject.cpp
min = Audio/miniAudioExec.c
Player = Units/Player.cpp
Level = Level/Level.cpp
StateM = StateMachine/StateMachine.cpp
PlayState = StateMachine/PlayGameState.cpp
MenuState = StateMachine/MenuGameState.cpp
main = main.cpp
Game = Game.cpp
Ball = Units/Ball.cpp
Collission = Collision/CollisionHandler.cpp
GraphObject = Rendering/GraphicObject.cpp
Block = Units/Block.cpp
LostState = StateMachine/LostGameState.cpp
WonState = StateMachine/WonGameState.cpp
all:
	$(CC) $(main) $(Game) $(Ball) $(Block) $(Collission) $(texManager) $(texObject) $(termHandler) $(inpHandler) $(AudHandler) $(AudObject) $(GraphObject) $(min) $(Player) $(Level) $(StateM) $(PlayState) $(MenuState) $(LostState) $(WonState) $(Linker_Flags) -g -Wall -o main 
