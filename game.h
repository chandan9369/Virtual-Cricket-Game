#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"
#include <unistd.h>

class Game
{
public:
    Game();
    int playerPerTeam;
    int maxBalls;
    int totalPlayers;
    std::string players[11] = {"R Sharma", "S Dhawan", "V Kohli", "KL Rahul", "S Iyer", "Rishabh",
                               "R Jadeja", "H Pandya", "J Bumrah", "M Shami", "B Kumar"};
    bool isfirstInnings;
    Team teamA, teamB;
    Team *battingTeam;
    Team *bowlingTeam;
    Player *batsman, *bowler;
    void greet();
    void instructions();
    void press();
    void pool();
    void show_player();
    int takeInteger();
    void selectPlayer();
    bool validateSelectedPlayer(int);
    void showTeamPlayer();
    void TossCoin();
    void tossChoice(Team);
    void startfirstInnings();
    void initializePlayers();
    void playInnings();
    void Bat();
    int validateInningsScore();
    void show_game();
    void startsecondInnings();
    void showepitome();

};
};
