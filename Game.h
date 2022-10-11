#include<iostream>
#include<cstdlib>
#include<ctime>		//used because of numeric_limit function used in one of the method of Game class... 
#include<limits>
#include<unistd.h>
#include "Team.h"		//<vector>, <string>, "player.h"

class Game{
	public:
		Game();		//Default Constructor...
		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];
		int totalRunsScoredTeamA;
		
		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman, *bowler;
		
		void welcomeMessage();
		void enterToContinue();
		void enterToToss();
		void showAllPlayers();
		int takeIntegerInput();
		void selectPlayers();
		bool validateSelectedPlayer(int);
		void showTeamPlayers();
		void toss();
		void tossChoice(Team);
		void startFirstInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInningsScore();
		void showGameScoreCard();
		void startSecondInnings();
		void matchSummary();
		
};
