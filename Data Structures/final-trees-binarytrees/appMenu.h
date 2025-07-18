#ifndef APP_MENU_H
#define APP_MENU_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "menu.h"
#include "appManager.h"

using namespace std;


class AppMenu : public Menu
{
	enum {
		SHOW_INORDER = '1',
		SEARCH = '2',
		EXIT = 'X'
	};
	string CONTCTS_DATA = "C:/Users/pable/Documents/Github/Ohlone/Data Structures/Downloads/50-contacts.csv";

public:
	AppMenu();
	~AppMenu();

	void initialize();
	void activate();

	void showInOrder();
	void showSearch();

	AppManager appManager;
	

private:

};
#endif // !GRADE_MENU_H
