#ifndef FACULTY_MANAGER_H
#define FACULTY_MANAGER_H

#include <iostream>
#include "HashTable.h"
#include "Faculty.h"

using namespace std;

class FacultyManager : public HashTable<Faculty>
{
public:
	FacultyManager();
	void initialize();
	void insert(string instructorId, const Faculty& x);
	//void erase(string instructorId, const Faculty& x);
	void printAll();
private:
	Iterator2<Faculty> iterator;
	//HashTable<Faculty> facultyTable;

};

#endif // !FACULTY_MANAGER_H


