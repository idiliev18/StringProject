#include "presentation.h"
#include <iostream>
#include "struct.h"
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include "data.h"
using namespace std;


void DATA_LAYER::deleteAccount() {
	ifstream myfile("acc.txt");
	ofstream tmpFile("accTmp.txt");
	string tokens[10], help;
	int counter = 0;
	string line;
	bool userExist = false;
	cout << "Name of user: ";
	cin >> help;

	if (myfile.is_open())
	{
		string line;
		while (!myfile.eof())
		{
			getline(myfile, line);

			if (line != "") {

				tokenize(line, tokens, ',');

				if (help != tokens[0]) {

					if (tmpFile.is_open())
					{
						counter = 2;
						tmpFile << tokens[counter] << "," << tokens[counter--] << "," << tokens[counter--] << "," << endl;
					}

				}
				else
				{
					userExist = true;
				}
			}
		}
		myfile.close();

		if (remove("acc.txt") != 0) {
			cerr << "A wild error appeared: ";
		}
		else {
			cout << "Deleting account 50% done" << endl;
		}

		tmpFile.close();

		if (rename("accTmp.txt", "acc.txt") != 0)
		{
			cerr << "A wild error appeared : ";
		}
		else
		{
			cout << "Deleting account done!!!!" << endl;
		}
	}
}

void DATA_LAYER::editUsername() {
	ifstream myfile("acc.txt");
	ofstream tmpFile("accTmp.txt");
	string tokens[10], help,newUsername;
	int counter = 0;
	string line;
	bool userExist = false;

	cout << "Name of user: ";
	cin >> help;

	if (myfile.is_open())
	{
		string line;

		while (!myfile.eof())
		{
			getline(myfile, line);

			if (line != "") {
				tokenize(line, tokens, ',');

				if (help != tokens[0]) {

					if (tmpFile.is_open())
					{

						tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << endl;
					}

				}
				else
				{
					cout << "New username: ";
					cin >> newUsername;
					tmpFile << newUsername << "," << tokens[1] << "," << tokens[2] << "," << endl;
					userExist = true;
				}
			}
		}
		if (!userExist)
		{
			cout << "This user doesn't exist, nothing happened" << endl;
			myfile.close();
			remove("acc.txt");
			tmpFile.close();
			rename("accTmp.txt", "acc.txt");

		}
		else
		{
			myfile.close();

			if (remove("acc.txt") != 0) {
				cerr << "A wild error appeared: ";
			}
			else {
				cout << "Editing username 50% done!" << endl;
			}

			tmpFile.close();

			if (rename("accTmp.txt", "acc.txt") != 0)
			{
				cerr << "A wild error appeared : ";
			}
			else
			{
				cout << "Editing username done!!!!" << endl;
			}
		}
	}
}

void DATA_LAYER::manageAdminUsers() {
	ifstream myfile("acc.txt");
	ofstream tmpFile("accTmp.txt");
	string tokens[10], help, newUsername;
	int counter = 0;
	string line;
	bool userExist = false;

	cout << "Name of user: ";
	cin >> help;
	if (myfile.is_open())
	{
		string line;

		while (!myfile.eof())
		{
			getline(myfile, line);

			if (line != "") {

				tokenize(line, tokens, ',');

				if (help != tokens[0]) {

					if (tmpFile.is_open())
					{

						tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << endl;
					}
				}
				else
				{
					if (tokens[2] == "1")
					{

						counter = 2;
						tmpFile << tokens[0] << "," << tokens[1] << "," << "0" << "," << endl;

					}
					else
					{

						counter = 2;
						tmpFile << tokens[0] << "," << tokens[1] << "," << "1" << "," << endl;

					}
					userExist = true;
				}
			}
		}
		if (!userExist)
		{
			cout << "This user doesn't exist, nothing happened" << endl;
			myfile.close();
			remove("acc.txt");
			tmpFile.close();
			rename("accTmp.txt", "acc.txt");

		}
		else
		{
			myfile.close();

			if (remove("acc.txt") != 0) {
				cerr << "A wild error appeared: ";
			}
			else {
				cout << "Adding/Removing Admin 50% done!" << endl;
			}

			tmpFile.close();

			if (rename("accTmp.txt", "acc.txt") != 0)
			{
				cerr << "A wild error appeared : ";
			}
			else
			{
				cout << "Adding/Removing Admin done!!!!" << endl;
			}
		}
	}
}

