#include "Register.h"
#include <cstdlib>
#include <time.h>

ostream& operator<<(ostream& out, Register& reg) 
{
	//cout << "Register: turn -- " << reg.turn << endl;
	//cout << "Player 1 has probability " << reg.ProbtoWin1 << ";" << endl;
	//cout << "Player 2 has probability " << reg.ProbtoWin2 << ";" << endl;
	
	for (int i = 0; i < reg.Reg.Size(); i++)
	{
		cout << reg.Reg[i] << endl;
	}
	cout << endl;
	return out;
}

void Register::SetPosition(short int p)
{
	int n, tA, tB;
	cin >> n;
	List tmp;

	for (int j = 0; j < n; j++)
	{
		cin >> tA >> tB;
		for (int i = 0; i < Reg.Size(); i++)
		{
			Field tmp1 = Reg[i];
			if (tmp1.setposition(tA, tB, p)) //Дальше проходят только те поля, на которых ход возможен
			{
				
				tmp.AddtoTail(&tmp1);
			}
			else tmp.AddtoTail(&tmp1);
		}
	}

	Reg = tmp;
}

void Register::FindWin() 
{
	Wins[0] = 0;
	Wins[1] = 0;
	for (int i = 0; i < Reg.Size(); i++)
	{
		Reg[i].findwin(Wins);
	}
}

Field Register::deUndeterminize()
{
	Field det;
	int d;
	int A = 0, B = 0, C = 0;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			srand(time(NULL));
			for (int k = 0; k < Reg.Size(); k++)
			{
				if (Reg[k].Block[i][j] == 1)
					A++;
				if (Reg[k].Block[i][j] == 2)
					B++;
				else 
					C++;
			}

			if (A == Reg.Size()) det.Block[i][j] = 1;
			else if (B == Reg.Size()) det.Block[i][j] = 2;
			else if (C == Reg.Size()) det.Block[i][j] = 0;
			else
			{
				d = rand() % (Reg.Size());
				if (d < A)
					det.Block[i][j] = 1;
				else if (d >= A && d <= A + B)
					det.Block[i][j] = 2;
				else if (d > Reg.Size() - C &&  d <= Reg.Size())
					det.Block[i][j] = 0;
			}
			A = 0;
			B = 0;
			C = 0;
		}
	}
	return det;
}