#include"player.h"
#include<vector>

class Team
{
  public:

  Team();

  std::string name;

    int total_runs_scored;

    int lost_wickets;

    int total_balls_Bowled;

   std:: vector<Player> players;
};
