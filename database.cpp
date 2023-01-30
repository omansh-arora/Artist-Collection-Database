#include "artist.h"
#include "database.h"
#include "menu.h"

using namespace std;

//Functions for validating user input
auto intCheck(string &age)
{

    for (int i = 0; i < age.length(); i++)
    {

        if (!isdigit(age[i]))
            return false;
    }
    return true;
}

auto ageValid(string &age)
{

    if (!intCheck(age))
        return false;
    if (stoi(age) <= 0 || stoi(age) > 200)
        return false;
    return true;
}

auto albumValid(string &age)
{

    if (!intCheck(age))
        return false;
    if (stoi(age) < 0 || stoi(age) > 200)
        return false;
    return true;
}
//

Database::Database() {}

void Database::readIn(const string &x)
{

    s = x;
    ifstream fin;
    fin.open(s);
    string s;
    vector<string> reply;

    while (getline(fin, s))
    {

        int i = 0;
        string g = "";

        for (int p = i; p < s.length() + 1; p++)
        {

            if (s[p] != ',')
            {
                i++;
                g = g + s[p];
            }
            else if (s[p] == ',')
            {
    
                reply.push_back(g);
                g = "";
                i++;
    
            }
        }
        reply.push_back(g);

        Artist r1(reply[0], stoi(reply[1]), reply[2], stoi(reply[3]));
        db.push_back(r1);
        reply.clear();
    }
}

void Database::add(Artist &r) { db.push_back(r); }

void Database::printDb()
{
    for (int i = 0; i < db.size(); i++)
    {

        cout << db[i].get_name() << ", "
             << db[i].get_age() << ", "
             << db[i].get_genre() << ", "
             << db[i].get_albums() << endl;
    }
}

vector<Artist> Database::nameSearch(string s)
{

    vector<Artist> v;
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    for (int i = 0; i < db.size(); i++)
    {

        string x = db[i].get_name();
        transform(x.begin(), x.end(), x.begin(), ::toupper);
        if (x == s)
            v.push_back(db[i]);
    }

    return v;
}
vector<Artist> Database::ageSearch(int i)
{

    vector<Artist> v;

    for (int j = 0; j < db.size(); j++)
    {

        if (db[j].get_age() == i)
            v.push_back(db[j]);
    }

    return v;
}
vector<Artist> Database::genreSearch(string s)
{

    vector<Artist> v;
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    for (int i = 0; i < db.size(); i++)
    {

        string x = db[i].get_genre();
        transform(x.begin(), x.end(), x.begin(), ::toupper);

        if (x == s)
            v.push_back(db[i]);
    }

    return v;
}
vector<Artist> Database::albumSearch(int i)
{

    vector<Artist> v;

    for (int j = 0; j < db.size(); j++)
    {

        if (db[j].get_albums() == i)
            v.push_back(db[j]);
    }

    return v;
}

void Database::menuAdd()
{

    string name;
    string age;
    string genre;
    string album;

    auto nameDup = [&](string s) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);

        for (int i = 0; i < db.size(); i++)
        {

            string x = db[i].get_name();
            transform(x.begin(), x.end(), x.begin(), ::toupper);
            if (x == s)
                return true;
        }
        return false;
    };

    cout << "\nEnter the name of the artist: ";
    getline(cin, name);

    if (name == "EXIT")
        return;

    while (nameDup(name))
    {

        cout << "That artist already exists in the database!\n";
        cout << "Enter the name of the artist: ";
        getline(cin, name);
        if (name == "EXIT")
        return;
    }

    cout << "Enter the age of the artist: ";
    std::getline(cin, age);

    if (age == "EXIT")
        return;

    while (!intCheck(age) || !ageValid(age))
    {

        cout << "Please enter a valid number: ";
        std::getline(cin, age);
        if (age == "EXIT")
        return;
    }

    cout << "Enter the genre: ";
    getline(cin, genre);

    if (genre == "EXIT")
        return;

    cout << "Enter the number of albums: ";
    std::getline(cin, album);

    if (album == "EXIT")
        return;

    while (!intCheck(album) || !albumValid(album))
    {

        cout << "Please enter a valid number: ";
        std::getline(cin, album);
        if (genre == "EXIT")
        return;
    }

    Artist r1(name, stoi(age), genre, stoi(album));

    cout << "\nArtist added.\n\n";

    Database::add(r1);
}

