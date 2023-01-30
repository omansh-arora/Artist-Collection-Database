#include "artist.h"
#include "database.h"
#include "menu.h"

using namespace std;

Artist::Artist()
    : name(""), age(1), genre(""), albums(0){};
Artist::Artist(string s, int a, string g, int album)
    : name(s), age(a), genre(g), albums(album) {}

Artist::Artist(const Artist &other) : name(other.name),
                                      age(other.age), genre(other.genre), albums(other.albums) {}

string Artist::get_name() const { return name; }
int Artist::get_age() const { return age; }
string Artist::get_genre() const { return genre; }
int Artist::get_albums() const { return albums; }

void Artist::set_name(string &s) { name = s; }
void Artist::set_age(int x) { age = x; }
void Artist::set_genre(string &s) { genre = s; }
void Artist::set_albums(int x) { albums = x; }
