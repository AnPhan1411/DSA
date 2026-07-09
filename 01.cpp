#include<iostream>
using namespace std;
struct Node {
	int inf; Node* next;
};
struct linkedList {
	Node* head;
};
void init(linkedList& l) {
	l.head = nullptr;
}
Node* createNode(int x) {//la kieu du lieu tu dinh nghia
	Node* p = new Node();//khoi tao 1 con tro rong
	p->inf = x;
	p->next = nullptr;
	return p; // tra ve vi tri x
}

bool isEmpty(linkedList l) {
	return l.head == nullptr;
}
void printList(linkedList l) {
	if (isEmpty(l)) {
		cout << "Danh sach rong\n";
	}
	Node* p = l.head;
	while (p != nullptr) {
		cout << p->inf << "\t";
		p = p->next;
	}
}
//tao mot kieu du lieu tim kiem 
Node* search(linkedList l, int key) {
	if (!isEmpty(l)) {
		Node* p = l.head;
		while (p != nullptr) {
			cout << p->inf << "\t";
			p = p->next;
		}
	}
}//chen vao truoc
void insertBefore() {

}//chen sau danh sach
Node* insertAfter(linkedList l, int x, int key) {
	Node* q = search(l, key);
	if (q != nullptr) {
		Node* p = createNode(x);
		q->next = p->next;
		q->next = p;
	}
} 
//them dau danh sach
void addHead(linkedList &l, int x) {
	Node* p = createNode ( x);// tao mot con tro x moi
	p->next = l.head;
	l.head = p;
}
//xoa phan tu dau danh sach
void delHead(linkedList &l) {
	if (!isEmpty(l)) {
		Node* p = l.head;
		l.head = l.head->next;
		p->next = nullptr;
		delete p;
	}
}
//them vao cuoi danh sach
void addTail() {

}
//xoa phan tu cuoi danh sach
void delTail(linkedList &l) {

}

// sap xep theo interchange sort
void sortList(linkedList l) {
	for (Node* i = l.head; i->next!=nullptr; i->next) {
		for (Node* j = i->next; j != nullptr; j->next) {
			if (j->inf < i->inf) {
				swap(i->inf, j->inf);
			}
		}
	}
}
//truy xuat phan tu
Node* getNodeAt(linkedList l, int index) {
	if (isEmpty(l) || index < 0) {
		return nullptr;
	}
	else {
		Node* q = l.head;
		int i = 0;
		while (q != nullptr && i < index) {
			i++
		}
	}
}
//xoa con tro
void clear(Node*& head) {
	while (head != nullptr) {
		delete (head);
	}
}
void destroy(linkedList l) {
	while (!isEmpty(l)) {
		delHead(l);
	}
}
int main() {
	linkedList l;
	init(l);
	addHead(l, 5);

	return 0;
}