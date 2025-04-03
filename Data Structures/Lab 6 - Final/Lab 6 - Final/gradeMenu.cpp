#include "gradeMenu.h"

GradeMenu::GradeMenu() : Menu("** Grade Menu **")
{
    // Implement the menu
    MenuOption op1('1', "List of grades", "Show details");
    MenuOption op2('2', "View of grades", "Show details");
    MenuOption op3('3', "Add new grades", "Show details");
    MenuOption op4('4', "Edit grades", "Show details");
    MenuOption op5('5', "Delete grades", "Show details");
    MenuOption op6('X', "Quit", "Show details");

    addOption(op1);
    addOption(op2);
    addOption(op3);
    addOption(op4);
    addOption(op5);
    addOption(op6);

    initialize();
}

GradeMenu::~GradeMenu()
{
    doSave();

}
void GradeMenu::initialize() {
    ifstream inFile(ASSIGNMENT_DATA);
    if (!inFile.is_open()) {
        cerr << "Failed to open file: " << ASSIGNMENT_DATA << endl;
        return;
    }

    string line;
    getline(inFile, line); // Skip header

    while (getline(inFile, line)) {
        stringstream ss(line);
        string temp, startDT, endDT;
        Assignment assignment;

        try {
            // Parse ID
            getline(ss, temp, ',');
            assignment.setId(stoi(temp));

            // Parse Group ID
            getline(ss, temp, ',');
            assignment.setGroupId(stoi(temp));

            // Parse Description
            getline(ss, temp, ',');
            assignment.setDescription(temp);

            // Parse Start Date
            getline(ss, startDT, ',');
            DateTime _startDate(startDT); // Assuming DateTime has a string constructor
            assignment.setStartDate(_startDate);

            // Parse End Date
            getline(ss, endDT, ',');
            DateTime _endDate(endDT); // Assuming DateTime has a string constructor
            assignment.setEndDate(_endDate);

            // Parse Possible Points
            getline(ss, temp, ',');
            assignment.setPossiblePoints(stod(temp));

            // Parse Points
            getline(ss, temp, ',');
            assignment.setPoints(stod(temp));

            // Add the parsed assignment to the tree
            courseGrades.addToTree(assignment);

        }
        catch (const exception& e) {
            cerr << "Error parsing line: " << line << " (" << e.what() << ")" << endl;
        }
    }
    inFile.close();
}

void GradeMenu::activate()
{
    char choice = 0;
    do {
        choice = getInput();
        switch (choice) {
        case LIST_OF_GRADES:
            doList();
            break;
        case VIEW_GRADES:
            doView();
            break;
        case ADD_GRADES:
            doAdd();
            break;
        case EDIT_GRADES:
            doEdit();
            break;
        case DELETE_GRADES:
            doRemove();
            break;
        case EXIT_MENU:
            cout << "Bye bye!" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
        }
    } while (choice != 'X');
}
void GradeMenu::doSave() // -save data to .csv file
{
    ofstream outFile(ASSIGNMENT_DATA); // Open the file in overwrite mode (it will create or overwrite the file)
    if (!outFile.is_open()) {
        cerr << "Failed to open file: " << ASSIGNMENT_DATA << endl;
        return;
    }

    // Write the header for the CSV file
    outFile << "ID,GroupID,Description,StartDate,EndDate,PossiblePoints,Points\n";

    // Traverse the tree and write assignment data to the file
    for (const Node1<Assignment>* group : courseGrades.root->children) {
        for (Node1<Assignment>* assignmentNode : group->children) {
            Assignment& assignment = assignmentNode->data;

            // Write each assignment to the file in CSV format
            outFile << assignment.getId() << ","
                << assignment.getGroupId() << ","
                << assignment.getDescription() << ","
                << assignment.getPossiblePoints() << ","
                << assignment.getPoints() << ","
                << assignment.getStartDate().toString() << ","
                << assignment.getEndDate().toString() << "\n";
        }
    }
    outFile.close(); // Close the file after writing
    cout << "Data successfully saved to " << ASSIGNMENT_DATA << endl;
}

void GradeMenu::doList() {
    courseGrades.print();
}

