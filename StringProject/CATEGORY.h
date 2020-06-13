#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include "struct.h"
using namespace std;

class CATEGORY {
public:
	vector<CATEGORY_ITEM> categories;

	void plusPlusId(int);

	int getIndexById(int);


	int getLastCatId();


	void loadCategoryData();


	int getCatIdByName(string catName);


	void createCategory(string catName);


	void saveCatData(int index);


	void deleteCategory(string catName);


	void saveDeleted();

	string getCatNameById(int id);

	vector<CATEGORY_ITEM> returnAll();



};