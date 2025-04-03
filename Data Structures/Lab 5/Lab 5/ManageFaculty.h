#ifndef MANAGE_FACULTY_H
#define MANAGE_FACULTY_H

#include <iostream>
#include "HashTable.h"
#include "Faculty.h"
#include <fstream>
#include <sstream>

using namespace std;

class ManageFaculty {
public:
    ManageFaculty(int nbuckets);
    ~ManageFaculty();

    void loadFromCSV(const string& filename);
    Faculty* findFacultyById(const string& instructorId);
    void updateFaculty(const string& instructorId, const Faculty& updatedFaculty);
    void listAllFaculty() const;

private:
    HashTable<pair<string, Faculty>> facultyTable;

    int hashKey(const string& key) {
        return hash_code(key) % facultyTable.size();
    }
};

ManageFaculty::ManageFaculty(int nbuckets) : facultyTable(nbuckets) {}

ManageFaculty::~ManageFaculty() {}

void ManageFaculty::loadFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        string instructor, firstName, lastName, department, address, city, state, zip, email, phone;

        getline(ss, instructor, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, department, ',');
        getline(ss, address, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, zip, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');

        Faculty faculty;
        faculty.setInstructor(instructor);
        faculty.setFirstName(firstName);
        faculty.setLastName(lastName);
        faculty.setDepartment(department);
        faculty.setAddress(address);
        faculty.setCity(city);
        faculty.setState(state);
        faculty.setZip(zip);
        faculty.setEmail(email);
        faculty.setPhone(phone);

        facultyTable.insert(make_pair(instructor, faculty));
    }

    file.close();
}

Faculty* ManageFaculty::findFacultyById(const string& instructorId) {
    for (auto it = facultyTable.begin(); !it.equals(facultyTable.end()); it.next()) {
        if (it.get().first == instructorId) {
            return new Faculty(it.get().second); // Return a copy of the Faculty
        }
    }
    return nullptr; // Not found
}

void ManageFaculty::updateFaculty(const string& instructorId, const Faculty& updatedFaculty) {
    auto existingFaculty = findFacultyById(instructorId);
    if (existingFaculty != nullptr) {
        facultyTable.erase(make_pair(instructorId, *existingFaculty));
        delete existingFaculty;
    }
    facultyTable.insert(make_pair(instructorId, updatedFaculty));
}

void ManageFaculty::listAllFaculty() const {
    for (auto it = facultyTable.begin(); !it.equals(facultyTable.end()); it.next()) {
        cout << it.get().second << endl;
    }
}

#endif // MANAGE_FACULTY_H
