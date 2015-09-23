/*------------------------------------------------------
 Student's Name: James Marino
 Student's email address: jm617@uow.edu.au
 Laboratory group: CL/03 Friday 15:30
 Purpose of this assignment:
  - Simulate a championship tournament using an object
	oriented model as in UML diagram in specification
 ------------------------------------------------------- */

#include "classes.h"
using namespace std;

/****************************************************************
 Class - Championship - Implementation
 ****************************************************************/

const string ChampionShip::HOME = "HOME";
const string ChampionShip::VISTING = "VISTING";


ChampionShip::ChampionShip()
{
	string exception = "Default Constructor in Class Championship Used.";
	throw exception;
}

ChampionShip::ChampionShip(string leagueName, int noOfTeams)
{
	// Initialise static values
	leagueType = leagueName;
	numberOfTeams = noOfTeams;
	numberOfGamesToPlay = noOfTeams*(noOfTeams-1);
	
	// Create correct amount of dynamic values
	team = new Team[numberOfTeams]();
	game = new Game[numberOfGamesToPlay]();
	
	// Set Team Names
	for (int i = 0; i < numberOfTeams; i++) {
		team[i].setTeamName(i+1);
	}
	// Assign the teams playing
	assignGamesToPlay();
	
	// Play the Game for all games
	for (int i = 0; i < numberOfGamesToPlay; i++) {
		game[i].playGame();
	}
	
}

ChampionShip::~ChampionShip()
{
	// DETROY ALL INSTANCES
	delete [] team;
	delete [] game;
}

void ChampionShip::assignGamesToPlay()
{
	
	// Local Vars
	// Set the game number to 0
	int gameNo = 0;
	
	// Make a randomised list
	// CC does not support array creation using non contant values
	// int list[numberOfGamesToPlay];
	
	// Make a dynamic randomised list
	int * list = new int[numberOfGamesToPlay];
	
	// Randomise the list
	randomiseArray(list);
	
	// Loop over all the teams to play
	for (int teamNo = 0; teamNo < numberOfTeams; teamNo++) {
		
		// Loop over all the teams to play again
		for (int teamGameNo = 0; teamGameNo < numberOfTeams; teamGameNo++) {
			
			// Check to see if the teams are playing themselves
			if (teamNo != teamGameNo) {
				
				// Assign what games to be played by what teams in a random order
				game[list[gameNo]].playTeams(&team[teamNo], &team[teamGameNo]);
				
				// Increment the amount of games being played
				gameNo++;
				
			}
		}
	}
	
	// Delete dynamically created list
	delete [] list;
	
}

void ChampionShip::randomiseArray(int * inputArray)
{
	// Local Vars
	int randomNumber = -1;
	bool notUniqueToList = true;
	
	// Initialise the list
	for (int i = 0; i < numberOfGamesToPlay; i++) {
		inputArray[i] = -1;
	}
	
	for (int i = 0; i < numberOfGamesToPlay; i++) {
		
		// while the random number is not unique to the list
		while (notUniqueToList) {
			
			// Get a random value
			randomNumber = rand() % numberOfGamesToPlay;
			
			// Assume there will not be a match
			notUniqueToList = false;
			
			// Check if it has been used
			// Traverse the list
			for (int j = 0; j < numberOfGamesToPlay; j++) {
				if (inputArray[j] == randomNumber) {
					
					// Set flag to true, a match was found
					notUniqueToList = true;
					
					// Exit out unique found, no need to go further
					break;
					
				}
			}
		}
		
		// Store the value in the array
		inputArray[i] = randomNumber;
		
		// Reset the flag
		notUniqueToList = true;
	}
	
	
}

