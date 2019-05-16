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
	Coordinate& operator=(const Coordinate &_XY)
	{
		x = _XY.x;
		y = _XY.y;
		return *this;
	}
	friend std::ostream& operator<< (std::ostream &out, const Coordinate &C);
};
std::ostream& operator<< (std::ostream &out, const Coordinate &C)
{
	out << C.x << C.y << endl;
	return out;
}
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
	void SetCoordinate(Coordinate _ship)
	{
		cship=_ship;
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
		KolHitTheShip = 0;
		StatusOfShip = true;
	}
	void SetCoordinate(Coordinate _begin, Coordinate _end)
	{
		cship1= _begin;
		cship2= _end;
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
		KolHitTheShip = 0;
		StatusOfShip = true;
	}
	void SetCoordinate(Coordinate _begin, Coordinate _end)
	{
		cshipBegin=_begin;
		cshipEnd=_end;
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
		KolHitTheShip = 0;
		StatusOfShip = true;
	}
	void SetCoordinate(Coordinate _begin, Coordinate _end)
	{
		cshipBegin= _begin;
		cshipEnd=_end;
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
	Coordinate GetCoordinateBegin()
	{
		return cshipEnd;
	}
	Coordinate GetCoordinateEnd()
	{
		return cshipBegin;
	}
	bool GetStatusOfShip()
	{
		return StatusOfShip;
	}
};
void main()
{
	setlocale(LC_ALL, "Rus");
	bool vvod3 = true;
	cout << "Добро пожаловать в игру Морской бой" << endl;
	cout << "Для начала необходимо расставить ваши корабли" << endl;
	int CoordinateGame[10][10] = { 0 };
	cout << "Введите поочерёдно координаты начала(x,y) и координаты конца четырёхпалубного корабля" << endl;
	int x4B=0;
	int y4B=0;
	int x4E=0;
	int y4E=0;
	cin >> x4B >> y4B >> x4E >> y4E;
	cout << endl;
	while (((x4B != x4E) && (y4B != y4E)) || ((abs(x4B - x4E) != 3) && (y4B == y4E)) || (abs(y4B - y4E) != 3) && (x4B == x4E))
	{
		cout << "Координаты введены неверно! Попробуйте ещё раз" << endl;
		cin >> x4B >> y4B >> x4E >> y4E;
		cout << endl;
	}
	while (((x4B < 0) || (x4B > 9)) || ((x4E < 0) || (x4E > 9)) || ((y4B < 0) || (y4B > 9)) || ((y4E < 0) || (y4E > 9)))
	{
		cout << "Координаты выходят за диапозон значений! Попробуйте ещё раз" << endl;
		cin >> x4B >> y4B >> x4E >> y4E;
		cout << endl;
	}
	if (x4B == x4E)
	{
		CoordinateGame[x4B][y4B] = 1;
		CoordinateGame[x4B][y4B+1] = 1;
		CoordinateGame[x4B][y4B + 2] = 1;
		CoordinateGame[x4E][y4E] = 1;
	}
	if (y4B == y4E)
	{
		CoordinateGame[x4B][y4B] = 1;
		CoordinateGame[x4B + 1][y4B] = 1;
		CoordinateGame[x4B + 2][y4B ] = 1;
		CoordinateGame[x4E][y4E] = 1;
	}	
	Coordinate begin(x4B, y4B);
	Coordinate end(x4E, y4E);
	FourDeckShip Myship4;
	Myship4.SetCoordinate(begin, end);
	cout << Myship4.GetCoordinateBegin() << " " << Myship4.GetCoordinateEnd << endl;
	cout << "Введите поочерёдно координаты начала(x,y) и координаты конца трёхпалубного корабля, сначала первого потом второго" << endl;
	cout << "Внимание! Корабли не должны стоять в соседних клетках" << endl;
	int x3B = 0;
	int y3B = 0;
	int x3E = 0;
	int y3E = 0;
	while (vvod3 == true)
	{
		cin >> x3B >> y3B >> x3E >> y3E;
		cout << endl;
		while (((x3B != x3E) && (y3B != y3E)) || ((abs(x3B - x3E) != 2) && (y3B == y3E)) || (abs(y3B - y3E) != 3) && (x3B == x3E))
		{
			cout << "Координаты введены неверно! Попробуйте ещё раз" << endl;
			cin >> x3B >> y3B >> x3E >> y3E;
			cout << endl;
		}
		while (((x3B < 0) || (x3B > 9)) || ((x3E < 0) || (x3E > 9)) || ((y3B < 0) || (y3B > 9)) || ((y3E < 0) || (y3E > 9)))
		{
			cout << "Координаты выходят за диапозон значений! Попробуйте ещё раз" << endl;
			cin >> x3B >> y3B >> x3E >> y3E;
			cout << endl;
		}
		
	}
	


}