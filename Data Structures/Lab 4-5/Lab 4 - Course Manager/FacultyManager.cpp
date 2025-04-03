#include "FacultyManager.h"
#include <fstream>
#include <sstream>

HashTable<Faculty> facultyTable(50); // Internal instance

FacultyManager::FacultyManager()
{

}

void FacultyManager::initialize()
{

	// read faculty_data.csv
	string FACULTY_DATA = "C:/Users/pable/Documents/Ohlone/Data Structures/Downloads/faculty_data.csv";
	ifstream inFile(FACULTY_DATA);
	if (inFile.fail())
	{
		cout << "Unable to open file " << FACULTY_DATA << endl;
		return;
	}
	string line;
	getline(inFile, line);
	while (getline(inFile, line))
	{
		istringstream ss(line);
		string value;
		Faculty faculty;
		getline(ss, value, ',');
		faculty.setInstructor(value);
		getline(ss, value, ',');
		faculty.setFirstName(value);
		getline(ss, value, ',');
		faculty.setLastName(value);
		getline(ss, value, ',');
		faculty.setDepartment(value);
		getline(ss, value, ',');
		faculty.setAddress(value);
		getline(ss, value, ',');
		faculty.setCity(value);
		getline(ss, value, ',');
		faculty.setState(value);
		getline(ss, value, ',');
		faculty.setZip(value);
		getline(ss, value, ',');
		faculty.setEmail(value);
		getline(ss, value, ',');
		faculty.setPhone(value);

		insert(faculty.getInstructor(), faculty);

	}
}

void FacultyManager::insert(string instructorId, const Faculty& x)
{
	HashTable<Faculty>::insert(instructorId,x);
}
void FacultyManager::printAll() {
	for (Iterator2<Faculty> it = facultyTable.begin(); !it.equals(facultyTable.end()); it.next()) {
		cout << it.get() << endl; // Assuming `Faculty` has a `<<` operator for printing
	}
}