void GradeMenu::doView() {
    if (!courseGrades.root) {
        cout << "Error: Root node is not initialized." << endl;
        return;
    }

    if (courseGrades.root->children.empty()) {
        cout << "No assignments available to view." << endl;
        return;
    }

    // Continue with your code for viewing assignments...


    int choice;
    cout << "View Options:\n"
        << "1. View all assignments in a group\n"
        << "2. View details of an individual assignment\n"
        << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int groupId;
        cout << "Enter Group ID to view all assignments in the group: ";
        cin >> groupId;

        if (cin.fail() || groupId <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Group ID. Please try again." << endl;
            return;
        }

        Node1<Assignment>* groupNode = nullptr;
        for (Node1<Assignment>* child : courseGrades.root->children) {
            // Debug print to check the group ID values being checked
            cout << "Checking Group ID: " << child->data.getGroupId() << endl;

            if (child->data.getGroupId() == groupId) {
                groupNode = child;
                break;
            }
        }

        if (!groupNode) {
            cout << "Group ID " << groupId << " not found." << endl;
            return;
        }

        // Check if group has any assignments
        if (groupNode->children.empty()) {
            cout << "No assignments found in Group " << groupId << "." << endl;
            return;
        }

        cout << "Assignments in Group " << groupId << ":\n";
        for (Node1<Assignment>* assignmentNode : groupNode->children) {
            cout << "Assignment ID: " << assignmentNode->data.getId() << ", "
                << "Description: " << assignmentNode->data.getDescription() << ", "
                << "Start Date: " << assignmentNode->data.getStartDate().toString() << ", "
                << "End Date: " << assignmentNode->data.getEndDate().toString() << ", "
                << "Possible Points: " << assignmentNode->data.getPossiblePoints() << ", "
                << "Points Earned: " << assignmentNode->data.getPoints() << endl;
        }
    }
    else if (choice == 2)
    {

        int assignmentId;
        cout << "Enter Assignment ID to view details: ";
        cin >> assignmentId;

        Node1<Assignment>* assignmentNode = nullptr;
        for (Node1<Assignment>* groupNode : courseGrades.root->children) {
            for (Node1<Assignment>* child : groupNode->children) {
                if (child->data.getId() == assignmentId) {
                    assignmentNode = child;
                    break;
                }
            }
            if (assignmentNode) break;
        }

        if (!assignmentNode) {
            cout << "Assignment ID " << assignmentId << " not found." << endl;
            return;
        }

        cout << "Assignment Details:\n"
            << "ID: " << assignmentNode->data.getId() << "\n"
            << "Group ID: " << assignmentNode->data.getGroupId() << "\n"
            << "Description: " << assignmentNode->data.getDescription() << "\n"
            << "Start Date: " << assignmentNode->data.getStartDate().toString() << "\n"
            << "End Date: " << assignmentNode->data.getEndDate().toString() << "\n"
            << "Possible Points: " << assignmentNode->data.getPossiblePoints() << "\n"
            << "Points Earned: " << assignmentNode->data.getPoints() << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }
}

void GradeMenu::doAdd() // -add to tree.
{
    int id, groupId;
    string description;
    double possiblePoints, points;
    DateTime dt;
    Assignment a;


    cout << "START ADDING A NEW GRADE\n";

    cout << "- Enter a class id: ";
    cin >> id;
    a.setId(id);

    cout << "- Enter a group id: ";
    cin >> groupId;
    a.setGroupId(groupId);

    cin.ignore();
    cout << "- Enter a description: ";
    getline(cin, description);
    a.setDescription(description);

    cout << "- Enter the points you can get: ";
    cin >> possiblePoints;
    a.setPossiblePoints(possiblePoints);

    cout << "- Enter the points you got: ";
    cin >> points;
    a.setPoints(points);

    cout << "- Enter a starting date";
    cin >> dt;
    a.setStartDate(dt);

    cout << "- Enter an ending date";
    cin >> dt;
    a.setEndDate(dt);

    courseGrades.addToTree(a);
}
void GradeMenu::doEdit() // -edit any fields
{
    int assignmentId;
    cout << "Enter the ID of the assignment you want to edit: ";
    cin >> assignmentId;

    Node1<Assignment>* assignmentNode = nullptr;
    for (Node1<Assignment>* groupNode : courseGrades.root->children) {
        for (Node1<Assignment>* child : groupNode->children) {
            if (child->data.getId() == assignmentId) {
                assignmentNode = child;
                break;
            }
        }
        if (assignmentNode) break;
    }

    if (!assignmentNode) {
        cout << "Assignment ID " << assignmentId << " not found." << endl;
        return;
    }

    cout << "Editing Assignment ID: " << assignmentNode->data.getId() << endl;
    int choice;
    cout << "What would you like to edit?\n"
        << "1. Edit Description\n"
        << "2. Edit Possible Points\n"
        << "3. Edit Points\n"
        << "4. Edit Start Date\n"
        << "5. Edit End Date\n"
        << "Enter your choice: ";
    cin >> choice;

    cin.ignore();  // To handle the newline character left by cin

    string newDescription;
    double newPossiblePoints, newPoints;
    DateTime newStartDate, newEndDate;

    switch (choice) {
    case 1: // Edit Description
        cout << "Enter new description: ";
        getline(cin, newDescription);
        assignmentNode->data.setDescription(newDescription);
        cout << "Description updated." << endl;
        break;

    case 2: // Edit Possible Points
        cout << "Enter new possible points: ";
        cin >> newPossiblePoints;
        assignmentNode->data.setPossiblePoints(newPossiblePoints);
        cout << "Possible points updated." << endl;
        break;

    case 3: // Edit Points
        cout << "Enter new points: ";
        cin >> newPoints;
        assignmentNode->data.setPoints(newPoints);
        cout << "Points updated." << endl;
        break;

    case 4: // Edit Start Date
        cout << "Enter new start date (mm/dd/yy hh:mm:ss): ";
        cin >> newStartDate;
        assignmentNode->data.setStartDate(newStartDate);
        cout << "Start date updated." << endl;
        break;

    case 5: // Edit End Date
        cout << "Enter new end date (mm/dd/yy hh:mm:ss): ";
        cin >> newEndDate;
        assignmentNode->data.setEndDate(newEndDate);
        cout << "End date updated." << endl;
        break;

    default:
        cout << "Invalid choice." << endl;
        break;
    }
}

