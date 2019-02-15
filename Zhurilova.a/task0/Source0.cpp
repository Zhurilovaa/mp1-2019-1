#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <ctime>

class mytime
{
private:
	int hour;
	int min;
	int sec;
public:
	mytime()
	{
		hour = 12;
		min = 38;
		sec = 34;
	}
	void Vivod(mytime T)//Вывод времени
	{
		printf("%d:%d:%d\n", hour, min, sec);
	}
	void Set_time(mytime T)//Установка времени
	{
		printf("Введите последовательно часы, минуты и секунды\n");
		scanf_s("%d", &hour);
		scanf_s("%d", &min);
		scanf_s("%d", &sec);
	}
	mytime Time_difference( mytime T1, int Time0=45514)//Вычисление разницы
	{
		int Time1=0,TimeR=0;
		mytime Tr;		
		//Перевод в секунды Установленного
		Time1 = (T1.hour * 3600) + (T1.min * 60) + T1.sec;
		if (Time0>Time1)
		{
			TimeR = Time0 - Time1;
		}
		else if (Time0 < Time1)
		{
			TimeR = Time1 - Time0;
		}
		Tr.sec = TimeR % 60;//Осаток от деления на 60 - секунды разницы
		Tr.hour = TimeR / 3600;//Целая часть от деления на 3600 - часы разницы
		Tr.min = (TimeR - (Tr.hour*3600) - (Tr.sec)) / 60;//Минуты
		
		return Tr;
	}
	mytime Time_shift(mytime Tsdv, mytime T1, int prov1, int prov2, int Time0 = 45514)//Сдвиг времени
	{
		int Time1 = 0, TimeR = 0, Timesdv=0;
		mytime Tr;
		Timesdv = (Tsdv.hour * 3600) + (Tsdv.min * 60) + Tsdv.sec;
		Time1 = (T1.hour * 3600) + (T1.min * 60) + T1.sec;
		if (prov1 == 1)//Сдвиг в большую сторону
		{
			if (prov2 == 1)
			{
				TimeR = Time0 + Timesdv;
			}
			if (prov2 == 2)
			{
				TimeR = Time1 + Timesdv;
			}
		}
		if (prov1 == 2)
		{
			if (prov2 == 1)
			{
				TimeR = Time0 - Timesdv;
			}
			if (prov2 == 2)
			{
				TimeR = Time1 - Timesdv;
			}
		}
		while (TimeR < 0)
		{
			TimeR =TimeR*(-1);	
			TimeR = 86399 - TimeR;
			Tr.sec = TimeR % 60;//Осаток от деления на 60 - секунды разницы
			Tr.hour = TimeR / 3600;//Целая часть от деления на 3600 - часы разницы
			Tr.min = (TimeR - (Tr.hour * 3600) - (Tr.sec)) / 60;//Минуты					
		}
		while(TimeR > 86399)
		{
			TimeR = TimeR - 86300;
			Tr.sec = TimeR % 60;//Осаток от деления на 60 - секунды разницы
		    Tr.hour = TimeR / 3600;//Целая часть от деления на 3600 - часы разницы
		    Tr.min = (TimeR - (Tr.hour * 3600) - (Tr.sec)) / 60;//Минуты
		}
		if ((TimeR >= 0) && (TimeR <= 86399))
		{
			Tr.sec = TimeR % 60;//Осаток от деления на 60 - секунды разницы
			Tr.hour = TimeR / 3600;//Целая часть от деления на 3600 - часы разницы
			Tr.min = (TimeR - (Tr.hour * 3600) - (Tr.sec)) / 60;//Минуты
		}
		return Tr;
	}
	mytime& operator=(const mytime &T)
	{
		hour = T.hour;
		min = T.min;
		sec = T.sec;
		return *this;
	}

};

int main()
{
	setlocale(LC_ALL, "Rus");
	int exit=0, prov1=0,prov2=0;
	int v = -1;
	mytime T,T1,Tres,Tsdv;
	while (exit == 0)
	{
		printf("Что сделать:\n 1)Установить время;\n 2)Узнать время;\n 3)Вычислить разницу;\n 4)Сдвинуть время;\n 5)Закончить работу;\n");
		scanf_s("%d", &v);
		if (v == 1) {
			printf("Установка времени\n");
			T1.Set_time(T1);
			printf("Введенное вами время\n");
			T1.Vivod(T1);
		}
		if (v == 2) {
			printf("Узнать время\nСейчас\n");
			T1.Vivod(T1);
		}
		if (v == 3) {
			printf("Узнать разницу во времени\n");
			Tres = T1.Time_difference(T1);
			Tres.Vivod(Tres);
		}
		if (v == 4)
		{
			printf("Задайте сдвиг в часах минутах и секундах\n");
			Tsdv.Set_time(Tsdv);
			printf("В большую(1) или меньшую(2) сторону?\n");
			scanf_s("%d", &prov1);
			printf("Задать сдвиг для установленного времени(1) или для заданного позже(2)\n");
			scanf_s("%d", &prov2);
			Tres = Tsdv.Time_shift(Tsdv, T1, prov1, prov2);
			printf("Время с учетом сдвига\n");
			Tres.Vivod(Tres);
		}
		if (v == 5)
		{
			exit = 1;
		}
	}
	printf("Выход");
	scanf_s("%d", &exit);
}
