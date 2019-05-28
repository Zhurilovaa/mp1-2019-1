#pragma once
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>
#ifndef GAME_H
#define GAME_HPP
class Game
{
private:
	int MapLivePlayer[10][10];
	int MapComputerPlayer[10][10];
	int MapComputerForConsole[10][10];
	int MapPlayerForConsole[10][10];
public:
	Game();
	void SetColor(int text, int bg);
	void DrawCoordinateGame();
	bool TestMapPoz(int x, int y);
	void SetElementMap(int x, int y, int z, int WhatMap);
	void SetOkr(int x, int y, int val, int WhatMap);
	void SetOkrShip(int x, int y, int val, int WhatMap);
	void OkrEnd(int WhatMap);
	bool NewPaluba(int x, int y, int Map[10][10]);
	void MakeDeckShip(int KolPaluba);
	void MakeOneDeckShip();
	void CompareMapPlayer();
	bool InstallationOfTheShip(int x, int y, int napr, int KolPaluba);
	bool InstallationOfTheShipOneDeck(int x, int y);
	int TestEndGame();
	void SetOkrPodbit(int x, int y, int WhatMap);
	void SetOkrShipPodbit(int x, int y, int WhatMap);
	void AnalizUbit(int x, int y, int KolPalub, int WhatMap);
	void TestUbit(int x, int y, int WhatMap);
	bool CompHod();
	bool LiveHod(int x, int y);
};
#endif // !GAME_H

