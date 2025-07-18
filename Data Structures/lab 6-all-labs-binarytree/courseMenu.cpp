#include "courseMenu.h"
#include "menuOption.h"
#include "dataException.h"
#include <sstream>

/*******************************************************
 * Purpose: Constructor of Course Menu. Base class menu is
 * initialize with menu title "Course Manager". Menu Options are
 * passed and added to Menu class.
 *
 *******************************************************/
CourseMenu::CourseMenu() : Menu("Course Manager")
{
	MenuOption op1('1', "List of course", "Default");
	MenuOption op2('2', "View of course", "Default");
	MenuOption op3('3', "Add new course", "Default");
	MenuOption op4('4', "Edit course", "Default");
	MenuOption op5('5', "Delete course", "Default");
	MenuOption op6('X', "Exit", "Default");

	addOption(op1);
	addOption(op2);
	addOption(op3);
	addOption(op4);
	addOption(op5);
	addOption(op6);

	// initialize data
	initData();

}
CourseMenu::~CourseMenu()
{
	saveData();
}
/*******************************************************
 * Purpose: Save data file
 *
 *******************************************************/
void CourseMenu::saveData()
{
	// Open file to write the data
	ofstream outFile(COURSE_DATA);
	if (outFile.fail())
	{
		cout << "Unable to open file " << COURSE_DATA << " for saving." << endl;
		return;
	}

	Node<Course>* current = courseList.getFirst();
	while (current != nullptr)
	{
		Course& course = current->data;

		// Write course data in the format used in initData
		outFile << course.getDepart() << ' ' << course.getCourse() << '\n';
		outFile << course.getTitle() << '\n';

		// For multiline descriptions, add a backslash at the end if needed
		string description = course.getDescription();
		istringstream descStream(description);
		string line;
		while (getline(descStream, line))
		{
			if (descStream.peek() == EOF)  // Last line, no backslash
				outFile << line << '\n';
			else
				outFile << line << "\\" << '\n';  // Append backslash
		}

		outFile << course.getPrereq() << '\n';
		outFile << course.getUnits() << '\n';
		outFile << course.getInstructor() << '\n';
		outFile << course.getGrade() << '\n';

		current = current->next;
	}

	outFile.close();
	cout << "Data saved successfully to " << COURSE_DATA << endl;
}
/*******************************************************
* Purpose: initializes the data by opening and reading the file
* and parsing the values into Course class
* Parameter: none
* Return: saves data to vector of Course type and closes the file
 *******************************************************/
void CourseMenu::initData()
{
	ifstream inFile(COURSE_DATA);
	if (inFile.fail())
	{
		cout << "Unable to open file " << COURSE_DATA << endl;
		return;
	}
	string line, description;
	while (getline(inFile, line))
	{
		istringstream ss(line);
		string value;

		Course newCourse;
		description.clear();  // Reset description for the new course

		getline(ss, value, ' ');
		newCourse.setDepart(value);
		getline(ss, value, ' ');
		newCourse.setCourse(value);
		getline(inFile, line);
		newCourse.setTitle(line);
		// Go over description and do it until line ends with a space
		while (getline(inFile, line)) {
			if (line.back() == '\\') {
				// Remove the trailing backslash and add the line to the description
				line.pop_back();
				description += line + "\n";  // Concatenate lines with space
			}
			else {
				// Add the last line (no backslash) and break the loop
				description += line;
				break;
			}
		}
		newCourse.setDescription(description);
		getline(inFile, line);
		newCourse.setPrereq(line);
		getline(inFile, line);
		newCourse.setUnits(stoi(line));
		getline(inFile, line);
		newCourse.setInstructor(line);
		getline(inFile, value);
		newCourse.setGrade(value);

		courseList.insert(newCourse);
	}
	inFile.close();

}
/*******************************************************
* Purpose: Activates the main menu
*
 *******************************************************/
