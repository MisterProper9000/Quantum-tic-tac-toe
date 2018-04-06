#pragma once
#include <iostream>
using namespace std;

//Обычное поле для крестиков-ноликов

class Field {
	short int Block[3][3];
	
public:
	Field() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Block[i][j] = 0;
			}
		}
	};
	void findwin(int* wins);
	bool setposition(int a, int b, short int n);
	friend ostream& operator<< (ostream& out, const Field& item);  //вывод одной доски
	Field& operator= (const Field& other);
	friend class Register;
	int Empty();
	bool operator==(const Field& other);
};