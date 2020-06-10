#include "presentation.h"
#include <iostream>
#include "struct.h"
#include <fstream>
#include <vector>
#include <string>
#include "data.h"
using namespace std;









int main()
{
	DATA_LAYER ds;
	ds.createCategory("pesho","haka","da");
}

// FOR DEBUGIN LOGIN/REGISTER
//int choice;
	//cout << "1. LOGIN" << endl << "2. REGISTER" << endl << "3. ADMIN" << endl<<"choice: ";
	//cin >> choice;
	//switch (choice)
	//{
	//case 1:
	//	login();
	//	break;
	//case 2:
	//	Register();
	//	break;
	//case 3:
	//	manageAccounts();
	//	break;
	//default:
	//	return 0;
	//	break;
	//}