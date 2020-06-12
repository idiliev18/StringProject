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
	
	void login();
	void Register();
	void manageAccounts();
	void mainMenu();
	bool categoriesMenu();
	void profileMenu();
};

