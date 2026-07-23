#include <iostream>
using namespace std;
struct Node {
	Node* next, * prev;
	int info;
};
struct DoublyList {
	Node* head, * tail;
};
Node* createNode(int x){
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	p->prev = nullptr;
	return p;

}
Node* search(DoublyList l, const int& key) {
	Node* q = nullptr;
	while (q != nullptr) {
		if (q->info == key) {
			return q;
			q = q->next;
		}
	} return q;
}
void init(DoublyList& l) {
	l.head = nullptr;
	l.tail = nullptr;
}
void addHead(DoublyList& l, int x) {
	Node* p = createNode(x);
	if (l.head == nullptr) {
		l.tail = p;
	}
	else {
		p->next = l.head;
		l.head->prev = p;
	}l.head = p;

}
void addTail(DoublyList& l, int x) {
	Node* p = createNode(x);
	if (l.tail == nullptr) {
		l.head = p;
	}
	else {
		p->prev = l.tail;
		l.tail->next = p;
	}l.tail = p;
}
void printFromHead(DoublyList l){
	if (l.head == nullptr) {
		cout << "Danh sach rong";
		return;
	}
	Node* p = l.head;
	while (p != nullptr) {
		cout << p->info << " ";
		p->next;
	}
}
void printFromTail(DoublyList l) {
	
	if (l.head == nullptr) {
		cout << "Danh sach rong";
		return;
	}
	Node* p = l.tail;
	while (p != nullptr) {
		cout << p->info << " ";
		p->prev;
	}

}
void delHead(DoublyList& l) {
	if (l.head == nullptr) {
		return;
	}
	Node* p = l.head;
	if (l.head != nullptr) {
		l.head = l.head->next;
	}
	else {
		l.tail = nullptr;
	}
	p->next = nullptr;
	delete p;

}
void delTail(DoublyList& l) {
	if (l.head == nullptr) {
		return;
	}
	Node* p = l.tail;
	l.tail = l.tail->prev;
	if (l.tail != nullptr) {
		l.tail->next = nullptr;
	}
	else {
		l.head = nullptr;
	}
	p->prev = nullptr;
	delete p;
}
void destroyList(DoublyList& l) {
	while (l.head != nullptr) {
		delHead(l);
	}
}
void insertAfter(DoublyList& l, int x, int key) {

}