void CourseMenu::activate()
{
	char choice = 0;
	do {
		choice = getInput();
		switch (choice) {
		case LIST_OF_COURSE:
			doList();
			break;
		case VIEW_COURSE:
			doView();
			break;
		case ADD_COURSE:
			doAdd();
			break;
		case EDIT_COURSE:
			doEdit();
			break;
		case DELETE_COURSE:
			doDelete();
			break;
		case EXIT_MENU:
			doExit();
			cout << "Bye bye!" << endl;
			break;
		default:
			cout << "Invalid option" << endl;
		}
	} while (choice != 'X');
}
void CourseMenu::moveFirst() {
	iter = courseList.begin(); // Move to the first course
	cout << "Navigated to the first course:\n";
	cout << *iter << endl; // Display current course
}
void CourseMenu::moveNext() {
	++iter; // Move to the next course
	if (iter.equals(courseList.end())) {
		cout << "Reached the end of the list.\n";
		--iter; // Move back to last valid position
	}
	/* else {
		cout << "Navigated to the next course:\n";
		cout << *iter << endl; // Display current course
	}*/
}
void CourseMenu::movePrevious() {
	--iter; // Move to the previous course
	if (iter.equals(courseList.begin())) {
		cout << "Reached the beginning of the list.\n";
		++iter; // Move forward to first valid position
	}
	else {
		cout << "Navigated to the previous course:\n";
		cout << *iter << endl; // Display current course
	}
}
void CourseMenu::moveLast() {
	iter = courseList.end(); // Move to the end of the list
	--iter; // Move to the last course
	cout << "Navigated to the last course:\n";
	cout << *iter << endl; // Display current course
}
/*******************************************************
 * Purpose: Shows average grade based on total grades from the
 * courses. Iterates over the list of Linked list until pointer is
 * null to cover all the elements. Also implements the sorting by
 * ascending 'a' or descending 'd' of each attribute on the Course class
 *
 *******************************************************/
void CourseMenu::doList()
{
	int fieldValue;
	/* Show average */
	int gradeValue = 0;
	int sumValues = 0;
	double avergeValue;
	// Assigns a new Node called current to the first element
	// of the courseList LinkedList
	Node<Course>* current = courseList.getFirst();

	while (current != nullptr)
	{
		string grade = current->data.getGrade();
		if (grade == "A")
		{
			gradeValue += 4;
			sumValues++;
		}
		else if (grade == "B")
		{
			gradeValue += 3;
			sumValues++;
		}
		else if (grade == "C")
		{
			gradeValue += 2;
			sumValues++;
		}
		current = current->next; // Moves to the next Node
	}
	avergeValue = static_cast<double>(gradeValue) / sumValues;
	cout << "Average grade is: " << avergeValue << endl;
	cout << "Select the field to sort by:" << endl;
	cout << "1. Department\n2. Course\n3. Title\n4. Description\n5. Prerequisite\n6. Units\n7. Instructor\n8. Grade\n" << endl;
	cin >> fieldValue;

	courseList.sortBy(fieldValue);
	courseList.print();

}
/*******************************************************
 * Purpose: Option 1 searches an specific course and display its information.
 * Option 2 navigates over the linkedlist and jumps to initial or last element
 *
 *******************************************************/
void CourseMenu::doView() {
	int choice;
	cout << "1. Search for a Course\n";  // Option to search for a course
	cout << "2. Navigate Courses\n";    // Option to navigate through courses
	cout << "3. Exit\n";                 // Option to exit
	cout << "Enter your choice: ";
	cin >> choice;

	switch (choice) {
	case 1: {
		// Search for a specific course
		string courseCode;
		cout << "Enter course code to search: ";
		cin >> courseCode;

		Course searchCourse;
		searchCourse.setCourse(courseCode);
		try
		{

			int result = courseList.search(searchCourse);
			if (result == -1) {
				throw(courseCode);
			}
			else {
				// Output the found course
				iter = courseList.begin(); // Reset iterator to the beginning
				for (int i = 0; i < result; ++i) {
					++iter;
				}
				cout << *iter << endl;  // Display course information
			}
		}
		catch (DataException d)
		{
			cout << "Course with code " << courseCode << " not found.\n";  // Course not found
		}
		catch (...)
		{
			cout << "Something went wrong while selecting your course" << endl;
		}
		break;
	}
	case 2: {
		navigating = true; // Set the navigating flag to true
		iter = courseList.begin(); // Initialize iterator to the first course

		while (navigating) {
			cout << "\nCurrent Course:\n";
			cout << *iter << endl;  // Display current course

			// Display navigation options
			cout << "Navigation Options:\n";
			cout << "1. Next\n";
			cout << "2. Previous\n";
			cout << "3. First Course\n";
			cout << "4. Last Course\n";
			cout << "5. Exit Navigation\n";
			cout << "Enter your choice: ";
			int navChoice;
			cin >> navChoice;

			switch (navChoice) {
			case 1:
				moveNext();  // Call to move to the next course
				break;
			case 2:
				movePrevious();  // Call to move to the previous course
				break;
			case 3:
				moveFirst();  // Call to move to the first course
				break;
			case 4:
				moveLast();  // Call to move to the last course
				break;
			case 5:
				navigating = false;  // Exit navigation
				break;
			default:
				cout << "Invalid choice. Please try again.\n";  // Handle invalid navigation choice
				break;
			}
		}
		break;
	}
	case 3:
		exit(0);  // Exit the program
	default:
		cout << "Invalid choice. Please try again.\n";  // Handle invalid menu choice
	}
}
/*******************************************************
 * Purpose: Adds a new Course by creating a new instance of
 * Course and adding each parameter and inserting it in the
 * CourseList LinkedList
 *
 *******************************************************/
