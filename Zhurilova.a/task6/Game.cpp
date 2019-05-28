#include "Game.hpp"
using namespace std;
Game::Game()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			MapLivePlayer[i][j] = 0;
			MapComputerPlayer[i][j] = 0;
			MapComputerForConsole[i][j] = 0;
			MapPlayerForConsole[i][j] = 0;
		}
	}
}
void Game::SetColor(int text, int bg)//Смена цвета
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
void Game::DrawCoordinateGame()//Рисовка координатного поля
{
	cout << endl;
	for (int z = 0; z < 12; z++)
	{
		cout << " ";
	}
	cout << "ВАШЕ ПОЛЕ";
	for (int z = 0; z < 28; z++)
	{
		cout << " ";
	}
	cout << "ПОЛЕ ПРОТИВНИКА";
	cout << endl;
	for (int z = 0; z < 69; z++)
	{
		cout << "_";
		if (z == 34)
		{
			cout << "     " << "_";
		}
	}
	cout << endl;
	cout << "  #  " << " 0 " << " 1 " << " 2 " << " 3 " << " 4 " << " 5 " << " 6 " << " 7 " << " 8 " << " 9 ";
	cout << "     " << "  #  " << " 0 " << " 1 " << " 2 " << " 3 " << " 4 " << " 5 " << " 6 " << " 7 " << " 8 " << " 9 " << endl;
	for (int z = 0; z < 69; z++)
	{
		cout << "_";
		if (z == 34)
		{
			cout << "     " << "_";
		}
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "| " << i << " " << "|";
		for (int j = 0; j < 10; j++)
		{
			if (MapPlayerForConsole[i][j] == 0)//Пустая клетка
			{
				SetColor(15, 0);
				cout << " " << MapPlayerForConsole[i][j] << " ";
			}
			if (MapPlayerForConsole[i][j] == 1)//Клетка корабля
			{
				SetColor(10, 0);
				cout << " " << MapPlayerForConsole[i][j] << " ";
			}
			if (MapPlayerForConsole[i][j] == (-1))//Ранен
			{
				SetColor(14, 0);
				cout << MapPlayerForConsole[i][j] << " ";
			}
			if (MapPlayerForConsole[i][j] == (-2))//Убит
			{
				SetColor(12, 0);
				cout << MapPlayerForConsole[i][j] << " ";
			}
			if (MapPlayerForConsole[i][j] == 8)
			{
				SetColor(5, 0);
				cout << " " << MapPlayerForConsole[i][j] << " ";
			}
			SetColor(15, 0);
		}
		cout << "     ";
		cout << "| " << i << " " << "|";
		for (int j = 0; j < 10; j++)
		{
			if (MapComputerForConsole[i][j] == 0)//Пустая клетка
			{
				SetColor(15, 0);
				cout << " " << MapComputerForConsole[i][j] << " ";
			}
			if (MapComputerForConsole[i][j] == 1)//Клетка корабля
			{
				SetColor(10, 0);
				cout << " " << MapComputerForConsole[i][j] << " ";
			}
			if (MapComputerForConsole[i][j] == (-1))//Ранен
			{
				SetColor(14, 0);
				cout << MapComputerForConsole[i][j] << " ";
			}
			if (MapComputerForConsole[i][j] == (-2))//Убит
			{
				SetColor(12, 0);
				cout << MapComputerForConsole[i][j] << " ";
			}
			if (MapComputerForConsole[i][j] == 8)
			{
				SetColor(5, 0);
				cout << " " << MapComputerForConsole[i][j] << " ";
			}
			SetColor(15, 0);
		}
		cout << endl;
	}
	cout << endl;
}
bool Game::TestMapPoz(int x, int y)
{
	if (((x > (-1)) && (x < 10)) && ((y > (-1)) && (y < 10)))
	{
		return true;
	}
	return false;
}
void Game::SetElementMap(int x, int y, int z, int WhatMap)
{
	if (WhatMap == 1)
	{
		MapComputerPlayer[x][y] = z;
	}
	if (WhatMap == 2)
	{
		MapLivePlayer[x][y] = z;
	}
}
void Game::SetOkr(int x, int y, int val, int WhatMap)
{
	if (WhatMap == 1)
	{
		if ((TestMapPoz(x, y) == true) && (MapComputerPlayer[x][y] == 0))
		{
			SetElementMap(x, y, val, WhatMap);
		}
	}
	if (WhatMap == 2)
	{
		if ((TestMapPoz(x, y) == true) && (MapLivePlayer[x][y] == 0))
		{
			SetElementMap(x, y, val, WhatMap);
		}
	}
}
void Game::SetOkrShip(int x, int y, int val, int WhatMap)
{
	SetOkr(x - 1, y - 1, val, WhatMap);
	SetOkr(x - 1, y, val, WhatMap);
	SetOkr(x - 1, y + 1, val, WhatMap);
	SetOkr(x, y + 1, val, WhatMap);
	SetOkr(x + 1, y + 1, val, WhatMap);
	SetOkr(x + 1, y, val, WhatMap);
	SetOkr(x + 1, y - 1, val, WhatMap);
	SetOkr(x, y - 1, val, WhatMap);
}
void Game::OkrEnd(int WhatMap)
{
	if (WhatMap == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (MapComputerPlayer[i][j] == (-2))
				{
					MapComputerPlayer[i][j] = -1;
				}
			}
		}
	}
	if (WhatMap == 2)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (MapLivePlayer[i][j] == (-2))
				{
					MapLivePlayer[i][j] = -1;
				}
			}
		}
	}
}
bool Game::NewPaluba(int x, int y, int Map[10][10])
{
	if (TestMapPoz(x, y) == false)
	{
		return false;
	}
	if ((Map[x][y] == 0) || (Map[x][y] == -2))
	{
		return true;
	}
	return false;
}
void Game::MakeDeckShip(int KolPaluba)
{
	while (true)
	{
		bool Proverka = false;
		int x = 0, y = 0, napr;
		x = rand() % 10;
		y = rand() % 10;
		napr = rand() % 4;
		if (NewPaluba(x, y, MapComputerPlayer) == true)
		{
			if (napr == 0)//вверх
			{
				if (NewPaluba(x - (KolPaluba - 1), y, MapComputerPlayer) == true)
				{
					Proverka = true;
				}
			}
			else if (napr == 1)//вправо
			{
				if (NewPaluba(x, y + (KolPaluba - 1), MapComputerPlayer) == true)
				{
					Proverka = true;
				}
			}
			else if (napr == 2)//вниз
			{
				if (NewPaluba(x + (KolPaluba - 1), y, MapComputerPlayer) == true)
				{
					Proverka = true;
				}
			}
			else if (napr == 3)//влево
			{
				if (NewPaluba(x, y + (KolPaluba - 1), MapComputerPlayer) == true)
				{
					Proverka = true;
				}
			}
		}
		if (Proverka == true)
		{
			MapComputerPlayer[x][y] = KolPaluba;
			SetOkrShip(x, y, -2, 1);
			if (napr == 0)//вверх
			{
				for (int i = (KolPaluba - 1); i > 0; i--)
				{
					MapComputerPlayer[x - i][y] = KolPaluba;
					SetOkrShip(x - i, y, -2, 1);
				}
			}
			if (napr == 1)//вправо
			{
				for (int i = (KolPaluba - 1); i > 0; i--)
				{
					MapComputerPlayer[x][y + i] = KolPaluba;
					SetOkrShip(x, y + i, -2, 1);
				}
			}
			if (napr == 2)//вниз
			{
				for (int i = (KolPaluba - 1); i > 0; i--)
				{
					MapComputerPlayer[x + i][y] = KolPaluba;
					SetOkrShip(x + i, y, -2, 1);
				}
			}
			if (napr == 3)//вправо
			{
				for (int i = (KolPaluba - 1); i > 0; i--)
				{
					MapComputerPlayer[x][y - i] = KolPaluba;
					SetOkrShip(x, y - i, -2, 1);
				}
			}
			break;
		}
	}
	OkrEnd(1);

}
void Game::MakeOneDeckShip()
{
	int x, y;
	for (int i = 0; i < 4; i++)
	{
		while (true)
		{
			x = rand() % 10;
			y = rand() % 10;
			if (MapComputerPlayer[x][y] == 0)
			{
				MapComputerPlayer[x][y] = 1;
				SetOkrShip(x, y, -1, 1);
				break;
			}
		}
	}
}
void Game::CompareMapPlayer()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((MapLivePlayer[i][j] == 1) || (MapLivePlayer[i][j] == 2) || (MapLivePlayer[i][j] == 3) || (MapLivePlayer[i][j] == 4))
			{
				MapPlayerForConsole[i][j] = 1;
			}
			if ((MapLivePlayer[i][j] == 6) || (MapLivePlayer[i][j] == 7))
			{
				MapPlayerForConsole[i][j] = 8;
			}
			if ((MapLivePlayer[i][j] > 7) && (MapLivePlayer[i][j] < 12))
			{
				MapPlayerForConsole[i][j] = -1;
			}
			if ((MapLivePlayer[i][j] > 15) && (MapLivePlayer[i][j] < 19))
			{
				MapPlayerForConsole[i][j] = -2;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((MapComputerPlayer[i][j] == 6) || (MapComputerPlayer[i][j] == 7))
			{
				MapComputerForConsole[i][j] = 8;
			}
			if ((MapComputerPlayer[i][j] > 7) && (MapComputerPlayer[i][j] < 12))
			{
				MapComputerForConsole[i][j] = -1;
			}
			if ((MapComputerPlayer[i][j] > 15) && (MapComputerPlayer[i][j] < 19))
			{
				MapComputerForConsole[i][j] = -2;
			}
		}
	}
}
bool Game::InstallationOfTheShip(int x, int y, int napr, int KolPaluba)
{
	bool Proverka = false;
	bool Result = false;//Удалось ли поставить корабль
	if (NewPaluba(x, y, MapLivePlayer) == true)
	{
		if (napr == 0)//вверх
		{
			if (NewPaluba(x - (KolPaluba - 1), y, MapLivePlayer) == true)
			{
				Proverka = true;
			}
		}
		else if (napr == 1)//вправо
		{
			if (NewPaluba(x, y + (KolPaluba - 1), MapLivePlayer) == true)
			{
				Proverka = true;
			}
		}
		else if (napr == 2)//вниз
		{
			if (NewPaluba(x + (KolPaluba - 1), y, MapLivePlayer) == true)
			{
				Proverka = true;
			}
		}
		else if (napr == 3)//влево
		{
			if (NewPaluba(x, y + (KolPaluba - 1), MapLivePlayer) == true)
			{
				Proverka = true;
			}
		}
	}
	if (Proverka == true)
	{
		MapLivePlayer[x][y] = KolPaluba;
		SetOkrShip(x, y, -2, 2);
		if (napr == 0)//вверх
		{
			for (int i = (KolPaluba - 1); i > 0; i--)
			{
				MapLivePlayer[x - i][y] = KolPaluba;
				SetOkrShip(x - i, y, -2, 2);
			}
		}
		if (napr == 1)//вправо
		{
			for (int i = (KolPaluba - 1); i > 0; i--)
			{
				MapLivePlayer[x][y + i] = KolPaluba;
				SetOkrShip(x, y + i, -2, 2);
			}
		}
		if (napr == 2)//вниз
		{
			for (int i = (KolPaluba - 1); i > 0; i--)
			{
				MapLivePlayer[x + i][y] = KolPaluba;
				SetOkrShip(x + i, y, -2, 2);
			}
		}
		if (napr == 3)//вправо
		{
			for (int i = (KolPaluba - 1); i > 0; i--)
			{
				MapLivePlayer[x][y - i] = KolPaluba;
				SetOkrShip(x, y - i, -2, 2);
			}
		}
		OkrEnd(2);
		Result = true;
	}
	return Result;
}
bool Game::InstallationOfTheShipOneDeck(int x, int y)
{
	bool Result = false;
	if (MapLivePlayer[x][y] == 0)
	{
		MapLivePlayer[x][y] = 1;
		SetOkrShip(x, y, -1, 2);
		Result = true;
	}
	return Result;
}
int Game::TestEndGame()
{
	int SignOfVictory = 330;
	int KolComp = 0;
	int KolPlay = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (MapLivePlayer[i][j] > 14)
				KolPlay = KolPlay + MapLivePlayer[i][j];
			if (MapComputerPlayer[i][j] > 14)
				KolComp = KolComp + MapComputerPlayer[i][j];
		}
	}
	if (KolPlay == SignOfVictory)
	{
		return 1;
	}
	else if (KolComp == SignOfVictory)
	{
		return 2;
	}
}
void Game::SetOkrPodbit(int x, int y, int WhatMap)
{
	if (TestMapPoz(x, y) == true)
	{
		if (WhatMap == 1)
		{
			if ((MapComputerPlayer[x][y] == -1) || (MapComputerPlayer[x][y] == 6))
			{
				MapComputerPlayer[x][y]--;
			}
		}
		if (WhatMap == 2)
		{
			if ((MapLivePlayer[x][y] == -1) || (MapLivePlayer[x][y] == 6))
			{
				MapLivePlayer[x][y]--;
			}
		}
	}
}
void Game::SetOkrShipPodbit(int x, int y, int WhatMap)
{
	SetOkrPodbit(x - 1, y - 1, WhatMap);
	SetOkrPodbit(x - 1, y, WhatMap);
	SetOkrPodbit(x - 1, y + 1, WhatMap);
	SetOkrPodbit(x, y + 1, WhatMap);
	SetOkrPodbit(x + 1, y + 1, WhatMap);
	SetOkrPodbit(x + 1, y, WhatMap);
	SetOkrPodbit(x + 1, y - 1, WhatMap);
	SetOkrPodbit(x, y - 1, WhatMap);
}
void Game::AnalizUbit(int x, int y, int KolPalub, int WhatMap)
{
	if (WhatMap == 1)
	{
		int KolRanen = 0;
		for (int i = x - (KolPalub - 1); i < x + KolPalub; i++)
		{
			for (int j = y - (KolPalub - 1); j < y + KolPalub; j++)
			{
				if ((TestMapPoz(i, j) == true) && (MapComputerPlayer[i][j] == (KolPalub + 7)))
				{
					KolRanen++;
				}
			}
		}
		if (KolRanen == KolPalub)
		{
			for (int i = x - (KolPalub - 1); i < x + KolPalub; i++)
			{
				for (int j = y - (KolPalub - 1); j < y + KolPalub; j++)
				{
					if ((TestMapPoz(i, j) == true) && (MapComputerPlayer[i][j] == (KolPalub + 7)))
					{
						MapComputerPlayer[i][j] = MapComputerPlayer[i][j] + 7;
						SetOkrShipPodbit(i, j, 1);
					}
				}
			}
		}
	}
	if (WhatMap == 2)
	{
		int KolRanen = 0;
		for (int i = x - (KolPalub - 1); i < x + KolPalub; i++)
		{
			for (int j = y - (KolPalub - 1); j < y + KolPalub; j++)
			{
				if ((TestMapPoz(i, j) == true) && (MapLivePlayer[i][j] == (KolPalub + 7)))
				{
					KolRanen++;
				}
			}
		}
		if (KolRanen == KolPalub)
		{
			for (int i = x - (KolPalub - 1); i < x + KolPalub; i++)
			{
				for (int j = y - (KolPalub - 1); j < y + KolPalub; j++)
				{
					if ((TestMapPoz(i, j) == true) && (MapLivePlayer[i][j] == (KolPalub + 7)))
					{
						MapLivePlayer[i][j] = MapLivePlayer[i][j] + 7;
						SetOkrShipPodbit(i, j, 2);
					}
				}
			}
		}
	}
}
void Game::TestUbit(int x, int y, int WhatMap)
{
	if (WhatMap == 1)
	{
		if (MapComputerPlayer[x][y] == 8)
		{
			MapComputerPlayer[x][y] = MapComputerPlayer[x][y] + 7;
			SetOkrShipPodbit(x, y, 1);
		}
		else if (MapComputerPlayer[x][y] == 9)
		{
			AnalizUbit(x, y, 2, 1);
		}
		else if (MapComputerPlayer[x][y] == 10)
		{
			AnalizUbit(x, y, 3, 1);
		}
		else if (MapComputerPlayer[x][y] == 11)
		{
			AnalizUbit(x, y, 4, 1);
		}
	}
	if (WhatMap == 2)
	{
		if (MapLivePlayer[x][y] == 8)
		{
			MapLivePlayer[x][y] = MapLivePlayer[x][y] + 7;
			SetOkrShipPodbit(x, y, 1);
		}
		else if (MapLivePlayer[x][y] == 9)
		{
			AnalizUbit(x, y, 2, 1);
		}
		else if (MapLivePlayer[x][y] == 10)
		{
			AnalizUbit(x, y, 3, 1);
		}
		else if (MapLivePlayer[x][y] == 11)
		{
			AnalizUbit(x, y, 4, 1);
		}
	}
}
bool Game::CompHod()
{
	bool Result = false;
	bool exit = false;
	bool Popal = false;
	int x;
	int y;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((MapLivePlayer[i][j] > 8) && (MapLivePlayer[i][j] < 12))
			{
				Popal = true;
				if ((TestMapPoz(i - 1, j) == true) && (MapLivePlayer[i - 1][j] < 5) && (MapLivePlayer[i - 1][j] != -2))
				{
					MapLivePlayer[i - 1][j] = MapLivePlayer[i - 1][j] + 7;
					TestUbit(i - 1, j, 2);
					if (MapLivePlayer[i - 1][j] > 7)
					{
						Result = true;
					}
					exit = true;
				}
				if ((TestMapPoz(i + 1, j) == true) && (MapLivePlayer[i + 1][j] < 5) && (MapLivePlayer[i + 1][j] != -2))
				{
					MapLivePlayer[i + 1][j] = MapLivePlayer[i + 1][j] + 7;
					TestUbit(i + 1, j, 2);
					if (MapLivePlayer[i + 1][j] > 7)
					{
						Result = true;
					}
					exit = true;
				}
				if ((TestMapPoz(i, j - 1) == true) && (MapLivePlayer[i][j - 1] < 5) && (MapLivePlayer[i][j - 1] != -2))
				{
					MapLivePlayer[i][j - 1] = MapLivePlayer[i][j - 1] + 7;
					TestUbit(i, j - 1, 2);
					if (MapLivePlayer[i][j - 1] > 7)
					{
						Result = true;
					}
					exit = true;
				}
				if ((TestMapPoz(i, j + 1) == true) && (MapLivePlayer[i][j + 1] < 5) && (MapLivePlayer[i][j + 1] != -2))
				{
					MapLivePlayer[i][j + 1] = MapLivePlayer[i][j + 1] + 7;
					TestUbit(i, j + 1, 2);
					if (MapLivePlayer[i][j + 1] > 7)
					{
						Result = true;
					}
					exit = true;
				}
			}
			if (exit == true) break;
		}
		if (exit == true) break;
	}
	exit = false;
	if (Popal == false)
	{
		for (int i = 0; i < 10; i++)
		{
			x = rand() % 10;
			y = rand() % 10;
			if ((MapLivePlayer[x][y] < 5) && (MapLivePlayer[x][y] != -2))
			{
				MapLivePlayer[x][y] = MapLivePlayer[x][y] + 7;
				TestUbit(x, y, 2);
				if (MapLivePlayer[x][y] > 7)
				{
					Result = true;
				}
				Popal = true;
				break;
			}
		}
		if (Popal == false)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if ((MapLivePlayer[x][y] < 5) && (MapLivePlayer[x][y] != -2))
					{
						MapLivePlayer[x][y] = MapLivePlayer[x][y] + 7;
						TestUbit(i, j, 2);
						if (MapLivePlayer[x][y] > 7)
						{
							Result = true;
						}
						exit = true;
					}
					if (exit == true) break;
				}
				if (exit == true) break;
			}
		}
	}
	return Result;
}
bool Game::LiveHod(int x, int y)
{
	bool NextStep = false;
	MapComputerPlayer[x][y] = MapComputerPlayer[x][y] + 7;
	TestUbit(x, y, 1);
	if (MapComputerPlayer[x][y] < 8)
	{
		NextStep = true;
	}
	return NextStep;
}