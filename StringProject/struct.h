#pragma once

#include <iostream>
#include <vector>
#include <string>

struct CATEGORY 
{
	int id = 0;
	std::string categoryName;
	std::string author;
	std::string dateOfCreation;
};

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

struct POST
{
	CATEGORY category;
	int id = 0;
	std::string title;
	std::string author;
	std::string text;
	std::string dateOfCreation;
	std::string tags[4];
};