vector<Artist> const Database::returnVec()
{

    return db;
}

vector<Artist> Database::name_sSearch(string s)
{

    vector<Artist> v;
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    for (int i = 0; i < db.size(); i++)
    {

        string x = db[i].get_name();
        transform(x.begin(), x.end(), x.begin(), ::toupper);
        if (x.find(s) != string::npos)
            v.push_back(db[i]);
    }

    return v;
}
vector<Artist> Database::age_sSearch(int i, int p)
{

    vector<Artist> v;

    for (int j = 0; j < db.size(); j++)
    {

        if (db[j].get_age() >= i && db[j].get_age() <= p)
            v.push_back(db[j]);
    }

    return v;
}
vector<Artist> Database::genre_sSearch(string s)
{

    vector<Artist> v;
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    for (int i = 0; i < db.size(); i++)
    {

        string x = db[i].get_genre();
        transform(x.begin(), x.end(), x.begin(), ::toupper);

        if (x.find(s) != string::npos)
            v.push_back(db[i]);
    }

    return v;
}
vector<Artist> Database::album_sSearch(int i, int p)
{

    vector<Artist> v;

    for (int j = 0; j < db.size(); j++)
    {

        if (db[j].get_albums() >= i && db[j].get_albums() <= p)
            v.push_back(db[j]);
    }

    return v;
}

