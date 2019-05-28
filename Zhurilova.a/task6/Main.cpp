#define _CRT_SECURE_NO_WARNINGS
#include "Game.hpp"
#include <conio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	Game MyGame;
	int x, y, napr;
	bool compHod = false;
	int endg = 0;
	cout << "Добро пожаловать!" << endl;
	MyGame.DrawCoordinateGame();
	MyGame.MakeDeckShip(4);
	MyGame.MakeDeckShip(3);
	MyGame.MakeDeckShip(3);
	MyGame.MakeDeckShip(2);
	MyGame.MakeDeckShip(2);
	MyGame.MakeDeckShip(2);
	MyGame.MakeOneDeckShip();
	cout << "Расставьте свои корабли" << endl;
	cout << "Начнем с 4 палубного." << endl;
	do {
		cout << "Введите координаты начала корабля и его направление : 0 - вверх, 1 - вправо, 2 - вниз, 3 - влево." << endl;
		cin >> x >> y >> napr;
		cout << endl;
	} while (MyGame.InstallationOfTheShip(x, y, napr, 4) == false);
	MyGame.CompareMapPlayer();
	MyGame.DrawCoordinateGame();
	cout << "Теперь трёхпалубные! Вперёд!" << endl;
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
			cout << "Первый корабль:" << endl;
		if (i == 1)
			cout << "Теперь второй корабль:" << endl;
		do {
			cout << "Введите координаты начала корабля и его направление : 0 - вверх, 1 - вправо, 2 - вниз, 3 - влево." << endl;
			cin >> x >> y >> napr;
			cout << endl;
		} while (MyGame.InstallationOfTheShip(x, y, napr, 3) == false);
		MyGame.CompareMapPlayer();
		MyGame.DrawCoordinateGame();
	}
	cout << "Дальше, двухпалубные..." << endl;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			cout << "Первый корабль:" << endl;
		if (i == 1)
			cout << "Теперь второй корабль:" << endl;
		if (i == 2)
			cout << "Ещё один, последний!" << endl;
		do {
			cout << "Введите координаты начала корабля и его направление : 0 - вверх, 1 - вправо, 2 - вниз, 3 - влево." << endl;
			cin >> x >> y >> napr;
			cout << endl;
		} while (MyGame.InstallationOfTheShip(x, y, napr, 2) == false);
		MyGame.CompareMapPlayer();
		MyGame.DrawCoordinateGame();
	}
	cout << "Последнее усилие, однопалубные..." << endl;
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
			cout << "Первый корабль:" << endl;
		if (i == 1)
			cout << "Теперь второй корабль:" << endl;
		if (i == 2)
			cout << "Ещё один, последний!" << endl;
		if (i == 3)
			cout << "Последний припоследний!" << endl;
		do {
			cout << "Введите координаты начала корабля" << endl;
			cin >> x >> y;
			cout << endl;
		} while (MyGame.InstallationOfTheShipOneDeck(x, y) == false);
		MyGame.CompareMapPlayer();
		MyGame.DrawCoordinateGame();
	}
	cout << "ОК! Игра началась. Первым ходите вы, введите координату выстрела" << endl;
	while (endg == 0)
	{
		while (compHod == false)
		{
			cout << "Ваш ход:" << endl;
			cin >> x >> y;
			cout << endl;
			while (MyGame.TestMapPoz(x, y) == false)
			{
				cout << "Таких координат нет на поле! Попробуйте ещё раз" << endl;
				cin >> x >> y;
				cout << endl;
			}
			compHod = MyGame.LiveHod(x, y);
			MyGame.CompareMapPlayer();
			endg = MyGame.TestEndGame();
			MyGame.DrawCoordinateGame();
		}
		while (compHod == true)
		{
			cout << "Ход Компьютера:" << endl;
			compHod = MyGame.CompHod();
			MyGame.CompareMapPlayer();
			endg = MyGame.TestEndGame();
			MyGame.DrawCoordinateGame();
		}
	}
	if (endg == 1)
	{
		cout << "Поздравляю вы выиграли!" << endl;
	}
	if (endg == 2)
	{
		cout << "Печалька, вы проиграли. Ну, ничего повезет в другой раз!" << endl;
	}
	_getch();
}