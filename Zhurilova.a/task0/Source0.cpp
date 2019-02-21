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
	void Set_Time(int h, int m, int s)//Установка времени
	{
		hour =h;
		min = m;
		sec = s;
	}
	int Time_difference(int h, int m, int s)//Вычисление разницы
	{
		h = abs(h - hour);
		m= abs(m - min);
		s = abs(s - sec);
		return h,m,s;
	}
	int Time_shiftMore(int h, int m, int s)//Сдвиг времени в большую сторону
	{
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
		return h,m,s;
	}
	int Time_shiftLess(int h, int m, int s)//Сдвиг времени
	{
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
		return h,m,s;
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
			printf("Введите последовательно часы, минуты и секунды\n");
			scanf_s("%d%d%d", &h, &m, &s);
			printf("Введенное вами время\n");
			T.Set_Time(h,m,s);
			T.Print();
		}
		if (v == 2) {
			printf("Узнать время\nСейчас\n");
			T.Print();
		}
		if (v == 3) {
			printf("Узнать разницу во времени\n");
			printf("Задайт время, разницу с которым нужно рассчитать\n");
			printf("Введите последовательно часы, минуты и секунды\n");
			scanf_s("%d%d%d", &h, &m, &s);
			printf("Введенное вами время\n");
			T1.Set_Time(h, m, s);
			T1.Print();
			T1.Time_difference(h, m, s);
			printf("Разница\n");
			T1.Print();
		}
		if (v == 4)
		{
			printf("Задайте сдвиг в часах минутах и секундах\n");
			printf("Введите последовательно часы, минуты и секунды\n");
			scanf_s("%d%d%d", &h, &m, &s);
			printf("Введенное вами сдвиг\n");
			T1.Set_Time(h, m, s);
			T1.Print();
			printf("В большую(1) или меньшую(2) сторону?\n");
			scanf_s("%d", &prov1);
			if (prov1 == 1)
			{
				T1.Time_shiftMore(h, m, s);
				printf("Время со сдвигом\n");
				T1.Print();
			}
			else if (prov1 == 2)
			{
				T1.Time_shiftLess(h, m, s);
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
