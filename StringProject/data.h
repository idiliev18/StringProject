#pragma once
#include <iostream>
#include "struct.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class DATA_LAYER
{

private:


public:
	vector<POST> posts;
	vector<USER> users;

	void inputElementsIntoVector();
	string getTodaysDate();
	void managingAccountsFunction(int);
	int tokenize(string, string*, char);
	string checkAcc(string, string);

};

