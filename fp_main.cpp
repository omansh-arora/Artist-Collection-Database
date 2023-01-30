/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

#include "artist.h"
#include "database.h"
#include "menu.h"
#include <string>

using namespace std;

int main()
{

    string file = "database.txt";

    Database d;

    Database *d_point = &d;

    d.readIn(file);

    Menu menu(d_point);

    menu.mainMenu();
}