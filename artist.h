#ifndef RECORD_H
#define RECORD_H

#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Artist
{
    //Fields for record
    string name;
    int age;
    string genre;
    int albums;

public:
    //Constructors
    Artist();
    Artist(string s, int a, string g, int album);
    Artist(const Artist &other);
    //Get functions to access private variables
    string get_name() const;
    int get_age() const;
    string get_genre() const;
    int get_albums() const;
    //Set functions to change private variabls
    void set_name(string &s);
    void set_age(int x);
    void set_genre(string &s);
    void set_albums(int x);
};

#endif