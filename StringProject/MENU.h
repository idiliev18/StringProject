#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include "struct.h"
#include "CATEGORY.h"
#include "POST.h"
using namespace std;

class MENU {
public:
	POST data;
	CATEGORY cat;

	MENU();

	void addPostMenu();
	void addCategoryMenu();
	void deleteCatMenu();
	void deletePostMenu();
	void showPostFromCategoryMenu();

};