void GradeMenu::doRemove() // -remove a node from the tree
{
    int assignmentId;
    cout << "Enter the ID of the assignment you want to remove: ";
    cin >> assignmentId;

    Node1<Assignment>* assignmentNode = nullptr;
    Node1<Assignment>* parentNode = nullptr;

    // Traverse the tree to find the node and its parent
    for (Node1<Assignment>* groupNode : courseGrades.root->children) {
        for (Node1<Assignment>* child : groupNode->children) {
            if (child->data.getId() == assignmentId) {
                assignmentNode = child;
                parentNode = groupNode;
                break;
            }
        }
        if (assignmentNode) break;
    }

    if (!assignmentNode) {
        cout << "Assignment ID " << assignmentId << " not found." << endl;
        return;
    }

    // Remove the assignment node from its parent's children list
    auto it = find(parentNode->children.begin(), parentNode->children.end(), assignmentNode);
    if (it != parentNode->children.end()) {
        parentNode->children.erase(it);
        cout << "Assignment ID " << assignmentId << " has been removed." << endl;
    }
    else {
        cout << "Failed to remove assignment." << endl;
    }
}

void GradeMenu::calculateGrade() {
    double totalPoints = 0, totalPossiblePoints = 0;

    // Define the weights for each group category
    const double classParticipationWeight = 0.10;
    const double quizzesWeight = 0.10;
    const double labsWeight = 0.30;
    const double midtermWeight = 0.20;
    const double finalExamWeight = 0.30;

    // Traverse through all groups in the courseGrades tree
    for (const Node1<Assignment>* group : courseGrades.root->children) {
        double groupTotalPoints = 0;
        double groupTotalPossiblePoints = 0;

        // Process assignments in the current group
        for (const Node1<Assignment>* assignmentNode : group->children) {
            const Assignment& assignment = assignmentNode->data;
            groupTotalPoints += assignment.getPoints();
            groupTotalPossiblePoints += assignment.getPossiblePoints();
        }

        // Apply group weight and accumulate to total grade
        if (group->data.getGroupId() == 1) {
            // Class Participation
            totalPoints += (groupTotalPoints / groupTotalPossiblePoints) * classParticipationWeight;
        }
        else if (group->data.getGroupId() == 2) {
            // Quizzes
            totalPoints += (groupTotalPoints / groupTotalPossiblePoints) * quizzesWeight;
        }
        else if (group->data.getGroupId() == 3) {
            // Labs
            totalPoints += (groupTotalPoints / groupTotalPossiblePoints) * labsWeight;
        }
        else if (group->data.getGroupId() == 4) {
            // Midterm
            totalPoints += (groupTotalPoints / groupTotalPossiblePoints) * midtermWeight;
        }
        else if (group->data.getGroupId() == 5) {
            // Final Exam
            totalPoints += (groupTotalPoints / groupTotalPossiblePoints) * finalExamWeight;
        }
    }

    // Ensure total grade is within 0 to 100 range
    totalPoints = std::min(totalPoints, 100.0);

    cout << "Your current grade: " << totalPoints << "%" << endl;
}