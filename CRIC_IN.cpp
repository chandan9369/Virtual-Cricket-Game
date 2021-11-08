#include "game.h"
using namespace std;



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