void DATA_LAYER::manageBadges() {
	ifstream myfile("acc.txt");
	ofstream tmpFile("accTmp.txt");
	string tokens[10], help, newUsername, badgeName, badges[20];
	int counter = 0, checkCounter = 0, badgeChoice;
	string line;
	bool accManagmentMenu = true, userExist = false, badgeExist = false;

	cout << "1) Delete badge" << endl << "2) Add badge" << endl << "Choice: ";
	cin >> badgeChoice;
	cout << "Name of user: ";
	cin >> help;
	if (myfile.is_open())
	{
		string line;

		while (!myfile.eof())
		{
			getline(myfile, line);

			if (line != "") {

				tokenize(line, tokens, ',');

				if (help != tokens[0]) {

					if (tmpFile.is_open())
					{

						tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << "," << endl;
					}


				}
				else
				{
					counter = tokenize(tokens[3], badges, '^');
					if (tmpFile.is_open())
					{
						tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << ",";
					}
					if (badgeChoice == 1)
					{
						cout << "Name of the badge you want to delete: ";
						cin >> badgeName;
						for (int i = 0; i < counter; i++)
						{
							if (badges[i] == badgeName)
							{
								badgeExist = true;
							}
							else
							{
								tmpFile << badges[i] << "^";
							}
						}
						tmpFile << "," << endl;
					}
					else
					{
						cout << "Name of the badge you want to add: ";
						cin >> badgeName;
						if (tmpFile.is_open())
						{
							tmpFile << tokens[3] << badgeName << "^" << "," << endl;
						}
						/*for (int i = 0; i < badgeName.length()+1; i++)
						{
							if (badges[i] == badgeName)
							{
								badgeExist = true;
							}
							else
							{
								tmpFile << "^" << badges[i];
							}
						}*/
					}
					userExist = true;
				}
			}
		}
		if (!userExist || !userExist && !badgeChoice)
		{
			if (badgeChoice == 1) {
				cout << "This user doesn't exist, nothing happened" << endl;
				myfile.close();
				remove("acc.txt");
				tmpFile.close();
				rename("accTmp.txt", "acc.txt");
			}
			else
			{
				cout << "This user doesn't exist, nothing happened" << endl;
				myfile.close();
				remove("acc.txt");
				tmpFile.close();
				rename("accTmp.txt", "acc.txt");
			}
		}
		else
		{
			myfile.close();

			if (remove("acc.txt") != 0) {
				cerr << "A wild error appeared: ";
			}
			else {
				cout << "Adding/Removing badge 50% done!" << endl;
			}

			tmpFile.close();

			if (rename("accTmp.txt", "acc.txt") != 0)
			{
				cerr << "A wild error appeared : ";
			}
			else
			{
				cout << "Adding/Removing badge done!!!!" << endl;
			}
		}
	}
}

void DATA_LAYER::showAccounts() {
	ifstream myfile("acc.txt");
	ofstream tmpFile("accTmp.txt");
	string tokens[10], help,line;
	int counter = 0;
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, tokens[0], ',');

			help = tokens[0];

			if (help == "") {}
			else
			{
				if (help[0] == '\n')
				{
					help.erase(0, 1);
				}
				cout << "          Username: " << help;

				getline(myfile, tokens[1], ',');
				getline(myfile, tokens[2], ',');

				cout << " | Admin: ";

				if (tokens[2] == "1")
				{
					cout << "True" << endl;
				}
				else
				{
					cout << "False" << endl;
				}
			}
		}
	}
}

int DATA_LAYER::tokenize(string line, string* results, char delimiter) {
	string help;
	int counter = 0, count = 0;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == delimiter)
		{
			results[counter++] = help;
			help = "";
			i++;
		}
		help += line[i];
	}
	return counter;
}

