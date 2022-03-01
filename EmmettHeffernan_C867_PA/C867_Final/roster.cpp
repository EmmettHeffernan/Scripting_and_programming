#include "roster.h"
#include <iostream>

DegreeProgram Roster::StrToEnum(string str)
{
	if (str == "NETWORK") return DegreeProgram::NETWORK;
	if (str == "SOFTWARE") return DegreeProgram::SOFTWARE;
	return DegreeProgram::SECURITY;
}

void Roster::Parse(string row)
{
	string psID;
	string pfName;
	string plName;
	string peAddress;
	int pAge;
	int pdiCourse1;
	int pdiCourse2;
	int pdiCourse3;
	DegreeProgram pdProgram;
	
	size_t endStr = row.find(",");
	psID = row.substr(0, endStr);

	size_t begStr = endStr + 1;
	endStr = row.find(",", begStr);
	pfName = row.substr(begStr, endStr - begStr);

	begStr = endStr + 1;
	endStr = row.find(",", begStr);
	plName = row.substr(begStr, endStr - begStr);


	begStr = endStr + 1;
	endStr = row.find(",", begStr);
	peAddress = row.substr(begStr, endStr - begStr);

	begStr = endStr + 1;
	endStr = row.find(",", begStr);
    pAge = stoi(row.substr(begStr, endStr - begStr));

	begStr = endStr + 1;
	endStr = row.find(",", begStr);
	pdiCourse1 = stoi(row.substr(begStr, endStr - begStr));

	begStr = endStr + 1;
	endStr = row.find(",", begStr);
	pdiCourse2 = stoi(row.substr(begStr, endStr - begStr));

	begStr = endStr + 1;
	endStr = row.find(",", begStr);
	pdiCourse3 = stoi(row.substr(begStr, endStr - begStr));

	begStr = endStr + 1;
	endStr = row.find(",", begStr);
	pdProgram = StrToEnum(row.substr(begStr, endStr - begStr));

	Add(psID, pfName, plName, peAddress, pAge, pdiCourse1, pdiCourse2, pdiCourse3, pdProgram);
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int tempArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[craIndex++] = new Student(studentID, firstName, lastName, emailAddress, age, tempArray, degreeProgram);	
}

void Roster::Remove(string studentID)
{
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentID() != "Invalid") {
			if (studentID == (classRosterArray[i])->GetStudentID()) {
				classRosterArray[i]->SetStudentID("Invalid");
			}
		}
	}
	cout << "Student with ID: " << studentID << " not found." << endl;
}

void Roster::printAll()
{
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentID() != "Invalid") {
			classRosterArray[i]->Print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			int days1 = 0;
			 int days2 = 0;
			int days3 = 0;
			int average = 0;
			if (studentID == (*classRosterArray[i]).GetStudentID()) {
				days1 = classRosterArray[i]->GetCourseDaysLeft()[0];
				days2 = classRosterArray[i]->GetCourseDaysLeft()[1];
				days3 = classRosterArray[i]->GetCourseDaysLeft()[2];

				average = (days1 + days2 + days3) / 3;
				cout << average << endl;
			}
		}
	}
}

void Roster::printInvalidEmails()
{
	string ceAddress;
	for (int i = 0; i < 5; i++) {
		ceAddress = classRosterArray[i]->GetEmailAddress();
		if (ceAddress.find('@') != string::npos && ceAddress.find('.') != string::npos
			&& ceAddress.find(' ') == string::npos) {
			continue;
		}
		else
			cout << ceAddress << endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram sdProgram)
{
	for (int i = 0; i < 5; i++) {
		if (sdProgram == classRosterArray[i]->GetDegreeProgram()) {
			classRosterArray[i]->Print();
		}
	}
}

Roster::~Roster()
{
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
	}
	cout << "Destroying roster";
}
