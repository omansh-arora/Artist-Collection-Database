#ifndef DATABASE_H
#define DATABASE_H

// Don't #include any other file
#include "artist.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "cmpt_error.h"
#include <sstream>
#include <algorithm>
#include <stdlib.h>

class Database
{
    //Vector that stores artist records
    vector<Artist> db;
    string s;

public:
    Database();
    //Reads in file with records into fb
    void readIn(const string &x);
    //Adds a record into database
    void add(Artist &r);
    //Prints the database
    void printDb();
    //Search functions for each field in record
    vector<Artist> nameSearch(string s);
    vector<Artist> ageSearch(int i);
    vector<Artist> genreSearch(string s);
    vector<Artist> albumSearch(int i);
    //Add record through menu
    void menuAdd();
    //Returns the vector for public access
    vector<Artist> const returnVec();
    //Additional search functions (Search by substring, Range)
    vector<Artist> name_sSearch(string s);
    vector<Artist> age_sSearch(int i, int p);
    vector<Artist> genre_sSearch(string s);
    vector<Artist> album_sSearch(int i, int p);
    //Delete a record
    void delRec_name(string &s);
    void delRec_sName(string &s);
    void delRec_age(int i);
    void delRec_ageRange(int i, int p);
    void delRec_genre(string &s);
    void delRec_sGenre(string &s);
    void delRec_albums(int i);
    void delRec_albumsRange(int i, int p);
    //List records
    vector<Artist> nameAlph();
    vector<Artist> name_rAlph();
    vector<Artist> age_asc();
    vector<Artist> age_dsc();
    vector<Artist> genreAlph();
    vector<Artist> genre_rAlph();
    vector<Artist> albums_asc();
    vector<Artist> albums_dsc();
    //Output to text file when program ends
    void output();
};

#endif