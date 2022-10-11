#include "Game.h"		//<vector>, <string>, "player.h", <cstdlib>, <limits>, <ctime>, <iostream>
using namespace std;
Game::Game() {
	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;
	
	totalRunsScoredTeamA = 0;
	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhavan";
	players[3] = "Pant";
	players[4] = "Kartik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10] = "Ishant";
	
	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";
}

void Game::welcomeMessage() {
	
	cout << "                        |===========================================================================|" << endl;
	cout << "                        |<------------------------------ Cric-In ---------------------------------->|" << endl;
	cout << "                        |                                                                           |" << endl;
	cout << "                        |                      Welcome to Virtual Cricket Game                      |" << endl;
	cout << "                        |                                                                           |" << endl;
	cout << "                        |===========================================================================|" << endl << endl << endl;
	
	cout << "                        |===========================================================================|" << endl;
	cout << "                        |<---------------------------- Instructions ------------------------------->|" << endl;
	cout << "                        |===========================================================================|" << endl;
	cout << "                        |                                                                           |" << endl;
	cout << "                        | 1. Create 2 Teams(Team A and Team B with 4 players each) from a given pool|" << endl;
	cout << "                        |    11 Players.                                                            |" << endl;
	cout << "                        | 2. Lead the Toss and decide the choice of play.                           |" << endl;
	cout << "                        | 3. Each innings will be of 6 Balls.                                       |" << endl;
	cout << "                        |                                                                           |" << endl;
	cout << "                        |===========================================================================|" << endl << endl;
	
}

void Game::enterToContinue() {
	
	cout << endl << "                          Press Enter to continue...";
	cin.get();
	cout << "                          " << endl;
}

void Game::enterToToss() {
	
	cout << endl << "                          Press Enter to Toss...";
	cin.get();
	cout << "                          " << endl;
}

void Game::showAllPlayers() {
	cout << "                        " << endl;
	cout << "                        |===========================================================================|" << endl;
	cout << "                        |<--------------------------- Pool Of Players ----------------------------->|" << endl;
	cout << "                        |===========================================================================|" << endl;
	cout << "                        " << endl;
	
	for(int i = 0; i < totalPlayers; i++)
	{
		cout << "                          [" << i << "]" << players[i] << endl;
	}
}

int Game::takeIntegerInput() {
	int n;
	while(!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << endl <<"                        INVALID INPUT!! Please try with a valid input ";
	}
	return n;
}

bool Game::validateSelectedPlayer(int index) {
	
	int n;
	vector<Player> players;
	
	players = teamA.players;
	n = players.size();
	for (int i = 0; i < n; i++)
	{
		if(players[i].id == index)
		{
			return false;
		}
	}
	
	players = teamB.players;
	n = players.size();
	for(int i = 0; i < n; i++)
	{
		if(players[i].id == index)
		{
			return false;
		}
	}
	
	return true;
} 

void Game::selectPlayers() {
	cout << "                        " << endl; 
	cout << "                        |===========================================================================|" << endl;
	cout << "                        |<------------------------ Create Team A and Team B ----------------------->|" << endl;
	cout << "                        |===========================================================================|" << endl;
	for(int i = 0; i < playersPerTeam; i++)										//Executes 4 times...
	{
		// Add Player to team A...
		teamASelection:																//Label for goto statement
			cout << endl << "                          Select Player " << i + 1 << " of Team A - ";
			
			int playerIndexTeamA = takeIntegerInput();
			
			if(playerIndexTeamA < 0 || playerIndexTeamA > 10) 
			{
				cout << "                          Please select from the given players! " << endl;
				goto teamASelection;
			} 
			else if(!validateSelectedPlayer(playerIndexTeamA)) {
				cout << endl << "                          Player has been already selected. Please select another player.";
				goto teamASelection;
			}
			else 
			{
				Player teamAPlayer;													// Player object
				teamAPlayer.id = playerIndexTeamA;
				teamAPlayer.name = players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);								//to push the players object to the vector...
			}
		
		// Add Player to team B...
		teamBSelection:
			cout << endl << "                          Select Player " << i + 1 << " of Team B - ";
			
			int playerIndexTeamB = takeIntegerInput();
			
			if(playerIndexTeamB < 0 || playerIndexTeamB > 10)
			{
				cout << "                          Please select from the given players! " << endl;
				goto teamBSelection;
			}
			else if(!validateSelectedPlayer(playerIndexTeamB)) 
			{
				cout << endl << "                          Player has been already selected. Please select another player.";
				goto teamBSelection;
			}
			else
			{
				Player teamBPlayer;													// Player object
				teamBPlayer.id = playerIndexTeamB;
				teamBPlayer.name = players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);								//to push the players object to the vector...
			}	
		}
}

