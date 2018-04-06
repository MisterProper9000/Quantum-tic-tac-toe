#include "Field.h"
#include <tchar.h>
#define UNICODE
#define _UNICODE
#ifdef _UNICODE
typedef wchar_t TCHAR;
#endif
ostream& operator<< (ostream& out, const Field& item) 
{
	for (int i = 0; i < 3; i++)
	{

		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			cout << item.Block[i][j];
		}
		
		if (i == 0) printf_s("\\ ");
		if (i == 1)cout << " )";
		if (i == 2) cout << "/ ";
		cout << endl;
	}
	return out;
}	

void Field::findwin(int* wins)
{
	bool f1 = 1, f2 = 1, f3 = 1;
	bool p1 = 0, p2 = 0, p = 1;
	for (int i = 1; i < 3; i++)
	{
		if (Block[0][0] != Block[0][i]) f1 = 0;
		if (Block[1][0] != Block[1][i]) f2 = 0;
		if (Block[2][0] != Block[2][i]) f3 = 0;
	}
	if (f1)
	{
		if (Block[0][0] == 1) wins[0]++;
		if (Block[0][0] == 2) wins[1]++;
	}
	if (f2)
	{
		if (Block[1][0] == 1) wins[0]++;
		if (Block[1][0] == 2) wins[1]++;
	}
	if (f3)
	{
		if (Block[2][0] == 1) wins[0]++;
		if (Block[2][0] == 2) wins[1]++;
	}

	f1 = 1, f2 = 1, f3 = 1;
	for (int i = 1; i < 3; i++)
	{
		if (Block[0][0] != Block[i][0]) f1 = 0;
		if (Block[0][1] != Block[i][1]) f2 = 0;
		if (Block[0][2] != Block[i][2]) f3 = 0;
	}
	if (f1)
	{
		if (Block[0][0] == 1) wins[0]++;
		if (Block[0][0] == 2) wins[1]++;
	}
	if (f2)
	{
		if (Block[0][1] == 1) wins[0]++;
		if (Block[0][1] == 2) wins[1]++;
	}
	if (f3)
	{
		if (Block[0][2] == 1) wins[0]++;
		if (Block[0][2] == 2) wins[1]++;
	}

	f1 = 1, f2 = 1;
	for (int i = 1; i < 3; i++)
	{
		if (Block[0][0] != Block[i][i]) f1 = 0;
		if (Block[0][2] != Block[i][2 - i]) f2 = 0;
	}
	if (f1)
	{
		if (Block[0][0] == 1) wins[0]++;
		if (Block[0][0] == 2) wins[1]++;
	}
	if (f2)
	{
		if (Block[0][2] == 1) wins[0]++;
		if (Block[0][2] == 2) wins[1]++;
	}
}

bool Field::setposition(int a, int b, short int n)
{
	if (Block[a][b] == 0)
	{
		Block[a][b] = n;
		return true;
	}
	return false;
}

Field& Field::operator= (const Field& other) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Block[i][j] = other.Block[i][j];
		}
	}
	return *this;
}

int Field::Empty()
{
	int s = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Block[i][j] == 0) s++;
		}
	}
	return s;
}

bool Field::operator==(const Field& other)
{
	bool f = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Block[i][j] != other.Block[i][j]) f = 0;
		}
	}
	return f;
}