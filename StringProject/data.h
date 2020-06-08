#pragma once
#include <iostream>
#include "struct.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void managingAccountsFunction(int choice);

int tokenize(string line, string* results, char delimiter);

string checkAcc(string username, string password);