#ifndef COURSE_H
#define COURSE_H

#include <iostream>
using namespace std;

/*******************************************************
 * Purpose: Course class that works with the file data and manipulates
 * to get or set the values.
 *
 *******************************************************/

class Course
{
public:
	Course(string department, string title, string description,
		string prerequisites, string instructor, char grade, int course, int units);
	Course();

	// Getters
	string getDepart() const { return department; };
	string getTitle() const { return title; };
	string getDescription() const { return description; };
	string getPrereq() const { return prerequisites; };
	string getInstructor() const { return instructor; };
	string getGrade() const { return grade; };
	string getCourse() const { return course; };
	int getUnits() const { return units; };
	// Setters
	void setDepart(string _department) { department = _department; };
	void setTitle(string _title) { title = _title; };
	void setDescription(string _description) { description = _description; };
	void setPrereq(string _prerequisites) { prerequisites = _prerequisites; };
	void setInstructor(string _instructor) { instructor = _instructor; };
	void setGrade(string _grade) { grade = _grade; };
	void setCourse(string _course) { course = _course; };
	void setUnits(int _units) { units = _units; };
	// Overloading operators
	Course& operator=(const Course& p);
	bool operator!=(const Course& p) const;
	bool operator==(const Course& p) const;
	friend ostream& operator<<(ostream& os, const Course& course);

private:
	string department, title, description, prerequisites, instructor, course, grade;
	int units;

};

#endif // !COURSE_H

/*
* UNUSED CODE
friend istream& operator>>(istream& is, Course& person);
bool operator<(const Course& p) const;
bool operator>(const Course& p) const;
bool operator<=(const Course& p) const;
bool operator>=(const Course& p) const;
*/

