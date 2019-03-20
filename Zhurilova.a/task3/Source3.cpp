#define _CRT_SECURE_NO_WARNINGS
#include<locale.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
class Integral
{
private:
	double(*function)(double);//Указатель на используемую математическую функцию
	double leftBorder, rightBorder;//Границы отрезка вычисления
	int n;//Количество частей отрезка(равных)
	double result;//Результат вычисления интеграла
public:
	Integral()//Конструктор для вызова без параметров
	{
		function = exp;
		leftBorder = 0;
		rightBorder = 1;
		n = 1000;
		result = 0;
	}
	Integral(double _left, double _right, double(*_function)(double)=exp, int _n=1000)//Конструктор с параметрами
	{
		function = _function;
		leftBorder = _left;
		rightBorder = _right;
		n = _n;
		result = 0;
	}
	void SetFunction(double(*_function)(double))//Установить функцию
	{
		function = _function;
	}
	void SetBorders(double _left, double _right)//Установка границ интегрирования
	{
		leftBorder = _left;
		rightBorder = _right;
	}
	void SetNumberOfSegments(int _n)//Установка количества отрезков интегрирования
	{
		n = _n;
	}
	double GetLeftBorder()//Узнать левую границу
	{
		return leftBorder;
	}
	double GetRightBorder()//Узнать правую границу
	{
		return rightBorder;
	}
	double CalculateByLeftRectangle()//Метод левых прямоугольников
	{
		double h, left_i;
		int i;
		h = (rightBorder - leftBorder) / n;//Длина каждого отрезка отрезка
		left_i = leftBorder;//Левая граница i отрезка
		for (i = 0; i < n; i++)
		{
			result = result + function(left_i);
			left_i = left_i + h;
		}
		result = result * h;
		return result;
	}
	double	CalculateByRightRectangle()//Метод правых прямоугольников
	{
		double h, right_i;
		int i;
		h=(rightBorder -leftBorder) / n;//Длина каждого отрезка отрезка
		right_i = leftBorder + h;//Левая граница i отрезка
		for (i = 1; i <= n; i++)
		{
			result = result + function(right_i);
			right_i = right_i + h;
		}
		result = result * h;
		return result;
	}
	double	CalculateByMiddleRectangle()
	{
		double h, middle_i;
		int i;
		h= (rightBorder - leftBorder) / n;//Длина каждого отрезка отрезка
		middle_i = leftBorder + (h / 2);
		for (i = 1; i <= n; i++)
		{
			result = result + function(middle_i);
			middle_i = middle_i + h;
		}
		result = result * h;
		return result;
	}
	Integral& operator=(const Integral &_A)
	{
		function = _A.function;
		leftBorder = _A.leftBorder;
		rightBorder = _A.rightBorder;
		n = _A.n;
		result = _A.result;
	}
};

void main()
{
	setlocale(LC_ALL, "Rus");
	int exit = 0, vibor = 0, funcvibor=0, integmethod=3;
	double(*_function[11])(double)= { 0, sqrt, cos, sin, tan, acos, asin, atan, exp, log, log10 };
	int x;
	double left, right;
	int N;
	Integral A;
	double _result=0;
	while (exit = 0) {
		printf("Выберите действие:\n1)Задать текущую функцию\n2)Задать пределы интегрирования\n3)Узнать пределы интегрирования\n4)Задать число отрезков метода прямоугольников\n5)Выбрать метод вычисления\n6)Вычислить значение интеграла выбранным методом\n7)Вывести результат вычисления на экран\n");
		scanf_s("%d", &vibor);
		while ((vibor < 1) || (vibor > 7))
		{
			printf("Нет действия под таким номером!\n");
			scanf_s("%d", &vibor);
		}
		if (vibor == 1)
		{
			printf("Задание функции\n");
			printf("Выберите функцию, которую хотите использовать:\n1)Квадратный корень\n2)Косинус\n3)Синус\n4)Тангенс\n5)Арккосинус\n6)Арксинус\n7)Арктангенс\n8)Экспонента\n9)Натуральный логарифм\n10)Десятичный логарифм\n");
			scanf_s("%d", &funcvibor);
			while ((funcvibor < 1) || (funcvibor > 10))
			{
				printf("Нет функции под таким номером!\n");
				scanf_s("%d", &funcvibor);
			}
			A.SetFunction(_function[funcvibor]);
		}
		if (vibor == 2)
		{
			printf("Задать пределы интегрирования\nВведите сначала правую границу,а заетм левую\n");
			scanf_s("%lf %lf", &right, &left);
			while (right <= left)
			{
				printf("Неверно заданы границы!\n");
				scanf_s("%lf %lf", &right, &left);
			}
			A.SetBorders(left, right);
		}
		if (vibor == 3)
		{
			printf("Узнать пределы интегрирования\n");
			left = A.GetLeftBorder();
			right = A.GetRightBorder();
			printf("[%lf,%lf]\n", right, left);
		}
		if (vibor == 4)
		{
			printf("Введите число отрезков метода прямоугольников\n");
			scanf_s("%d", &N);
			while (N < 1)
			{
				printf("Неверно введено число отрезков!(Минимальное количество 1)\n");
				scanf_s("%d", &N);
			}
			A.SetNumberOfSegments(N);
		}
		if (vibor == 5)
		{
			printf("Выбор метода вычисления\n1)Левые прямоугольники\n2)Правые прямоугольни\n3)Средние прямоугольники\n");
			scanf_s("%d",&integmethod);
			while ((integmethod < 1) || (integmethod > 3))
			{
				printf("Неверно введен номер метода!\n");
				scanf_s("%d", &integmethod);
			}
		}
		if (vibor == 6)
		{
			if (integmethod == 1)
			{
				printf("Вычисление интеграла методом левых прямоугольников\n");
				_result = A.CalculateByLeftRectangle();
			}
			if (integmethod == 2)
			{
				printf("Вычисление интеграла методом правых прямоугольников\n");
				_result = A.CalculateByRightRectangle();
			}
			if (integmethod == 3)
			{
				printf("Вычисление интеграла методом средних прямоугольников\n");
				_result = A.CalculateByMiddleRectangle();
			}
		}
		if (vibor == 7)
		{
			_result = A.CalculateByMiddleRectangle();
			printf("Результат вычислений %lf\n", _result);
		}
		printf("Желаете выйти? Если да-введите любое число, если нет - введите 0\n");
		scanf("%d", &exit);
	}	
}