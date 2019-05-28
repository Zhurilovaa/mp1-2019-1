#pragma once
#include "ProcessingCenter.hpp"
#ifndef BANKOMAT_H
#define BANKOMAT_HPP
class BankСash :public ProcessingCenter//Класс Банкомат
{
private:
	Client Now;//Клиент, с чьим счетом ведется работа в данный момент
	ProcessingCenter Base;
	int NumberOfBanknotes[6][2];//Кассеты банкомата
	int SortOfBanknotes(int _NumberOfBanknotes, int _Sum)//"Сортировка" по банкнотам
	{
		int Number = 0;
		if ((_Sum / _NumberOfBanknotes) != 0)
			Number = _Sum / _NumberOfBanknotes;
		return Number;
	}
public:
	BankСash();//Конструктор
	Client TakeCards(string _NumberCard);//Принять карту(Найти по номеру счета клиента)
	bool BankСash::ControlPinCode(string _PinCode);//Проверка ввода пин-кода
	Client WithdrawCash(int _Sum);//Снять наличные со счёта
	Client PutMoneyIntoAccount(int _Sum);//Положить наличные на счет
};
#endif // !BANKOMAT_H