#pragma once
#include <iostream>
#include "dateTime.h"

using namespace std;

class Assignment
{
public:
	Assignment() {}
	Assignment(const Assignment& other)
		: id(other.id), groupId(other.groupId), description(other.description),
		possiblePoints(other.possiblePoints), points(other.points) {}

	~Assignment() {}


	// Setters
	void setId(int _id) { id = _id; }
	void setGroupId(int _groupId) { groupId = _groupId; }
	void setDescription(string _description) { description = _description; }
	void setPossiblePoints(double _possiblePoints) { possiblePoints = _possiblePoints; }
	void setPoints(double _points) { points = _points; }

	// Getters
	int getId() const { return id; }
	int getGroupId() const { return groupId; }
	string getDescription() const { return description; }
	double getPossiblePoints() const { return possiblePoints; }
	double getPoints() const { return points; }

	// Date Time manipulation

	void setStartDate(DateTime dt) {
		startDate = dt;
	}
	void setEndDate(DateTime dt) { endDate = dt; }

	DateTime getStartDate() {
		return startDate;
	}

	// Getter for end date
	DateTime getEndDate() {
		return endDate;
	}

	// Overloading operators
	bool operator==(const Assignment& a) const {
		return this->id == a.id && this->groupId == a.groupId &&
			this->description == a.description && this->possiblePoints == a.possiblePoints &&
			this->points == a.points;
	}

	bool operator!=(const Assignment& a) const
	{
		return this->groupId != a.groupId;
	}
	friend ostream& operator<<(ostream& os, const Assignment& a) {
		os << "Id: " << a.id << "\n"
			<< "Group id: " << a.groupId << "\n"
			<< "Description: " << a.description << "\n"
			<< "Start date: " << a.startDate.toString() << "\n"
			<< "End date: " << a.endDate.toString() << "\n" // Assuming DateTime has a `toString()` method
			<< "Possible points: " << a.possiblePoints << "\n"
			<< "Points: " << a.points << "\n";
		return os;
	}

private:
	int id, groupId;
	string description;
	double possiblePoints, points;
	DateTime startDate;
	DateTime endDate;

};

