#include "List.h"

List::Node::Node(Node* prev, Field item) {
	m_Data = item;
	Next = prev->Next;
	prev->Next = this;
	Prev = prev;
	Next->Prev = this;
}

List::Node::~Node() {
	if (Prev)
		Prev->Next = Next;
	if (Next)
		Next->Prev = Prev;
	Prev = nullptr;
	Next = nullptr;
}

ostream& operator<<(ostream& out, const List::Node& node) {
	return out << node.m_Data;
}

void List::Node::Swap(Node* obj) {
	if (Next == obj) {
		Prev->Next = obj;
		obj->Next->Prev = this;
		Next = obj->Next;
		obj->Prev = Prev;
		Prev = obj;
		obj->Next = this;
	}
	else {
		Prev->Next = obj;
		Next->Prev = obj;
		obj->Next->Prev = this;
		obj->Prev->Next = this;

		Node* tmp1 = Next;
		Node* tmp2 = Prev;
		Next = obj->Next;
		Prev = obj->Prev;

		obj->Next = tmp1;
		obj->Prev = tmp2;
	}
}