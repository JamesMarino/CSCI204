/*------------------------------------------------------
 Student's Name: James Marino
 Student's email address: jm617@uow.edu.au
 Laboratory group: CL/03 Friday 15:30
 Purpose of this assignment:
  - Simulate a championship tournament using an object
	oriented model as in UML diagram in specification
 ------------------------------------------------------- */

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

// Multiple Inclusion Gaurds
#ifndef _GAURD_
#define _GAURD_

class Team;
class Game;

class ChampionShip
{
	private:
	
		// Composite classes
		Game *game;
		Team *team;
	
		std::string leagueType;
		int numberOfTeams;
		int numberOfGamesToPlay;
	
		// Helpers
		void randomiseArray(int*);
		void assignGamesToPlay();
	
	public:
	
		// Constants
		static const std::string HOME;
		static const std::string VISTING;
	
		ChampionShip();
		~ChampionShip();
		ChampionShip(std::string, int);
	
		// Public Helpers
		void updateTeamPositions();
	
		// Output Functions
		void displayHeaderDetails() const;
		void displayGamesPlayed() const;
		void displayChampionShipTable() const;
};

class Game
{
	private:
		Team *homeTeam;
		Team *visitingTeam;
	
		static const int POINTS_WIN;
		static const int POINTS_DRAW;
		static const int POINTS_LOSE;
	
		int homeTeamGoals;
		int visitingTeamGoals;
	
	public:
		Game();
	
		// Helpers
		void playTeams(Team*, Team*);
		void playGame();
	
		// Read Only Access to Members
		int getHomeTeamGoals() const;
		int getVisitingTeamGoals() const;
		std::string getTeamName(std::string) const;
};

class Team
{
	private:
		
		// Constants
		static const std::string TEAM_PREFIX;
		
		std::string teamName;
		int totalPoints;
		int goalsScoredFor;
		int goalsScoredAgainst;
	
	public:
		
		// Constructors / Destructors
		Team();
		
		// Utilities
		int computeGoalDifference();
		
		// Get or Set Private Methods
		int getOrSetTotalPoints(int p = 0);
		int getOrSetGoalsScoredFor(int g = 0);
		int getOrSetGoalsScoredAgainst(int g = 0);
		
		// Getting / Setting Team Name
		std::string getTeamName() const;
		void setTeamName(int);

		// Overloaded Operators
		bool operator==(const Team&) const;
		bool operator!=(const Team&) const;
		bool operator>(const Team&) const;
		bool operator<(const Team&) const;
		const Team& operator=(const Team&);
	
};

// End Inclusion Guard
#endif
