#pragma once
#include<locale.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#ifndef CLIENT_H
#define CLIENT_HPP
using namespace std;
class Client//Класс клиент банкомата
{
private:
	string NumberCard;//Номер карты
	string Surname;//Фамилия
	string Name;//Имя
	string Patronymic;//Отчество
	int InvoiceAmount;//Сумма на счету
	string PinCode;//Пин-код	
	bool WorkwithMoney;//Статус пользования карты
	int MistakePin;//Ошибки ввода пин-кода
public:
	Client();
	Client(string _NumberCard, string _Surname, string _Name, string _Patronymic, string _PinCode, int _InvoiceAmount = 15000);//Конструктор
	void ChangeInvoiceAmount(int _InvoiceAmount);//Изменить сумму на счету
	void AddMistakePin();//Ошибка ввода пин-кода +1
	string GetNumberCard();//Вернуть номер карты
	string GetPinCode();//Вернуть Пин-код
	bool GetStatusWork();//Вернуть Статус работы карты
	int GetMistakePin();//Вернуть количество ошибок ввода пин-кода
	int GetInvoiceAmount();//Вернуть количество средств на счету
	Client& Client::operator=(const Client &_C);//Оператор присваивания
	friend std::ostream& operator<< (std::ostream &out, const Client &C);
};
#endif // !CLIENT_H
