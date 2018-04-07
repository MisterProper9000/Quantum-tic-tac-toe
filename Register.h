#pragma once
#include "List.h"
#include <iostream>  
using namespace std;
//Квантовый регистр, содержит все состояния досок и вычисляет следующие состояния, устанавливает ходы и снимает неопределённость.

class Register {
	List Reg;  //Список состояний досок
	int turn;
	double ProbtoWin1;
	double ProbtoWin2;
	int Wins[2];
public:
	int Size() { return Reg.Size(); };
	Register() : Reg(), turn(0), ProbtoWin1(0), ProbtoWin2(0) 
	{
		Field f;
		Reg.AddtoTail(&f);
		Wins[0] = 0;
		Wins[1] = 0;
	}; //создаётся с одним пустым полем
	void SetPosition(short int p);  //установка хода(число разбиений, координаты клеток,...
	void FindWin();
	Field deUndeterminize();
	friend ostream& operator<<(ostream& out, Register& reg);
	int GetWins(int n)
	{
		return Wins[n];
	}

};