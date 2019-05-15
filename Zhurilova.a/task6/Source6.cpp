#define _CRT_SECURE_NO_WARNINGS
#include<locale.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
class Coordinate//Класс координат поля
{
private:
	int x;
	int y;
public:
	Coordinate(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	Coordinate SetCoordinate(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	Coordinate& operator=(const Coordinate &_XY)
	{
		x = _XY.x;
		y = _XY.y;
		return *this;
	}
};
class SingleDeckShip//Однопалубный корабль
{
private:
	Coordinate cship;
	//int KolHitTheShip;
	bool StatusOfShip;
public:
	SingleDeckShip()
	{
		//KolHitTheShip = 0;
		StatusOfShip = true;
	}
	void SetCoordinate(int _x, int _y)
	{
		cship.SetCoordinate(_x, _y);
	}
	bool ChangeStatusOfShip()
	{
		StatusOfShip = false;
	}
};
class TwoDeckShip//Двухпалубный корабль
{
private:
	Coordinate cship1;
	Coordinate cship2;
	int KolHitTheShip;
	bool StatusOfShip;
public:
	TwoDeckShip()
	{
		cship2.SetCoordinate(0, 1);
		KolHitTheShip = 0;
		StatusOfShip = true;
	}
	void SetCoordinate(int _x1, int _y1,int _x2, int _y2)
	{
		cship1.SetCoordinate(_x1, _y1);
		cship2.SetCoordinate(_x2, _y2);
	}
	void AddHitTheShip()
	{
		if (KolHitTheShip != 2)
		{
			KolHitTheShip++;
		}
		if (KolHitTheShip == 2)
		{
			StatusOfShip = false;
		}		
	}
	bool GetStatusOfShip()
	{
		return StatusOfShip;
	}
};
class ThreeDeckShip //Трёхпалубный корабль
{
private:
	Coordinate cshipBegin;
	Coordinate cshipEnd;
	int KolHitTheShip;
	bool StatusOfShip;
public:
	ThreeDeckShip()
	{
		cshipEnd.SetCoordinate(0, 2);
		KolHitTheShip = 0;
		StatusOfShip = true;
	}
	void SetCoordinate(int _x1, int _y1, int _x2, int _y2)
	{
		cshipBegin.SetCoordinate(_x1, _y1);
		cshipEnd.SetCoordinate(_x2, _y2);
	}
	void AddHitTheShip()
	{
		if (KolHitTheShip != 3)
		{
			KolHitTheShip++;
		}
		if (KolHitTheShip == 3)
		{
			StatusOfShip = false;
		}
	}
	bool GetStatusOfShip()
	{
		return StatusOfShip;
	}
};
class FourDeckShip//Четырёхпалубный корабль
{
private:
	Coordinate cshipBegin;
	Coordinate cshipEnd;
	int KolHitTheShip;
	bool StatusOfShip;
public:
	FourDeckShip()
	{
		cshipEnd.SetCoordinate(0, 3);
		KolHitTheShip = 0;
		StatusOfShip = true;
	}
	void SetCoordinate(int _x1, int _y1, int _x2, int _y2)
	{
		cshipBegin.SetCoordinate(_x1, _y1);
		cshipEnd.SetCoordinate(_x2, _y2);
	}
	void AddHitTheShip()
	{
		if (KolHitTheShip != 4)
		{
			KolHitTheShip++;
		}
		if (KolHitTheShip == 4)
		{
			StatusOfShip = false;
		}
	}
	bool GetStatusOfShip()
	{
		return StatusOfShip;
	}
};
void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Добро пожаловать в игру Морской бой" << endl;
	cout << "Для начала необходимо расставить ваши корабли" << endl;
	int CoordinateGame[10][10] = { 0 };
	cout << "Введите поочерёдно координаты начала(x,y) и координаты конца четырёх палубного корабля" << endl;
	cout << "Если координаты введены неверно, потребуется ввести их ещё раз" << endl;
	int x4B=0;
	int y4B=0;
	int x4E=0;
	int y4E=0;
	do {
		if (((x4B < 0) || (x4B > 9)) || ((x4E < 0) || (x4E > 9)) || ((y4B < 0) || (y4B > 9)) || ((y4E < 0) || (y4E > 9)))
		{
			cin >> x4B >> y4B >> x4E >> y4E;
			cout << endl;
		}		
	} while (((x4B != x4E) && (y4B != y4E)) || ((abs(x4B - x4E) != 3) && (y4B == y4E)) || (abs(y4B - y4E) != 3) && (x4B == x4E));

}