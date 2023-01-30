#ifndef MENU_H
#define MENU_H

#include "artist.h"
#include "database.h"
#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

class Menu
{

    //Variables which store users choice and a copy of database for easy access
    Database *db;
    int choice = 0;
    string input;

public:
    Menu(Database *db);
    //Menu options
    void mainMenu();
    void addArtist();
    void findArtist();
    void deleteArtist();
    void listArtist();
};

#endif
