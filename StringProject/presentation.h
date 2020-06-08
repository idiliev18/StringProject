#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "struct.h"


class PRESENTATION_LAYER
{

private:



public:
	std::vector<POST> posts;
	std::vector<USER> users;

};

void login();

void Register();

void manageAccounts();