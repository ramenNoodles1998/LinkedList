#include "List.h"


List::~List(){
	while (head != nullptr) {
		Node* temp = new Node();
		temp = head;
		head = temp->next;
		delete temp;
	}
}

void List::	push_front(const int & value)
{
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;

	++SIZE;
}

void List::push_back(const int & value)
{
	if (head == nullptr) {
		push_front(value);
	}
	else {
		Node* temp = new Node();
		temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		//temp is last node
		Node* newNode = new Node(value);
		newNode->next = nullptr;
		temp->next = newNode;
		

	}
	++SIZE;

}

void List::remove(const int & value)
{
	
	while (head->data == value && head != nullptr) {
		Node* temp = new Node();
		temp = head;
		head = head->next;
		delete temp;
		--SIZE;

	}
	Node* temp = new Node();
	temp = head;
	while (temp->next != nullptr) {
		if (temp->next->data == value) {
			Node* DataDelete = new Node();
			DataDelete = temp->next;
			temp->next = DataDelete->next;
			delete DataDelete;
			--SIZE;
		}
		else
			temp = temp->next;
	}

}

int List::size()
{
	return SIZE -1;
}

void List::PrintList()
{
	Node* temp = new Node();
	temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	delete temp;
	
}
