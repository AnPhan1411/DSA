#include <iostream>
using namespace std;
struct Term {
	float coef;
	int exp;
};

//12 5 3 7 5
struct Node {
	//Vung thong tin
	Term info;
	//Vung lien ket
	Node* next;
};

struct LinkedList {
	Node* head;
};

//Thao tac khoi tao rong
void init(LinkedList& l) {
	l.head = nullptr;
}

bool isEmpty(LinkedList l) {
	return l.head == nullptr;
}

//Thao tac them phan tu vao dau danh sach
Node* createNode(const Term x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	return p;
}

void addHead(LinkedList& l, const Term x) {
	Node* p = createNode(x);
	p->next = l.head;
	l.head = p;
}
ostream& operator <<(ostream& out, Term t) {
	out << t.coef;
	if (t.exp != 0) {
		out << "x" << t.exp;
		return out;
	}

}


//Thao tac duyet danh sach
void printList(LinkedList l) {
	if (isEmpty(l)) {
		cout << "Danh sach rong!\n";
		return;
	}

	Node* p = l.head;
	while (p!=nullptr){
		cout << p->info.coef << " ";
		if (p->info.exp != 0) {
			cout <<"x^"<< p->info.exp;
		}
		p = p->next;
		if (p)
			cout << " + ";
	}

	cout << endl;
}

//Tim kiem phan tu mang gia tri key
Node* search(LinkedList l, int key) {
	Node* p = l.head;
	while (p != nullptr) {
		if (p->info.exp == key)
			return p;
		p = p->next;
	}
	return p;
}

//Them phan tu x vao danh sach phia sau phan tu mang gia tri key
void insertAfter(LinkedList l, const Term x, int key) {
	Node* q = search(l, key);
	if (q != nullptr) {
		Node* p = createNode(x);
		p->next = q->next;
		q->next = p;
	}
}

//Them cuoi danh sach
void addTail(LinkedList& l, const Term x) {
	Node* p = createNode(x);
	if (isEmpty(l)) {
		l.head = p;
	}
	else {
		Node* q = l.head;
		while (q->next!=nullptr) {
			q = q->next;
		}
		q->next = p;
	}
}

//Xoa phan tu cuoi danh
void delTail(LinkedList& l) {
	if (isEmpty(l))
		return;

	Node* q = l.head;
	Node* prev = nullptr;
	while (q->next != nullptr) {
		prev = q;
		q = q->next;
	}
	if (prev != nullptr)
		prev->next = nullptr;
	else
		l.head = nullptr;
	delete q;
}

//Thao tac them vao truoc phan tu mang gia tri key
void insertBefore(LinkedList& l, const Term x, int key) {
	Node* q = l.head;
	Node* prev = nullptr;

	while (q != nullptr && q->info.exp != key) {
		prev = q;
		q = q->next;
	}

	//Truong hop khong tim thay key
	if (q == nullptr)
		return;

	Node* p = createNode(x);
	p->next = q;
	if (prev == nullptr) {
		l.head = p;
	}
	else {
		prev->next = p;
	}
}

//Them phan tu vao danh sach co thu tu
void insertOrdered(LinkedList& l, const Term x) {
	if (isEmpty(l) || x.exp < l.head->info.exp) {
		addHead(l, x);
		return;
	}

	Node* p = createNode(x);
	Node* q = l.head;
	while (q->next != nullptr && x.exp > q->next->info.exp) {
		q = q->next;
	}

	p->next = q->next;
	q->next = p;
}

//Thao tac sap xep danh sach lien ket
int cmpAsc(Node* a, Node* b) {
	return a->info.exp - b->info.exp;
}

void sortList(LinkedList l, int func(Node*, Node*)) {
	if (!isEmpty(l)) {
		for (Node* i = l.head; i->next != nullptr; i = i->next) {
			for (Node* j = i->next; j != nullptr; j = j->next) {
				if (func(j, i)<0)
					swap(i->info, j->info);
			}
		}
	}
}

//Truy xuat phan tu thu i trong danh sach
Node* getNodeAt(LinkedList l, int index) {
	if (isEmpty(l) || index < 0)
		return nullptr;

	Node* q = l.head;
	int i = 0;
	while (q != nullptr && i < index) {
		q = q->next;
		i++;
	}

	return q;
}

//Xoa phan tu dau danh sach
void delHead(LinkedList& l) {
	if (!isEmpty(l)) {
		Node* p = l.head;
		l.head = l.head->next;

		p->next = nullptr;
		delete p;
	}
}



//Giai phong nho
void destroyList(LinkedList& l) {
	while (!isEmpty(l)) {
		delHead(l);
	}
}

int main() {
	LinkedList l;
	init(l);
	Term t1, t2, t3;
	t1.coef = 2;
	t1.exp = 1;
	insertOrdered(l, t1);
	t2.coef = 2;
	t2.exp = 2;
	insertOrdered(l, t2);
	t3.coef = 2;
	t3.exp = 3;
	insertOrdered(l, t3);
	printList(l);
	destroyList(l);
	
	return 0;
}