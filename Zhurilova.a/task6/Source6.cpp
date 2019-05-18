#define _CRT_SECURE_NO_WARNINGS
#include<locale.h>
#include <stdio.h>
#include <Windows.h>
#include<string>
#include <iostream>
#include <cmath>
using namespace std;
class Coordinate //Класс координат поля
{
private:
	int x;
	int y;
public:
	Coordinate(int _x=0, int _y=0)//Конструктор
	{
		x = _x;
		y = _y;
	}
	void SetCoordinate(int _x, int _y)//Сменить координаты
	{
		x = _x;
		y = _y;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	Coordinate& operator=(const Coordinate &_XY)//Оператор присваивания
	{
		x = _XY.x;
		y = _XY.y;
		return *this;
	}
	friend std::ostream& operator<< (std::ostream &out, const Coordinate &C);
};
std::ostream& operator<< (std::ostream &out, const Coordinate &C)
{
	out << "(" <<C.x <<","<< C.y <<")";
	return out;
}
class OneDeckShip//Однопалубный корабль
{
private:
	Coordinate cship;//Координата
	bool StatusOfShip;//Состояние корабля "жив" или мёртв"
public:
	OneDeckShip()//Конструктор
	{
		StatusOfShip = true;
	}
	void SetCoordinate(Coordinate _ship)//Установить координаты корабля
	{
		cship=_ship;
	}
	Coordinate GetBegin()
	{
		return cship;
	}
	void ChangeStatusOfShip()//Сменить статус корабля на "мёртв"
	{
		StatusOfShip = false;
	}
	bool GetStatusOfShip()
	{
		return StatusOfShip;
	}
};
class TwoDeckShip//Двухпалубный корабль
{
private:
	Coordinate cship1;//Координата начала корабля
	Coordinate cship2;//Координата конаца корабля
	int KolHitTheShip;//Количество попаданий в корабль
	bool StatusOfShip;//Состояние корабля
public:
	TwoDeckShip()//Конструктор
	{
		KolHitTheShip = 0;
		StatusOfShip = true;
	}
	void SetCoordinate(Coordinate _begin, Coordinate _end)//Установить координаты  корабля
	{
		cship1= _begin;
		cship2= _end;
	}
	Coordinate GetBegin()
	{
		return cship1;
	}
	Coordinate GetEnd()
	{
		return cship2;
	}
	void AddHitTheShip()//Увеличить количество попаданий
	{
		if (KolHitTheShip != 2)
		{
			KolHitTheShip++;
		}
		if (KolHitTheShip == 2)//Если достигнуто max число попаданий
		{
			StatusOfShip = false;
		}		
	}
	bool GetStatusOfShip()//Вернуть состояние корабля
	{
		return StatusOfShip;
	}
};
class ThreeDeckShip //Трёхпалубный корабль
{
private:
	Coordinate cshipBegin;//Координата начала корабля
	Coordinate cshipEnd;//Координата конаца корабля
	int KolHitTheShip;//Количество попаданий в корабль
	bool StatusOfShip;//Состояние корабля
public:
	ThreeDeckShip()//Конструктор
	{
		KolHitTheShip = 0;
		StatusOfShip = true;
	}
	void SetCoordinate(Coordinate _begin, Coordinate _end)//Установить координаты  корабля
	{
		cshipBegin=_begin;
		cshipEnd=_end;
	}
	Coordinate GetBegin()
	{
		return cshipBegin;
	}
	Coordinate GetEnd()
	{
		return cshipEnd;
	}
	void AddHitTheShip()//Увеличить количество попаданий
	{
		if (KolHitTheShip != 3)
		{
			KolHitTheShip++;
		}
		if (KolHitTheShip == 3)//Если достигнуто max число попаданий
		{
			StatusOfShip = false;
		}
	}
	bool GetStatusOfShip()//Вернуть состояние корабля
	{
		return StatusOfShip;
	}
};
class FourDeckShip//Четырёхпалубный корабль
{
private:
	Coordinate cshipBegin;//Координата начала корабля
	Coordinate cshipEnd;//Координата конаца корабля
	int KolHitTheShip;//Количество попаданий в корабль
	bool StatusOfShip;//Состояние корабля
public:
	FourDeckShip()//Конструктор
	{
		KolHitTheShip = 0;
		StatusOfShip = true;
	}
	void SetCoordinate(Coordinate _begin, Coordinate _end)//Установить координаты  корабля
	{
		cshipBegin= _begin;
		cshipEnd=_end;
	}
	Coordinate GetBegin()
	{
		return cshipBegin;
	}
	Coordinate GetEnd()
	{
		return cshipEnd;
	}
	void AddHitTheShip()//Увеличить количество попаданий
	{
		if (KolHitTheShip != 4)
		{
			KolHitTheShip++;
		}
		if (KolHitTheShip == 4)//Если достигнуто max число попаданий
		{
			StatusOfShip = false;
		}
	}
	bool GetStatusOfShip()//Вернуть состояние корабля
	{
		return StatusOfShip;
	}
};
void SetColor(int text, int bg)//Смена цвета
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
void DrawCoordinateGame(int CoordinateP[10][10], int CoordinateC[10][10])//Рисовка координатного поля
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
			if (CoordinateP[i][j] == 0)//Пустая клетка
			{
				SetColor(15, 0);
				cout << " " << CoordinateP[i][j] << " ";
			}
			if (CoordinateP[i][j] == 1)//Клетка корабля
			{
				SetColor(10, 0);
				cout << " " << CoordinateP[i][j] << " ";
			}
			if (CoordinateP[i][j] == -1)//Ранен
			{
				SetColor(14, 0);
				cout << CoordinateP[i][j] << " ";
			}
			if (CoordinateP[i][j] == -2)//Убит
			{
				SetColor(12, 0);
				cout << CoordinateP[i][j] << " ";
			}
			SetColor(15, 0);
		}	
		cout << "     ";
		cout << "| " << i << " " << "|";
		for (int j = 0; j < 10; j++)
		{
			if (CoordinateC[i][j] == 0)//Пустая клетка
			{
				SetColor(15, 0);
				cout << " " << CoordinateC[i][j] << " ";
			}
			if (CoordinateC[i][j] == 1)//Клетка корабля
			{
				SetColor(10, 0);
				cout << " " << CoordinateC[i][j] << " ";
			}
			if (CoordinateC[i][j] == -1)//Ранен
			{
				SetColor(14, 0);
				cout << CoordinateC[i][j] << " ";
			}
			if (CoordinateC[i][j] == -2)//Убит
			{
				SetColor(12, 0);
				cout << CoordinateC[i][j] << " ";
			}
			SetColor(15, 0);
		}
		cout << endl;
	}
	cout << endl;
}
void ProverkaVvodaFour(int &_x4B, int & _y4B, int &_x4E, int &_y4E)//Проверка ввода четырёхпалубного корабля
{
		while (((_x4B != _x4E) && (_y4B != _y4E)) || ((abs(_x4B - _x4E) != 3) && (_y4B == _y4E)) || (abs(_y4B - _y4E) != 3) && (_x4B == _x4E))
		{
			cout << "Координаты введены неверно! Попробуйте ещё раз" << endl;
			cin >> _x4B >> _y4B >> _x4E >> _y4E;
			cout << endl;
		}
		while (((_x4B < 0) || (_x4B > 9)) || ((_x4E < 0) || (_x4E > 9)) || ((_y4B < 0) || (_y4B > 9)) || ((_y4E < 0) || (_y4E > 9)))
		{
			cout << "Координаты выходят за диапозон значений! Попробуйте ещё раз" << endl;
			cin >> _x4B >> _y4B >> _x4E >> _y4E;
			cout << endl;
		}
}
void ProverkaVvodaThree(int &_x3B, int &_y3B, int  &_x3E, int &_y3E)//Проверка ввода трёхпалубного корабля
{
		while (((_x3B != _x3E) && (_y3B != _y3E)) || ((abs(_x3B - _x3E) != 2) && (_y3B == _y3E)) || (abs(_y3B - _y3E) != 2) && (_x3B == _x3E))
		{
			cout << "Координаты введены неверно! Попробуйте ещё раз" << endl;
			cin >> _x3B >> _y3B >> _x3E >> _y3E;
			cout << endl;
		}
		while (((_x3B < 0) || (_x3B > 9)) || ((_x3E < 0) || (_x3E > 9)) || ((_y3B < 0) || (_y3B > 9)) || ((_y3E < 0) || (_y3E > 9)))
		{
			cout << "Координаты выходят за диапозон значений! Попробуйте ещё раз" << endl;
			cin >> _x3B >> _y3B >> _x3E >> _y3E;
			cout << endl;
		}
}
void ProverkaVvodaTwo(int &_x2B, int &_y2B, int &_x2E, int &_y2E)//Проверка ввода двухпалубного корабля
{
		while (((_x2B != _x2E) && (_y2B != _y2E)) || ((abs(_x2B - _x2E) != 1) && (_y2B == _y2E)) || (abs(_y2B - _y2E) != 1) && (_x2B == _x2E))
		{
			cout << "Координаты введены неверно! Попробуйте ещё раз" << endl;
			cin >> _x2B >> _y2B >> _x2E >> _y2E;
			cout << endl;
		}
		while (((_x2B < 0) || (_x2B > 9)) || ((_x2E < 0) || (_x2E > 9)) || ((_y2B < 0) || (_y2B > 9)) || ((_y2E < 0) || (_y2E > 9)))
		{
			cout << "Координаты выходят за диапозон значений! Попробуйте ещё раз" << endl;
			cin >> _x2B >> _y2B >> _x2E >> _y2E;
			cout << endl;
		}
}
void ProverkaVvodaOne(int &_x1B, int &_y1B)
{
		while (((_x1B < 0) || (_x1B > 9)) || ((_y1B < 0) || (_y1B > 9)))
		{
			cout << "Координаты выходят за диапозон значений! Попробуйте ещё раз" << endl;
			cin >> _x1B >> _y1B;
			cout << endl;
		}
}
bool ProverkaShip1(int X1, int Y1, int CoordinateComputerGame[10][10])//Проверка однопалубного корабля на наличие "соседей"
{
		if ((X1 > 0) && (X1 < 9) && (Y1 > 0) && (Y1 < 9))
		{
			if ((CoordinateComputerGame[X1 - 1][Y1] == 1) || (CoordinateComputerGame[X1 + 1][Y1] == 1) || (CoordinateComputerGame[X1][Y1 - 1] == 1) || (CoordinateComputerGame[X1][Y1 + 1] == 1))
			{
				return true;
			}
		}
		if (((X1 > 0) && (X1 < 9)) && ((Y1 == 0) || (Y1 == 9)))
		{
			if ((CoordinateComputerGame[X1 - 1][Y1] == 1) || (CoordinateComputerGame[X1 + 1][Y1] == 1))
			{
				return true;
			}
		}
		if (((Y1 > 0) && (Y1 < 9)) && ((X1 == 0) || (X1 == 9)))
		{
			if ((CoordinateComputerGame[X1][Y1 - 1] == 1) || (CoordinateComputerGame[X1][Y1 + 1] == 1))
			{
				return true;
			}
		}
		if ((X1 == 0) && (Y1 == 0))
		{
			if ((CoordinateComputerGame[1][0] == 1) || (CoordinateComputerGame[0][1] == 1))
			{
				return true;
			}
		}
		if ((X1 == 0) && (Y1 == 9))
		{
			if ((CoordinateComputerGame[1][9] == 1) || (CoordinateComputerGame[0][8] == 1))
			{
				return true;
			}
		}
		if ((X1 == 9) && (Y1 == 0))
		{
			if ((CoordinateComputerGame[8][0] == 1) || (CoordinateComputerGame[9][1] == 1))
			{
				return true;
			}
		}
		if ((X1 == 9) && (Y1 == 9))
		{
			if ((CoordinateComputerGame[8][9] == 1) || (CoordinateComputerGame[9][8] == 1))
			{
				return true;
			}
		}
		return false;
}
bool ProverkaSosed(int X1, int Y1, int X2, int Y2,int CoordinateComputerGame[10][10])//Проверка кораблей на наличие соседей
{
		int N;
		if (X1 == X2)
		{
			N = abs(Y2 - Y1) + 1;
			if ((X1 > 0) && (X1 < 9))
			{
				for (int i = 0; i < N; i++)
				{
					if (CoordinateComputerGame[X1 - 1][Y1 + i] == 1)
					{
						return true;
					}
					if ((CoordinateComputerGame[X1 + 1][Y1 + i] == 1))
					{
						return true;
					}
				}
			}
			else//X либо 0, либо 9
			{
				if (X1 == 0)
				{
					for (int i = 0; i < N; i++)
					{
						if (CoordinateComputerGame[X1 + 1][Y1 + i] == 1)
						{
							return true;
						}
					}
					if (X1 == 9)
					{
						for (int i = 0; i < N; i++)
						{
							if (CoordinateComputerGame[X1 - 1][Y1 + i] == 1)
							{
								return true;
							}
						}
					}
				}
			}
			if ((Y1 > 0) && (Y2 < 9))
			{
				if ((CoordinateComputerGame[X1][Y1 - 1] == 1) || (CoordinateComputerGame[X1][Y2 + 1] == 1))
					return true;
			}
			if (Y1 == 0)
			{
				if (CoordinateComputerGame[X1][Y2 + 1] == 1)
					return true;
			}
			if (Y2 == 9)
			{
				if (CoordinateComputerGame[X1][Y1 - 1] == 1)
					return true;
			}
		}
		if (Y1 == Y2)
		{
			N = abs(X2 - X1) + 1;
			if ((Y1 > 0) && (Y1 < 9))
			{
				for (int i = 0; i < N; i++)
				{
					if (CoordinateComputerGame[X1 + i][Y1 + 1] == 1)
					{
						return true;
					}
					if ((CoordinateComputerGame[X1 + i][Y1 - 1] == 1))
					{
						return true;
					}
				}
			}
			else//Y либо 0, либо 9
			{
				if (Y1 == 0)
				{
					for (int i = 0; i < N; i++)
					{
						if (CoordinateComputerGame[X1 + i][Y1 + 1] == 1)
						{
							return true;
						}
					}
					if (X1 == 9)
					{
						for (int i = 0; i < N; i++)
						{
							if (CoordinateComputerGame[X1 + i][Y1 - 1] == 1)
							{
								return true;
							}
						}
					}
				}
			}
			if ((X1 > 0) && (X2 < 9))
			{
				if ((CoordinateComputerGame[X1 - 1][Y1] == 1) || (CoordinateComputerGame[X2 + 1][Y2] == 1))
				{
					return true;
				}					
			}
			if (Y1 == 0)
			{
				if (CoordinateComputerGame[X2 + 1][Y1] == 1)
					return true;
			}
			if (Y2 == 9)
			{
				if (CoordinateComputerGame[X1 - 1][Y1] == 1)
					return true;
			}
		}
		return false;
}
class Game//Класс игрока Компьютер
{
private:
	int CoordinateComputerGame[10][10];//Координатная плоскость
	int CoordinateLiveGame[10][10];
	int CoordinatePopal[10][10];
	OneDeckShip CShip1[4];//Координаты Однопалубных кораблей
	TwoDeckShip CShip2[3];//Координаты Двухпалубных кораблей
	ThreeDeckShip CShip3[2];//Координаты Трёхпалубных кораблей
	FourDeckShip CShip4;//Координаты Четырёхпалубных кораблей
	int ComputerKolShip;//Количество кораблей
public:
	Game()//Конструктор
	{
		ComputerKolShip = 10;
		for (int i = 0; i < 10; i++)//Обнуление координатной плоскости
		{
			for (int j = 0; j < 10; j++)
			{
				CoordinateComputerGame[i][j] = 0;
				CoordinateLiveGame[i][j] = 0;
				CoordinatePopal[i][j] = 0;
			}
		}
		int X1, Y1, X2, Y2;
		int pologenie;//Положение корабля относительно осям координат
		bool Sosed = true;
		Coordinate Begin;
		Coordinate End;
		//Четырёхпалубный
		X1 = rand() % 10;
		Y1 = rand() % 10;
		pologenie = rand() % 2;//0-по горизонтали, 1-по вертикали
		if (pologenie == 0)
		{
			while(Y1>6)
				Y1 = rand() % 10;
			X2 = X1;
			Y2 = Y1 + 3;
			for (int i = 0; i < 4; i++)
			{
				CoordinateComputerGame[X1][Y1+i] = 1;
			}			
		}
		if (pologenie == 1)
		{
			while (X1 > 6)
				X1 = rand() % 10;
			Y2 = Y1;
			X2 = X1 + 3;
			for (int i = 0; i < 4; i++)
			{
				CoordinateComputerGame[X1 + i][Y1] = 1;
			}
		}		
		Begin.SetCoordinate(X1, Y1);
		End.SetCoordinate(X2,Y2);
		CShip4.SetCoordinate(Begin, End);//Создание корабля
		//Трёхпалубные
		for (int i = 0; i < 2; i++)
		{
			int indexX[3];
			int indexY[3];
			Sosed = true;
			while (Sosed == true)
			{			
				for (int z = 0; z < 3; z++)
				{
					indexX[z] = -1;
					indexY[z] = -1;
				}
				X1 = rand() % 10;
				Y1 = rand() % 10;
				pologenie = rand() % 2;//0-по горизонтали, 1-по вертикали
				if (pologenie == 0)
				{
					while (Y1 > 7)
						Y1 = rand() % 10;
					X2 = X1;
					Y2 = Y1 + 2;
					for (int j = 0; j < 3; j++)
					{
						if (CoordinateComputerGame[X1][Y1 + j] != 1)
						{
							CoordinateComputerGame[X1][Y1 + j] = 1;
						}
						else
						{
							indexX[j] = X1;
							indexY[j] = Y1 + i;
						}
					}
				}
				if (pologenie == 1)
				{
					while (X1 > 7)
						X1 = rand() % 10;
					Y2 = Y1;
					X2 = X1 + 2;
					for (int j = 0; j < 3; j++)
					{
						if (CoordinateComputerGame[X1 + j][Y1] != 1)
						{
							CoordinateComputerGame[X1 + j][Y1] = 1;
						}
						else
						{
							indexX[j] = X1;
							indexY[j] = Y1 + i;
						}
					}
				}
				Coordinate Begin(X1, Y1);
				Coordinate End(X2, Y2);
				CShip3[i].SetCoordinate(Begin, End);
				Sosed=ProverkaSosed(X1, Y1, X2, Y2, CoordinateComputerGame);
				if (Sosed == true)
				{
					if (pologenie == 0)
					{
						for (int j = 0; j < 3; j++)
						{
							CoordinateComputerGame[X1][Y1 + j] = 0;
							if ((indexX[j] != (-1)) && (indexY[j] != (-1)))
							{
								CoordinateComputerGame[indexX[j]][indexY[j]] = 1;
							}
						}						
					}
					if (pologenie == 1)
					{
						for (int j = 0; j < 3; j++)
						{
							CoordinateComputerGame[X1 + j][Y1] = 0;
							if ((indexX[j] != (-1)) && (indexY[j] != (-1)))
							{
								CoordinateComputerGame[indexX[j]][indexY[j]] = 1;
							}
						}						
					}
				}
			}
		}
		//Двухпалубные
		for (int i = 0; i < 3; i++)
		{
			int indexX[2];
			int indexY[2];
			Sosed = true;
			while (Sosed == true)
			{
				for (int z = 0; z < 2; z++)
				{
					indexX[z] = -1;
					indexY[z] = -1;
				}
				X1 = rand() % 10;
				Y1 = rand() % 10;
				pologenie = rand() % 2;//0-по горизонтали, 1-по вертикали
				if (pologenie == 0)
				{
					while (Y1 > 8)
						Y1 = rand() % 10;
					X2 = X1;
					Y2 = Y1 + 2;
					for (int j = 0; j < 2; j++)
					{
						if (CoordinateComputerGame[X1][Y1 + j] != 1)
						{
							CoordinateComputerGame[X1][Y1 + j] = 1;
						}
						else
						{
							indexX[j] = X1;
							indexY[j] = Y1 + i;
						}
					}
				}
				if (pologenie == 1)
				{
					while (X1 > 8)
						X1 = rand() % 10;
					Y2 = Y1;
					X2 = X1 + 2;
					for (int j = 0; j < 2; j++)
					{
						if (CoordinateComputerGame[X1 + j][Y1] != 1)
						{
							CoordinateComputerGame[X1 + j][Y1] = 1;
						}
						else
						{
							indexX[j] = X1;
							indexY[j] = Y1 + i;
						}
					}
				}
				Coordinate Begin(X1, Y1);
				Coordinate End(X2, Y2);
				CShip3[i].SetCoordinate(Begin, End);
				Sosed = ProverkaSosed(X1, Y1, X2, Y2, CoordinateComputerGame);
				if (Sosed == true)
				{
					if (pologenie == 0)
					{
						for (int j = 0; j < 2; j++)
						{
							CoordinateComputerGame[X1][Y1 + j] = 0;
							if ((indexX[j] != (-1)) && (indexY[j] != (-1)))
							{
								CoordinateComputerGame[indexX[j]][indexY[j]] = 1;
							}
						}
					}
					if (pologenie == 1)
					{
						for (int j = 0; j < 2; j++)
						{
							CoordinateComputerGame[X1 + j][Y1] = 0;
							if ((indexX[j] != (-1)) && (indexY[j] != (-1)))
							{
								CoordinateComputerGame[indexX[j]][indexY[j]] = 1;
							}
						}
					}
				}
			}
		}
		//Однопалубные
		for (int i = 0; i < 4; i++)
		{
			int indexX;
			int indexY;
			Sosed = true;
			while (Sosed == true)
			{
				indexX = -1;
				indexY = -1;
				X1 = rand() % 10;
				Y1 = rand() % 10;
				if (CoordinateComputerGame[X1][Y1] != 1)
				{
					CoordinateComputerGame[X1][Y1] = 1;
				}
				else
				{
					indexX = X1;
					indexY = Y1;
				}
				Coordinate Begin(X1, Y1);
				CShip1[0].SetCoordinate(Begin);
				Sosed = ProverkaShip1(X1, Y1, CoordinateComputerGame);
				if (Sosed == true)
				{
					CoordinateComputerGame[X1][Y1] = 0;
					if ((indexX != (-1)) && (indexY != (-1)))
					{
						CoordinateComputerGame[indexX][indexY] = 1;
					}
				}
			}
		}
	}
	bool ProverkaPopadania(int X, int Y)
	{
		cout << X << Y << endl;
		bool nextstep;
		if (CoordinateComputerGame[X][Y] == 0)
		{
			cout << "Эх, не повезло... Вы промазали" << endl;
			nextstep = false;
		}
		if ((CoordinateComputerGame[X][Y] == (-1)) || (CoordinateComputerGame[X][Y] == (-2)))
		{
			cout << "Эй, так нечестно, вы сюда уже стреляли, попробуйте ещё раз" << endl;
			nextstep = true;
		}
		if (CoordinateComputerGame[X][Y] == 1)
		{
			Coordinate BeginShip[10];
			BeginShip[0] = CShip4.GetBegin();
			BeginShip[1] = CShip3[0].GetBegin();
			BeginShip[2] = CShip3[1].GetBegin();
			BeginShip[3] = CShip2[0].GetBegin();
			BeginShip[4] = CShip2[1].GetBegin();
			BeginShip[5] = CShip2[2].GetBegin();
			BeginShip[6] = CShip1[0].GetBegin();
			BeginShip[7] = CShip1[1].GetBegin();
			BeginShip[8] = CShip1[2].GetBegin();
			BeginShip[9] = CShip1[3].GetBegin();
			Coordinate End;
			if ((X == BeginShip[0].GetX())||(Y== BeginShip[0].GetY()))//Произошло попадание в Четырёхпалубный
			{
				CShip4.AddHitTheShip();
				if (CShip4.GetStatusOfShip() == false)//Если убит
				{
					ComputerKolShip = ComputerKolShip - 1;
					cout << "Убит" << endl;
					End = CShip4.GetEnd();
					if (BeginShip[0].GetX() == End.GetX())
					{
						int x = BeginShip[0].GetX();
						int y = BeginShip[0].GetY();
						for (int j = 0; j < 4; j++)
						{
							CoordinateComputerGame[x][y + j] = -2;
							CoordinatePopal[x][y + j] = -2;
						}						
					}
					if (BeginShip[0].GetY() == End.GetY())
					{
						int x = BeginShip[0].GetX();
						int y = BeginShip[0].GetY();
						for (int j = 0; j < 4; j++)
						{
							CoordinateComputerGame[x + j][y] = -2;
							CoordinatePopal[x][y + j] = -2;
						}
					}
				}
				else
				{
					cout << "Ранен" << endl;
					CoordinateComputerGame[X][Y] = -1;
					CoordinatePopal[X][Y] = -1;
				}
			}
			for (int i = 1; i < 3; i++)
			{
				if ((X == BeginShip[i].GetX()) || (Y == BeginShip[i].GetY()))//Произошло попадание в один из трёхпалубных
				{
					CShip3[i-1].AddHitTheShip();
					if (CShip3[i - 1].GetStatusOfShip() == false)//Если убит
					{
						ComputerKolShip = ComputerKolShip - 1;
						cout << "Убит" << endl;
						End = CShip3[i - 1].GetEnd();
						if (BeginShip[i].GetX() == End.GetX())
						{
							int x = BeginShip[i].GetX();
							int y = BeginShip[i].GetY();
							for (int j = 0; j < 3; j++)
							{
								CoordinateComputerGame[x][y + j] = -2;
							}
						}
						if (BeginShip[i].GetY() == End.GetY())
						{
							int x = BeginShip[i].GetX();
							int y = BeginShip[i].GetY();
							for (int j = 0; j < 3; j++)
							{
								CoordinateComputerGame[x + j][y] = -2;
							}
						}
					}
					else
					{
						cout << "Ранен" << endl;
						CoordinateComputerGame[X][Y] = -1;
						CoordinatePopal[X][Y] = -1;
					}
				}
			}
			for (int i = 3; i < 6; i++)
			{
				if ((X == BeginShip[i].GetX()) || (Y == BeginShip[i].GetY()))//Произошло попадание в один из двухпалубных
				{
					CShip2[i - 3].AddHitTheShip();
					if (CShip2[i - 3].GetStatusOfShip() == false)//Если убит
					{
						ComputerKolShip = ComputerKolShip - 1;
						cout << "Убит" << endl;
						End = CShip2[i - 3].GetEnd();
						if (BeginShip[i].GetX() == End.GetX())
						{
							int x = BeginShip[i].GetX();
							int y = BeginShip[i].GetY();
							for (int j = 0; j < 2; j++)
							{
								CoordinateComputerGame[x][y + j] = -2;
							}
						}
						if (BeginShip[i].GetY() == End.GetY())
						{
							int x = BeginShip[i].GetX();
							int y = BeginShip[i].GetY();
							for (int j = 0; j < 2; j++)
							{
								CoordinateComputerGame[x + j][y] = -2;
							}
						}
					}
					else
					{
						cout << "Ранен" << endl;
						CoordinateComputerGame[X][Y] = -1;
						CoordinatePopal[X][Y] = -1;
						DrawCoordinateGame(CoordinateComputerGame, CoordinatePopal);
					}
				}
			}
			for (int i = 6; i < 10; i++)
			{
				if ((X == BeginShip[i].GetX()) || (Y == BeginShip[i].GetY()))//Произошло попадание в один из однопалубных
				{
					CShip1[i - 6].ChangeStatusOfShip();
					if (CShip2[i - 3].GetStatusOfShip() == false)//Убит
					{
						ComputerKolShip = ComputerKolShip - 1;
						cout << "Убит" << endl;						
						CoordinateComputerGame[X][Y] = -2;
						CoordinatePopal[X][Y] = -2;
					}
				}
			}
			DrawCoordinateGame(CoordinateLiveGame, CoordinatePopal);
			nextstep = true;
		}
		return nextstep;
	}
	Coordinate FindCoordinate(int X, int Y)
	{
		Coordinate Maybe;
		int pologenie;
		if ((X > 0) && (X < 9) && (Y > 0) && (Y < 9))
		{
			pologenie = rand() % 4;
			if (pologenie == 0)
			{
				X = X - 1;
				Maybe.SetCoordinate(X, Y);
			}
			if (pologenie == 1)
			{
				X = X + 1;
				Maybe.SetCoordinate(X, Y);
			}
			if (pologenie == 3)
			{
				Y = Y - 1;
				Maybe.SetCoordinate(X, Y);
			}
			if (pologenie == 4)
			{
				Y = Y - 1;
				Maybe.SetCoordinate(X, Y);
			}
		}
		if ((X == 0)&&(Y==0))
		{
			pologenie = rand() % 2;
			if (pologenie == 0)
			{
				X = X + 1;
				Maybe.SetCoordinate(X, Y);
			}
			if (pologenie == 1)
			{
				Y = Y + 1;
				Maybe.SetCoordinate(X, Y);
			}
		}
		if ((X == 0) && (Y == 9))
		{
			pologenie = rand() % 2;
			if (pologenie == 0)
			{
				X = X + 1;
				Maybe.SetCoordinate(X, Y);
			}
			if (pologenie == 1)
			{
				Y = Y - 1;
				Maybe.SetCoordinate(X, Y);
			}
		}
		if ((X == 9) && (Y == 0))
		{
			pologenie = rand() % 2;
			if (pologenie == 0)
			{
				X = X - 1;
				Maybe.SetCoordinate(X, Y);
			}
			if (pologenie == 1)
			{
				Y = Y + 1;
				Maybe.SetCoordinate(X, Y);
			}
		}
		if ((X == 9) && (Y == 9))
		{
			pologenie = rand() % 2;
			if (pologenie == 0)
			{
				X = X - 1;
				Maybe.SetCoordinate(X, Y);
			}
			if (pologenie == 1)
			{
				Y = Y - 1;
				Maybe.SetCoordinate(X, Y);
			}
		}
		if (((X > 0) && (X < 9)) && ((Y == 0) || (Y == 9)))
		{
			pologenie = rand() % 2;
			if (pologenie == 0)
			{
				X = X - 1;
				Maybe.SetCoordinate(X, Y);
			}
			if (pologenie == 1)
			{
				X = X + 1;
				Maybe.SetCoordinate(X, Y);
			}
		}
		if (((Y > 0) && (Y < 9)) && ((X == 0) || (X == 9)))
		{
			pologenie = rand() % 2;
			if (pologenie == 0)
			{
				Y = Y - 1;
				Maybe.SetCoordinate(X, Y);
			}
			if (pologenie == 1)
			{
				Y = Y + 1;
				Maybe.SetCoordinate(X, Y);
			}
		}
		return Maybe;
	}
	int GetComputerKolShip()
	{
		return ComputerKolShip;
	}
	void ChangeCoordinateGameRanen(Coordinate Popadanie)
	{
		CoordinateLiveGame[Popadanie.GetX()][Popadanie.GetY()] = -1;
	}
	void ChagneCoordinateYbit(Coordinate Popadanie)
	{
		CoordinateLiveGame[Popadanie.GetX()][Popadanie.GetY()] = -2;
	}
	void InputCoordinateFour(FourDeckShip &Myship4)//Ввод координат четырёхпалубного корабля
	{		
		DrawCoordinateGame(CoordinateLiveGame, CoordinatePopal);
		cout << "Введите поочерёдно координаты начала(x,y) и координаты конца четырёхпалубного корабля" << endl;
		int x4B = 0;
		int y4B = 0;
		int x4E = 0;
		int y4E = 0;
		cin >> x4B >> y4B >> x4E >> y4E;
		cout << endl;
		ProverkaVvodaFour(x4B, y4B, x4E, y4E);//Проверка координат
		if (x4B == x4E)
		{
			CoordinateLiveGame[x4B][y4B] = 1;
			CoordinateLiveGame[x4B][y4B + 1] = 1;
			CoordinateLiveGame[x4B][y4B + 2] = 1;
			CoordinateLiveGame[x4E][y4E] = 1;
		}
		if (y4B == y4E)
		{
			CoordinateLiveGame[x4B][y4B] = 1;
			CoordinateLiveGame[x4B + 1][y4B] = 1;
			CoordinateLiveGame[x4B + 2][y4B] = 1;
			CoordinateLiveGame[x4E][y4E] = 1;
		}
		Coordinate begin(x4B, y4B);
		Coordinate end(x4E, y4E);
		Myship4.SetCoordinate(begin, end);//Смена координат для корабля на правильные
		DrawCoordinateGame(CoordinateLiveGame, CoordinatePopal);
	}
	void InputCoordinateThree(ThreeDeckShip &Myship31, ThreeDeckShip &Myship32)//Ввод координат трёхпалубного корабля
	{
		cout << "Введите поочерёдно координаты начала(x,y) и координаты конца трёхпалубного корабля, сначала первого, потом второго" << endl;
		cout << "ВНИМАНИЕ!!!" << "ВНИМАНИЕ!!!" << "ВНИМАНИЕ!!!" << "ВНИМАНИЕ!!!" << "ВНИМАНИЕ!!!" << endl;
		cout << "Корабли не должны стоять в соседних клетках" << endl;
		bool Sosed;
		int indexX[3];
		int indexY[3];
		for (int i = 1; i < 3; i++)
		{
			int x3B = 0;
			int y3B = 0;
			int x3E = 0;
			int y3E = 0;
			
			if (i == 1)
			{
				cout << "Сначала первый" << endl;
			}
			if (i == 2)
			{
				cout << "Теперь второй" << endl;
			}
			Sosed = true;
			while (Sosed == true)
			{
				for (int z = 0; z < 3; z++)
				{
					indexX[z] = -1;
					indexY[z] = -1;
				}				
				cin >> x3B >> y3B >> x3E >> y3E;
				cout << endl;
				ProverkaVvodaThree(x3B, y3B, x3E, y3E);//Проверка координат
				Coordinate begin(x3B, y3B);
				Coordinate end(x3E, y3E);
				if (i == 1)//Созддание кораблей
				{
					Myship31.SetCoordinate(begin, end);
				}
				if (i == 2)
				{
					Myship32.SetCoordinate(begin, end);
				}
				if (x3B == x3E)
				{
					for (int j = 0; j < 3; j++)
					{
						if (CoordinateLiveGame[x3B][y3B + j] != 1)
						{
							CoordinateLiveGame[x3B][y3B + j] = 1;
						}
						else//Если корабли пересеклись по одной точке
						{
							indexX[j] = x3B;
							indexY[j] = y3B + j;
						}
					}
				}
				if (y3B == y3E)
				{
					for (int j = 0; j < 3; j++)
					{
						if (CoordinateLiveGame[x3B + j][y3B] != 1)
						{
							CoordinateLiveGame[x3B + j][y3B] = 1;
						}
						else//Если корабли пересеклись по одной точке
						{
							indexX[j] = x3B + j;
							indexY[j] = y3B;
						}
					}
				}
				Sosed = ProverkaSosed(x3B, y3B, x3E, y3E, CoordinateLiveGame);//Проверка на соседей
				if (Sosed == true)
				{
					cout << "Караул корабли в соседних клетках! Попробуйте ещё раз" << endl;
					if (x3B == x3E)
					{
						for (int j = 0; j < 3; j++)
						{
							CoordinateLiveGame[x3B][y3B + j] = 0;
							if ((indexX[j] != (-1)) && (indexY[j] != (-1)))//Если корабли пересеклись по одной точке
							{
								CoordinateLiveGame[indexX[j]][indexY[j]] = 1;
							}
						}						
					}				
					if (y3B == y3E)
					{
						for (int j = 0; j < 3; j++)
						{
							CoordinateLiveGame[x3B + j][y3B] = 0;
							if ((indexX[j] != (-1)) && (indexY[j] != (-1)))//Если корабли пересеклись по одной точке
							{
								CoordinateLiveGame[indexX[j]][indexY[j]] = 1;
							}
						}
					}
					DrawCoordinateGame(CoordinateLiveGame, CoordinatePopal);
				}
			}		
			DrawCoordinateGame(CoordinateLiveGame, CoordinatePopal);
		}
	}
	void InputCoordinateTwo(TwoDeckShip &Myship21, TwoDeckShip &Myship22, TwoDeckShip &Myship23)//Ввод координат двухпалубного корабля
	{
		cout << "Введите поочерёдно координаты начала(x,y) и координаты конца двухпалубного корабля, сначала первого, потом второго, затем третьего" << endl;
		cout << "ВНИМАНИЕ!!!"<<"ВНИМАНИЕ!!!"<<"ВНИМАНИЕ!!!"<<"ВНИМАНИЕ!!!"<<"ВНИМАНИЕ!!!" << endl;
		cout << "Корабли не должны стоять в соседних клетках" << endl;
		bool Sosed;
		int indexX[2];
		int indexY[2];
		for (int i = 1; i < 4; i++)
		{
			int x2B = 0;
			int y2B = 0;
			int x2E = 0;
			int y2E = 0;
			if (i == 1)
				{
					cout << "Сначала первый" << endl;
				}
				if (i == 2)
				{
					cout << "Теперь второй" << endl;
				}
				if (i == 3)
				{
					cout << "Последний!" << endl;
				}
				Sosed = true;
				while (Sosed == true)
				{
					for (int z = 0; z < 2; z++)
					{
						indexX[z] = -1;
						indexY[z] = -1;
					}					
					cin >> x2B >> y2B >> x2E >> y2E;
					cout << endl;
					ProverkaVvodaTwo(x2B, y2B, x2E, y2E);//Проверка координат
					Coordinate begin(x2B, y2B);
					Coordinate end(x2E, y2E);
					if (i == 1)//Создание кораблей
					{
						Myship21.SetCoordinate(begin, end);
					}
					if (i == 2)
					{
						Myship22.SetCoordinate(begin, end);
					}
					if (i == 3)
					{
						Myship23.SetCoordinate(begin, end);
					}
					if (x2B == x2E)
					{
						for (int j = 0; j < 2; j++)
						{
							if (CoordinateLiveGame[x2B][y2B + j] != 1)
							{
								CoordinateLiveGame[x2B][y2B + j] = 1;
							}
							else//Если корабли пересеклись по одной точке
							{
								indexX[j] = x2B;
								indexY[j] = y2B + j;
							}
						}
					}
					if (y2B == y2E)
					{
						for (int j = 0; j < 2; j++)
						{
							if (CoordinateLiveGame[x2B + j][y2B] != 1)
							{
								CoordinateLiveGame[x2B + j][y2B] = 1;
							}
							else//Если корабли пересеклись по одной точке
							{
								indexX[j] = x2B + j;
								indexY[j] = y2B;
							}
						}
					}
					Sosed = ProverkaSosed(x2B, y2B, x2E, y2E, CoordinateLiveGame);//Проверка на соседей
					if (Sosed == true)
					{
						cout << "Караул корабли в соседних клетках! Попробуйте ещё раз" << endl;
						if (x2B == x2E)
						{
							for (int j = 0; j < 2; j++)
							{
								CoordinateLiveGame[x2B][y2B + j] = 0;
								if ((indexX[j] != (-1)) && (indexY[j] != (-1)))//Если корабли пересеклись по одной точке
								{
									CoordinateLiveGame[indexX[j]][indexY[j]] = 1;
								}
							}							
						}
						if (y2B == y2E)
						{
							for (int j = 0; j < 2; j++)
							{
								CoordinateLiveGame[x2B + j][y2B] = 0;
								if ((indexX[j] != (-1)) && (indexY[j] != (-1)))//Если корабли пересеклись по одной точке
								{
									CoordinateLiveGame[indexX[j]][indexY[j]] = 1;
								}
							}							
						}
					}
				}				
			DrawCoordinateGame(CoordinateLiveGame, CoordinatePopal);
		}
	}
	void InputCoordinateOne(OneDeckShip &Myship11, OneDeckShip &Myship12, OneDeckShip &Myship13, OneDeckShip &Myship14)//Ввод координат однопалубного корабля
	{
		for (int i = 1; i < 5; i++)
		{
			cout << "Введите поочерёдно координаты(x,y) корабля" << endl;
			cout << "ВНИМАНИЕ!!!" << "ВНИМАНИЕ!!!" << "ВНИМАНИЕ!!!" << "ВНИМАНИЕ!!!" << "ВНИМАНИЕ!!!" << endl;
			cout << "Корабли не должны стоять в соседних клетках" << endl;
			int x1B = 0;
			int y1B = 0;
			bool Sosed;
			int indexX;
			int indexY;
			Sosed = true;
			while (Sosed == true)
			{
				indexX = -1;
				indexY = -1;
				cin >> x1B >> y1B;
				cout << endl;
				ProverkaVvodaOne(x1B, y1B);//Проверка ввода
				if (CoordinateLiveGame[x1B][y1B] != 1)
				{
					CoordinateLiveGame[x1B][y1B] = 1;
				}
				else
				{
					indexX = x1B;
					indexY = y1B;
				}
				Coordinate begin(x1B, y1B);
				if (i == 1)//Создание кораблей
				{
					Myship11.SetCoordinate(begin);
				}
				if (i == 2)
				{
					Myship12.SetCoordinate(begin);
				}
				if (i == 3)
				{
					Myship13.SetCoordinate(begin);
				}
				if (i == 4)
				{
					Myship14.SetCoordinate(begin);
				}
				Sosed = ProverkaShip1(x1B, y1B, CoordinateLiveGame);//Проверка на соседей
				if (Sosed == true)
				{
					cout << "Караул корабли в соседних клетках! Попробуйте ещё раз" << endl;
					CoordinateLiveGame[x1B][y1B] = 0;
					if ((indexX != (-1)) && (indexY != (-1)))
					{
						CoordinateLiveGame[indexX][indexY] = 1;
					}
				}				
			}
			DrawCoordinateGame(CoordinateLiveGame, CoordinatePopal);
		}
	}
};
void main()
{
	setlocale(LC_ALL, "Rus");
	SetColor(15, 0);
	cout << "Добро пожаловать в игру Морской бой" << endl;
	cout << "Для начала необходимо расставить ваши корабли" << endl;
	cout << "Вводите координаты слева направо или сверху вниз" << endl;
	int ForComputer[10][10] = { 0 };
	bool Livenextstep = true;
	int LiveKolShip = 10;
	int X1, Y1, X2, Y2,size;
	string result;
	Coordinate Popadanie;
	Game SeaBattle;
	FourDeckShip Myship4;
	SeaBattle.InputCoordinateFour(Myship4);
	cout << "Отлично один есть! Идём дальше." << endl;
	ThreeDeckShip Myship31, Myship32;
	SeaBattle.InputCoordinateThree(Myship31, Myship32);
	cout << "Чудно, трёхпалубные есть! Флот набирает мощь... Дальше." << endl;
	TwoDeckShip Myship21, Myship22, Myship23;
	SeaBattle.InputCoordinateTwo(Myship21, Myship22, Myship23);	
	cout << "Фух, последний рывок и можно играть!" << endl;
	OneDeckShip Myship11, Myship12, Myship13, Myship14;
	SeaBattle.InputCoordinateOne(Myship11, Myship12, Myship13, Myship14);
	cout << "Итак, вы бьёте первым. Введите координату:" << endl;
	int X, Y;
	while ((LiveKolShip != 0) || (SeaBattle.GetComputerKolShip() != 0))
	{
		while ((Livenextstep == true)&&(SeaBattle.GetComputerKolShip() != 0))
		{
			cout << "Ваш ход:" << endl;
			cin >> X >> Y;
			cout << endl;
			while ((X < 0) || (X > 9) || (Y < 0) || (Y > 9))
			{
				cout << "К сожалению вы промахнулись полем, таких координат нет!" << endl << "Попробуйте ещё раз" << endl;
				cin >> X >> Y;
				cout << endl;
			}
			Livenextstep = SeaBattle.ProverkaPopadania(X, Y);
		}
		while ((Livenextstep == false)&&(LiveKolShip != 0))
		{
			result = "мимо";
			if ((result == "мимо")||(result == "убит"))
			{
				do
				{
					X = rand() % 10;
					Y = rand() % 10;					
				} while ((ForComputer[X][Y] == -1) || (ForComputer[X][Y] == -2));
				Popadanie.SetCoordinate(X, Y);
			}
			if (result == "ранен")
			{
				SeaBattle.ChangeCoordinateGameRanen(Popadanie);
				Popadanie = SeaBattle.FindCoordinate(X,Y);
			}			
			cout << "Ход компьютера:" << endl;
			cout << Popadanie << endl;
			cout << "Введите: мимо, ранен или убит в соответсвующих случаях. Чур не мухлевать!!!"<<endl;
			cin >> result;
			if (result == "мимо")
			{
				Livenextstep = true;
			}
			if (result == "ранен")
			{
				Livenextstep = false;
				ForComputer[X][Y] = -1;
			}
			if (result == "убит")
			{				
				LiveKolShip = LiveKolShip - 1;
				Livenextstep = false;
				cout << "Введите координаты убитого корабля(начало, конец, длина) для смены поля!" << endl;
				cin >> X1 >> Y1 >> X2 >> Y2 >> size;
				for (int i = 0; i < size; i++)
				{
					if (X1 == X2)
					{
						Popadanie.SetCoordinate(X1, Y1 + i);
						ForComputer[X1][Y1+i] = -2;
						SeaBattle.ChagneCoordinateYbit(Popadanie);
					}
					if (Y1 == Y2)
					{
						Popadanie.SetCoordinate(X1 + i, Y1);
						ForComputer[X1 + i][Y1] = -2;
						SeaBattle.ChagneCoordinateYbit(Popadanie);
					}
				}
			}
		}
	}
	if (LiveKolShip == 0)
	{
		cout << "Сожалею, но вы проиграли!(((" << endl;
	}
	if (SeaBattle.GetComputerKolShip() == 0)
	{
		cout << "Поздравляю! Вы выиграли!!!(((" << endl;
	}
	int a;
	cin >> a;
}
	


