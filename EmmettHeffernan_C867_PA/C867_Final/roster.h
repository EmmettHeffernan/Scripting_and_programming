#include <string>
using namespace std;
#include "Student.h"

class Roster {
		
	public:
		DegreeProgram StrToEnum(string str);
		void Parse(string row);
		void Add(string studentID, string firstName, string lastName, string emailAddress,
			int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
			DegreeProgram degreeProgram);
		void Remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram sdProgram);
		~Roster();
		
		Student* classRosterArray[5];
		int craIndex = 0;

};
