#include "List.h"
#include <fstream>

void List::AddtoHead(Field* obj) {
	new Node(&Head, *obj);
	m_size++;
}

void List::AddtoTail(Field* obj) {
	new Node(Tail.Prev, *obj);
	m_size++;
}

bool List::Delete(const Field* obj) {
	Node* t = Head.Next;
	for (int i = 0; i < m_size; i++) {
		if (t->m_Data == *obj) {
			((t->Prev)->Next) = t->Next;
			((t->Next)->Prev) = t->Prev;
			delete t;
			m_size--;
			return true;
		}
		t = t->Next;
	}
	return false;
}

int List::DeleteAll(const Field* obj) {
	int c = 0;
	Node* t = Head.Next;
	Node* tmp = t;
	for (int i = 0; i < m_size; i++) {
		if (t->m_Data == *obj) {
			((t->Prev)->Next) = t->Next;
			((t->Next)->Prev) = t->Prev;
			tmp = t->Next;
			delete t;
			c++;
		}
		else tmp = t->Next;
		t = tmp;
	}
	m_size -= c;
	return c;
}

void List::Clear() {
	Node* t = Head.Next;
	Node* tmp = t;
	for (int i = 0; i < m_size; i++) {
		tmp = t->Next;
		delete t;
		t = tmp;
	}
	m_size = 0;
}

List::~List() {
	Clear();
}
/*
void List::Sort() {

	Node *tmp, *a;
	for (int i = m_size - 1; i >= 0; i--) {
		tmp = Head.Next;
		a = tmp->Next;
		for (int j = 0; j < i; j++) {
			if (&(tmp->m_Data) < tmp->Next->m_Data) {
				tmp->Swap(tmp->Next);
				Node* ttmp = tmp;
				tmp = a;
				a = ttmp;
			}
			tmp = tmp->Next;
			a = a->Next;
		}

	}

*/


	/*
	Node *tmp, *a;
	bool flag = 1;
	while (flag)
	{
	tmp = Head.Next;
	a = tmp->Next;
	flag = 0;
	while (a != &Tail)
	{
	if ((a->m_Data)<(tmp->m_Data))
	{
	tmp->Swap(a);
	flag = 1;
	Node* ttmp = tmp;
	tmp = a;
	a = ttmp;
	}


	tmp = tmp->Next;
	a = a->Next;
	}
	}
	*/

//}

void List::Outfile() {
	ofstream fout;
	fout.open("output.txt");
	fout << m_size << '\n';
	for (Node* t = Head.Next; t != &Tail; t = t->Next) {
		fout << *t << '\n';
	}
	fout.close();
}

ostream& operator<<(ostream& out, const List& list) {
	List::Node* t = list.Head.Next;
	cout << "List:" << '\n' << "Head: " << t->Prev << endl;
	for (int i = 0; i < list.m_size; i++) {
		cout << "Node: (" << t->Prev << ", " << t->Next << ") " << *t << endl;
		t = t->Next;
	}
	cout << "Tail: " << t << endl;
	return out << "";
}

List::List(const List& obj) {
	Head.Next = &Tail;
	Tail.Prev = &Head;
	m_size = 0;
	Node* t = obj.Tail.Prev;
	for (int i = 0; i < obj.m_size; i++) {
		AddtoHead(&t->m_Data);
		t = t->Prev;
	}
}

Field& List::operator[](const int i) {
	int e = 0;
	for (Node* t = Head.Next; t != &Tail; t = t->Next) {
		if (e == i) return t->m_Data;
		e++;
	}
}

List& List::operator=(const List& obj) {
	Clear();
	m_size = 0;
	Node* t = obj.Tail.Prev;
	for (int i = 0; i < obj.m_size; i++) {
		AddtoHead(&t->m_Data);
		t = t->Prev;
	}
	return *this;
}

void List::swap() {
	Node* t1 = Head.Next->Next;
	Node* t2 = t1->Next->Next->Next;
	t1->Swap(t2);
}

size_t List::Size() {
	return m_size;
}