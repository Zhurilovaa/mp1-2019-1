﻿#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include<stdio.h>
#include <iostream>
class Matrix
{
private:
	int n;
	int matrix[8][8];
	bool Diagonal;
public:
	Matrix()//Конструктор
	{
		n = 8;
		Diagonal = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = rand() % 1000 + 0;
			}
		}
	}
	Matrix(int _n)
	{
		n = _n;
	}
	void PrintMatrix()//Вывод матрицы
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d  ", matrix[i][j]);
			}
			printf("\n");
		}
	}
	void SetSize(int _n)//Установка размера матрицы
	{
		if ((_n > 1) && (_n < 9))
		{
			n = _n;
		}
		else if ((_n < 2) || (n > 8)) {
			printf("Неверно задан размер\n");
		}
	}
	int GetSize() const//Узнать размер матрицы
	{
		return n;
	}
	void SetElement(int a, int i, int j)//Установка элемента
	{
		if ((i >= 0) && (i < n) && (j >= 0) && (j < n))
		{
			matrix[i][j] = a;
		}
		else printf("Нет элемента с таким индексом в матрице\n");
	}
	int GetElement(int &i, int &j)//Узнать элемент матрицы по индексам
	{
		return matrix[i][j];
	}
	bool DiagonalMatrix()//Проверка на диагональное преобладание
	{
		int i, j, sum = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 1; j < n; j++)
			{
				sum = sum + matrix[i][j];
			}
			if (matrix[i][i] >= sum)
			{
				Diagonal = true;
			}
		}		
		return Diagonal;
	}
	Matrix MatrixAdd(const Matrix &_m)//Сложение матриц
	{
		if (n == _m.n)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					matrix[i][j] = _m.matrix[i][j] + matrix[i][j];
				}
			}
		}
		else printf("У матриц не совпадает размер\n");
		return *this;
	}
	Matrix& operator=(const Matrix &m)//Оператор присваивания
	{
		n = m.n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = m.matrix[i][j];
			}
		}
		return *this;
	}
};
void main()
{
	setlocale(LC_ALL, "Rus");
	Matrix M1, M2, M3;
	int elem;
	int N, N1;
	bool diag=false;
	int exit=0,v = 0,i,j;
	while (exit == 0)
	{
		printf("Выберите действие:\n");
		printf("1-Задать размер матрицы\n2-Узнать размер матрицы\n3-Задать элемент матрицы по его индексам\n4-Узнать элемент матрицы по его индексам\n5-Проверить, обладает ли матрица диагональным преобладанием\n6-Вычислить сумму двух матриц одного размера\n");
		scanf_s("%d", &v);
		while ((v < 1) || (v > 6))
		{
			printf("Нет действия под таким номером!\n");
			scanf_s("%d", &v);
		}		
		if (v == 1) {
			printf("Введите размер матрицы nхn, n от 2 до 8 включительно\n");
			scanf_s("%d", &N);
			while ((N < 2) || (N > 8))
			{
				printf("Неправильно введен размер!\n");
				scanf_s("%d", &N);
			}
			M1.SetSize(N);
		}
		if (v == 2) {			
			N=M1.GetSize();
			printf("Размер матрицы %d\n", N);
		}
		if (v == 3) {
			printf("Введите номер строки и столбца нужного элемента\n");
			scanf_s("%d %d", &i, &j);
			while ((i < 0) || (i > 7) || (j < 0) || (j > 7))
			{
				printf("Нет элемента с таким индексом\n");
				scanf_s("%d %d", &i, &j);
			}
			printf("Введите значение элемента матрицы(целое число)\n");
			scanf_s("%d", &elem);
			M1.SetElement(elem, i, j);
		}
		if (v == 4) {
			printf("Введите номер строки и столбца нужного элемента\n");
			scanf_s("%d %d", &i, &j);
			while ((i < 0) || (i > 7) || (j < 0) || (j > 7))
			{
				printf("Нет элемента с таким индексом\n");
				scanf_s("%d %d", &i, &j);
			}
			elem=M1.GetElement(i, j);
			printf("Элемент под таким индексом %d",elem);
		}
		if (v == 5) {
			printf("Обладает ли матрица диагональным преобладанием?\n");
			diag=M1.DiagonalMatrix();
			if (diag == true)
			{
				printf("Матрица облидает диагональным преобладанием\n");
			}
			else printf("Матрица не обладет диагональным преобладанием\n");
		}
		if(v==6){
			printf("Сложение матриц\n");
			printf("Установите размеры 1 и 2 матриц\n");
			scanf_s("%d", &N);
			M1.SetSize(N);
			M2.SetSize(N);
			printf("Первая матрица\n");
			M1.PrintMatrix();
			printf("Вторая матрица\n");
			M2.PrintMatrix();
			printf("Их сумма\n");
			M3.SetSize(N);
			M3 = M1.MatrixAdd(M2);
			M3.PrintMatrix();
		}
		printf("\nХотите выйти из программы?\n");
		scanf_s("%d", &exit);
	}
}