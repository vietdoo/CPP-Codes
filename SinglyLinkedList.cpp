#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

struct student {
	char * name;
	int id;
	float mark;
	student * Next;
};

struct linkedList {
	student * head;
	student * tail;
};

char *firstName[] = {"DO", "Pham", "Hoang", "Ho", "Nguyen", "Le"};
char *middleName[] = {"Xuan", "Ngoc", "Gia", "Anh", "Ngoc Xuan", "Anh", "Bao", "Thien", "Hai", "Kieu Thanh"};
char *lastName[] = {"Khanh", "Linh", "Phuong", "Minh", "Chau", "Giang", "Kim", "Thanh", "Binh", "Tu", "Duong", "Hien", "Khue", "Tue", "Tam", "Tien", "Tuyen"};

int x = sizeof(firstName)/8;
int y = sizeof(middleName)/8;
int z = sizeof(lastName)/8;
int k = 0;

char * randomName () {
	
	char * fN = *(firstName + (rand() % x));
	char * mN = *(middleName + (rand() % y));
	char * lN = *(lastName + (rand() % z));
	char name[100] = "";
	strcat(name, fN);
	strcat(name, " ");
	strcat(name, mN);
	strcat(name, " ");
	strcat(name, lN);
	char *fullName = new char[100];
	strcpy(fullName, name);
	return fullName;
}

student * createNode () {
	student * node = new student;
	cout << "Full Name : ";
	node->name = new char[100];
	char temp_name[100];
	if (k++ == 0) 
		cin.ignore(0);
	else
		cin.ignore();
	cin.getline(temp_name, 100);
	strcpy(node->name, temp_name);
	cout << "Student ID : ";
	cin >> node->id;
	cout << "Mark : ";
	cin >> node->mark;
	node->Next = NULL;
	return node;
}

void addHead(linkedList &l, student * node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	} else {
		node->Next = l.head;
		l.head = node;
	}
}

void addTail(linkedList &l, student * node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	} else {
		l.tail->Next = node;
		l.tail = node;
	}
}

void addAfterFirst (linkedList &l, student * node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	} else {
		node->Next = l.head->Next;
		l.head->Next = node;
	}
}

void addBeforeLast (linkedList &l, student * node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	} else {
		node->Next = l.tail;
		for (student * temp = l.head; temp != NULL; temp = temp->Next) {
			if (temp->Next == l.tail) {
				temp->Next = node;
				return;
			} 
		}
	}
}

void add5First (linkedList &l) {
	for (int i = 0; i < 5; i++) {
		student * node = new student;
		node->Next = NULL;
		node->name = randomName();
		node->mark = ((rand() % 80) + 20) * 1.0 / 10;
		node->id = rand() % 100 + 100;
		addHead(l, node);
	}
}

void add10First (linkedList &l) {
	for (int i = 0; i < 10; i++) {
		student * node = new student;
		node->Next = NULL;
		node->name = randomName();
		node->mark = ((rand() % 80) + 20) * 1.0 / 10;
		node->id = rand() % 100 + 100;
		addHead(l, node);
	}
}

void deleteFirst (linkedList & l) {
	if (l.head == l.tail) {
		l.head = NULL;
		l.tail = NULL;
	} else if (l.head != NULL) {
		l.head = l.head->Next;	
	} 
}

void deleteLast (linkedList & l) {
	if (l.head == l.tail) {
		l.head = NULL;
		l.tail = NULL;
	} else if (l.head != NULL) {
		for (student * node = l.head; node != NULL; node = node->Next) {
			if (node->Next == l.tail) {
				l.tail = node;
				l.tail->Next = NULL;
				return;
			} 
		}
	}
}

void deleteStudentByMark (linkedList & l, float target) {
	student * nodeA = l.head;
	for (student * node = l.head->Next; node != NULL; node = node->Next) {
		if (node->mark == target) {
			if (node == l.head)
				deleteFirst(l);
			else if (node == l.tail) {
				deleteLast(l);
			} 
			else {
				nodeA->Next = node->Next;
			}
		}
		nodeA = node;
	}
	if (l.head->mark == target)
		deleteFirst(l);
}

bool duplicateData(student * a, student * b) {
	if (strcmp(a->name, b->name) || a->id != b->id || a->mark != b->mark)
		return false;
	return true;
}


int getListSize(linkedList l) {
	int ans = 0;
	while (l.head != NULL) {
		l.head  = l.head->Next;
		ans++;
	}
	return ans;
}

