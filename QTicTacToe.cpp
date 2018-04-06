// QTicTacToe.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Register.h"

/*
Ввод -- число квантовых ходов, перечисление координат клеток, в которые будет совершён квантовый ход

Первый ход делает второй игрок.

Состояния поля хранятся в квантовом регистре (Register)

Ход делается для всех состояний поля.

Если в каком-то из состояний ход невозможен (клетка уже занята), тогда ход игнорируется. При этом состояние из регистра не удаляется.

Игра ведётся до заполнения всех клеток всех состояний, после чего победитель определяется по величине вероятности выиграть при снятии неопределённости.
*/

using namespace std;

int main()
{
	cout << "Welcome to the Quantum Tic Tac Toe!" << endl;
	bool HaveWinner = 0, drawn = 0;
	char Winner;
	int tricknum = 0;
	Register Game;
	
	while (!HaveWinner)
	{
		cout << "Turn: " << tricknum << endl;	
		cout << Game << endl;
		Game.FindWin();
	    if (Game.GetWins(0)) cout << "Probability of player 1 to win: " << Game.GetWins(0) << "/" << Game.Size() << endl;
		else cout << "Probability of player 1 to win: 0" << endl;
		if (Game.GetWins(1)) cout << "Probability of player 2 to win: " << Game.GetWins(1) << "/" << Game.Size() << endl;
		else cout << "Probability of player 2 to win: 0" << endl;

		if (tricknum%2)
		{
			Game.SetPosition(1);
		}
		else
		{
			Game.SetPosition(2);
		}

		cout << Game << endl;

		Field f = Game.deUndeterminize();
		int a[2];
		a[0] = 0;
		a[1] = 0;
		f.findwin(a);
		if (a[0] > 0)
		{
			//HaveWinner = 1;
			Winner = 1;
		}
		if (a[1] > 0)
		{
			//HaveWinner = 1;
			Winner = 2;
		}
		if (a[1] == 0 && a[2] == 0 && f.Empty() == 0)
			break;

		tricknum++;
	}

	
	if (Game.GetWins(0) >Game.GetWins(1)) cout << "Player 1 won";
	else cout << "Player 2 won";

    return 0;
}