void Database::delRec_name(string &s)
{

    transform(s.begin(), s.end(), s.begin(), ::toupper);

    for (int i = 0; i < db.size(); i++)
    {

        string x = db[i].get_name();
        transform(x.begin(), x.end(), x.begin(), ::toupper);
        if (x == s)
        {

            cout << "Are you sure you would like to delete the following artist: \n\n";
            cout << db[i].get_name() << ", " << db[i].get_age() << ", "
                 << db[i].get_genre() << ", " << db[i].get_albums() << " albums\n\n";
            cout << "(1) Yes\n";
            cout << "(2) No\n";
            int choice = -1;
            string input;
            while (choice < 0 || choice > 2)
            {

                std::getline(cin, input);

                //Check to see if user input is an int
                if (!intCheck(input))
                    choice = -1;
                else
                    choice = stoi(input);

                if (choice < 0 || choice > 2)
                {

                    cout << "Please enter a valid choice: ";
                }
            }

            cout << "\n";

            if (choice == 1)
            {

                cout << "Artist erased succesfully.\n";
                db.erase(db.begin() + i);
                i = i - 1;
            }
        }
    }
}
void Database::delRec_sName(string &s)
{

    transform(s.begin(), s.end(), s.begin(), ::toupper);

    for (int i = 0; i < db.size(); i++)
    {

        string x = db[i].get_name();
        transform(x.begin(), x.end(), x.begin(), ::toupper);
        if (x.find(s) != string::npos)
        {

            cout << "Are you sure you would like to delete the following artist: \n\n";
            cout << db[i].get_name() << ", " << db[i].get_age() << ", "
                 << db[i].get_genre() << ", " << db[i].get_albums() << " albums\n\n";
            cout << "(1) Yes\n";
            cout << "(2) No\n";
            int choice = -1;
            string input;
            while (choice < 0 || choice > 2)
            {

                std::getline(cin, input);

                //Check to see if user input is an int
                if (!intCheck(input))
                    choice = -1;
                else
                    choice = stoi(input);

                if (choice < 0 || choice > 2)
                {

                    cout << "Please enter a valid choice: ";
                }
            }

            cout << "\n";

            if (choice == 1)
            {
                cout << "Artist erased succesfully.\n";
                db.erase(db.begin() + i);
                i = i - 1;
            }
        }
    }
}
void Database::delRec_age(int i)
{

    for (int j = 0; j < db.size(); j++)
    {

        if (db[j].get_age() == i)
        {

            cout << "Are you sure you would like to delete the following artist: \n\n";
            cout << db[j].get_name() << ", " << db[j].get_age() << ", "
                 << db[j].get_genre() << ", " << db[j].get_albums() << " albums\n\n";
            cout << "(1) Yes\n";
            cout << "(2) No\n";
            int choice = -1;
            string input;

            while (choice < 0 || choice > 2)
            {

                std::getline(cin, input);

                //Check to see if user input is an int
                if (!intCheck(input))
                    choice = -1;
                else
                    choice = stoi(input);

                if (choice < 0 || choice > 2)
                {

                    cout << "Please enter a valid choice: ";
                }
            }

            cout << "\n";

            if (choice == 1)
            {
                cout << "Artist erased succesfully.\n";
                db.erase(db.begin() + j);
                j = j - 1;
            }
        }
    }
}
void Database::delRec_ageRange(int i, int p)
{

    for (int j = 0; j < db.size(); j++)
    {

        if (db[j].get_age() >= i && db[j].get_age() <= p)
        {

            cout << "Are you sure you would like to delete the following artist: \n\n";
            cout << db[j].get_name() << ", " << db[j].get_age() << ", "
                 << db[j].get_genre() << ", " << db[j].get_albums() << " albums\n\n";
            cout << "(1) Yes\n";
            cout << "(2) No\n";
            int choice = -1;
            string input;
            while (choice < 0 || choice > 2)
            {

                std::getline(cin, input);

                //Check to see if user input is an int
                if (!intCheck(input))
                    choice = -1;
                else
                    choice = stoi(input);

                if (choice < 0 || choice > 2)
                {

                    cout << "Please enter a valid choice: ";
                }
            }

            cout << "\n";

            if (choice == 1)
            {
                db.erase(db.begin() + j);
                j = j - 1;
            }
        }
    }
}
void Database::delRec_genre(string &s)
{

    transform(s.begin(), s.end(), s.begin(), ::toupper);

    for (int i = 0; i < db.size(); i++)
    {

        string x = db[i].get_genre();
        transform(x.begin(), x.end(), x.begin(), ::toupper);

        if (x == s)
        {

            cout << "Are you sure you would like to delete the following artist: \n\n";
            cout << db[i].get_name() << ", " << db[i].get_age() << ", "
                 << db[i].get_genre() << ", " << db[i].get_albums() << " albums\n\n";
            cout << "(1) Yes\n";
            cout << "(2) No\n";
            int choice = -1;
            string input;
            while (choice < 0 || choice > 2)
            {

                std::getline(cin, input);

                //Check to see if user input is an int
                if (!intCheck(input))
                    choice = -1;
                else
                    choice = stoi(input);

                if (choice < 0 || choice > 2)
                {

                    cout << "Please enter a valid choice: ";
                }
            }

            cout << "\n";

            if (choice == 1)
            {

                cout << "Artist erased succesfully.\n";
                db.erase(db.begin() + i);
                i = i - 1;
            }
        }
    }
}
void Database::delRec_sGenre(string &s)
{

    transform(s.begin(), s.end(), s.begin(), ::toupper);

    for (int i = 0; i < db.size(); i++)
    {

        string x = db[i].get_genre();
        transform(x.begin(), x.end(), x.begin(), ::toupper);

        if (x.find(s) != string::npos)
        {

            cout << "Are you sure you would like to delete the following artist: \n\n";
            cout << db[i].get_name() << ", " << db[i].get_age() << ", "
                 << db[i].get_genre() << ", " << db[i].get_albums() << " albums\n\n";
            cout << "(1) Yes\n";
            cout << "(2) No\n";
            int choice = -1;
            string input;
            while (choice < 0 || choice > 2)
            {

                std::getline(cin, input);

                //Check to see if user input is an int
                if (!intCheck(input))
                    choice = -1;
                else
                    choice = stoi(input);

                if (choice < 0 || choice > 2)
                {

                    cout << "Please enter a valid choice: ";
                }
            }

            cout << "\n";

            if (choice == 1)
            {

                cout << "Artist erased succesfully.\n";
                db.erase(db.begin() + i);
                i = i - 1;
            }
        }
    }
}
void Database::delRec_albums(int i)
{

    for (int j = 0; j < db.size(); j++)
    {

        if (db[j].get_albums() == i)
        {

            cout << "Are you sure you would like to delete the following artist: \n\n";
            cout << db[j].get_name() << ", " << db[j].get_age() << ", "
                 << db[j].get_genre() << ", " << db[j].get_albums() << " albums\n\n";
            cout << "(1) Yes\n";
            cout << "(2) No\n";
            int choice = -1;
            string input;

            while (choice < 0 || choice > 2)
            {

                std::getline(cin, input);

                //Check to see if user input is an int
                if (!intCheck(input))
                    choice = -1;
                else
                    choice = stoi(input);

                if (choice < 0 || choice > 2)
                {

                    cout << "Please enter a valid choice: ";
                }
            }

            cout << "\n";

            if (choice == 1)
            {
                cout << "Artist erased succesfully.\n";
                db.erase(db.begin() + j);
                j = j - 1;
            }
        }
    }
}
void Database::delRec_albumsRange(int i, int p)
{

    for (int j = 0; j < db.size(); j++)
    {

        if (db[j].get_albums() >= i && db[j].get_albums() <= p)
        {

            cout << "Are you sure you would like to delete the following artist: \n\n";
            cout << db[j].get_name() << ", " << db[j].get_age() << ", "
                 << db[j].get_genre() << ", " << db[j].get_albums() << " albums\n\n";
            cout << "(1) Yes\n";
            cout << "(2) No\n";
            int choice = -1;
            string input;

            while (choice < 0 || choice > 2)
            {

                std::getline(cin, input);

                //Check to see if user input is an int
                if (!intCheck(input))
                    choice = -1;
                else
                    choice = stoi(input);

                if (choice < 0 || choice > 2)
                {

                    cout << "Please enter a valid choice: ";
                }
            }

            cout << "\n";

            if (choice == 1)
            {
                cout << "Artist erased succesfully.\n";
                db.erase(db.begin() + j);
                j = j - 1;
            }
        }
    }
}

