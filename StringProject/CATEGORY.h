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


	int getLastCatId()
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

	void loadCategoryData()
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

	int getCatIdByName(string catName)
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

	void createCategory(string catName) {
		CATEGORY_ITEM category;

		category.id = getLastCatId();
		category.name = catName;

		categories.push_back(category);

		int index = getIndexById(category.id);
		saveCatData(index);
		plusPlusId(category.id);
	}

	void saveCatData(int index)
	{
		ofstream myfile("Categories.txt", ios::app);
		if (myfile.is_open())
		{

			myfile << categories[index].id << "|" << categories[index].name << "|" << endl;

		}
	}

	void deleteCategory(string catName)
	{
		int id = getCatIdByName(catName);
		int index = getIndexById(id);
		categories.erase(categories.begin() + index);
		saveDeleted();
	}

	void saveDeleted()
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


};