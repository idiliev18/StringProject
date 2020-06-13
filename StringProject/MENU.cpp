#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include "struct.h"
#include "CATEGORY.h"
#include "MENU.h"
#include "POST.h"
#include "data.h"
using namespace std;


MENU::MENU()
{
	data.loadPostData();
	cat.loadCategoryData();
}

void MENU::addPostMenu()
{
	string catName, title, text;
	string tags[5];
	short a;

	cout << "Enter category name: ";
	getline(cin, catName);

	cout << "Title: ";
	getline(cin, title);

	cout << "Text: ";
	getline(cin, text);

	cout << "How many tags you want to add: ";
	cin >> a;
	for (short i = 0; i < a; i++)
	{
		cout << i << ") ";
		cin >> tags[i];
	}

	data.createPost(catName, title, text, tags, a);
}
void MENU::addCategoryMenu()
{
	string catName;
	cout << "Enter category name: ";
	getline(cin, catName);
	cat.createCategory(catName);

}
void MENU::deleteCatMenu()
{
	string catName;
	cout << "Enter cat name: ";
	getline(cin, catName);
	cat.deleteCategory(catName);
}
void MENU::deletePostMenu()
{
	string title;
	cout << "Enter post title: ";
	getline(cin, title);
	data.deleteCategory(title);
}
void MENU::showPostFromCategoryMenu()
{
	string catName;
	cout << "Enter Category: ";
	getline(cin, catName);
	vector<POST_ITEM> filter = data.filterByCategory(catName);


	for (size_t i = 0; i < filter.size(); i++)
	{
		cout << "ID: " << filter[i].id << " " << "Title: " << filter[i].title << " " << "Author: " << filter[i].author << " " << "Text: " << filter[i].text << " " << "Date: " << filter[i].dateOfCreation << filter[i].categoryId << endl;
	}
}
void MENU::showAllPosts()
{
	vector<POST_ITEM> filter = data.returnAll();

	for (size_t i = 0; i < filter.size(); i++)
	{
		cout << "Title: " << filter[i].title;
		cout << " Author: " << filter[i].author;
		cout << " Text: " << filter[i].text;
		cout << " Date of creation: " << filter[i].dateOfCreation;
		cout << " Category: " << cat.getCatNameById(filter[i].categoryId) << endl;
	}
}

void MENU::getlenghtAndPrint(int characters, string str, int specific) {
	int length;
	if (specific == 1)
	{
		if (str.length() % 2 == 0)
			length = (((characters - str.length())) / 2);
		else
			length = ((characters - str.length()) / 2);
	}
	if (str.length() % 2 == 0)
		length = (((characters - str.length())) / 2);
	else
		length = ((characters - str.length()) / 2) - 1;
	for (int i = 0; i < (((characters - str.length())) / 2); i++)
	{
		cout << " ";
	}
	cout << str;
	for (int i = 0; i < length; i++)
	{
		cout << " ";
	}
}

void MENU::welcomeMenu() {
	int i = 2;
	string line, tokens[10];
	fstream myfile("acc.txt");
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			mamo.tokenize(line, tokens, ',');
			if (mamo.sess.name == tokens[0])
			{
				mamo.tokenize(tokens[3], mamo.sess.badges, '^');
			}
		}

	}
	cout << "\n             +-----------------------------------------+" << endl;
	cout << "             |";
	getlenghtAndPrint(42, mamo.sess.name, 1);
	cout << "|" << endl;
	cout << "             +-----------------------------------------+" << endl << endl;
	cout << " +------------------------------------+ " << endl;
	cout << " |               Badges:              | " << endl;
	cout << " |                                    | " << "       +---------------------+" << endl << " |";
	getlenghtAndPrint(37, mamo.sess.badges[0], 0);
	cout << "| " << "       |       9.Back        |" << endl << " |";
	getlenghtAndPrint(37, mamo.sess.badges[1], 0);
	cout << "| " << "       +---------------------+" << endl;


	while (mamo.sess.badges[i] != "")
	{
		cout << " |";

		getlenghtAndPrint(38, mamo.sess.badges[i], 0);
		cout << "| " << endl;
		i++;
	}
	cout << " |                                    | " << endl;
	cout << " +------------------------------------+ \n" << endl;
	mainMenu();
}

void MENU::Register() {
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
	myfile << endl << username << "," << password << ",0,Member^,";
	myfile.close();

}

void MENU::login() {
	string username, password, result = "invalidAccount";
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
			result = mamo.checkAcc(username, password);
		}
		mamo.sess.name = username;
		mamo.sess.logged = true;
		if (mamo.checkAcc(username, password) == "1")
		{
			manageAccounts();
		}
		else
		{
			welcomeMenu();
		}
	}
	else if (character == 'N')
	{
		cout << " Please first register before login!" << endl;
		Register();
	}
}

void MENU::manageAccounts() {
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
		cout << " |                5. Manage badges                    |" << endl;
		cout << " |                9. Go back                          |" << endl;
		cout << " +----------------------------------------------------+\n" << endl;
		cout << " Choose option: ";
		cin >> choice;
		if (choice == 9)
		{
			//go to menu
		}
		else if (choice > 0 && choice < 6)
		{
			mamo.managingAccountsFunction(choice);
		}
		cout << endl;
	}

}

void MENU::mainMenu() {
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
		switch (choice)
		{
			case 1:
				showAllPosts();
				break;
			case 2:
				break;
			case 3:
				break;
		}
	}

}

bool MENU::categoriesMenu()
{
	int choice;

	cout << "                   +-------------------------+" << endl;
	cout << "                   |     Categories Menu     |" << endl;
	cout << "                   +-------------------------+" << endl;
	cout << endl;
	cout << " +-----------------------------------------------------------+" << endl;
	cout << " |                                                           |" << endl;
	cout << " |                   1.                                      |" << endl;
	cout << " |                   2.                                      |" << endl;
	cout << " |                   3.                                      |" << endl;
	cout << " |                   4.                                      |" << endl;
	cout << " |                   5.                                      |" << endl;
	cout << " |                   9.Exit                                  |" << endl;
	cout << " |                                                           |" << endl;
	cout << " +-----------------------------------------------------------+\n" << endl;
	cout << " Choose option: ";
	cin >> choice;

	while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 9) {

		cout << "\n Incorect input, please try again: "; cin >> choice;

	}

	switch (choice) {

		case 1: return true;
			break;
		case 2: return true;
			break;
		case 3: return true;
			break;
		case 4: return true;
			break;
		case 5: return true;
			break;
		case 9: return false;
			break;
	}
	return true;
}

void MENU::profileMenu()
{
	int choice;

	cout << "\n             +-----------------------------------------+" << endl;
	cout << "             |                 Username                |" << endl;
	cout << "             +-----------------------------------------+" << endl;
	cout << endl;
	cout << " +------------------------------------+ " << endl;
	cout << " |               Badges:              | " << endl;
	cout << " |                                    | " << "       +---------------------+" << endl;
	cout << " |                                    | " << "       |       9.Back        |" << endl;
	cout << " |                                    | " << "       +---------------------+" << endl;
	cout << " |                                    | " << endl;
	cout << " |                                    | " << endl;
	cout << " +------------------------------------+ \n" << endl;
	cout << " Click 9 to back: "; cin >> choice;


	while (choice != 9) {

		cout << "\n Incorrect input, please try again:"; cin >> choice;

	}

	cout << "\n______________________________________________________________________________" << endl;

	switch (choice) {

		case 9:
			break;

	}

}

