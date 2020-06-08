#pragma once

#include <iostream>
#include <vector>
#include <string>



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
	std::string category;
	std::string title;
	std::string author;
	std::string text;
	std::string tags[4];
};