void Game::showTeamPlayers() {
	vector<Player> teamAPlayers = teamA.players;
	vector<Player> teamBPlayers = teamB.players;
	
	cout << endl << endl;
    cout << "                        |========================|\t\t\t\t|========================|" << endl;
    cout << "                        |<------  Team-A  ------>|\t\t\t\t|<------  Team-B  ------>|" << endl;
    cout << "                        |========================|\t\t\t\t|========================|" << endl;

    for (int i = 0; i < playersPerTeam; i++) {
        cout << "                        |\t" << "[" << i << "] " << teamAPlayers[i].name << "\t |" << "\t\t\t\t" << "|\t" << "[" << i << "] " << teamBPlayers[i].name << "\t |" << endl;
    }
    cout << "                        |========================|\t\t\t\t|========================|" << endl << endl;
}

void Game::toss() {
	
	cout << endl;
	cout << endl << "                        |===========================================================================|" << endl;
	cout <<         "                        |                                                                           |" << endl;
	cout <<         "                        |<------------------------------- Lets TOSS  ------------------------------>|" << endl;
	cout <<         "                        |                                                                           |" << endl;
	cout <<         "                        |===========================================================================|" << endl;
	
	cout << endl << "                          Tossing the Coin..." << endl << endl;
	
	
	srand(time(NULL));
	int randomValue = rand() % 2;														// 0 or 1.
	
	switch(randomValue)
	{
	case 0:
		usleep(3000000);
		cout <<  "                        |===========================================================================|" << endl;
		cout <<  "                        |===========================================================================|" << endl;
		cout <<  "                        |                                                                           |" << endl;			
		cout <<  "                        |<------------------------- Team A won the Toss --------------------------->|" << endl;
		cout <<  "                        |                                                                           |" << endl;
		cout <<  "                        |===========================================================================|" << endl;
		cout <<  "                        |===========================================================================|" << endl;		
		tossChoice(teamA);
		break;
	case 1:
		usleep(3000000);
		cout <<  "                        |===========================================================================|" << endl;
		cout <<  "                        |===========================================================================|" << endl;
		cout <<  "                        |                                                                           |" << endl;		
		cout <<  "                        |<------------------------- Team B won the Toss --------------------------->|" << endl;
		cout <<  "                        |                                                                           |" << endl;
		cout <<  "                        |===========================================================================|" << endl;
		cout <<  "                        |===========================================================================|" << endl;		
		tossChoice(teamB);
		break;
	}
}

void Game::tossChoice(Team tossWinnerTeam) {
	cout << "                         Enter 1 to Bat or 2 to Bowl first. " << endl;
	cout << "                         	1. Bat" << endl;
	cout << "                         	2. Bowl" << endl;
	
	cout << "                                " ;
	int tossInput = takeIntegerInput();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');				// To clear the exceeded buffer memory...
	
	switch(tossInput)
	{
		case 1:
			cout << endl  << "                        " << tossWinnerTeam.name << " won the toss and elected to Bat first." << endl << endl;
			
			if(tossWinnerTeam.name.compare("Team-A") == 0)			// if teamA is the toss winner
			{
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			}
			else													// else teamB is the toss winner
			{
				battingTeam = &teamB;
				bowlingTeam = &teamA;					
			}
			
			break;
		case 2:
			cout << endl << "                        " << tossWinnerTeam.name << " won the toss and elected to Bowl first." << endl << endl;
			
			if(tossWinnerTeam.name.compare("Team-A") == 0)			// if teamA is the toss winner
			{
				bowlingTeam = &teamA;
				battingTeam = &teamB;
			}
			else													// else teamB is the toss winner
			{
				bowlingTeam = &teamB;
				battingTeam = &teamA;					
			}				
			break;
		default:
			cout << endl << "                         Invalid Input! Please try again." << endl << endl;
			tossChoice(tossWinnerTeam);
			break;	
	} 

}

void Game::startFirstInnings() {
	cout << "                         |||                         First Innings Start                         |||" << endl << endl;
	
	isFirstInnings = true;
	
	initializePlayers();
	playInnings();
}

void Game::initializePlayers() {
	
	if(isFirstInnings == true)
	{
		batsman = &battingTeam->players[0];
		bowler = &bowlingTeam->players[0];
	}
	else
	{
		swap(battingTeam, bowlingTeam);
		
		batsman = &battingTeam->players[0];
		bowler = &bowlingTeam->players[0];
	}
	cout << "                         " << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << "                         " << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
	
}

void Game::playInnings() {
	for(int i = 0; i < maxBalls; i++)
	{
		cout << "                         Press Enter to Bowl...";
		getchar();
		cout << "                         Bowling..." << endl;
		usleep(1000000);
		bat();
		
		if(!validateInningsScore())
		{
			break;
		}
	}
}