void DATA_LAYER::managingAccountsFunction(int choice) {

	ifstream myfile("acc.txt");
	ofstream tmpFile("accTmp.txt");
	string tokens[10], help, newUsername, badgeName, badges[20];
	int counter = 0, checkCounter = 0, badgeChoice;
	string line;
	bool accManagmentMenu = true, userExist = false, badgeExist = false;
	switch (choice)
	{
		case 1:
			showAccounts();
			/*if (myfile.is_open())
			{
				while (myfile.good())
				{
					getline(myfile, tokens[0], ',');

					help = tokens[0];

					if (help == "") {}
					else
					{
						if (help[0] == '\n')
						{
							help.erase(0, 1);
						}
						cout << "          Username: " << help;

						getline(myfile, tokens[1], ',');
						getline(myfile, tokens[2], ',');

						cout << " | Admin: ";

						if (tokens[2] == "1")
						{
							cout << "True" << endl;
						}
						else
						{
							cout << "False" << endl;
						}
					}
				}
			}*/
			break;
		case 2:
			/*cout << "Name of user: ";
			cin >> help;

			if (myfile.is_open())
			{
				string line;
				while (!myfile.eof())
				{
					getline(myfile, line);

					if (line != "") {

						tokenize(line, tokens, ',');

						if (help != tokens[0]) {

							if (tmpFile.is_open())
							{
								counter = 2;
								tmpFile << tokens[counter] << "," << tokens[counter--] << "," << tokens[counter--] << "," << endl;
							}

						}
						else
						{
							userExist = true;
						}
					}
				}
				myfile.close();

				if (remove("acc.txt") != 0) {
					cerr << "A wild error appeared: ";
				}
				else {
					cout << "Deleting account 50% done" << endl;
				}

				tmpFile.close();

				if (rename("accTmp.txt", "acc.txt") != 0)
				{
					cerr << "A wild error appeared : ";
				}
				else
				{
					cout << "Deleting account done!!!!" << endl;
				}
			}*/
			deleteAccount();
			break;
		case 3:
			/*cout << "Name of user: ";
			cin >> help;

			if (myfile.is_open())
			{
				string line;

				while (!myfile.eof())
				{
					getline(myfile, line);

					if (line != "") {
						tokenize(line, tokens, ',');

						if (help != tokens[0]) {

							if (tmpFile.is_open())
							{

								tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << endl;
							}

						}
						else
						{
							cout << "New username: ";
							cin >> newUsername;
							tmpFile << newUsername << "," << tokens[1] << "," << tokens[2] << "," << endl;
							userExist = true;
						}
					}
				}
				if (!userExist)
				{
					cout << "This user doesn't exist, nothing happened" << endl;
					myfile.close();
					remove("acc.txt");
					tmpFile.close();
					rename("accTmp.txt", "acc.txt");

				}
				else
				{
					myfile.close();

					if (remove("acc.txt") != 0) {
						cerr << "A wild error appeared: ";
					}
					else {
						cout << "Editing username 50% done!" << endl;
					}

					tmpFile.close();

					if (rename("accTmp.txt", "acc.txt") != 0)
					{
						cerr << "A wild error appeared : ";
					}
					else
					{
						cout << "Editing username done!!!!" << endl;
					}
				}
			}*/
			editUsername();
			break;

		case 4:
			/*cout << "Name of user: ";
			cin >> help;
			if (myfile.is_open())
			{
				string line;

				while (!myfile.eof())
				{
					getline(myfile, line);

					if (line != "") {

						tokenize(line, tokens, ',');

						if (help != tokens[0]) {

							if (tmpFile.is_open())
							{

								tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << endl;
							}
						}
						else
						{
							if (tokens[2] == "1")
							{

								counter = 2;
								tmpFile << tokens[0] << "," << tokens[1] << "," << "0" << "," << endl;

							}
							else
							{

								counter = 2;
								tmpFile << tokens[0] << "," << tokens[1] << "," << "1" << "," << endl;

							}
							userExist = true;
						}
					}
				}
				if (!userExist)
				{
					cout << "This user doesn't exist, nothing happened" << endl;
					myfile.close();
					remove("acc.txt");
					tmpFile.close();
					rename("accTmp.txt", "acc.txt");

				}
				else
				{
					myfile.close();

					if (remove("acc.txt") != 0) {
						cerr << "A wild error appeared: ";
					}
					else {
						cout << "Adding/Removing Admin 50% done!" << endl;
					}

					tmpFile.close();

					if (rename("accTmp.txt", "acc.txt") != 0)
					{
						cerr << "A wild error appeared : ";
					}
					else
					{
						cout << "Adding/Removing Admin done!!!!" << endl;
					}
				}
			}*/
			manageAdminUsers();
			break;
		case 5:
			manageBadges();
			/*
			cout << "1) Delete badge" << endl << "2) Add badge" << endl << "Choice: ";
			cin >> badgeChoice;
			cout << "Name of user: ";
			cin >> help;
			if (myfile.is_open())
			{
				string line;

				while (!myfile.eof())
				{
					getline(myfile, line);

					if (line != "") {

						tokenize(line, tokens, ',');

						if (help != tokens[0]) {

							if (tmpFile.is_open())
							{

								tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << "," << tokens[3] << "," << endl;
							}


						}
						else
						{
							counter = tokenize(tokens[3], badges, '^');
							if (tmpFile.is_open())
							{
								tmpFile << tokens[0] << "," << tokens[1] << "," << tokens[2] << ",";
							}
							if (badgeChoice == 1)
							{
								cout << "Name of the badge you want to delete: ";
								cin >> badgeName;
								for (int i = 0; i < counter; i++)
								{
									if (badges[i] == badgeName)
									{
										badgeExist = true;
									}
									else
									{
										tmpFile << badges[i] << "^";
									}
								}
								tmpFile << "," << endl;
							}
							else
							{
								cout << "Name of the badge you want to add: ";
								cin >> badgeName;
								if (tmpFile.is_open())
								{
									tmpFile << tokens[3] << badgeName << "^" << "," << endl;
								}
								for (int i = 0; i < badgeName.length()+1; i++)
								{
									if (badges[i] == badgeName)
									{
										badgeExist = true;
									}
									else
									{
										tmpFile << "^" << badges[i];
									}
								}
							}
							userExist = true;
						}
					}
				}
				if (!userExist || !userExist && !badgeChoice)
				{
					if (badgeChoice == 1) {
						cout << "This user doesn't exist, nothing happened" << endl;
						myfile.close();
						remove("acc.txt");
						tmpFile.close();
						rename("accTmp.txt", "acc.txt");
					}
					else
					{
						cout << "This user doesn't exist, nothing happened" << endl;
						myfile.close();
						remove("acc.txt");
						tmpFile.close();
						rename("accTmp.txt", "acc.txt");
					}
				}
				else
				{
					myfile.close();

					if (remove("acc.txt") != 0) {
						cerr << "A wild error appeared: ";
					}
					else {
						cout << "Adding/Removing badge 50% done!" << endl;
					}

					tmpFile.close();

					if (rename("accTmp.txt", "acc.txt") != 0)
					{
						cerr << "A wild error appeared : ";
					}
					else
					{
						cout << "Adding/Removing badge done!!!!" << endl;
					}
				}
			}
			*/
			break;
		case 9:
			myfile.close();
			accManagmentMenu = false;

			break;

		default:
			break;
	}
	myfile.close();
}

string DATA_LAYER::checkAcc(string username, string password)
{
	ifstream myfile("acc.txt");
	string line[20];
	int counter = 0, checkCounter = 0;
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, line[0], ',');
			if (line[0] == username)
			{
				getline(myfile, line[1], ',');
				if (line[1] == password)
				{
					getline(myfile, line[2], ',');

					return line[2];
				}
				else
				{
					cout << "Invalid password or username!" << endl;
				}
			}
			else
			{
				getline(myfile, line[3]);
			}
		}
		myfile.close();
	}
	cout << "Please try to loign again!" << endl;
	return "invalidAccount";
}

