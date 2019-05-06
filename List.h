#pragma once
#include "Node.h"
#include <iostream>
#include "Iterator.h"
using namespace std;
class List {
	public:
		List() { head = nullptr; }
		~List();
		void push_front(const int& value);
		void push_back(const int& value);
		void remove(const int& value);
		Iterator begin() {
			return Iterator(head);
		}
		Iterator end() {
			Node* temp = new Node();
			temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			return Iterator(temp);
		};
		int size();
		void PrintList();
	private:
		Node* head;
		int SIZE;
};