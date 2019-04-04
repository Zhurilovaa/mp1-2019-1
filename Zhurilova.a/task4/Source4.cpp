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
	Data& operator=(const Data &_D)//Оператор присваивания
	{
		year = _D.year;
		month = _D.month;
		day = _D.day;
		return *this;
	}
	friend std::ostream& operator<< (std::ostream &out, const Data &D);
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
		name = _name;
		film_director = _film_director;
		screenwriter = _screenwriter;
		composer = _composer;
		releasedate = _releasedate;
		filmfees = _filmfees;

	}
	//Установить параметры фильма
	void ChangeFilmFees(double _filmfees)
	{
		filmfees = _filmfees;
	}
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
		return *this;
	}
	friend std::ostream& operator<< (std::ostream &out, const Film &F);
};
class FilmLibrary//Класс фильмотека
{
private:
	vector <Film> FilmLib;//Массив фильмов
	size_t AlphabeticalComparisons(Film &_film);//Сравнение по алфавиту
	size_t FindFilm(string _name, Data _releasedate);//Поиск фильма
public:
	FilmLibrary();//Конструктор
	FilmLibrary(size_t n)
	{
		FilmLib.clear();
	}
	void AppendFilm(Film _film);//Добавить фильм	
	void ChangeData(string _name, Data _releasedate,double _filmfees);//Изменить данные фильма	
	Film GetFilm(string _name, Data _releasedate);//Получить фильм
	size_t GetSize();//Получить количество фильмов
	FilmLibrary FindByDirector(string _stringR);//Поиск фильмов по режиссеру
	FilmLibrary FindByData(Data _releasedate);//Поиск фильмов по году
	FilmLibrary FindByFilmsFees( size_t sizefilms);//Поиск фильмов по наибольшим сборам
	void DeleteFilm(string _name, Data _releasedate);//Удалить фильм
	void WriteToFile();//Запись фильмотеки в файл
	void ReadFromFile();//Чтение из файла
	void PrintFilmLibrary();
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
					printf("В этом месяце нет такого числа");
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
std::ostream& operator<< (std::ostream &out, const Data &D)
{
	out << D.day<< "." << D.month << "." << D.year << "г";

	return out;
}
FilmLibrary::FilmLibrary()//Конструктор для FilmLibrary
{
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
	FilmLib.resize(3);
	Film film0(name0, film_director0, screenwriter0, composer0, filmfees0, releasedate0);
	Film film1(name1, film_director1, screenwriter1, composer1, filmfees1, releasedate1);
	Film film2(name2, film_director2, screenwriter2, composer2, filmfees2, releasedate2);
	FilmLib.at(0) = (film0);
	FilmLib.at(1) = (film1);
	FilmLib.at(2) = (film2);
}
size_t FilmLibrary::AlphabeticalComparisons(Film &_film)//Сортировка по алфавиту
{
	string namef = string(_film.GetName());
	string namelib;
	int i;
	size_t index = -1;
	bool Comparisons;
	for (i = 0; i <FilmLib.size(); i++)
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
		if ((Comparisons == true) && (i < FilmLib.size()))
		{
			index = i + 1;
			break;
		}
		else
			if (i == FilmLib.size())
				index = FilmLib.size() + 1;
	}
	return index;
}
void FilmLibrary::AppendFilm(Film _film)//Добавить фильм
{
	size_t index = AlphabeticalComparisons(_film);
	FilmLib.push_back(_film);
	Film temp;
	for (size_t i = index; i < FilmLib.size() -1; i++)
	{
		temp = FilmLib[i];
		FilmLib[i] = FilmLib[FilmLib.size() -1];
		FilmLib[FilmLib.size() -1] = temp;
	}
}
void FilmLibrary::ChangeData(string _name, Data _releasedate, double _filmfees)//Изменить данные фильма
{
	size_t number = FindFilm(_name,_releasedate);
	FilmLib[number].ChangeFilmFees(_filmfees);
}
size_t FilmLibrary::FindFilm(string _name, Data _releasedate)//Найти фильм
{
	int i = 0;
	int number;
	bool Comparisons;
	Data filmdata;
	for (i = 0; i < FilmLib.size(); i++)
	{
		Comparisons = (FilmLib[i].GetName() == _name);
		filmdata = FilmLib[i].GetData();
		if ((filmdata == _releasedate) && (Comparisons == true))
			number = i;
	}
	return i;
}
Film FilmLibrary::GetFilm(string _name, Data _releasedate)//Получить фильм
{
	size_t number = FindFilm(_name, _releasedate);
	return FilmLib[number];
}
size_t FilmLibrary::GetSize()//Получить количество фильмов
{
	return FilmLib.size();
}
FilmLibrary FilmLibrary::FindByDirector(string _stringR)//Поиск фильмов по режиссеру
{
	FilmLibrary LibraryByDir(0);
	for (int i = 0; i < FilmLib.size(); i++)
	{
		string director = FilmLib[i].GetFilmDirector();
		if (director == _stringR)
		{
			LibraryByDir.AppendFilm(FilmLib[i]);
		}
	}
	return LibraryByDir;
}
FilmLibrary FilmLibrary::FindByData(Data _releasedate)//Поиск фильмов по году
{
	FilmLibrary LibraryByData(0);
	for (int i = 0; i < FilmLib.size(); i++)
	{
		Data releasedateD = FilmLib[i].GetData();
		if (releasedateD.GetDataYear() == _releasedate.GetDataYear())
		{
			LibraryByData.AppendFilm(FilmLib[i]);
		}
	}
	return LibraryByData;
}
FilmLibrary FilmLibrary::FindByFilmsFees(size_t sizefilms)//Поиск заданного числа фильмов с наибольшими сборами
{
	FilmLibrary Temp;
	size_t j = 0;
	Film film1,film2;
	Film max;
	int index;
	while (j < sizefilms)
	{
		for (int i = 0; i < FilmLib.size() - 1; i++)
		{
			if (FilmLib[i].GetFilmFees()>= FilmLib[i+1].GetFilmFees())
			{
				max = FilmLib[i];
				index = i;
			}
			else
			{
				max = FilmLib[i+1];
				index = i + 1;
			}							
		}
		Temp.AppendFilm(max);
		j++;
		string _name = FilmLib[index].GetName();
		Data _releasedate = FilmLib[index].GetData();
		DeleteFilm(_name, _releasedate);
	}
	return Temp;
}
void FilmLibrary::DeleteFilm(string _name, Data _releasedate)//Удалить фильм
{
	size_t number;
	number = FindFilm(_name, _releasedate);
	for (size_t j = number; j < FilmLib.size()-1; j++)
	{
		FilmLib[j] = FilmLib[j+1];
	}
	FilmLib.pop_back();
}
std::ostream& operator<< (std::ostream &out, const Film &F)
{
	out << F.name << ' ' << F.film_director << F.screenwriter << ' ' << F.composer << ' ' << F.releasedate << ' ' << F.filmfees << "млн. руб" << endl;

	return out;
}
void FilmLibrary::PrintFilmLibrary()
{
	for (size_t i = 0; i < FilmLib.size(); i++)
	{
		cout << FilmLib[i] << endl;
	}
}
void FilmLibrary::WriteToFile()//Запись фильмотеки в файл
{
	ofstream fout;
	fout.open("MyFilms.txt");
	for (int i = 0; i < FilmLib.size(); i++)
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
	for (int i = 0; i < FilmLib.size(); i++)
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
	setlocale(LC_ALL, "Rus");
	string stringName;
	string stringR;
	string stringS;
	string stringC;
	int day, month, year, ind;
	size_t sizefilms, N;
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
			cin >> stringName;
			cout << endl;
			printf("Введите режиссера\n");
			cin >> stringR;
			cout << endl;
			printf("Введите сценариста\n");
			cin >> stringS;
			cout << endl;
			printf("Введите композитора\n");
			cin >> stringC;
			cout << endl;
			printf("Введите дату выхода в прокат\n");
			cin >> day;
			cin >> month;
			cin >> year;
			releasedate.SetData(day, month, year);
			printf("Введите мировые сборы\n");
			scanf("%lf", &filmfees);
			Film film1(stringName, stringR, stringS, stringC, filmfees, releasedate);
			MyFilms.AppendFilm(film1);
			MyFilms.WriteToFile();
		}
		if (vibor == 2)//Изменить данные выбранного фильма
		{
			MyFilms.WriteToFile();
			MyFilms.ReadFromFile();
			printf("Введите название фильма\n");
			cin >> stringName;
			cout << endl;
			printf("Введите дату выхода в прокат\n");
			cin >> day;
			cin >> month;
			cin >> year;
			releasedate.SetData(day, month, year);
			printf("Введите мировые сборы\n");
			scanf("%lf", &filmfees);
			MyFilms.ChangeData(stringName, releasedate, filmfees);
			MyFilms.WriteToFile();
		}
		if (vibor == 3)//Найти фильм по названию и году
		{
			printf("Введите название фильма\n");
			cin >> stringName;
			cout << endl;
			printf("Введите год выхода в прокат\n");
			cin >> day;
			cin >> month;
			cin >> year;
			releasedate.SetData(day, month, year);
			film2 = MyFilms.GetFilm(stringName, releasedate);
			printf("Ваш фильм\n");
			cout << film2 << endl;
		}
		if (vibor == 4)//Выдать все фильмы заданного режиссера
		{
			printf("Введите режиссера\n");
			cin >> stringR;
			cout << endl;
			MyFilmsR=MyFilms.FindByDirector(stringR);
			printf("Ваши фильмы\n");
			MyFilmsR.PrintFilmLibrary();						
		}
		if (vibor == 5)//Выдать все фильмы, вышедшие в прокат в выбранном году
		{
			printf("Введите год\n");
			cin >> day;
			cin >> month;
			cin >> year;
			releasedate.SetData(day, month, year);
			MyFilmsD=MyFilms.FindByData(releasedate);
			printf("Ваши фильмы\n");
			MyFilmsD.PrintFilmLibrary();
		}
		if (vibor == 6)//Выдать заданное число фильмов с наибольшими сборами
		{
			printf("Введите заданное число фильмов\n");
			int z1;
			scanf("%d", &z1);
			sizefilms = z1;
			N = MyFilms.GetSize();
			while ((sizefilms < 1) || (sizefilms > N))
			{
				printf("В Фильмотеке нет столько фильмов!\n");
				scanf("%d", &z1);
				sizefilms = z1;
			}
			MyFilms6.FindByFilmsFees(sizefilms);
			printf("Ваши фильмы\n");
			MyFilms6.PrintFilmLibrary();
		}
		if (vibor == 7)//Выдать заданное число фильмов с наибольшими сборами в выбранном году
		{
			printf("Введите год\n");
			cin >> day;
			cin >> month;
			cin >> year;
			releasedate.SetData(day, month, year);
			MyFilmsD.FindByData(releasedate);
			N = MyFilmsD.GetSize();
			printf("Введите заданное число фильмов\n");
			int z3;
			scanf("%d", &z3);
			sizefilms = z3;
			while ((sizefilms < 1) || (sizefilms > N))
			{
				printf("В Фильмотеке нет столько фильмов!\n");
				scanf("%d", &z3);
				sizefilms = z3;
			}			
			MyFilms7.FindByFilmsFees(sizefilms);
			printf("Ваши фильмы\n");
			MyFilms7.PrintFilmLibrary();
		}
		if (vibor == 8)//Узнать текущее число фильмов
		{
			sizefilms = MyFilms.GetSize();
			cout << sizefilms << endl;
		}
		
		if (vibor == 9)//Удалить фильм
		{
			MyFilms.WriteToFile();
			MyFilms.ReadFromFile();
			printf("Введите название фильма\n");
			cin >> stringName;
			cout << endl;
			printf("Введите год выхода в прокат\n");
			cin >> day;
			cin >> month;
			cin >> year;
			releasedate.SetData(day, month, year);
			MyFilms.DeleteFilm(stringName, releasedate);
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
