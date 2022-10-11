#include<vector>
#include "Player.h"		//<string>

class Team {
	
	public:
		Team();		//Default Constructor...
		std::string name;
		int totalRunsScored;
		int wicketsLost;
		int totalBallsBowled;
		std::vector<Player> players;
			
};
