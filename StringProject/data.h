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
	vector<CATEGORY> categories;
	short categoryId;
	SESSION	sess;

	string getCategoryId();
	void createCategory(string, string, string);
	void inputElementsIntoVector();
	string getTodaysDate();
	void managingAccountsFunction(int);
	int tokenize(string, string*, char);
	string checkAcc(string, string);
	void saveIncrementetCategoryIdValue();
	void getPostInfo();
	void post(POST, string);
};

