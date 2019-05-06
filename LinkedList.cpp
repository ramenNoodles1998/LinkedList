#include "LinkedList.h"

LinkedList::~LinkedList()
{
	cout << "Destructing List" << endl;
	DestructorHelper(head);
	head = nullptr;
}

void LinkedList::DestructorHelper(Course * cursor)
{
	if (cursor == nullptr)
	{
		return;
	}
	else
	{
		Course *tmp = cursor->next;
		delete cursor;
		DestructorHelper(tmp);
	}
}

void LinkedList::PrintList() const
{
	cout << "Current List: (" << Size() << ")" << endl;
	PrintListHelper(head);
	
}

void LinkedList::PrintListHelper(Course const * cursor) const
{
	if (cursor == nullptr)
	{
		cout << endl;
		return;
	}
	else
	{
		cout << "cs" << cursor->courseNumber << " ";
		cout << cursor->courseName << ": ";
		cout << cursor->grade << ",";
		cout << " Credit Hours: " <<cursor->credits << endl;
		
		PrintListHelper(cursor->next);
	}
}
void LinkedList::Insert(Course * newCourse)
{
	head = InsertHelper(head, newCourse);
}
int LinkedList::Size() const
{
	return SizeHelper(head);
}
int LinkedList::SizeHelper(Course const * cursor) const
{
	int size = 0;
	if (cursor == nullptr) {
		return size;
	}
	else {
		size = size++;
		return SizeHelper(cursor->next)+size;
	}
}

Course * LinkedList::InsertHelper(Course * head, Course * newCourse)
{
	if (head == nullptr)
	{
		Course *tmp = new Course(newCourse->courseNumber, newCourse->courseName, newCourse->credits, newCourse->grade);
		return tmp;
	}
	else if (head->courseNumber > newCourse->courseNumber)
	{
		Course *tmp = new Course(newCourse->courseNumber, newCourse->courseName, newCourse->credits,newCourse->grade);
		tmp->next = head;
		return tmp;
	}
	else
	{
		head->next = InsertHelper(head->next, newCourse);
		return head;
	}
}
double LinkedList::CalculateGPA() const
{
	return CalculateTotalGradePoints(head)/CalculateTotalCredits(head);
}

double LinkedList::CalculateTotalGradePoints(Course const * cursor) const
{
	
	if (cursor ==  nullptr) {
		return 0;
	}
	else {
		return (cursor->grade * cursor->credits) + CalculateTotalGradePoints(cursor->next);
		
	}
}

unsigned int LinkedList::CalculateTotalCredits(Course const * cursor) const
{
	
	if (cursor == nullptr) {
		return 0;
	}
	else {
		
		return cursor->credits + CalculateTotalCredits(cursor->next);
	}
}


