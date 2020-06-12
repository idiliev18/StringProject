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
			return i;
		}
	}
	return -1;
}