void deleteDuplicateStudents(linkedList & l) {
	student * node1 = l.head;
	student * node3 = NULL;
	while (node1 != NULL) {
		node3 = node1;
		student * node2 = node1->Next;
		while (node2 != NULL) {
			if (duplicateData(node1, node2) == true) {
				if (node2 == l.head)
					deleteFirst(l);
				else if (node2 == l.tail) 
					deleteLast(l);
				else {
					node3->Next = node2->Next;
					node2 = node2->Next;
					break;
				}
			}
			else {
				node3 = node2;
				node2 = node2->Next;
			}
		}
		node1 = node1->Next;
	}
}


void swapData(student * a, student * b) {
	char * name = a->name;
	int id = a->id;
	float mark = a->mark;
	a->name = b->name;
	a->id = b->id;
	a->mark = b->mark;
	b->name = name;
	b->id = id;
	b->mark = mark;
}

void sortStudentList(linkedList & l) {
	for (student * node1 = l.head; node1 != NULL; node1 = node1->Next) {
		for (student * node2 = node1 ->Next; node2 != NULL; node2 = node2->Next) {
			if (node1->mark > node2->mark) 
				swapData(node1, node2);
		}
	}
}

void reverseStudentList (linkedList & l) {
	student * current = l.head;
	student * prev = NULL, *next = NULL;
	while (current != NULL) {
		next = current->Next;
		current->Next = prev;
		prev = current;
		current = next;
	}
	student * tmp = l.head;
	l.head = l.tail;
	l.tail = tmp;
}

void addToSortedList(linkedList &l, student * node) {
	if (l.head->mark >= node->mark) {
		addHead(l, node);
		return;
	}
	else if (l.tail->mark <= node->mark) {
		addTail(l, node);
		return;
	}
	for (student * tmp = l.head; tmp != NULL; tmp = tmp->Next) {
		if (tmp->mark <= node->mark && tmp->Next->mark >= node->mark) {
			node->Next = tmp->Next;
			tmp->Next = node;
			return;
		}
	}
}

void printSingleStudent (student * node) {
	cout << "Full Name : " << node->name;
	cout << "\nStudent ID : " << node->id;
	cout << "\nMark : " << node->mark << '\n';
}

void printStudentList (linkedList l) {
	student * node = l.head;
	int i = 0;
	while (node != NULL) {
		cout << ++i << ".\n";
		printSingleStudent(node);
		node = node->Next; 
	}
}

bool containsCycle (linkedList l) {
	int n = getListSize(l);
	int i = 0;
	for (student * tmp = l.head; tmp != NULL; tmp = tmp->Next) {
		i++;
		if (i > n * 2) 
			return true;
	}
	return false;
}

void addStudentByID (linkedList &l, student * node) {
	for (student * tmp = l.head; tmp != NULL; tmp = tmp->Next) {
		if (tmp->id == node->id)
			tmp->name = node->name;
			tmp->mark = node->mark;
			return;
	}
	addTail(l, node);
}

void createStartWithHList (linkedList l, linkedList & h) {
	for (student * tmp = l.head; tmp != NULL; tmp = tmp->Next) {
		if (tmp->name[0] == 'H') {
			student * node = new student;
			node->name = tmp->name;
			node->id = tmp->id;
			node->mark = tmp->mark;
			node->Next = NULL;
			addTail(h, node);
		}
	}
}

int main () {
	srand(time(0));	
	freopen("input.txt", "r", stdin);
	linkedList l;
	l.head = NULL;
	l.tail = NULL;
	addHead(l, createNode());
	addTail(l, createNode());
	addAfterFirst(l, createNode());
	addBeforeLast(l, createNode());
	add5First(l);
	deleteFirst(l);
	deleteLast(l);
	//cout << "\nInput Mark : ";
	float target;
	cin >> target;
	deleteStudentByMark(l, target);
	add10First(l);
	deleteDuplicateStudents(l);
	reverseStudentList(l);
	sortStudentList(l);
	addToSortedList(l, createNode());	
	if (containsCycle(l)) {
		cout << "This Linked List contains Cycle";
	} else {
		cout << "This Linked List not contains Cycle";
	}
	linkedList h;
	h.head = NULL;
	h.tail = NULL;
	createStartWithHList(l, h);
	printStudentList(h);
	addStudentByID(l, createNode());
	printStudentList(l);
	return 0;
}

