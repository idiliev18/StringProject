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

	vector<USER> users;
	short categoryId;
	SESSION	sess;

	void managingAccountsFunction(int);
	int tokenize(string, string*, char);
	string checkAcc(string, string);
	void deleteAccount();
	void editUsername();
	void manageAdminUsers();
	void showAccounts();
	void manageBadges();
};

