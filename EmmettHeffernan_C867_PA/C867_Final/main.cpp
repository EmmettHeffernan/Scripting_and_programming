#include <iostream>
using namespace std;
#include "roster.h"

int main()
{
	const string studentData[] = {

		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Emmett,Heffernan,emmettjheffernan@gmail.com,22,20,50,70,SOFTWARE"
	};
	
	cout << "Scripting & Programming - C867, C++, 001411110, Emmett Heffernan" << endl;
	
	Roster classRoster;
	
	
	for (int i = 0; i < 5; i++) {

		classRoster.Parse(studentData[i]);

	}

	classRoster.printAll();
	classRoster.printInvalidEmails();

	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}

	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.Remove("A3");
	classRoster.printAll();
	classRoster.Remove("A3");
}
