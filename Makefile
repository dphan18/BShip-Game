
GAME_SRC :=	main.cpp		\
		Ship.cpp		\
		BS_ComputerPlayer.cpp	\
		BS_HumanPlayer.cpp	\
		BS_Board.cpp		\
		BattleShip.cpp		\
		BS_Strategy.cpp

all: battleShipGame

battleShipGame:
	g++ -std=c++11 $(GAME_SRC) -o battleShipGame

Ship:
	g++ -std=c++11 -c Ship.cpp

BattleShip:
	g++ -std=c++11 -c BattleShip.cpp

BS_HumanPlayer:
	g++ -std=c++11 -c BS_HumanPlayer.cpp

BS_ComputerPlayer:
	g++ -std=c++11 -c BS_ComputerPlayer.cpp

BS_Board:
	g++ -std=c++11 -c BS_Board.cpp

BS_Strategy:
	g++ -std=c++11 -c BS_Strategy.cpp

clean:
	-rm *.o battleShipGame
