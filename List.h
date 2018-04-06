#pragma once
#include "Field.h"
#include <iostream>  
using namespace std;

class List {
	
	class Node {
		Node* Prev;
		Node* Next;
		Field m_Data;
		Node() :m_Data() { Prev = Next = nullptr; };
		Node(Node* prev, Field item);
		~Node();
		void Swap(Node* obj);
		friend class List;
		friend ostream& operator<<(ostream& out, const Node& node);
		friend ostream& operator<<(ostream& out, const List& list);
	};

	Node Head;
	Node Tail;
	size_t m_size;
public:
	List() {
		Head.Next = &Tail;
		Tail.Prev = &Head;
		m_size = 0;
	};
	void AddtoHead(Field* obj);
	void AddtoTail(Field* obj);
	bool Delete(const Field* obj);
	int DeleteAll(const Field* obj);
	void Clear();
	~List();
	void Sort();
	void Infile();
	void Outfile();
	List(const List& obj);
	friend ostream& operator<<(ostream& out, const List& list);
	friend ostream& operator<<(ostream& out, const Node& node);
	friend void MergeSort(List* a, size_t m);
	Field &operator[](const int i);
	List& operator=(const List& obj);
	void swap();
	size_t Size();

	friend class Register;
	
};