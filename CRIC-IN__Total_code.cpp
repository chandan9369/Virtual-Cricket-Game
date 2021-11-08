#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

class Player
{
public:
    Player();
    std::string name;
    int index;
    int runs_scored;
    int ball_played;
    int ball_bowled;
    int runs_given;
    int wicketsTaken;
};

Player::Player()
{
    runs_scored = 0;
    ball_played = 0;
    ball_bowled = 0;
    runs_given = 0;
    wicketsTaken = 0;
}
class Team
{
public:
    Team();
    std::string name;
    int total_runs_scored;
    int lost_wickets;
    int total_balls_Bowled;
    std::vector<Player> players;
};

Team::Team()
{
    total_runs_scored = 0;
    lost_wickets = 0;
    total_balls_Bowled = 0;
};
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

Game::Game()
{
    playerPerTeam = 4;
    maxBalls = 6;
    totalPlayers = 11;
    isfirstInnings = 0;
    teamA.name = "Team-A";
    teamB.name = "Team-B";
}
void Game::greet()
{
    cout << "\t\t******************************************\n";
    cout << "\t\t|=================CRIC-IN================|\n";
    cout << "\t\t|                                        |\n";
    cout << "\t\t|    Welcome To Virtual Cricket Game     |\n";
    cout << "\t\t******************************************\n\n";
    usleep(2000000);
}
void Game::instructions()
{
    cout << "\t\t*****************************************************\n";
    cout << "\t\t|====================Instructions===================|\n";
    cout << "\t\t|                                                   |\n";
    cout << "\t\t| 1. Create 2 teams (team-A and team-B with 4       |\n";
    cout << "\t\t|    players each) from a given pool of 11 players. |\n";
    cout << "\t\t| 2. lead the toss and decide the choice of play.   |\n";
    cout << "\t\t| 3. Each innings will be of 6 balls.               |\n";
    cout << "\t\t*****************************************************\n\n";
    usleep(2000000);
}

void Game::press()
{
    cout << "\t\tPress Enter to continue......\n";
    getchar();
    cout << "\n\n";
}
void Game::pool()
{
    cout << "\t\t*******************************************\n";
    cout << "\t\t|=============Pool of Players=============|\n";
    cout << "\t\t*******************************************\n\n";
    usleep(2000000);
}
void Game::show_player()
{
    for (int i = 0; i < 11; i++)
    {
        cout << "\t\t\t [" << i << "] " << players[i] << endl;
        usleep(200000);
    }
    cout << endl;
}

