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

int main(int argc, const char * argv[]) {
	
	// Local Vars
	string leagueType = "";
	int numberOfTeams = 0;
	
	// Constants
	const int ARGUMENTS_MIN = 3;
	const int TEAMS_MIN = 2;
	const int TEAMS_MAX = 50;
	const string LEAGUE_TYPE[] = {
		"soccer",
		"handball",
		"hockey"
	};
	const int SIZEOF_LEAGUE_TYPE = sizeof(LEAGUE_TYPE) / sizeof(LEAGUE_TYPE[0]);
	
	
	// Testing ********************************//
	// argc = ARGUMENTS_MIN;
	// Testing ********************************//
	
	// Check amount of arguments is ARGUMENTS_MIN
	if (argc == ARGUMENTS_MIN) {
		
		// Store Passed In Values
		
		// Production *****************************//
		leagueType = argv[1];
		// Production *****************************//
		
		// Testing ********************************//
		// leagueType = "hockey";
		// Testing ********************************//
		
		// Check if the legue type is equal to pre defined values
		if ((leagueType == LEAGUE_TYPE[0]) ||
			(leagueType == LEAGUE_TYPE[1]) ||
			(leagueType == LEAGUE_TYPE[2]))
		{
				
			// Production *****************************//
			numberOfTeams = atoi(argv[2]);
			// Production *****************************//
		
			// Testing ********************************//
			// numberOfTeams = 3;
			// Testing ********************************//
			
			// Produce error if TEAMS_MAX is breached
			if (numberOfTeams <= TEAMS_MAX) {
			
				// Check if integer is greater than or equal to two
				// Following specification
				if (numberOfTeams >= TEAMS_MIN) {
					
					// Have a try / catch, incase of mis use or failure of class
					try {
						
						
						// Declare a championship class
						ChampionShip championShip(leagueType, numberOfTeams);
						
						// Print Header Details
						championShip.displayHeaderDetails();
						
						// Print Games Played Details
						championShip.displayGamesPlayed();
						
						// Order the Teams
						// Update Rankings of Teams (Positions)
						championShip.updateTeamPositions();
						
						// Print the championship
						championShip.displayChampionShipTable();
						
						return 0;
						
						
					} catch (string e) {
						cerr << "Error: " << e << endl;
					}
					
				} else {
					cerr << "Please ensure the number of teams is greater than or equal to " << TEAMS_MIN << " in the tournament" << endl;
					return -1;
				}
				
			} else {
				cerr << "Please have an appropriate range of teams. No More than " << TEAMS_MAX << " in the tournament" << endl;
				return -1;
			}
			
		} else {
			cerr << "Please enter an appropriate League Type From Below: " << endl;
			
			for (int i = 0; i < SIZEOF_LEAGUE_TYPE; i++)
				cerr << i + 1 << ". " << LEAGUE_TYPE[i] << endl;
			
			return -1;
		}
		
	} else {
		cerr << "Please enter apropriate amount of arguments: " << ARGUMENTS_MIN - 1 << " arguments." << endl;
		return -1;
	}
	
	
    return 0;
}
