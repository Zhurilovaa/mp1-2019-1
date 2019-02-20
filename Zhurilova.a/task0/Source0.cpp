#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <ctime>
#include <cmath>
class MyTime
{
private:
	int hour;
	int min;
	int sec;
public:
	MyTime()
	{
		hour = 12;
		min = 38;
		sec = 34;
	}
	MyTime(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	void Print()//Вывод времени
	{
		printf("%d:%d:%d\n", hour, min, sec);
	}
	int Scan_Time(int &h, int &m, int &s)//Установка времени
	{
		printf("Введите последовательно часы, минуты и секунды\n");
		scanf_s("%d%d%d", &h,&m,&s);
		return h, m, s;
	}
	void Set_Time(int (&Time)[3])//Установка времени
	{
		hour = Time[0];
		min = Time[1];
		sec = Time[2];
	}
	int Time_difference(int(&Time)[3])//Вычисление разницы
	{
		Time[0] = abs(Time[0] - hour);
		Time[1] = abs(Time[1] - min);
		Time[2] = abs(Time[2] - sec);
		return Time[3];
	}
	int Time_shift1(int(&Time)[3])//Сдвиг времени в большую сторону
	{
		int h = Time[0], m = Time[1], s = Time[2];
		h = h + hour;
		m = m + min;
		s = s + sec;
		if (s > 59)
		{
			m = m + (s / 60);
			s = s - 59;
			if (m > 59)
			{
				h = h + (m / 60);
				m = m - 59;
			}
		}
		Time[0] = h;
		Time[1] = m;
		Time[2] = s;
		return Time[3];
	}
	int Time_shift2(int(&Time)[3])//Сдвиг времени
	{
		int h = Time[0], m = Time[1], s = Time[2];
		h = hour-h;
		m = min-m;
		s =sec-s;
		if (s < 0)
		{
			m = m - (s / 60);
			s = 59 - s;
			if (m < 0)
			{
				h = h - (m / 60);
				m = 59 - m;
			}
		}
		Time[0] = h;
		Time[1] = m;
		Time[2] = s;
		return Time[3];
	}
	MyTime& operator=(const MyTime &T)
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
	MyTime T, T1;
	int Time[3] = { 0 };
	int h = Time[0];
	int m = Time[1];
	int s = Time[2];
	while (exit == 0)
	{
		printf("Что сделать:\n 1)Установить время;\n 2)Узнать время;\n 3)Вычислить разницу;\n 4)Сдвинуть время;\n 5)Закончить работу;\n");
		scanf_s("%d", &v);
		if (v == 1) {
			printf("Установка времени\n");
			T.Scan_Time(Time[0],Time[1],Time[2]);
			printf("Введенное вами время\n");
			T.Set_Time(Time);
			T.Print();
		}
		if (v == 2) {
			printf("Узнать время\nСейчас\n");
			T.Print();
		}
		if (v == 3) {
			printf("Узнать разницу во времени\n");
			printf("Задайт время, разницу с которым нужно рассчитать\n");
			T1.Scan_Time(Time[0], Time[1], Time[2]);
			printf("Введенное вами время\n");
			T1.Set_Time(Time);
			T1.Print();
			T1.Time_difference(Time);
			printf("Разница\n");
			T1.Print();
		}
		if (v == 4)
		{
			printf("Задайте сдвиг в часах минутах и секундах\n");
			T1.Scan_Time(Time[0], Time[1], Time[2]);
			printf("Введенное вами сдвиг\n");
			T1.Set_Time(Time);
			T1.Print();
			printf("В большую(1) или меньшую(2) сторону?\n");
			scanf_s("%d", &prov1);
			if (prov1 == 1)
			{
				T1.Time_shift1(Time);
				printf("Время со сдвигом\n");
				T1.Print();
			}
			else if (prov1 == 2)
			{
				T1.Time_shift2(Time);
				printf("Время со сдвигом\n");
				T1.Print();
			}			
		}
		if (v == 5)
		{
			exit = 1;
		}
	}
	printf("Выход");
	scanf_s("%d", &exit);
}
