#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
using namespace std;

class Student {

public:
	void SetStudentID(string newStudentID);
	void SetFirstName(string newFirstName);
	void SetLastName(string newLastName);
	void SetEmailAddress(string newEmailAddress);
	void SetAge(int newAge);
	void SetCourseDaysLeft(int daysLeft[]);
	void SetDegreeProgram(DegreeProgram newDegreeProgram);
	void Print();

	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmailAddress() const;
	int GetAge() const;
	int* GetCourseDaysLeft();
	DegreeProgram GetDegreeProgram();
	Student();
	Student(string sID, string fName, string lName, string eAddress, int a, int cDaysLeft[], DegreeProgram degreeProgram);

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseDaysLeft[3];
	DegreeProgram degreeProgram;
	string degreeProgramStrings[3] = { "SECURITY", "NETWORK", "SOFTWARE" };
};

#endif