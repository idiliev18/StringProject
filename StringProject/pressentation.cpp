#include "presentation.h"
#include <iostream>
#include "struct.h"
#include <fstream>
#include <vector>
#include <string>
#include "data.h"
using namespace std;

void PRESENTATION_LAYER::Register() {
	ofstream myfile("acc.txt", ios::app);
	string username, password, c_password;
	cout << endl;

	cout << "   +------------------------------------+";
	cout << endl;
	cout << "   |              Register              |\n";
	cout << "   +------------------------------------+\n" << endl;
	cout << " Username: ";
	cin >> username;
	cout << " Password: ";
	cin >> password;
	cout << " Confirm password: ";
	cin >> c_password;

	cout << " ________________________________________________" << endl;
	
	while (c_password != password)
	{
		cout << "\n Invalid confirm password, please enter confirm pass again: "; cin >> c_password;
	}

	cout << endl;
	myfile << endl << username << "," << password << ",0,";
	myfile.close();

}

void PRESENTATION_LAYER::login() {
	string username, password, result = " invalidAccount";
	char character;
	cout << " Do you have existing account[Y/N]: ";
	cin >> character;
	cout << endl;

	while (character != 'Y' && character != 'N') {

		cout << " Invalid option, try again: ";
		cin >> character;

	}

	if (character == 'Y')
	{
		while (result == "invalidAccount")
		{
			cout << "   +------------------------------------+";
			cout << endl;
			cout << "   |               Login                |\n";
			cout << "   +------------------------------------+\n" << endl;
			cout << " Username: ";
			cin >> username;
			cout << " Password: ";
			cin >> password;
			cout << endl;
			cout << " ________________________________________________\n" << endl;
			result = checkAcc(username, password);
		}
		if (checkAcc(username, password) == "1")
		{

		}
		else
		{

		}
	}
	else if (character == 'N')
	{
		cout << " Please first register before login!" << endl;
		Register();
	}
}

void PRESENTATION_LAYER::manageAccounts() {
	int choice;
	bool accManagmentMenu = true, userExist = false;
	while (accManagmentMenu)
	{
		userExist = false;
		cout << " ______________________________________________________" << endl;
		cout << endl;
		cout << " +----------------------------------------------------+" << endl;
		cout << " |                1. Show all accounts                |" << endl; 
		cout << " |                2. Delete account                   |" << endl;
		cout << " |                3. Edit username                    |" << endl;
		cout << " |                4. Remove/Add Admin                 |" << endl;
		cout << " |                9. Go back                          |" << endl;
		cout << " +----------------------------------------------------+\n" << endl;
		cout << " Choose option: ";
		cin >> choice;
		if (choice == 9)
		{
			//go to menu
		}
		else if (choice > 0 && choice < 5)
		{
			da.managingAccountsFunction(choice);
		}
		cout << endl;
	}

}


void PRESENTATION_LAYER::mainMenu() {
	int choice;
	bool accManagmentMenu = true, userExist = false;
	while (accManagmentMenu)
	{
		userExist = false;
		cout << "                      +-------------------+" << endl;
		cout << "                      |     Main Menu     |" << endl;
		cout << "                      +                   +" << endl;
		cout << " +---------------------                   -------------------+" << endl;
		cout << " |                                                           |" << endl;
		cout << " |          1.                   2.                 9.       |" << endl;
		cout << " |    Show all posts      Show categories        Go back     |" << endl;
		cout << " |                                                           |" << endl;
		cout << " +-----------------------------------------------------------+\n" << endl;
		cout << " Choose option: ";
		cin >> choice;
		if (choice == 9)
		{
			//go to menu
		}
		else if (choice > 0 && choice < 2)
		{
			managingAccountsFunction(choice);
		}
		cout << endl;
	}

}
