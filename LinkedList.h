#ifndef __LinkedList__
#define __LinkedList__

#include "Course.h"

class LinkedList
{
public:
	LinkedList() { head = nullptr; }
	~LinkedList();

	
	void PrintList() const;

	           sorted order. using recursison.
	void Insert(Course * newCourse);

	
	int Size() const;

	
	double CalculateGPA() const;


private:
	Course *head;	// start of linked list

	Course* InsertHelper(Course *head,Course *newCourse); // recursive helper for insert()
	int SizeHelper(Course const *cursor) const; // recursive helper for size()
	void PrintListHelper(Course const *cursor) const; // recursive helper for PrintList()
	void DestructorHelper(Course *cursor); // recursive helper for ~LinkedList()

	
	double CalculateTotalGradePoints(Course const *cursor) const;	// total of all earned Grade Points in list of courses
	unsigned int CalculateTotalCredits(Course const *cursor) const; // total of all credits in list of courses
};

#endif

