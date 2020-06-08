#include "presentation.h"
#include <iostream>
#include "struct.h"
#include <fstream>
#include <vector>
#include <string>
#include "data.h"
using namespace std;

class DATA_LAYER
{

private:


public:
	vector<POST> posts;
	vector<USER> users;


	void inputElementsIntoVector()
	{
		fstream data;
		data.open("Text.txt"); // File Name
		string tokens1[10];

		if (data.is_open())
		{
			while (!data.eof())
			{
				for (int i = 0; i < 4; i++)
				{
					getline(data, tokens1[i], ',');
				}

				POST post;

				post.category = tokens1[0];
				post.title = tokens1[1];
				post.author = tokens1[2];
				post.text = tokens1[3];

				string tokens2[10];
				int arrIndex = 0;
				for (int i = 0; i < 4; i++)
				{
					getline(data, tokens2[i], '|');

					if (tokens2[i] != "") {
						post.tags[arrIndex++] = tokens2[i];
					}
					else {
						post.tags[arrIndex++] = "NO_TAG";
					}
				}

				posts.push_back(post);

				ws(data);

			}
		}


	}




};

class PRESENTATION_LAYER
{
	
private:



public:
	vector<POST> posts;
	vector<USER> users;

};



int main()
{


}
