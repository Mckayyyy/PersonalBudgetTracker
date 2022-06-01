#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <windows.h>

#include "UserManager.h"


using namespace std;

void displayUser(User user)
{
    cout << user.getId() << endl;
    cout << user.getLogin() << endl;
    cout << user.getPassword() << endl;
}


int main()
{
    string fileRoot = "C:\\Users\\progg\\Desktop\\Budget\\PersonalBudgetTracker\\Users.xml";


    UserManager userManager(fileRoot);

    userManager.displayUsers();

    cout << endl;

    cout << userManager.getLoggedinUserId();

    system("pause");

    userManager.loggingIn();

    cout << userManager.getLoggedinUserId();

    system ("pause");


    return 0;
}
