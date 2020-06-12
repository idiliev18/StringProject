#pragma once

#include <iostream>
#include <vector>
#include <string>


struct SESSION
{
	bool logged;
	std::string name;
	int currCategory;
};

struct USER
{
	int id = 0;
	std::string username;
	std::string password;
	bool isAdmin = false;
	std::string badges[20];
};

struct CATEGORY_ITEM {
	int id = 0;
	string name;
};

struct POST_ITEM {
	int id = 0;
	string title;
	string author;
	string text;
	string dateOfCreation;
	int categoryId = 0;
	string tags[5];
};

