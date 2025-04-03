#ifndef GRADE_MANAGER_H
#define GRADE_MANAGER_H

#include <iostream>
#include "assignment.h"
#include "tree.h"
#include <fstream>

using namespace std;

class GradeManager : public Tree<Assignment>
{
public:
	GradeManager();
	~GradeManager();
	void addToTree(Assignment& a);
	void add_subtree(Assignment subtree);
	vector<Assignment> getAssignmentsByGroup(int groupId);
	void deleteTree(Node1<Assignment>* node);
	void print() const;

};
#endif // !COURSE_GRADE_MANAGER_H