void Game::bat() {
	
	srand(time(NULL));
	int runsScored = rand() % 7;				// 0 to 6...
	
	// update batting team and batsman score.
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam ->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;
	
	// update bowling team and bowler score.
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;
	
	
	if(runsScored != 0)
	{
		cout << endl << "                         " << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
		showGameScoreCard();

	}
	else
	{
		cout << endl << "                         "  << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;
		battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
		bowler->wicketsTaken = bowler->wicketsTaken + 1;
		
		showGameScoreCard();
		
		int nextPlayerIndex = battingTeam->wicketsLost;
		batsman = &battingTeam->players[nextPlayerIndex];
	} 
}

bool Game::validateInningsScore() {
	
	if(isFirstInnings)				// for first Innings...
	{
		if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
		{
			cout << endl << "                         |||                           First Innings Ends                          |||" << endl << endl;
			cout << "                         " << battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ") " << endl;
			cout << "                         " << bowlingTeam->name << " " << battingTeam->totalRunsScored + 1 << " runs to win the match " << endl << endl;
//			int totalRunsScoredTeamA;
			totalRunsScoredTeamA = battingTeam->totalRunsScored;

			return false;
		}
	}
	else							// for second Innings...
	{
		if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
		{
			cout << "                         |||                         Second Innings Ends                         |||" << endl << endl;
			cout << "                         " << battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ") " << endl;
						
			if(totalRunsScoredTeamA > battingTeam->totalRunsScored || battingTeam->wicketsLost == playersPerTeam)
			{
				
				cout <<  "                        |===========================================================================|" << endl;
				cout <<  "                        |===========================================================================|" << endl;
				cout <<  "                        |                                                                           |" << endl;			
				cout <<  "                        |<------------------------- " << bowlingTeam->name << " won the Match --------------------------->|" << endl;
				cout <<  "                        |                                                                           |" << endl;
				cout <<  "                        |===========================================================================|" << endl;
				cout <<  "                        |===========================================================================|" << endl;		

				
			}
			else if(totalRunsScoredTeamA == battingTeam->totalRunsScored)
			{
				cout <<  "                        |===========================================================================|" << endl;
				cout <<  "                        |===========================================================================|" << endl;
				cout <<  "                        |                                                                           |" << endl;			
				cout <<  "                        |<------------------ " << bowlingTeam->name << " and " << battingTeam->name << " have a DRAW Match -------------------->|" << endl;
				cout <<  "                        |                                                                           |" << endl;
				cout <<  "                        |===========================================================================|" << endl;
				cout <<  "                        |===========================================================================|" << endl;		
				
			}
			else
			{
				cout <<  "                        |===========================================================================|" << endl;
				cout <<  "                        |===========================================================================|" << endl;
				cout <<  "                        |                                                                           |" << endl;			
				cout <<  "                        |<------------------------- " << battingTeam->name << " won the Match --------------------------->|" << endl;
				cout <<  "                        |                                                                           |" << endl;
				cout <<  "                        |===========================================================================|" << endl;
				cout <<  "                        |===========================================================================|" << endl;		
				
			}
				return false;
		}
	}
	return true;
}

void Game::showGameScoreCard() {
	cout << "                         |===========================================================================|" << endl;
	cout << "                                           " << battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t|" << bowler->name << " " << bowler->ballsBowled << "-" << bowler->runsGiven << "-" << bowler->wicketsTaken << "\t\t" << endl;
	cout << "                         |===========================================================================|" << endl;
}

void Game::startSecondInnings() {
	cout << "                         |||                         Second Innings Starts                         |||" << endl << endl;
	
	isFirstInnings = false;
	
	initializePlayers();
	playInnings();
}

void Game::matchSummary() {
		cout << endl << endl << endl << "                        |===========================================================================|" << endl;
		cout <<  "                        |===========================================================================|" << endl;
		cout <<  "                        |                                                                           |" << endl;		
		cout <<  "                        |<-------------------------- ||| Match Ends ||| --------------------------->|" << endl;
		cout <<  "                        |                                                                           |" << endl;
		cout <<  "                        |===========================================================================|" << endl;
		cout <<  "                        |===========================================================================|" << endl;
		
//		swap(battingTeam, bowlingTeam);
//		batsman = &battingTeam->players[0];
//		bowler = &bowlingTeam->players[0];
//		
//		cout << "                         " << battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ") " << endl;
//		
//		cout << "                        |===========================================================================|" << endl;
//		cout << "                        |    PLAYER                          BATTING                     BOWLING    |" << endl;
//		cout << "                        |===========================================================================|" << endl;
//		vector<Player> teamAPlayers = teamA.players;
//		vector<Player> teamBPlayers = teamB.players;
//		
//		for (int i = 0; i < playersPerTeam; i++) {
//        cout << "                        |\t" << "[" << i << "] " << teamAPlayers[i].name << "                     " << batsman->name << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ")" << "|\t" << "[" << i << "] " << teamBPlayers[i].name << "\t |" << endl;
//    	}
//    
//		cout << "                        |===========================================================================|" << endl;

}
