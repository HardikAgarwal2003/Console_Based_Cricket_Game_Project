#include "Game.h"		//<vector>, <string>, "player.h", <cstdlib>, <limits>, <ctime>, <iostream>
using namespace std;

int main() {
	Game game;
	
	game.welcomeMessage();
	
	game.enterToContinue();
	
	game.showAllPlayers();
	
	game.enterToContinue();

	game.selectPlayers();
	
	game.showTeamPlayers();
	
	cin.ignore(numeric_limits<streamsize>::max(),'\n');				// To clear the exceeded buffer memory...
	game.enterToToss();

	game.toss();
	
	game.startFirstInnings();
	
	game.startSecondInnings();
	
	game.matchSummary();
	
	return 0;
}