void ChampionShip::updateTeamPositions()
{
	
	// Create Tempory Team
	Team temp;
	
	// Iterate through teams
	for (int i = 0; i < numberOfTeams - 1; i++) {
		for (int j = i + 1; j < numberOfTeams; j++) {
			
			if (team[i] < team[j]) {
				
				// Swap them
				temp = team[i];
				team[i] = team[j];
				team[j] = temp;
				
			} else if (team[i] == team[j]) {
				
				// Test who has the highest goal difference
				// goalDifference[i] < goalDifference[j]
				if (team[i].computeGoalDifference() < team[j].computeGoalDifference()) {
					
					// Swap them
					temp = team[i];
					team[i] = team[j];
					team[j] = temp;
					
					// Test if Goal Difference is the same
					// goalDifference[i] == goalDifference[j]
				} else if (team[i].computeGoalDifference() == team[j].computeGoalDifference()) {
					
					// Test who has the highest amount of goals scored for
					// goalsScoredFor[i] < goalsScoredFor[j]
					if (team[i].getOrSetGoalsScoredFor() < team[j].getOrSetGoalsScoredFor()) {
						
						// Swap them
						temp = team[i];
						team[i] = team[j];
						team[j] = temp;
						
					}
					
				}
				
			}
			
		}
		
	}
	
}

void ChampionShip::displayHeaderDetails() const
{
	cout << "*** " << leagueType << " League Championship ***" << endl;
	cout << "- Participant List -" << endl;
	
	for (int i = 0 ; i < numberOfTeams; i++) {
		cout << team[i].getTeamName() << endl;
	}
	
	cout << endl;
	
}

void ChampionShip::displayGamesPlayed() const
{
	// Output to client
	cout << "- Games Played -" << endl;
	
	for (int i = 0; i < numberOfGamesToPlay; i++) {
		cout << game[i].getTeamName(ChampionShip::HOME) << " "
		<< game[i].getTeamName(ChampionShip::VISTING) << " " << setw(4)
		<< game[i].getHomeTeamGoals() << " " << setw(4)
		<< game[i].getVisitingTeamGoals() << endl;
	}
	
	cout << endl;
}

void ChampionShip::displayChampionShipTable() const
{
	// Output to client
	int samePositionCounter = 0;
	
	cout << "- Championship Table - " << endl;
	cout << "Position" << setw(10)
	<< "|   Team" << setw(15)
	<< "|   Points" << setw(15)
	<< "|   GoalDiff" << setw(15)
	<< "|   GoalsFor" << setw(20)
	<< "|   Goals Against" << setw(15)
	<< endl;
	
	for (int i = 0; i < numberOfTeams; i++) {
		
		// Test if Goals Scored for are the same
		if ((team[i - 1] == team[i]) &&
			(team[i - 1].computeGoalDifference() == team[i].computeGoalDifference()) &&
			(team[i - 1].getOrSetGoalsScoredFor() == team[i].getOrSetGoalsScoredFor())) {
			
			// Display previous position again (is equal positioning)
			cout << setw(5) << (i);
			
			// Increase the counter
			samePositionCounter++;
			
		} else {
			
			// Print as normal
			cout << setw(5) << ((i + 1) - samePositionCounter);
		}
		
		cout
		<< setw(14) << team[i].getTeamName()
		<< setw(12) << team[i].getOrSetTotalPoints()
		<< setw(13) << team[i].computeGoalDifference()
		<< setw(16) << team[i].getOrSetGoalsScoredFor()
		<< setw(16) << team[i].getOrSetGoalsScoredAgainst()
		<< setw(0) << endl;
		
	}
	
	cout << endl;
}

/****************************************************************
 Class - Game - Implementation
 ****************************************************************/

const int Game::POINTS_WIN = 3;
const int Game::POINTS_DRAW = 1;
const int Game::POINTS_LOSE = 0;

Game::Game()
{
	// Initialise Teams to NULL
	homeTeam = NULL;
	visitingTeam = NULL;
	
	// Set Points to 0
	homeTeamGoals = 0;
	visitingTeamGoals = 0;
	
}

void Game::playTeams(Team *home, Team *visiting)
{
	// Set home and visiting pointers
	homeTeam = home;
	visitingTeam = visiting;
}

