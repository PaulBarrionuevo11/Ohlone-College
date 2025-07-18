#include "gradeManager.h"

GradeManager::GradeManager() {
    root = new Node1<Assignment>(); // Initialize root with a placeholder
    root->data.setDescription("Course Root");
}

GradeManager::~GradeManager()
{

}
void GradeManager::addToTree(Assignment& assignment) {
    if (!root) {
        cerr << "Error: Root is null!" << endl;
        return;
    }


    Node1<Assignment>* groupNode = nullptr;

    for (Node1<Assignment>* child : root->children) {
        if (child->data.getGroupId() == assignment.getGroupId()) {
            groupNode = child;
            break;
        }
    }

    if (!groupNode) {
        groupNode = new Node1<Assignment>();
        groupNode->data.setDescription("Group " + to_string(assignment.getGroupId()));
        root->children.push_back(groupNode);
    }

    Node1<Assignment>* assignmentNode = new Node1<Assignment>();
    assignmentNode->data = assignment;
    groupNode->children.push_back(assignmentNode);

    cout << "Added assignment to Group " << assignment.getGroupId() << ": " << assignment.getDescription() << endl;
}

vector<Assignment> GradeManager::getAssignmentsByGroup(int groupId) {
    vector<Assignment> assignments;

    for (Node1<Assignment>* child : root->children) {
        if (child->data.getGroupId() == groupId) {
            for (Node1<Assignment>* assignmentNode : child->children) {
                assignments.push_back(assignmentNode->data);
            }
            break;
        }
    }

    return assignments;
}

void GradeManager::deleteTree(Node1<Assignment>* node) {
    if (!node) return;
    for (Node1<Assignment>* child : node->children) {
        deleteTree(child);
    }
    delete node;
}
void GradeManager::print() const {
    if (root) {
        root->print();
    }
}