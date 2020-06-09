#include "presentation.h"
#include <iostream>
#include "struct.h"
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include "data.h"
using namespace std;

string DATA_LAYER::getTodaysDate()
{
	time_t t = time(NULL);
	tm tPtr{ 0 };
	errno_t err = localtime_s(&tPtr, &t);

	int day, month, year;
	string dayS, monthS, yearS, date;

	day = (tPtr.tm_mday);
	month = (tPtr.tm_mon) + 1;
	year = (tPtr.tm_year) + 1900;

	dayS = to_string(day);
	monthS = to_string(month);
	/*if (monthS.length() > 1)
		monthS = "0" + monthS;*/

	yearS = to_string(year);

	return yearS + '-' + monthS + '-' + dayS;
}

void DATA_LAYER::inputElementsIntoVector()
{
	fstream data;
	data.open("Text.txt"); // File Name
	string tokens1[10];
	string categoryTokens[5];
	string tokens2[10];

	if (data.is_open())
	{
		while (!data.eof())
		{
			POST post;

			for (int i = 0; i < 4; i++)
			{
				getline(data, categoryTokens[i], '~');
			}
			post.category.id = atoi(categoryTokens[0].c_str());
			post.category.categoryName = categoryTokens[1];
			post.category.author = categoryTokens[2];
			post.category.dateOfCreation = categoryTokens[3];

			for (int i = 0; i < 5; i++)
			{
				getline(data, tokens1[i], '|');
			}

			

			post.id = atoi(tokens1[0].c_str());
			post.title = tokens1[1];
			post.author = tokens1[2];
			post.text = tokens1[3];
			post.dateOfCreation = tokens1[4];

			
			int arrIndex = 0;
			for (int i = 0; i < 4; i++)
			{
				getline(data, tokens2[i], '}');

				if (tokens2[i] != "") {
					post.tags[arrIndex++] = tokens2[i];
				}
				else {
					post.tags[arrIndex++] = "NO_TAG";
				}
			}

			posts.push_back(post);

			//ws(data);

		}
	}


}

int tokenize(string line, string* results, char delimiter) {
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

void managingAccountsFunction(int choice) {

	ifstream myfile("acc.txt");
	ofstream tmpFile("accTmp.txt");
	string tokens[10], help, newUsername;
	int counter = 0, checkCounter = 0;
	string line;
	bool accManagmentMenu = true, userExist = false;
	switch (choice)
	{
	case 1:
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
		break;
	case 2:
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
		break;
	case 3:
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
		break;

	case 4:
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

string checkAcc(string username, string password)
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


