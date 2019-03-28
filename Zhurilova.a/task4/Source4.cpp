#define _CRT_SECURE_NO_WARNINGS
#include<locale.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class Data//Класс дата
{
private:
	int year;//Год
	int month;//Месяц
	int day;//День
public:
	Data(int _d=1, int _m=1, int _y=2000)//Конструктор
	{
		SetData(_d,_m,_y);
	}
	void SetData(int _d, int _m, int _y);//Установить дату	
	int GetDataYear()//Получить год
	{
		return year;
	}
	int GetDataMonth()//Получить месяц
	{
		return month;
	}
	int GetDataDay()//Получить день
	{
		return day;
	}
	const bool operator == (const Data &D2)//Перегрузка ==
	{
		if ((day == D2.day) && (month == D2.month) && (year == D2.year))
			return true;
		return false;
	}
	Data& operator=(const Data & _D)//Оператор присваивания
	{
		year = _D.year;
		month = _D.month;
		day = _D.day;
	}
};
class Film//Класс фильм
{
private:
	string name;//Имя файла
	string film_director;//Режиссер
	string screenwriter;//Сценарист
	string composer;//Композитор
	Data releasedate;//Дата выхода
	double filmfees;//Сборы в млн. руб.
public:
	//Конструктор
	Film(string _name = "Название фильма", string _film_director = "Режиссер", string _screenwriter = "Сценарист", string _composer = "Композитор", double _filmfees = 1, Data _releasedate = (1, 12, 2000))
	{
		SetFilm(_name, _film_director, _screenwriter, _composer, _filmfees, _releasedate);
	}
	//Установить параметры фильма
	void SetFilm(string _name, string _film_director, string _screenwriter, string _composer, double _filmfees, Data _releasedate);
	void SetName(string _name)//Установить имя фильма
	{
		name = _name;
	}
	string GetName()//Получить имя фильма
	{
		return name;
	}
	string GetFilmDirector()//Получить имя режессера
	{
		return film_director;
	}
	string GetScreenwriter()//Получить имя сценариста
	{
		return screenwriter;
	}
	string GetComposer()//Получить имя композитора
	{
		return composer;
	}
	double GetFilmFees()//Получить сборы в млн. руб.
	{
		return filmfees;
	}
	Data GetData()//Получить дату выхода в прокат
	{
		return releasedate;
	}
	//Оператор присваивания
	Film& operator=(const Film &_F)
	{
		name = _F.name;
		film_director = _F.film_director;
		screenwriter = _F.screenwriter;
		composer = _F.composer;
		filmfees = _F.filmfees;
		releasedate = _F.releasedate;
	}
};
class FilmLibrary//Класс фильмотека
{
private:
	vector <Film> FilmLib;//Массив фильмов
	int N = FilmLib.size();//Количество фильмов
public:
	FilmLibrary();//Конструктор
	void AppendFilm(Film _film);//Добавить фильм
	int AlphabeticalComparisons(Film &_film);//Сравнение по алфавиту
	void ChangeData(Film _film, int &_i);//Изменить данные фильма
	int FindFilm(string _name, Data _releasedate);//Поиск фильма
	Film GetFilm(int _i);//Получить фильм
	int GetSize();//Получить количество фильмов
	void FindDirector(FilmLibrary &MyFilmsR,string _stringR);//Поиск фильмов по режиссеру
	void FindData(FilmLibrary &MyFilms, Data _releasedate);//Поиск фильмов по году
	void FindFilmsFees(FilmLibrary MyFilms, int sizefilms);//Поиск фильмов по наибольшим сборам
	void DeleteFilm(int i);//Удалить фильм
	void WriteToFile();//Запись фильмотеки в файл
	void ReadFromFile();//Чтение из файла
};
void Data::SetData(int _d, int _m, int _y)//Установить дату
{
	if ((_y <= 2019) && (_y > 1894))
	{
		if ((_m < 13) && (_m > 0))
		{
			if (_m == 2)
			{
				month = _m;
				if ((_d > 29) || (_d < 0))
					throw "В этом месяце нет такого числа";
				else
					day = _d;
			}
			if ((_d < 32) || (_d > 0))
			{
				day = _d;
				month = _m;
				year = _y;
			}
		}
	}
}
//Установить параметры фильма
void Film::SetFilm(string _name, string _film_director, string _screenwriter, string _composer, double _filmfees, Data _releasedate)
{	
	name = _name;
	film_director = _film_director;
	screenwriter = _screenwriter;
	composer = _composer;
	filmfees = _filmfees;
	releasedate = _releasedate;
}
FilmLibrary::FilmLibrary()//Конструктор для FilmLibrary
{
	Film film0, film1, film2;
	string name0 = "1+1";
	string name1 = "Капитан Марвел";
	string name2 = "Фантастические твари и где они обитают";
	string film_director0 = "Оливье Накаш";
	string film_director1 = "Анна Боден";
	string film_director2 = "Дэвид Йейтс";
	string screenwriter0 = "Эрик Толедано";
	string screenwriter1 = "Райан Флек";
	string screenwriter2 = "Дж. К. Роулинг";
	string composer0 = "Людовико Эйнауди";
	string composer1 = "Пинар Топрак";
	string composer2 = "Джеймс Ньютон Ховард";
	double filmfees0 = 426.589;
	double filmfees1 = 911.666;
	double filmfees2=814.038;	
	Data releasedate0(26, 4, 2011);
	Data releasedate1(7, 3, 2019);
	Data releasedate2(10,11,2016);	
	film0.SetFilm(name0, film_director0, screenwriter0, composer0, filmfees0, releasedate0);
	film1.SetFilm(name1, film_director1, screenwriter1, composer1, filmfees1, releasedate1);
	film2.SetFilm(name2, film_director2, screenwriter2, composer2, filmfees2, releasedate2);
	FilmLib.reserve(3);
	FilmLib.at(0) = (film0);
	FilmLib.at(1) = (film1);
	FilmLib.at(2) = (film2);
}
int FilmLibrary::AlphabeticalComparisons(Film &_film)//Сортировка по алфавиту
{
	string namef = string(_film.GetName());
	string namelib;
	int i, j;
	int index = -1;
	bool Comparisons;
	for (i = 0; i < N; i++)
	{
		namelib = string(FilmLib[i].GetName());
		Comparisons = namef > namelib;
		if ((Comparisons == false) && (i > 0))
		{
			index = i - 1;
			break;
		}
		else
			if (i == 0)
				index = 0;
		if ((Comparisons == true) && (i < N))
		{
			index = i + 1;
			break;
		}
		else
			if (i == N)
				index = N + 1;
	}
	return index;
}
void FilmLibrary::AppendFilm(Film _film)//Добавить фильм
{
	int index = AlphabeticalComparisons(_film);
	FilmLib.push_back(_film);
	N = FilmLib.size();
	Film temp;
	for (int i = index; i < N-1; i++)
	{
		temp = FilmLib[i];
		FilmLib[i] = FilmLib[N-1];
		FilmLib[N-1] = temp;
	}
}
void FilmLibrary::ChangeData(Film _film, int &_i)//Изменить данные фильма
{
	string _name=FilmLib[_i].GetName();
	_film.SetName(_name);
	FilmLib[_i] = _film;	
}
int FilmLibrary::FindFilm(string _name, Data _releasedate)//Найти фильм
{
	int i = 0;
	int number;
	bool Comparisons;
	Data filmdata;
	for (i = 0; i < N; i++)
	{
		Comparisons = (FilmLib[i].GetName() == _name);
		filmdata = FilmLib[i].GetData();
		if ((filmdata == _releasedate) && (Comparisons == true))
			number = i;
	}
	return i;
}
Film FilmLibrary::GetFilm(int _i)//Получить фильм
{
	return FilmLib[_i];
}
int FilmLibrary::GetSize()//Получить количество фильмов
{
	return N;
}
void FilmLibrary::FindDirector(FilmLibrary &MyFilms,string _stringR)//Поиск фильмов по режиссеру
{
	int j = 0;
	Film film;
	for (int i = 0; i < N; i++)
	{
		film = MyFilms.GetFilm(i);
		string director = film.GetFilmDirector();
		if (director == _stringR)
		{
			FilmLib[j] = MyFilms.GetFilm(i);
			j++;
		}
	}
}
void FilmLibrary::FindData(FilmLibrary &MyFilms, Data _releasedate)//Поиск фильмов по году
{
	int j = 0;
	Film film;
	for (int i = 0; i < N; i++)
	{
		film = MyFilms.GetFilm(i);
		Data releasedateD = film.GetData();
		if (releasedateD == _releasedate)
		{
			FilmLib[j] = MyFilms.GetFilm(i);
			j++;
		}
	}
}
void FilmLibrary::FindFilmsFees(FilmLibrary MyFilms, int sizefilms)//Поиск заданного числа фильмов с наибольшими сборами
{
	FilmLibrary Temp;
	Temp = MyFilms;
	int j = 0;
	int money;
	Film film1,film2;
	Film max;
	int index;
	while (j < sizefilms)
	{
		for (int i = 0; i < N - 1; i++)
		{
			film1 = Temp.GetFilm(i);
			film2 = Temp.GetFilm(i + 1);
			if (film1.GetFilmFees >= film2.GetFilmFees)
			{
				max = film1;
				index = i;
			}
			else
			{
				max = film2;
				index = i + 1;
			}							
		}
		Temp.DeleteFilm(index);
		FilmLib[j] = max;
		j++;
	}	
}
void FilmLibrary::DeleteFilm(int i)//Удалить фильм
{
	Film temp;
	for (int j = i; i < N-1; i++)
	{
		temp = FilmLib[i];
		FilmLib[i] = FilmLib[i+1];
	}
	FilmLib.pop_back();
}
void FilmLibrary::WriteToFile()//Запись фильмотеки в файл
{
	ofstream fout;
	fout.open("MyFilms.txt");
	for (int i = 0; i < N; i++)
	{
		string name = FilmLib[i].GetName();
		string filmdirector = FilmLib[i].GetFilmDirector();
		string screenwriter = FilmLib[i].GetScreenwriter();
		string composer = FilmLib[i].GetComposer();
		Data releasedate = FilmLib[i].GetData();
		int year = releasedate.GetDataYear();
		int month = releasedate.GetDataMonth();
		int day = releasedate.GetDataDay();
		double filmfees = FilmLib[i].GetFilmFees();
		fout <<name<< ' '<<filmdirector<< ' ' <<screenwriter<< ' ' <<composer<< ' ' <<day<<'.'<<month<<'.'<<year<< ' ' <<filmfees;
	}
	fout.close();
}
void FilmLibrary::ReadFromFile()//Чтения фильмотеки из файла
{
	char string[150];
	ifstream fin("MyFilms.txt");
	for (int i = 0; i < N; i++)
	{
		fin >> string;
		for (int j = 0; j < strlen(string); j++)
		{
			cout << string[j];
		}
		cout << "\n";
	}
}
void main()
{
	string stringName;
	string stringR;
	string stringS;
	string stringC;
	int day, month, year, ind;
	int sizefilms, N;
	Data releasedate;
	double filmfees;
	Film film1, film2;
	FilmLibrary MyFilms,MyFilmsR, MyFilmsD,MyFilms6,MyFilms7;
	int exit = 0, vibor=0;
	while (exit == 0)
	{
		printf("Выберите действия:1)Добавить фильм\n2)Изменить данные выбранного фильма\n3)Найти фильм по названию и году\n4)Выдать все фильмы заданного режиссера\n5)Выдать все фильмы, вышедшие в прокат в выбранном году\n6)Выдать заданное число фильмов с наибольшими сборами\n7)Выдать заданное число фильмов с наибольшими сборами в выбранном году\n8)Узнать текущее число фильмов\n9)Удалить фильм\n10)Сохранить фильмотеку в файл\n11)Считать фильмотеку из файла\n");
		scanf_s("%d", &vibor);
		while ((vibor < 1) || (vibor > 11))
		{
			printf("Нет действия под таким номером!\n");
			scanf_s("%d", &vibor);
		}
		if (vibor == 1)//Добавить фильм
		{
			printf("Введите название фильма\n");
			scanf("&s\n", &stringName);
			printf("Введите режиссера\n");
			scanf("&s\n", &stringR);
			printf("Введите сценариста\n");
			scanf("&s\n", &stringS);
			printf("Введите композитора\n");
			scanf("&s\n", &stringC);
			printf("Введите дату выхода в прокат\n");
			scanf("&d &d &d\n", &day, &month, &year);
			releasedate.SetData(day, month, year);
			printf("Введите мировые сборы\n");
			scanf("&d\n", &filmfees);
			film1.SetFilm(stringName, stringR, stringS, stringC, filmfees, releasedate);
			MyFilms.AppendFilm(film1);
			MyFilms.WriteToFile();
		}
		if (vibor == 2)//Изменить данные выбранного фильма
		{
			MyFilms.WriteToFile();
			MyFilms.ReadFromFile();
			printf("Введите номер строки, начиная с 1(ту, в которой написан фильм, который желаете изменить\n");
			scanf("%d", &ind);
			printf("Введите режиссера\n");
			scanf("&s\n", &stringR);
			printf("Введите сценариста\n");
			scanf("&s\n", &stringS);
			printf("Введите композитора\n");
			scanf("&s\n", &stringC);
			printf("Введите дату выхода в прокат\n");
			scanf("&d &d &d\n", &day, &month, &year);
			releasedate.SetData(day, month, year);
			printf("Введите мировые сборы\n");
			scanf("&d\n", &filmfees);
			stringName=film1.GetName();
			film1.SetFilm(stringName, stringR, stringS, stringC, filmfees, releasedate);
			MyFilms.ChangeData(film1,ind);
			MyFilms.WriteToFile();
		}
		if (vibor == 3)//Найти фильм по названию и году
		{
			printf("Введите название фильма\n");
			scanf("&s\n", &stringName);
			printf("Введите год выхода в прокат\n");
			scanf("&d &d &d\n", &day, &month, &year);
			releasedate.SetData(day, month, year);
			ind=MyFilms.FindFilm(stringName, releasedate);
			film2 = MyFilms.GetFilm(ind);
			string name = film2.GetName();
			string filmdirector = film2.GetFilmDirector();
			string screenwriter = film2.GetScreenwriter();
			string composer = film2.GetComposer();
			Data releasedate = film2.GetData();
			int year = releasedate.GetDataYear();
			int month = releasedate.GetDataMonth();
			int day = releasedate.GetDataDay();
			double filmfees = film2.GetFilmFees();
			printf("Ваш фильм\n");
			cout << name << ' ' << filmdirector << ' ' << screenwriter << ' ' << composer << ' ' << day << '.' << month << '.' << year << ' ' << filmfees;
		}
		if (vibor == 4)//Выдать все фильмы заданного режиссера
		{
			printf("Введите режиссера\n");
			scanf("&s\n", &stringR);
			MyFilmsR.FindDirector(MyFilms,stringR);
			int n = MyFilmsR.GetSize();
			for (int i = 0; i < n; i++)
			{
				film2 = MyFilmsR.GetFilm(i);
				string name = film2.GetName();
				string filmdirector = film2.GetFilmDirector();
				string screenwriter = film2.GetScreenwriter();
				string composer = film2.GetComposer();
				Data releasedate = film2.GetData();
				int year = releasedate.GetDataYear();
				int month = releasedate.GetDataMonth();
				int day = releasedate.GetDataDay();
				double filmfees = film2.GetFilmFees();
				printf("Ваши фильмы\n");
				cout << name << ' ' << filmdirector << ' ' << screenwriter << ' ' << composer << ' ' << day << '.' << month << '.' << year << ' ' << filmfees;
			}			
		}
		if (vibor == 5)//Выдать все фильмы, вышедшие в прокат в выбранном году
		{
			printf("Введите год\n");
			scanf("&d &d &d\n", &day, &month, &year);
			releasedate.SetData(day, month, year);
			MyFilmsD.FindData(MyFilms, releasedate);
			int n = MyFilmsD.GetSize();
			for (int i = 0; i < n; i++)
			{
				film2 = MyFilmsD.GetFilm(i);
				string name = film2.GetName();
				string filmdirector = film2.GetFilmDirector();
				string screenwriter = film2.GetScreenwriter();
				string composer = film2.GetComposer();
				Data releasedate = film2.GetData();
				int year = releasedate.GetDataYear();
				int month = releasedate.GetDataMonth();
				int day = releasedate.GetDataDay();
				double filmfees = film2.GetFilmFees();
				printf("Ваши фильмы\n");
				cout << name << ' ' << filmdirector << ' ' << screenwriter << ' ' << composer << ' ' << day << '.' << month << '.' << year << ' ' << filmfees;
			}

		}
		if (vibor == 6)//Выдать заданное число фильмов с наибольшими сборами
		{
			printf("Введите заданное число фильмов\n");
			scanf("&d\n", &sizefilms);
			N = MyFilms.GetSize();
			while ((sizefilms < 1) || (sizefilms > N))
			{
				printf("В Фильмотеке нет столько фильмов!\n");
				scanf_s("%d", &sizefilms);
			}
			MyFilms6.FindFilmsFees(MyFilms, sizefilms);
			int y = MyFilms6.GetSize();
			for (int i = 0; i < y; i++)
			{
				film2 = MyFilms6.GetFilm(i);
				string name = film2.GetName();
				string filmdirector = film2.GetFilmDirector();
				string screenwriter = film2.GetScreenwriter();
				string composer = film2.GetComposer();
				Data releasedate = film2.GetData();
				int year = releasedate.GetDataYear();
				int month = releasedate.GetDataMonth();
				int day = releasedate.GetDataDay();
				double filmfees = film2.GetFilmFees();
				printf("Ваши фильмы\n");
				cout << name << ' ' << filmdirector << ' ' << screenwriter << ' ' << composer << ' ' << day << '.' << month << '.' << year << ' ' << filmfees;
			}
		}
		if (vibor == 7)//Выдать заданное число фильмов с наибольшими сборами в выбранном году
		{
			printf("Введите год\n");
			scanf("&d &d &d\n", &day, &month, &year);
			releasedate.SetData(day, month, year);
			MyFilmsD.FindData(MyFilms, releasedate);
			N = MyFilmsD.GetSize();
			printf("Введите заданное число фильмов\n");
			scanf("&d\n", &sizefilms);
			while ((sizefilms < 1) || (sizefilms > N))
			{
				printf("В Фильмотеке нет столько фильмов!\n");
				scanf_s("%d", &sizefilms);
			}			
			MyFilms7.FindFilmsFees(MyFilmsD, sizefilms);
		}
		if (vibor == 8)//Узнать текущее число фильмов
		{
			sizefilms = MyFilms.GetSize();
			printf("Фильмов: %d", sizefilms);
		}
		if (vibor == 9)//Удалить фильм
		{
			MyFilms.WriteToFile();
			MyFilms.ReadFromFile();
			printf("Введите номер строки, начиная с 1(ту, в которой написан фильм, который желаете удалить\n");
			scanf("%d", &ind);
			MyFilms.DeleteFilm(ind);
			MyFilms.WriteToFile();
		}
		if (vibor == 10)//Запись фильмотеки в файл
		{
			MyFilms.WriteToFile();
		}
		if (vibor == 11)
		{
			MyFilms.ReadFromFile();
		}
		printf("Желаете выйти: да-1, нет-0\n");
		scanf("%d", &exit);
	}

}
