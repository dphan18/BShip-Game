
#include <iostream>
#include "BattleShip.h"

using namespace std;

int main()
{
	BattleShip bs(cin, cout);
	
	while(!bs.gameOver()) {
		bs.gameUpdate();
	}
	return 0;
}