int Game::takeInteger()
{
    int n;

    while (!(cin >> n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please try again with valid input: ";
    }
    return n;
}
bool Game::validateSelectedPlayer(int a)
{
    int n;
    vector<Player> players;
    players = teamA.players;
    n = players.size();
    for (int i = 0; i < n; i++)
    {
        if (players[i].index == a)
        {
            return false;
        }
    }
    players = teamB.players;
    n = players.size();
    for (int i = 0; i < n; i++)
    {
        if (players[i].index == a)
        {
            return false;
        }
    }
    return true;
}
void Game::selectPlayer()
{
    cout << "\t\t**********************************************\n";
    cout << "\t\t|========= Create Team-A and Team-B =========|\n";
    cout << "\t\t**********************************************\n\n";
    usleep(2000000);
    for (int i = 0; i < 4; i++)
    {
    //Add player for team-A
    teamASelection:
        cout << endl
             << "Select player " << i + 1 << " of  Team A - ";
        int playerIndexTeamA = takeInteger();
        if (playerIndexTeamA < 0 || playerIndexTeamA > 10)
        {
            cout << endl
                 << "Please select from the given players " << endl;
            goto teamASelection;
        }
        else if (!validateSelectedPlayer(playerIndexTeamA))
        {
            cout << endl
                 << "Player has been already selected. Please select other player " << endl;
            goto teamASelection;
        }

        else
        {
            Player teamAPlayer;
            teamAPlayer.index = playerIndexTeamA;
            teamAPlayer.name = players[playerIndexTeamA];
            teamA.players.push_back(teamAPlayer);
        }

        //Add player for team-B
    teamBSelection:
        cout << endl
             << "Select player " << i + 1 << " of  Team B - ";
        int playerIndexTeamB = takeInteger();
        if (playerIndexTeamB < 0 || playerIndexTeamB > 10)
        {
            cout << endl
                 << "Please select from the given players " << endl;
            goto teamBSelection;
        }
        else if (!validateSelectedPlayer(playerIndexTeamB))
        {
            cout << endl
                 << "Player has been already selected. Please select other player " << endl;
            goto teamBSelection;
        }

        else
        {

            Player teamBPlayer;
            teamBPlayer.index = playerIndexTeamB;
            teamBPlayer.name = players[playerIndexTeamB];
            teamB.players.push_back(teamBPlayer);
        }
    }
}

void Game::showTeamPlayer()
{
    vector<Player> teamAPlayers = teamA.players;
    vector<Player> teamBPlayers = teamB.players;

    cout << endl
         << endl;
    cout << "\t\t************************\t\t************************" << endl;
    cout << "\t\t|=====  Team-A  =======|\t\t|=======  Team-B  =====|" << endl;
    cout << "\t\t************************\t\t************************" << endl;

    for (int i = 0; i < playerPerTeam; i++)
    {
        cout << "\t\t"
             << "\t[" << i << "] " << teamAPlayers[i].name << "\t"
             << "\t\t"
             << "\t[" << i << "] " << teamBPlayers[i].name << "\t" << endl;
    }
    cout << "\t\t************************\t\t************************" << endl
         << endl;
    usleep(2000000);
}

void Game::TossCoin()
{
    srand(time(NULL));
    cout << "\t\t**********************************************\n";
    cout << "\t\t|================ Let's Toss  ================|\n";
    cout << "\t\t**********************************************\n\n";
    usleep(2000000);
    cout << "\t\tTossing the coin...\n";
    int t = rand() % 2;
    if (t == 1)
    {
        cout << "\t\tTeam-A won the toss\n";
        tossChoice(teamA);
    }
    else
    {
        cout << "\t\tTeam-B won the toss\n";
        tossChoice(teamB);
    }
}
void Game::tossChoice(Team tossWinnerTeam)
{

    cout << "Enter 1 to bat or 2 to bowl first. " << endl
         << "1. Bat" << endl
         << "2. Bowl " << endl;

    int tossInput = takeInteger();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (tossInput)
    {
    case 1:
        cout << endl
             << tossWinnerTeam.name << " won the toss and elected to bat first" << endl
             << endl;

        if (tossWinnerTeam.name.compare("Team-A") == 0)
        { // if Team-A is the toss winner
            battingTeam = &teamA;
            bowlingTeam = &teamB;
        }
        else
        { // else Team-B is the toss winner
            battingTeam = &teamB;
            bowlingTeam = &teamA;
        }

        break;
    case 2:
        cout << endl
             << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl
             << endl;

        if (tossWinnerTeam.name.compare("Team-A") == 0)
        { // if Team-A is the toss winner
            bowlingTeam = &teamA;
            battingTeam = &teamB;
        }
        else
        { // else Team-B is the toss winner
            bowlingTeam = &teamB;
            battingTeam = &teamA;
        }

        break;
    default:
        cout << endl
             << "Invalid input. Please try again:" << endl
             << endl;
        tossChoice(tossWinnerTeam);
        break;
    }
}
void Game::startfirstInnings()
{
    cout << "\t\t|||  FIRST INNINGS START  ||| \n\n";
    isfirstInnings = true;
    initializePlayers();
}
void Game::startsecondInnings()
{
    cout << "\t\t|||  SECOND INNINGS START  ||| \n\n";
    isfirstInnings = false;
    Team *t = battingTeam;
    battingTeam = bowlingTeam;
    bowlingTeam = t;
    initializePlayers();
}

void Game::initializePlayers()
{
    //choose  batsman and bowler
    batsman = &battingTeam->players[0];
    bowler = &bowlingTeam->players[0];
    cout << battingTeam->name << "-" << batsman->name << " is batting " << endl;
    cout << bowlingTeam->name << "-" << bowler->name << " is bowling \n"
         << endl;
}

void Game::playInnings()
{

    for (int i = 0; i < maxBalls; i++)
    {
        press();
        cout << "Bowling ...\n";
        Bat();
        if (!validateInningsScore())
        {
            break;
        }
    }
}

void Game::Bat()
{
    srand(time(NULL));
    int runScored = rand() % 7;
    // updating batting team and batsman score

    batsman->runs_scored += runScored;
    battingTeam->total_runs_scored += runScored;
    batsman->ball_played += 1;

    //updatting bowling team and bower score
    bowler->ball_bowled += 1;
    bowlingTeam->total_balls_Bowled += 1;
    bowler->runs_given += runScored;

    if (runScored != 0)
    {
        cout << endl
             << bowler->name << " to " << batsman->name << " " << runScored << " runs!\n\n";
        show_game();
    }
    else
    {
        cout << endl
             << bowler->name << " to " << batsman->name << " OUT!\n\n";
        battingTeam->lost_wickets += 1;
        bowler->wicketsTaken += 1;
        show_game();
        int nextPlayerIndex = battingTeam->lost_wickets;
        batsman = &battingTeam->players[nextPlayerIndex];
    }
}

int Game::validateInningsScore()
{

    if (isfirstInnings)
    {

        if ((battingTeam->lost_wickets == playerPerTeam) || (bowlingTeam->total_balls_Bowled == maxBalls))
        {

            cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl
                 << endl;

            cout << battingTeam->name << " " << battingTeam->total_runs_scored << " - "
                 << battingTeam->lost_wickets << " (" << bowlingTeam->total_balls_Bowled
                 << ")" << endl;

            cout << bowlingTeam->name << " needs " << battingTeam->total_runs_scored + 1
                 << " runs to win the match" << endl
                 << endl;

            return 0;
        }
    }
    else
    { // Else 2nd innings
        if (bowlingTeam->total_runs_scored < battingTeam->total_runs_scored)
        {
            cout << battingTeam->name << " WON THE MATCH\n";
        }
        else if (((battingTeam->lost_wickets == playerPerTeam) || (bowlingTeam->total_balls_Bowled == maxBalls)))
        {
            if (bowlingTeam->total_runs_scored > battingTeam->total_runs_scored)
            {
                cout << bowlingTeam->name << " WON THE MATCH\n";
            }
            else if (bowlingTeam->total_runs_scored == battingTeam->total_runs_scored)
            {
                cout << "MATCH TIED\n";
            }
        }
    }

    return 1;
}

void Game ::show_game()
{
    cout << "--------------------------------------------------------------------------" << endl;

    cout << "\t" << battingTeam->name << "  " << battingTeam->total_runs_scored << " - "
         << battingTeam->lost_wickets << " (" << bowlingTeam->total_balls_Bowled << ") | " << batsman->name
         << " " << batsman->runs_scored << " (" << batsman->ball_played << ") \t" << bowler->name << " "
         << bowler->ball_bowled << " - " << bowler->runs_given << " - " << bowler->wicketsTaken << "\t" << endl;

    cout << "--------------------------------------------------------------------------" << endl
         << endl;
}
void Game::showepitome()
{
    cout << "\t\t ||| MATCH ENDS ||| " << endl
         << endl;
    cout << bowlingTeam->name << " " << bowlingTeam->total_runs_scored << "-" << bowlingTeam->lost_wickets << " (" << maxBalls << ")" << endl;
    cout << "========================================================\n";
    cout << " PLAYER                BATTING                BOWLING   \n";
    for (int i = 0; i < playerPerTeam; i++)
    {
        cout << "------------------------------------------------------\n";
        cout << " [" << i << "]" << bowlingTeam->players[i].name << "            " << bowlingTeam->players[i].runs_scored << "(" << bowlingTeam->players[i].ball_played << ")                 " << bowlingTeam->players[i].ball_bowled << "-" << bowlingTeam->players[i].runs_given << "-" << bowlingTeam->players[i].wicketsTaken << "  \n";
    }
    cout << "========================================================\n";
    cout << "\n\n";
    cout << battingTeam->name << " " << battingTeam->total_runs_scored << "-" << battingTeam->lost_wickets << " (" << maxBalls << ")" << endl;
    cout << "========================================================\n";
    cout << " PLAYER                BATTING                BOWLING   \n";
    for (int i = 0; i < playerPerTeam; i++)
    {
        cout << "------------------------------------------------------\n";
        cout << " [" << i << "]" << battingTeam->players[i].name << "            " << battingTeam->players[i].runs_scored << "(" << battingTeam->players[i].ball_played << ")                 " << battingTeam->players[i].ball_bowled << "-" << battingTeam->players[i].runs_given << "-" << battingTeam->players[i].wicketsTaken << "  \n";
    }
    cout << "========================================================\n";
}
int main()
{
    Game game;
    game.greet();

    game.instructions();

    game.press();

    game.pool();

    game.show_player();

    game.press();

    game.selectPlayer();

    game.showTeamPlayer();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    game.press();

    game.TossCoin();

    game.startfirstInnings();

    game.playInnings();

    cout << "Press enter to start second inning......\n";
    getchar();
    usleep(20000);
    game.startsecondInnings();

    game.playInnings();

    game.showepitome();

    return 0;
}