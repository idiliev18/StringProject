#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include "struct.h"
#include "CATEGORY.h"
using namespace std;

class POST {
public:
	CATEGORY cat;
	vector<POST_ITEM> posts;


	POST()
	{
		cat.loadCategoryData();
	}

	string getTodaysDate();

	void plusPlusId(int);
	int getPostIdByTitle(string);
	int getIndexById(int);
	int getLastPostId();
	void loadPostData();
	void createPost(string, string, string, string*, short);
	void savePostData(int index);
	void deleteCategory(string title);
	void saveDeleted();
	vector<POST_ITEM> filterByCategory(string catName);

};
