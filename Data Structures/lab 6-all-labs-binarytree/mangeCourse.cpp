
#include "manageCourse.h"
#include <iostream>

void ManageCourses::sortBy(int fieldValue) {
	char order;
	cout << "Enter 'a' for ascending or 'd' for descending order: ";
	cin >> order;

	bool ascending = (order == 'a');
	selectionSort(fieldValue, ascending);
}

void ManageCourses::selectionSort(int fieldValue, bool ascending) {
	if (first == nullptr || first->next == nullptr) return;

	for (Node<Course>* i = first; i != nullptr; i = i->next) {
		Node<Course>* target = i;

		for (Node<Course>* j = i->next; j != nullptr; j = j->next) {
			bool condition;
			switch (fieldValue) {
			case 1: condition = ascending ? (j->data.getDepart() < target->data.getDepart())
				: (j->data.getDepart() > target->data.getDepart()); break;
			case 2: condition = ascending ? (j->data.getCourse() < target->data.getCourse())
				: (j->data.getCourse() > target->data.getCourse()); break;
			case 3: condition = ascending ? (j->data.getTitle() < target->data.getTitle())
				: (j->data.getTitle() > target->data.getTitle()); break;
			case 4: condition = ascending ? (j->data.getDescription() < target->data.getDescription())
				: (j->data.getDescription() > target->data.getDescription()); break;
			case 5: condition = ascending ? (j->data.getPrereq() < target->data.getPrereq())
				: (j->data.getPrereq() > target->data.getPrereq()); break;
			case 6: condition = ascending ? (j->data.getUnits() < target->data.getUnits())
				: (j->data.getUnits() > target->data.getUnits()); break;
			case 7: condition = ascending ? (j->data.getInstructor() < target->data.getInstructor())
				: (j->data.getInstructor() > target->data.getInstructor()); break;
			case 8: condition = ascending ? (j->data.getGrade() < target->data.getGrade())
				: (j->data.getGrade() > target->data.getGrade()); break;

			default: condition = false; break;
			}

			if (condition) target = j;

		}

		if (target != i) {
			Course temp = i->data;
			i->data = target->data;
			target->data = temp;
		}

	}
}
int ManageCourses::search(Course element)
{
	string course = element.getCourse();
	Node<Course>* current = this->first;
	bool found = false;  // Flag to indicate if any course is found

	while (current != nullptr) {
		// Compare the course from the element with the course in the current node
		if (course == current->data.getCourse()) {
			// Print course details
			cout << "-----------------------\n";
			cout << current->data;  // Ensure your Course class has an appropriate operator<< defined
			cout << "-----------------------\n";
			found = true;  // Set the flag to true
		}
		current = current->next;
	}

	// Return based on whether any courses were found
	return found ? 0 : -1;  // Return 0 if found, -1 if not found
}

void ManageCourses::print() {
	Node<Course>* current = this->first;
	while (current != nullptr) {
		cout << "-----------------------\n" << current->data;
		current = current->next;
	}
}
void ManageCourses::binSearch(Course element)
{  };

