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
	int getCatIdByName(string);
	void createCategory(string);
	void saveCatData(int);
	void deleteCategory(string);
	void saveDeleted();

};