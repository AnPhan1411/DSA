#include <iostream>
using namespace std;
struct Node
{
	int inf;
	Node *next;
};
struct linkedList
{
	Node *head;
};
void init(linkedList &l)
{
	l.head = nullptr;
}
Node *createNode(int x)
{						  // la kieu du lieu tu dinh nghia
	Node *p = new Node(); // khoi tao 1 con tro rong
	p->inf = x;
	p->next = nullptr;
	return p; // tra ve vi tri x
}

bool isEmpty(linkedList l)
{
	return l.head == nullptr;
}
void printList(linkedList l)
{
	if (isEmpty(l))
	{
		cout << "Danh sach rong\n";
		return;
	}
	Node *p = l.head;
	while (p != nullptr)
	{
		cout << p->inf << "\t";
		p = p->next;
	}
	cout << "\n";
}
// tao mot kieu du lieu tim kiem
Node *search(linkedList l, int key)
{
	Node *p = l.head;
	while (p != nullptr)
	{
		if (p->inf == key)
			return p;
		p = p->next;
	}
	return nullptr;
}
// chen vao truoc
void insertBefore(linkedList &l, int x, int key)
{
	Node *q = l.head;
	Node *pre = nullptr;
	while (q != nullptr && q->inf != key)
	{
		pre = q;
		q = q->next;
	}
	if (q == nullptr)
		return;
	Node *p = createNode(x);
	p->next = q;
	if (pre == nullptr)
	{
		l.head = p;
	}
	else
	{
		pre->next = p;
	}
}
// chen sau danh sach
void insertAfter(linkedList l, int value, int key)
{
	Node *q = search(l, key);
	if (q != nullptr)
	{
		Node *p = createNode(value);
		p->next = q->next;
		q->next = p;
	}
}
// them dau danh sach
void addHead(linkedList &l, int x)
{
	Node *p = createNode(x); // tao mot con tro x moi
	p->next = l.head;
	l.head = p;
}
// xoa phan tu dau danh sach
void delHead(linkedList &l)
{
	if (!isEmpty(l))
	{
		Node *p = l.head;
		l.head = l.head->next;
		p->next = nullptr;
		delete p;
	}
}
// them vao cuoi danh sach
void addTail(linkedList &l, int x)
{
	Node *p = createNode(x);
	if (!isEmpty(l))
	{
		l.head = p;
	}
	else
	{

		Node *q = l.head;
		while (q->next != nullptr)
		{
			q = q->next;
		}
		q->next = p;
	}
}
// xoa phan tu cuoi danh sach
void delTail(linkedList &l)
{
	if (isEmpty(l))
	{
		return;
	}
	Node *q = l.head;
	Node *pre = nullptr;
	while (q->next != nullptr)
	{
		pre = q;
		q = q->next;
	}
	if (pre != nullptr)
	{
		pre->next = nullptr;
	}
	else
	{
		l.head = nullptr;
		delete q;
	}
}
void insertOrdered(linkedList &l, int x) // chèn phần tử vào danh sách liên kết sao cho danh sách vẫn giữ đúng thứ tự, tương tự như thuật toán insertion sort
{
	if (isEmpty(l) || x < l.head->inf)
	{
		addHead(l, x);
		return;
	}
	Node *p = createNode(x);
	Node *q = l.head;
	while (q->next != nullptr && x > q->next->inf)
	{
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
}
// tác dụng bổ trợ cho hàm sortlist, được xem như luật lệ của sortlist, được dùng khi cần thay đổi tính năng sắp xếp chỉ cần thay đổi cmpAsc
int cmpAsc(Node *a, Node *b)
{
	return a->inf - b->inf;
}
// sap xep theo interchange sort
void sortList(linkedList l, int func(Node *, Node *))
{
	if (!isEmpty)
	{
		for (Node *i = l.head; i->next != nullptr; i->next)
		{
			for (Node *j = i->next; j != nullptr; j->next)
			{
				if (func(j, i) < 0)
				{
					swap(i->inf, j->inf);
				}
			}
		}
	}
}
// truy xuat phan tu
Node *getNodeAt(linkedList l, int index)

{
	if (isEmpty(l) || index < 0)
	{
		return nullptr;
	}
	
		Node *q = l.head;
		int i = 0;
		while (q != nullptr && i < index)
		{

			q = q->next;
			i++;
		}

		return q;
	
}

// thêm phần tử vào danh sách có thứ tự
// xoa con tro
void clear(Node *&head)
{
	while (head != nullptr)
	{
		delete (head);
	}
}
void destroy(linkedList l)
{
	while (!isEmpty(l))
	{
		delHead(l);
	}
}
int main()
{
linkedList l;
	init(l);

	addHead(l, 5);
	addHead(l, 7);

	printList(l);

	cout << "==================TIM KIEM================\n";
	Node* res = search(l, 47);

	if (res != nullptr) {
		cout << "Ket qua: " << res->inf<< endl;
	}
	else
		cout << "Khong tim thay!\n";

	cout << "==================THEM SAU================\n";
	insertAfter(l, 6, 7);
	printList(l);

	cout << "==================THEM CUOI================\n";
	addTail(l, 10);
	printList(l);

	cout << "==================XOA CUOI================\n";
	delTail(l);
	printList(l);

	cout << "==================THEM TRUOC================\n";
	insertBefore(l, 2, 6);
	printList(l);

	cout << "==================TRUY XUAT================\n";
	cout << getNodeAt(l, 2)->inf << endl;

	cout << "==================SAP XEP================\n";
	sortList(l, cmpAsc);
	printList(l);

	cout << "==================THEM VAO DS CO THU TU================\n";
	insertOrdered(l, 10);
	printList(l);

	destroy(l);
	
	return 0;
}