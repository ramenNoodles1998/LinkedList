#include "Course.h"

Course::Course()
{
	courseNumber = 0;
	courseName = "courseName";
	credits = 0;
	grade = 0.0;
}

Course::Course(unsigned int courseNumber, std::string courseName, unsigned int credits, double grade)
{
	this->courseName = courseName;
	this->courseNumber = courseNumber;
	this->credits = credits;
	this->grade = grade;
	next = nullptr;
}
