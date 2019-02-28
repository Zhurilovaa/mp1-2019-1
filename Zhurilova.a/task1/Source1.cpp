#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include<stdio.h>

class Matrix
{
private:
	int n;
	int matrix[8][8];
public:
	Matrix(int m[][],int n = 2)//!!!!!!!!!!!!
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = m[i][j];
			}
		}
	}
	void PrintMatrix()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d", matrix[i][j]);
			}
			printf("");//!!!!!!!!!!!!!!!!!
		}
	}
	void Set_Size(int _n)
	{
		if ((n >= 2) && (n <= 8))
		{
			n = _n;
		}
		else throw n; //"Неверно задан размер"
	}	
public:
	void Print_Size() const
	{
		printf("Размер матрицы %d", n);
	}
	void Set_element(int a, int i, int j)
	{
		float mistakeind;
		if ((i >= 0) && (i < n) && (j >= 0) && (j < n))
		{
			matrix[i][j] = a;
		}
		else printf("Нет элемента с таким индексом в матрице");
	}
	void Print_element(int i, int j) const
	{
		if ((i >= 0) && (i < n) && (j >= 0) && (j < n))
		{
			printf("Элемент под таким индексом %d", matrix[i][j]);
		}
		else printf("Нет элемента под таким индексом");
	}
	bool Diagonal_matrix()
	{
		bool diagonal=false;
		int i, j, sum=0;
		for (i = 0;i < n; i++)
		{
			for (j = 1; j < n; j++)
			{
				sum = sum + matrix[i][j];
			}
			if (matrix[i][i] >= sum)
			{
				diagonal= true;
			}			
		}
		return diagonal;
	}
	Matrix Add(Matrix _m)
	{
		if (n == _m.n)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					_m.matrix[i][j] = _m.matrix[i][j] + matrix[i][j];
				}
			}
		}
		else printf("У матриц не совпадает размер");
		return _m;
	}
	Matrix& operator=(const Matrix &m)
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


}