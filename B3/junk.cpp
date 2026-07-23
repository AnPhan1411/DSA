//addHead(l, 5);
	//addHead(l, 7);

printList(l);

cout << "==================TIM KIEM================\n";
Node* res = search(l, 47);

if (res != nullptr) {
	cout << "Ket qua: " << res->info << endl;
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
cout << getNodeAt(l, 2)->info << endl;

cout << "==================SAP XEP================\n";
sortList(l, cmpAsc);
printList(l);

cout << "==================THEM VAO DS CO THU TU================\n";
insertOrdered(l, 10);
printList(l);

destroyList(l);
/*printList(l);*/