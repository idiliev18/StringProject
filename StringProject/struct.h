#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct USER
{
	int id = 0;
	string username;
	string password;
	bool isAdmin = false;
	string badges[20];
};

struct POST
{
	string category;
	string title;
	string author;
	string text;
	string tags[4];
};

