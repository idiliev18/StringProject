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

};

void managingAccountsFunction(int choice);

int tokenize(string line, string* results, char delimiter);

string checkAcc(string username, string password);