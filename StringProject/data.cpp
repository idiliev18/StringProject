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

void DATA_LAYER::saveIncrementetCategoryIdValue()
{
	ofstream myfile;
	myfile.open("categoryId.txt");
	myfile << categoryId-1;
	myfile.close();
}

string DATA_LAYER::getCategoryId()
{
	string line;
	ifstream myfile;
	myfile.open("categoryId.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line))
		{
			return line;
		}
		myfile.close();
	}
	return "-1";
}

void DATA_LAYER::createCategory(string categoryName, string author, string dateOfCreation)
{
	categoryId = atoi(getCategoryId().c_str()) + 1;
	CATEGORY category;
	string fileName = to_string(categoryId) + ".txt";

	category.id = categoryId;
	category.categoryName = categoryName;
	category.author = author;
	category.dateOfCreation = dateOfCreation;
	
	categories.push_back(category);

	fstream file;
 
	file.open(fileName, ios::out);

	if (!file)
	{
		cerr << "Error in creating file!!!";
		
	}
	cout << "Complete";


	file.close();
	categoryId++;
	saveIncrementetCategoryIdValue();
}

void DATA_LAYER::showCategories() {
	int id = atoi(getCategoryId().c_str()) ;
	string file,line,tokens[10];
	for (int i = 1; i <= id; i++)
	{
		file = to_string(i)+".txt";
		ifstream myfile(file);
		if (myfile.is_open())
		{
			getline(myfile, line);
			tokenize(line, tokens, '|');
			cout << i << ". " << tokens[0]<<endl;
		}
	}
	browsingCategory();
}

void DATA_LAYER::browsingCategory() {
	sess.currCategory = 1;
	string file = to_string(sess.currCategory)+".txt",line;
	ifstream myfile(file);
	if (myfile.is_open())
	{
		string line, tokens[10];
		getline(myfile, line);
		while (!myfile.eof())
		{
			getline(myfile, line);

			if (line != "") {
				getline(myfile, line);
				tokenize(line, tokens, '|');
				cout << "Title: " << tokens[0] << endl
					<< "Text: " << tokens[1] << endl
					<< "Date: " << tokens[2] << endl<<endl;
			}
		}
	}
}

void DATA_LAYER::enterCategory() {
	string choice;
	showCategories();
	cout << "Type the number of the category you want view: ";
	cin >> choice;
	sess.currCategory = atoi(choice.c_str());

}

void DATA_LAYER::post(POST post,string cat) {
	ofstream myfile(cat,ios::app);
	string line;
	if (myfile.is_open())
	{
		myfile << "1|" << post.title << "|" << post.author << "|"
		<< post.text << "|" << post.dateOfCreation << "|";
		for (int i = 0; i < 3; i++)
		{
			myfile << post.tags[i] << "^";
		}
		myfile <<"|"<< endl;
	}
}

void DATA_LAYER::getPostInfo() {
	string cat = "1.txt";
	DATA_LAYER::sess.logged;
	if (true)
	{
		int count=0,choice;
		POST post;
		string tags;
		cout<<"Title: ";
		cin.ignore();
		getline(cin, post.title);
		//post.author = sess.name;
		post.author = "test";
		cout << "Text: ";
		getline(cin, post.text);
		post.dateOfCreation = getTodaysDate();
		cout << "Tags: ";
		getline(cin, tags);
		count = tokenize(tags, post.tags, ' ');
		cout << "Are you sure you want to post this."<<endl;
		cout << "Title: " << post.title << endl;
		cout << "text: " << post.text << endl<<"Tags: ";
		for (int i = 0; i < count; i++)
		{
			cout << post.tags[i] << " ";
		}
		cout << endl << "1. Post" << endl << "2. Cancel"<<endl<<"Choice: ";
		cin >> choice;
		if (choice==1)
		{
			DATA_LAYER::post(post,cat);
		}
	}
	/*else
	{
		cout << "You must be logged to post"<<endl;
		PRESENTATION_LAYER::login;
	}*/
	
}
