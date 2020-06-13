#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include "struct.h"
#include "CATEGORY.h"
using namespace std;

void CATEGORY::plusPlusId(int id)
{
	ofstream myfile("lastCatId.txt");
	if (myfile.is_open())
	{

		myfile << id++;

	}
}

int CATEGORY::getIndexById(int id)
{
	for (size_t i = 0; i < categories.size(); i++)
	{
		if (categories[i].id == id)
		{
			return (int)i;
		}
	}
	return -1;
}

int CATEGORY::getLastCatId()
{
	string line;
	ifstream myfile;
	myfile.open("lastCatId.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line))
		{
			return atoi(line.c_str()) + 1;
		}
		myfile.close();
	}
	return -1;
}

void CATEGORY::loadCategoryData()
{
	fstream data;
	data.open("Categories.txt");
	string tokens[10];

	if (data.is_open())
	{
		while (!data.eof())
		{
			CATEGORY_ITEM category;

			for (int i = 0; i < 2; i++)
			{
				getline(data, tokens[i], '|');
			}

			category.id = atoi(tokens[0].c_str());
			category.name = tokens[1];

			categories.push_back(category);


		}
		categories.erase(categories.end() - 1);
	}

}

int CATEGORY::getCatIdByName(string catName)
{
	for (size_t i = 0; i < categories.size(); i++)
	{
		if (categories[i].name == catName)
		{
			return categories[i].id;
		}
	}
	return -1;
}

void CATEGORY::createCategory(string catName) {
	CATEGORY_ITEM category;

	category.id = getLastCatId();
	category.name = catName;

	categories.push_back(category);

	int index = getIndexById(category.id);
	saveCatData(index);
	plusPlusId(category.id);
}

void CATEGORY::saveCatData(int index)
{
	ofstream myfile("Categories.txt", ios::app);
	if (myfile.is_open())
	{

		myfile << categories[index].id << "|" << categories[index].name << "|" << endl;

	}
}

void CATEGORY::deleteCategory(string catName)
{
	int id = getCatIdByName(catName);
	int index = getIndexById(id);
	categories.erase(categories.begin() + index);
	saveDeleted();
}

void CATEGORY::saveDeleted()
{
	ofstream myfile("Categories.txt");
	if (myfile.is_open())
	{
		for (size_t i = 0; i < categories.size(); i++)
		{
			myfile << categories[i].id << "|" << categories[i].name << "|" << endl;
		}
	}
}

string CATEGORY::getCatNameById(int id)
{
	for (size_t i = 0; i < categories.size(); i++)
	{
		if (categories[i].id == id)
		{
			return categories[i].name;
		}
	}
	return "Wild Error";
}

vector<CATEGORY_ITEM> CATEGORY::returnAll()
{
	vector<CATEGORY_ITEM> result;
	for (size_t i = 0; i < categories.size(); i++)
	{
		result.push_back(categories[i]);
	}
	return result;
}