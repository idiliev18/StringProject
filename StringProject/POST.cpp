#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include "struct.h"
#include "CATEGORY.h"
#include "POST.h"
using namespace std;


POST::POST()
{
	cat.loadCategoryData();
}

string POST::getTodaysDate()
{
	time_t t = time(NULL);
	tm tPtr{ 0 };
	errno_t err = localtime_s(&tPtr, &t);

	int day, month, year;
	string dayS, monthS, yearS, date;

	day = (tPtr.tm_mday);
	month = (tPtr.tm_mon) + 1;
	year = (tPtr.tm_year) + 1900;

	dayS = to_string(day);
	monthS = to_string(month);
	/*if (monthS.length() > 1)
		monthS = "0" + monthS;*/

	yearS = to_string(year);

	return yearS + '-' + monthS + '-' + dayS;
}

void POST::plusPlusId(int id)
{
	ofstream myfile("lastPostId.txt");
	if (myfile.is_open())
	{

		myfile << id++;

	}
}

int POST::getPostIdByTitle(string title)
{
	for (size_t i = 0; i < posts.size(); i++)
	{
		if (posts[i].title == title)
		{
			return posts[i].id;
		}
	}
}

int POST::getIndexById(int id)
{
	for (size_t i = 0; i < posts.size(); i++)
	{
		if (posts[i].id == id)
		{
			return i;
		}
	}
	return -1;
}

int POST::getLastPostId()
{
	string line;
	ifstream myfile;
	myfile.open("lastPostId.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line))
		{
			return atoi(line.c_str()) + 1;
		}
		myfile.close();
	}
	return -1;
}

void POST::loadPostData()
{
	fstream data;
	data.open("Posts.txt");
	string tokens[10];
	string tokens2[10];

	if (data.is_open())
	{
		while (!data.eof())
		{
			POST_ITEM post;

			for (int i = 0; i < 6; i++)
			{
				getline(data, tokens[i], '|');
			}

			post.id = atoi(tokens[0].c_str());
			post.title = tokens[1];
			post.author = tokens[2];
			post.text = tokens[3];
			post.dateOfCreation = tokens[4];
			post.categoryId = atoi(tokens[5].c_str());

			int arrIndex = 0;
			for (int i = 0; i < 5; i++)
			{
				getline(data, tokens2[i], '~');
				if (tokens2[i] != "") {
					post.tags[arrIndex++] = tokens2[i];
				}
				else {
					post.tags[arrIndex++] = "NO_TAG";
				}
			}

			posts.push_back(post);

		}
		posts.erase(posts.end() - 1);
	}

}

void POST::createPost(string catName, string title, string text, string* tags, short a)
{
	POST_ITEM post;
	int categoryId = cat.getCatIdByName(catName);

	post.id = getLastPostId();
	post.title = title;
	//post.author = author;
	post.author = "Azis";
	post.text = text;
	post.dateOfCreation = getTodaysDate();
	post.categoryId = categoryId;

	for (int i = 0; i < 5; i++)
	{
		for (short i = 0; i < a; i++)
		{
			post.tags[i] = tags[i];
			if (tags[i] == "")
			{
				post.tags[i] = "NO_TAG";
			}
		}
	}



	posts.push_back(post);
	int index = getIndexById(post.id);
	savePostData(index);
	plusPlusId(post.id);
}

void POST::savePostData(int index)
{

	ofstream myfile("Posts.txt", ios::app);
	if (myfile.is_open())
	{

		myfile << posts[index].id << "|" << posts[index].title << "|" << posts[index].author << "|" << posts[index].text << "|" << posts[index].dateOfCreation << "|" << posts[index].categoryId << "|";
		for (size_t i = 0; i < 5; i++)
		{
			myfile << posts[index].tags[i] << "~";
		}
		myfile << endl;


	}
}

void POST::deleteCategory(string title)
{
	int id = getPostIdByTitle(title);
	int index = getIndexById(id);
	posts.erase(posts.begin() + index);
	saveDeleted();
}

void POST::saveDeleted()
{
	ofstream myfile("Posts.txt");
	if (myfile.is_open())
	{
		for (size_t i = 0; i < posts.size(); i++)
		{
			myfile << posts[i].id << "|" << posts[i].title << "|" << posts[i].author << "|" << posts[i].text << "|" << posts[i].dateOfCreation << "|" << posts[i].categoryId << "|";
			for (size_t k = 0; k < 5; k++)
			{
				myfile << posts[i].tags[k] << "~";
			}
			myfile << endl;
		}
	}
}

vector<POST_ITEM> POST::filterByCategory(string catName)
{
	int id = cat.getCatIdByName(catName);

	vector<POST_ITEM> result;

	for (size_t i = 0; i < posts.size(); i++)
	{
		if (posts[i].categoryId == id)
		{
			result.push_back(posts[i]);
		}
	}
	return result;
}