void CourseMenu::doAdd()
{
	Course newCourse;
	//const int MAX_CHARS = 4; // Maximum number of characters to read
	//char department[MAX_CHARS + 1], prerequisites[MAX_CHARS + 1]; // +1 for null terminator

	string title, description, instructor, course, department, prerequisites, grade;
	int units;
	//
	cout << "**** Add your Course ****" << endl;
	cout << "1. Enter department: ";
	// Adding get method to limit input to MX_CHARS
	cin >> (department);
	newCourse.setDepart(department);
	cout << "2. Enter course: ";
	cin >> course;
	newCourse.setCourse(course);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "3. Enter title: ";
	getline(cin, title);
	newCourse.setTitle(title);
	cout << "4. Enter description: ";
	getline(cin, description);
	newCourse.setDescription(description);
	cout << "5. Enter prerequisites: ";
	getline(cin, prerequisites);
	newCourse.setPrereq(prerequisites);
	cout << "6. Enter number of units: ";
	cin >> units;
	newCourse.setUnits(units);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "7. Enter the instructor imparting the class: ";
	getline(cin, instructor);
	newCourse.setInstructor(instructor);
	cout << "8. Enter your grade: ";
	cin >> grade;
	newCourse.setGrade(grade);
	courseList.insert(newCourse);

}
/*******************************************************
 * Purpose: Modifies Course based by selecting the course
 * it wants to be edited.
 *
 *******************************************************/
void CourseMenu::doEdit()
{
	string title, description, instructor, course, department, prerequisites, grade;
	int units;

	cout << "Select the course you want to edit (Ex: 116): ";
	cin >> course;

	Node<Course>* current = courseList.getFirst();
	bool courseFound = false;

	while (current != nullptr)
	{
		if (current->data.getCourse() == course)
		{
			courseFound = true;
			cout << "Editing course " << course << ".\n";

			cout << "1. Enter department: ";
			cin >> department;
			current->data.setDepart(department);

			cout << "2. Enter course: ";
			cin >> course;
			current->data.setCourse(course);

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore newline

			cout << "3. Enter title: ";
			getline(cin, title);
			current->data.setTitle(title);

			cout << "4. Enter description: ";
			getline(cin, description);
			current->data.setDescription(description);

			cout << "5. Enter prerequisites: ";
			getline(cin, prerequisites);
			current->data.setPrereq(prerequisites);

			cout << "6. Enter number of units: ";
			cin >> units;
			current->data.setUnits(units);

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore newline

			cout << "7. Enter the instructor imparting the class: ";
			getline(cin, instructor);
			current->data.setInstructor(instructor);

			cout << "8. Enter your grade: ";
			cin >> grade;
			current->data.setGrade(grade);

			cout << "Course updated successfully.\n";
			break;
		}
		current = current->next;
	}

	if (!courseFound) {
		cout << "Course not found.\n";
	}
}
/*******************************************************
 * Purpose: Deletes course Node and reconnects the previous
 * and next pointer of the the node that was removed
 *
 *******************************************************/
void CourseMenu::doDelete()
{
	string department, course;
	cout << "**** Delete Course ****" << endl;
	cout << "Enter Department: ";
	cin >> department;
	cout << "Enter the course: ";
	cin >> course;

	Node<Course>* current = courseList.getFirst();

	while (current != nullptr)
	{
		if (current->data.getDepart() == department && current->data.getCourse() == course)
		{
			Node<Course>* toDelete = current; // Save current node to delete

			if (current->previous)
			{
				current->previous->next = current->next;
			}
			else
			{
				courseList.setFirst(current->next); // Update head if deleting first node
			}

			if (current->next)
			{
				current->next->previous = current->previous;
			}
			else
			{
				courseList.setFirst(current->previous); // Update tail if deleting last node
			}

			current = current->next; // Move to the next node before deletion
			delete toDelete;         // Delete the node
			cout << "Course deleted (X)";
		}
		else if (current->data.getDepart() != department || current->data.getCourse() != course)
		{
			cout << "Course not found";
			break;
		}
		else
		{
			current = current->next; // Move to the next node if not deleting

		}
	}

}
/*******************************************************
 * Purpose: Exits program and saves the data that was modified
 *
 *******************************************************/
void CourseMenu::doExit()
{
	saveData();
}
