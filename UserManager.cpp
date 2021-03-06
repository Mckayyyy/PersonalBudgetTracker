#include "UserManager.h"

bool UserManager::checkIfUserAlreadyExists(string checkedUserLogin)
{
    for(auto it1 = users.begin(); it1 != users.end() ; it1++ )
    {
        if(it1->getLogin() == checkedUserLogin) return true;
    }
    return false;
}

int UserManager::getNewUserId()
{
    if(users.empty()) return 1;
    else return users.back().getId() +1;
}

void UserManager::displayUsers()
{
    if(users.empty()) cout << "Nie ma uzytkownikow" << endl;

    for(auto it1 = users.begin(); it1 != users.end() ; it1++ )
    {
        cout << it1->getId() << endl;
        cout << it1->getLogin() << endl;
        cout << it1->getPassword() << endl;
    }
}

void UserManager::registration()
{
    string login;
    string password;
    string name;
    string surname;

    cout << "Podaj nazwe uzytkownika: ";
    cin >> login;

    while(checkIfUserAlreadyExists(login))
    {
        cout << "Nazwa uzytkownika jest juz zajeta" << endl;
        cout << "Sprobuj jeszcze raz" << endl;
        cin >> login;
    }
    cout << "Podaj haslo: ";
    cin >> password;

    cout << "Podaj imie: ";
    cin >> name;

    cout << "Podaj nazwisko: ";
    cin >> surname;

    User user(getNewUserId(),login,password,name,surname);
    users.push_back(user);

    usersXMLFile.saveUserToXMLFile(user);
    cout << "Pomyslnie zarejestrowano uzytkownika!" << endl;
}

int UserManager::checkIfCorrectPassword(string login, string password)
{
    for(auto it1 = users.begin() ; it1 != users.end(); it1++)
    {
        if(it1->getLogin() == login)
        {
            if(it1->getPassword() == password) return it1->getId();
            else return 0;
        }
    }
    return 0;
}

void UserManager::loggingIn()
{
    string login;
    string password;

    cout << "Podaj login: ";
    cin >> login;

    int number;

    if(checkIfUserAlreadyExists(login))
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            cout << "Podaj haslo: ";
            cin >> password;
            number = checkIfCorrectPassword(login,password);
            if(number)
            {
                cout << "Pomyslnie zalogowano." << endl;
                loggedInUserId = number;
                return ;
            }
            else
            {
                cout << "Zle haslo. Pozostalo ci " << 2 - i << " proby. " << endl;
            }
        }
    }
    else cout << "Nie ma takiego uzytkownika!" << endl;
}

int UserManager::getLoggedinUserId()
{
    return this->loggedInUserId;
}

void UserManager::changePassword()
{
    string newPassword;

    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for(auto it1 = users.begin(); it1 != users.end(); it1++ )
    {
        if (it1 -> getId() == loggedInUserId)
        {
            it1 -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione pomyslnie." << endl;
            usersXMLFile.savePasswordChangeToXMLFile(it1->getLogin(),newPassword);
        }
    }
}

void UserManager::logout()
{
    loggedInUserId = 0;
}

char UserManager::loginMenu()
{
    char decision;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    cin >> decision;
    return decision;
}