void Game::playGame()
{
	// Set GAME goals randomly
	homeTeamGoals = rand() % 10 + 1;
	visitingTeamGoals = rand() % 10 + 1;
	
	// Update TEAM goals with above values
	// Home Team
	homeTeam->getOrSetGoalsScoredFor(homeTeamGoals);
	homeTeam->getOrSetGoalsScoredAgainst(visitingTeamGoals);
	
	// Update TEAM goals with above values
	// Visiting Team
	visitingTeam->getOrSetGoalsScoredFor(visitingTeamGoals);
	visitingTeam->getOrSetGoalsScoredAgainst(homeTeamGoals);
	
	// Set The Points
	if (homeTeamGoals > visitingTeamGoals) {
		// Give Winner Points
		homeTeam->getOrSetTotalPoints(POINTS_WIN);
	} else if (homeTeamGoals == visitingTeamGoals) {
		// Give Both points
		homeTeam->getOrSetTotalPoints(POINTS_DRAW);
		visitingTeam->getOrSetTotalPoints(POINTS_DRAW);
	} else {
		// Give Winner Points
		visitingTeam->getOrSetTotalPoints(POINTS_WIN);
	}
}

int Game::getHomeTeamGoals() const
{
	return homeTeamGoals;
}

int Game::getVisitingTeamGoals()  const
{
	return visitingTeamGoals;
}

string Game::getTeamName(string option) const
{
	if (option == ChampionShip::HOME) {
		return homeTeam->getTeamName();
	} else if (option == ChampionShip::VISTING) {
		return visitingTeam->getTeamName();
	} else {
		// Just incase
		return "Use either HOME or VISITING as options";
	}
}

/*****************************************************************
 Class - Team - Implementation
 ****************************************************************/

const string Team::TEAM_PREFIX = "Team";

Team::Team()
{
	teamName = "";
	totalPoints = 0;
	goalsScoredFor = 0;
	goalsScoredAgainst = 0;
}

int Team::computeGoalDifference()
{
	return goalsScoredFor - goalsScoredAgainst;
}

string Team::getTeamName() const
{
	return teamName;
}

void Team::setTeamName(int counter)
{
	// Reference: String Stream application
	// Converting integer to strings without using C++ 11
	// to_string unavaliable on CC on Banshee
	// http://stackoverflow.com/questions/5290089/how-to-convert-a-number-to-string-and-vice-versa-in-c
	
	
	counter = counter + 1;
	
	// New String Stream
	ostringstream stringStream;
	
	// Read in integer
	stringStream << counter;
	
	string counterString = stringStream.str();
	
	teamName = TEAM_PREFIX + counterString;
	// teamName = TEAM_PREFIX + to_string(counter);
}

int Team::getOrSetTotalPoints(int p) {
	// Check if getting or setting
	if (p == 0) {
		return totalPoints;
	} else {
		totalPoints += p;
		return 0;
	}
}

int Team::getOrSetGoalsScoredFor(int g) {
	// Check if getting or setting
	if (g == 0) {
		return goalsScoredFor;
	} else {
		goalsScoredFor += g;
		return 0;
	}
}

int Team::getOrSetGoalsScoredAgainst(int g) {
	// Check if getting or setting
	if (g == 0) {
		return goalsScoredAgainst;
	} else {
		goalsScoredAgainst += g;
		return 0;
	}
}

/*
 * Operators for Team
 */

bool Team::operator==(const Team &team) const
{
	return (totalPoints == team.totalPoints);
}

bool Team::operator!=(const Team &team) const
{
	return (totalPoints != team.totalPoints);
}

bool Team::operator>(const Team &team) const
{
	return (totalPoints > team.totalPoints);
}

bool Team::operator<(const Team &team) const
{
	return (totalPoints < team.totalPoints);
}

const Team& Team::operator=(const Team &team)
{
	if (this != &team) {
		// Copy Data Members
		teamName = team.teamName;
		totalPoints = team.totalPoints;
		goalsScoredFor = team.goalsScoredFor;
		goalsScoredAgainst = team.goalsScoredAgainst;
	}
	
	return (*this);
	
}