vector<Artist> Database::nameAlph()
{

    vector<Artist> sorted = db;

    auto alph_check = [&](Artist &a, Artist &b) {
        return a.get_name() < b.get_name();
    };

    sort(sorted.begin(), sorted.end(), alph_check);

    return sorted;
}
vector<Artist> Database::name_rAlph()
{

    vector<Artist> sorted = db;

    auto rAlph_check = [&](Artist &a, Artist &b) {
        return a.get_name() > b.get_name();
    };

    sort(sorted.begin(), sorted.end(), rAlph_check);

    return sorted;
}
vector<Artist> Database::age_asc()
{

    vector<Artist> sorted = db;

    auto asc_check = [&](Artist &a, Artist &b) {
        return a.get_age() < b.get_age();
    };

    sort(sorted.begin(), sorted.end(), asc_check);

    return sorted;
}
vector<Artist> Database::age_dsc()
{

    vector<Artist> sorted = db;

    auto dsc_check = [&](Artist &a, Artist &b) {
        return a.get_age() > b.get_age();
    };

    sort(sorted.begin(), sorted.end(), dsc_check);

    return sorted;
}
vector<Artist> Database::genreAlph()
{

    vector<Artist> sorted = db;

    auto alph_check = [&](Artist &a, Artist &b) {
        return a.get_genre() < b.get_genre();
    };

    sort(sorted.begin(), sorted.end(), alph_check);

    return sorted;
}
vector<Artist> Database::genre_rAlph()
{

    vector<Artist> sorted = db;

    auto rAlph_check = [&](Artist &a, Artist &b) {
        return a.get_genre() > b.get_genre();
    };

    sort(sorted.begin(), sorted.end(), rAlph_check);

    return sorted;
}
vector<Artist> Database::albums_asc()
{

    vector<Artist> sorted = db;

    auto asc_check = [&](Artist &a, Artist &b) {
        return a.get_albums() < b.get_albums();
    };

    sort(sorted.begin(), sorted.end(), asc_check);

    return sorted;
}
vector<Artist> Database::albums_dsc()
{

    vector<Artist> sorted = db;

    auto dsc_check = [&](Artist &a, Artist &b) {
        return a.get_albums() > b.get_albums();
    };

    sort(sorted.begin(), sorted.end(), dsc_check);

    return sorted;
}

void Database::output()
{

    ofstream myfile;
    myfile.open(s);

    for (int i = 0; i < db.size(); i++)
    {
        myfile << db[i].get_name()
               << "," << db[i].get_age()
               << "," << db[i].get_genre()
               << "," << db[i].get_albums() << "\n";
    }
    myfile.close();
}