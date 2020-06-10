#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "struct.h"
#include "data.h"


class PRESENTATION_LAYER
{

private:



public:
	DATA_LAYER data;
	std::vector<POST> posts;
	std::vector<USER> users;
	void login();
	void Register();
	void manageAccounts();
	void mainMenu();
	bool categoriesMenu();
};

