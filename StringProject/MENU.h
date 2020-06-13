#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include "struct.h"
#include "CATEGORY.h"
#include "POST.h"
#include "data.h"
using namespace std;

class MENU {
public:
	POST data;
	CATEGORY cat;
	DATA_LAYER mamo;

	MENU();

	void getlenghtAndPrint(int, string, int);
	void welcomeMenu();
	void addPostMenu();
	void addCategoryMenu();
	void deleteCatMenu();
	void deletePostMenu();
	void showPostFromCategoryMenu();
	void showAllPosts();
	void login();
	void Register();
	void manageAccounts();
	void mainMenu();
	bool categoriesMenu();
	void profileMenu();

};