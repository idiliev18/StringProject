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

	MENU()
	{
		data.loadPostData();
		cat.loadCategoryData();
	}

	void addPostMenu()
	{
		string catName, title, text;
		string tags[5];
		short a;

		cout << "Enter category name: ";
		getline(cin, catName);

		cout << "Title: ";
		getline(cin, title);

		cout << "Text: ";
		getline(cin, text);

		cout << "How many tags you want to add: ";
		cin >> a;
		for (short i = 0; i < a; i++)
		{
			cout << i << ") ";
			cin >> tags[i];
		}

		data.createPost(catName, title, text, tags, a);
	}
	void addCategoryMenu()
	{
		string catName;
		cout << "Enter category name: ";
		getline(cin, catName);
		cat.createCategory(catName);

	}
	void deleteCatMenu()
	{
		string catName;
		cout << "Enter cat name: ";
		getline(cin, catName);
		cat.deleteCategory(catName);
	}
	void deletePostMenu()
	{
		string title;
		cout << "Enter post title: ";
		getline(cin, title);
		data.deleteCategory(title);
	}
	void showPostFromCategoryMenu()
	{
		string catName;
		cout << "Enter Category: ";
		getline(cin, catName);
		vector<POST_ITEM> filter = data.filterByCategory(catName);


		for (size_t i = 0; i < filter.size(); i++)
		{
			cout << "ID: " << filter[i].id << " " << "Title: " << filter[i].title << " " << "Author: " << filter[i].author << " " << "Text: " << filter[i].text << " " << "Date: " << filter[i].dateOfCreation << filter[i].categoryId << endl;
		}
	}
};