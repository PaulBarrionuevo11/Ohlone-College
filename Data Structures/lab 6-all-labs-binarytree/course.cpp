#include "course.h"

/*******************************************************
 * Purpose: Constructor of class type Course
 *
 * @params characteristics of a course
 * @return Instance of course with new characteristics
 *******************************************************/
Course::Course(string _department, string _title, string _description,
	string _prerequisites, string _instructor, char _grade, int _course, int _units)
{
	department = _department, title = _title, description = _description, prerequisites = _prerequisites,
		instructor = _instructor, grade = _grade, course = _course, units = _units;
}
/*******************************************************
 * Purpose: Constructor of class type Course
 *
 * @params none
 * @return empty
 *******************************************************/
Course::Course()
{
}
/*******************************************************
 * Purpose: Overloading operator that sets two classes
 * of type Course equal after checking that the argument passed
 * is not the current class that is trying to compare
 *
 * @params An instance reference of Course
 * @return Current Course class
 *******************************************************/
Course& Course::operator=(const Course& p)
{
	if (this != &p)
	{
		department = p.department;
		title = p.title;
		description = p.description;
		prerequisites = p.prerequisites;
		instructor = p.instructor;
		grade = p.grade;
		course = p.course;
		units = p.units;
	}
	return *this;
}
/*******************************************************
 * Purpose: Overloading operator check that two courses are not
 * equal to each other by comparing the title
 *
 * @params An instance reference of Course
 * @return true or false based on the comparison
 *******************************************************/
bool Course::operator!=(const Course& p) const
{
	return this->title != p.title;
}
/*******************************************************
 * Purpose: Overloading operator check that two courses are
 * equal to each other by comparing the title
 *
 * @params An instance reference of Course
 * @return true or false based on the comparison
 *******************************************************/
bool Course::operator==(const Course& p) const
{
	return this->title == p.title;
}
/*******************************************************
 * Purpose: Overloading operator that outputs
 * the Course type that is passed down
 *
 * @params An outstream declaration and an instance reference of Course
 * @return true or false based on the comparison
 *******************************************************/
ostream& operator<<(ostream& out, const Course& course)
{
	out << course.getDepart() << " " << course.getCourse() << endl;
	out << course.getTitle() << endl;
	out << course.getDescription() << endl;
	out << course.getPrereq() << endl;
	out << course.getUnits() << endl;
	out << course.getInstructor() << endl;
	out << course.getGrade() << endl;
	return out;
}