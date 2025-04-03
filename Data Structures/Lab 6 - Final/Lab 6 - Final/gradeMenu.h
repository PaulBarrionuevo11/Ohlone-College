#ifndef GRADE_MENU_H
#define GRADE_MENU_H

#include <iostream>
#include "assignment.h"
#include "gradeManager.h"
#include "menu.h"
#include <fstream>
#include <sstream>

using namespace std;

class GradeMenu : public Menu
{
	string ASSIGNMENT_DATA = "C:/Users/pable/Documents/Github/Ohlone/Data Structures/Downloads/assignment_data.csv";
	string GRADE_BOOK = "C:/Users/pable/Documents/Github/Ohlone/Data Structures/Downloads/grade_scale.csv";

	enum COURSE_OPTIONS
	{
		LIST_OF_GRADES = '1',
		VIEW_GRADES = '2',
		ADD_GRADES = '3',
		EDIT_GRADES = '4',
		DELETE_GRADES = '5',
		EXIT_MENU = '6'
	};

public:
	GradeMenu();
	~GradeMenu();

	void initialize();
	void activate();
	void doSave(); // -save data to.csv file

	void doList(); // -display all data from the root of the tree.
	void doView(); // -view individual assignment and view group of assignments in rows and columns
	void doAdd(); // -add to tree.
	void doEdit(); // -edit any fields
	void doRemove(); // -remove a node from the tree
	void calculateGrade(); // -Implement your grade and display.


protected:
	GradeManager courseGrades;

};
#endif // !GRADE_MENU_H
