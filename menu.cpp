#include "artist.h"
#include "database.h"
#include "menu.h"

using namespace std;

//Prints database
void printVec(vector<Artist> &v)
{

    for (int i = 0; i < v.size(); i++)
    {

        cout << "\n"
             << v[i].get_name()
             << ", " << v[i].get_age()
             << ", " << v[i].get_genre()
             << ", Albums: " << v[i].get_albums() << "\n";
    }
}

//Functions to validate input
auto intChecker(string &age)
{

    for (int i = 0; i < age.length(); i++)
    {

        if (!isdigit(age[i]))
            return false;
    }
    return true;
}

auto ageValider(string &age)
{

    if (!intChecker(age))
        return false;
    if (stoi(age) <= 0 || stoi(age) > 200)
        return false;
    return true;
}

auto albumValider(string &age)
{

    if (!intChecker(age))
        return false;
    if (stoi(age) < 0 || stoi(age) > 200)
        return false;
    return true;
}

//Menu constructor
Menu::Menu(Database *db) : db(db){};

//Menu options
void Menu::mainMenu()
{

    choice = -1;

    cout << "-------------------------------\n";
    cout << "Welcome to artist database 1.0!\n";
    cout << "-------------------------------\n";
    cout << "(1) Add an artist\n";
    cout << "(2) Find an artist\n";
    cout << "(3) Delete an artist\n";
    cout << "(4) List records\n\n";
    cout << "(0) Exit database\n";
    cout << "-------------------------------\n";

    while (choice < 0 || choice > 4)
    {

        getline(std::cin, input);
        if (input == "0")
        {
            db->output();
            exit(EXIT_SUCCESS);
        }
        if (!intChecker(input))
            choice = -1;
        else
            choice = stoi(input);
        if (choice < 0 || choice > 4)
        {

            cout << "Please enter a valid choice: ";
        }
    }

    if (choice == 1)
        Menu::addArtist();
    if (choice == 2)
        Menu::findArtist();
    if (choice == 3)
        Menu::deleteArtist();
    if (choice == 4)
        Menu::listArtist();

    if (choice == 0)
    {
        db->output();
        exit(EXIT_SUCCESS);
    }
}
void Menu::addArtist()
{

    cout << "------------------------------\n";
    cout << "Add an artist.";
    cout
        << "Type \"EXIT\" at any time to return to main menu.\n";

    db->menuAdd();
    cout << "------------------------------\n";

    Menu::mainMenu();
}
void Menu::findArtist()
{

    cout << "------------------------------\n";
    cout << "(1) Find by name\n";
    cout << "(2) Find by name - partial match\n";
    cout << "(3) Find by age\n";
    cout << "(4) Find by age range\n";
    cout << "(5) Find by genre\n";
    cout << "(6) Find by genre - partial match\n";
    cout << "(7) Find by number of albums\n";
    cout << "(8) Find by number of albums - range\n";
    cout << "\n(0) Return to main menu\n";
    cout << "------------------------------\n";

    choice = -1;

    string input;

    while (choice < 0 || choice > 8)
    {

        getline(std::cin, input);
        if (input == "0")
            Menu::mainMenu();
        if (!intChecker(input))
            choice = -1;
        else
            choice = stoi(input);
        if (choice < 0 || choice > 8)
        {

            cout << "Please enter a valid choice: ";
        }
    }

    if (choice == 1)
    {

        cout
            << "Please enter the name of the artist: ";

        getline(std::cin, input);

        vector<Artist> v = db->nameSearch(input);

        if (v.size() == 0)
        {

            cout << "Sorry no records found.";
            Menu::findArtist();
        }

        printVec(v);

        Menu::findArtist();
    }
    if (choice == 2)
    {

        cout << "Please enter the partial name of the artist: ";

        getline(std::cin, input);

        vector<Artist> v = db->name_sSearch(input);

        if (v.size() == 0)
        {

            cout << "\nSorry no records found.\n";
            Menu::findArtist();
        }

        printVec(v);

        Menu::findArtist();
    }
    if (choice == 3)
    {

        cout << "Please enter the age of the artist: ";

        getline(std::cin, input);

        while (!intChecker(input) || !ageValider(input))
        {

            cout << "Please enter a valid age: ";
            getline(std::cin, input);
        }

        vector<Artist> v = db->ageSearch(stoi(input));

        if (v.size() == 0)
        {

            cout << "\nSorry no records found.\n";
            Menu::findArtist();
        }

        printVec(v);

        Menu::findArtist();
    }
    if (choice == 4)
    {

        cout
            << "Please enter the lower age of the artist: ";

        string low;
        getline(std::cin, low);

        while (!intChecker(low) || !ageValider(low))
        {

            cout << "Please enter a valid age: ";
            getline(std::cin, low);
        }

        cout
            << "Please enter the higher age of the artist: ";

        string high;
        getline(std::cin, high);

        while (!intChecker(high) || !ageValider(high) || stoi(high) <= stoi(low))
        {

            cout << "Please enter a valid age: ";
            getline(std::cin, high);
        }

        vector<Artist> v = db->age_sSearch(stoi(low),
                                           stoi(high));

        if (v.size() == 0)
        {

            cout << "\nSorry no records found.\n";
            Menu::findArtist();
        }

        printVec(v);

        Menu::findArtist();
    }
    if (choice == 5)
    {

        cout
            << "Please enter the genre of the artist: ";

        getline(std::cin, input);

        vector<Artist> v = db->genreSearch(input);

        if (v.size() == 0)
        {

            cout << "Sorry no records found.";
            Menu::findArtist();
        }

        printVec(v);

        Menu::findArtist();
    }
    if (choice == 6)
    {

        cout
            << "Please enter the partial genre of the artist: ";

        getline(std::cin, input);

        vector<Artist> v = db->genre_sSearch(input);

        if (v.size() == 0)
        {

            cout << "Sorry no records found.";
            Menu::findArtist();
        }

        printVec(v);

        Menu::findArtist();
    }
    if (choice == 7)
    {

        cout << "Please enter the albums of the artist: ";

        getline(std::cin, input);

        while (!intChecker(input) || !albumValider(input))
        {

            cout << "Please enter a valid number: ";
            getline(std::cin, input);
        }

        vector<Artist> v = db->albumSearch(stoi(input));

        if (v.size() == 0)
        {

            cout << "\nSorry no records found.\n";
            Menu::findArtist();
        }

        printVec(v);

        Menu::findArtist();
    }
    if (choice == 8)
    {

        cout
            << "Please enter the lower album number of the artist: ";

        string low;
        getline(std::cin, low);

        while (!intChecker(low) || !albumValider(low))
        {

            cout << "Please enter a valid number: ";
            getline(std::cin, low);
        }

        cout
            << "Please enter the higher album number of the artist: ";

        string high;
        getline(std::cin, high);

        while (!intChecker(high) || !albumValider(high) || stoi(high) <= stoi(low))
        {

            cout << "Please enter a valid number: ";
            getline(std::cin, high);
        }

        vector<Artist> v = db->album_sSearch(stoi(low),
                                             stoi(high));

        if (v.size() == 0)
        {

            cout << "\nSorry no records found.\n";
            Menu::findArtist();
        }

        printVec(v);

        Menu::findArtist();
    }
    if (choice == 0)
        Menu::mainMenu();
}
void Menu::deleteArtist()
{

    cout << "------------------------------\n";
    cout << "(1) Delete by name\n";
    cout << "(2) Delete by name - partial match\n";
    cout << "(3) Delete by age\n";
    cout << "(4) Delete by age range\n";
    cout << "(5) Delete by genre\n";
    cout << "(6) Delete by genre - partial match\n";
    cout << "(7) Delete by number of albums\n";
    cout << "(8) Delete by number of albums - range\n";
    cout << "\n(0) Return to main menu\n";
    cout << "------------------------------\n";

    choice = -1;

    string input;

    while (choice < 0 || choice > 8)
    {

        getline(std::cin, input);
        if (input == "0")
            Menu::mainMenu();
        if (!intChecker(input))
            choice = -1;
        else
            choice = stoi(input);
        if (choice < 0 || choice > 8)
        {

            cout << "Please enter a valid choice: ";
        }
    }

    if (choice == 1)
    {

        cout
            << "Please enter the name of the artist: ";

        getline(std::cin, input);

        db->delRec_name(input);

        Menu::deleteArtist();
    }
    if (choice == 2)
    {

        cout << "Please enter the partial name of the artist: ";

        getline(std::cin, input);

        db->delRec_sName(input);

        Menu::deleteArtist();
    }
    if (choice == 3)
    {

        cout << "Please enter the age of the artist: ";

        getline(std::cin, input);

        while (!intChecker(input) || !ageValider(input))
        {

            cout << "Please enter a valid age: ";
            getline(std::cin, input);
        }

        db->delRec_age(stoi(input));

        Menu::deleteArtist();
    }
    if (choice == 4)
    {

        cout
            << "Please enter the lower age of the artist: ";

        string low;
        getline(std::cin, low);

        while (!intChecker(low) || !ageValider(low))
        {

            cout << "Please enter a valid age: ";
            getline(std::cin, low);
        }

        cout
            << "Please enter the higher age of the artist: ";

        string high;
        getline(std::cin, high);

        while (!intChecker(high) || !ageValider(high) || stoi(high) <= stoi(low))
        {

            cout << "Please enter a valid age: ";
            getline(std::cin, high);
        }

        db->delRec_ageRange(stoi(low),
                            stoi(high));

        Menu::deleteArtist();
    }
    if (choice == 5)
    {

        cout
            << "Please enter the genre of the artist: ";

        getline(std::cin, input);

        db->delRec_genre(input);

        Menu::deleteArtist();
    }
    if (choice == 6)
    {

        cout
            << "Please enter the partial genre of the artist: ";

        getline(std::cin, input);

        db->genre_sSearch(input);

        Menu::deleteArtist();
    }
    if (choice == 7)
    {

        cout << "Please enter the albums of the artist: ";

        getline(std::cin, input);

        while (!intChecker(input) || !albumValider(input))
        {

            cout << "Please enter a valid number: ";
            getline(std::cin, input);
        }

        db->delRec_albums(stoi(input));

        Menu::deleteArtist();
    }
    if (choice == 8)
    {

        cout
            << "Please enter the lower album number of the artist: ";

        string low;
        getline(std::cin, low);

        while (!intChecker(low) || !albumValider(low))
        {

            cout << "Please enter a valid number: ";
            getline(std::cin, low);
        }

        cout
            << "Please enter the higher album number of the artist: ";

        string high;
        getline(std::cin, high);

        while (!intChecker(high) || !albumValider(high) || stoi(high) <= stoi(low))
        {

            cout << "Please enter a valid number: ";
            getline(std::cin, high);
        }

        db->delRec_albumsRange(stoi(low),
                               stoi(high));

        Menu::deleteArtist();
    }
    if (choice == 0)
        Menu::mainMenu();
}
void Menu::listArtist()
{

    cout << "------------------------------\n";
    cout << "(1) List by name - alphabetical\n";
    cout << "(2) List by name - reverse alphabetical\n";
    cout << "(3) List by age - ascending\n";
    cout << "(4) List by age - descending\n";
    cout << "(5) List by genre - alphabetical\n";
    cout << "(6) List by genre - reverse alphabetical\n";
    cout << "(7) List by number of albums - ascending\n";
    cout << "(8) List by number of albums - descending\n";
    cout << "(9) List all records\n";
    cout << "\n(0) Return to main menu\n";
    cout << "------------------------------\n";

    choice = -1;

    string input;

    while (choice < 0 || choice > 9)
    {

        getline(std::cin, input);
        if (input == "0")
            Menu::mainMenu();
        if (!intChecker(input))
            choice = -1;
        else
            choice = stoi(input);
        if (choice < 0 || choice > 8)
        {

            cout << "Please enter a valid choice: ";
        }
    }

    if (choice == 1)
    {

        vector<Artist> v = db->nameAlph();

        printVec(v);

        Menu::listArtist();
    }
    if (choice == 2)
    {

        vector<Artist> v = db->name_rAlph();

        printVec(v);

        Menu::listArtist();
    }
    if (choice == 3)
    {

        vector<Artist> v = db->age_asc();

        printVec(v);

        Menu::listArtist();
    }
    if (choice == 4)
    {

        vector<Artist> v = db->age_dsc();

        printVec(v);

        Menu::listArtist();
    }
    if (choice == 5)
    {

        vector<Artist> v = db->genreAlph();

        printVec(v);

        Menu::listArtist();
    }
    if (choice == 6)
    {

        vector<Artist> v = db->genre_rAlph();

        printVec(v);

        Menu::listArtist();
    }
    if (choice == 7)
    {

        vector<Artist> v = db->albums_asc();

        printVec(v);

        Menu::listArtist();
    }
    if (choice == 8)
    {

        vector<Artist> v = db->albums_dsc();

        printVec(v);

        Menu::listArtist();
    }
    if (choice == 9)
    {

        vector<Artist> v = db->returnVec();
        printVec(v);
    }

    if (choice == 0)
    {

        Menu::mainMenu();
    }
}