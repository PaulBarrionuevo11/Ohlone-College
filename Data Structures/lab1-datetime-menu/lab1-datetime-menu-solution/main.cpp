#include <iostream>
#include "dateTime.h"
#include "time.h"
#include "menu.h"
#include "menuOption.h"

using namespace std;

int main() {
	Menu menu("User Menu");
	MenuOption o1('a', "Show Date", "Show dd/mm/yyyy");
	menu.addOption(o1);
	MenuOption o2('b', "Show Time", "Show hh:mm:ss");
	menu.addOption(o2);
	MenuOption o3('c', "Show DateTime", "Show dd/mm/yyyy hh:mm:ss");
	menu.addOption(o3);
	MenuOption o4('d', "Show Time Now", "Show Current DateTime dd/mm/yyyy hh:mm:ss");
	menu.addOption(o4);
	MenuOption o5('x', "Exit", "Exit the program");
	menu.addOption(o5);

	DateTime dt(9,17,2024,18,30,0);
	int y = -1;
	do {
		y = menu.getInput();
		if (y == 'a') {
			cout << dt.getDate().toString() << endl;
		}
		else if (y == 'b') {
			cout << dt.getTime().toString() << endl;
		}
		else if (y == 'c') {
			cout << dt.toString() << endl;
		}
		else if (y == 'd') {
			cout << dt.now().toString() << endl;
		}
		else if (y == 'x') {
			cout << "Bye!" << endl;
		}
		else {
			cout << "Invalid command" << endl;
		}

	} while (y != 'x' /** exit */);

	return 0;
}