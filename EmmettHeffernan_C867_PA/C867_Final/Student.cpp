#include "Student.h"
#include <string>
using namespace std;
#include <iostream>

void Student::SetStudentID(string newStudentID)
{
	studentID = newStudentID;
}

void Student::SetFirstName(string newFirstName)
{
	firstName = newFirstName;
}

void Student::SetLastName(string newLastName)
{
	lastName = newLastName;
}

void Student::SetEmailAddress(string newEmailAddress)
{
	emailAddress = newEmailAddress;
}

void Student::SetAge(int newAge)
{
	age = newAge;
}

void Student::SetCourseDaysLeft(int newDaysLeft[])
{
	courseDaysLeft[0] = newDaysLeft[0];
	courseDaysLeft[1] = newDaysLeft[1];
	courseDaysLeft[2] = newDaysLeft[2];
}

void Student::SetDegreeProgram(DegreeProgram newDegreeProgram)
{
	degreeProgram = newDegreeProgram;
}

void Student::Print()
{
	cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName 
		<< "\tEmail Address: " << emailAddress << "\tAge: " << age << "\tcourseDaysLeft: " 
		<< "{" << courseDaysLeft[0] << ", " << courseDaysLeft[1] << ", " << courseDaysLeft[2] << "}"
		<< "\tDegree Program: " << degreeProgramStrings[(int)degreeProgram] << endl;
}

string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

int* Student::GetCourseDaysLeft()
{
	return courseDaysLeft;
}

DegreeProgram Student::GetDegreeProgram()
{
	return degreeProgram;
}

Student::Student()
{
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;
	courseDaysLeft[0] = 0;
	courseDaysLeft[1] = 0;
	courseDaysLeft[2] = 0;
	degreeProgram =	SOFTWARE;
}

Student::Student(string sID, string fName, string lName, string eAddress, int a, int cDaysLeft[], DegreeProgram dProgram)
{
	studentID = sID;
	firstName = fName;
	lastName = lName;
	emailAddress = eAddress;
	age = a;
	courseDaysLeft[0] = cDaysLeft[0];
	courseDaysLeft[1] = cDaysLeft[1];
	courseDaysLeft[2] = cDaysLeft[2];
	degreeProgram = dProgram;
}
