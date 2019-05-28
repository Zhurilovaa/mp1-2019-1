#include "Bankomat.hpp"
using namespace std;
BankСash::BankСash()//Конструктор
{
	NumberOfBanknotes[0][0] = 5000;
	NumberOfBanknotes[1][0] = 2000;
	NumberOfBanknotes[2][0] = 1000;
	NumberOfBanknotes[3][0] = 500;
	NumberOfBanknotes[4][0] = 200;
	NumberOfBanknotes[5][0] = 100;
	for (int i = 0; i < 6; i++)
		NumberOfBanknotes[i][1] = 1600;
}
Client BankСash::TakeCards(string _NumberCard)//Принять карту(Найти по номеру счета клиента)
{
	Client Temp;
	for (size_t i = 0; i < Base.GetSizeBase(); i++)
	{
		Temp = Base.GetClient(i);
		if (Temp.GetNumberCard() == _NumberCard)
		{
			Now = Temp;
		}
	}
	return Now;
}
bool BankСash::ControlPinCode(string _PinCode)//Проверка ввода пин-кода
{
	bool TheEntry = false;
	if (Now.GetStatusWork() == true)
	{
		if (Now.GetPinCode() != _PinCode)
		{
			Now.AddMistakePin();
		}
		else
			TheEntry = true;
	}
	return TheEntry;
}
Client BankСash::WithdrawCash(int _Sum)//Снять наличные со счёта
{
	int temp = Now.GetInvoiceAmount();
	int SumOfBanknotes = 0;
	for (int i = 0; i < 6; i++)
	{
		SumOfBanknotes = SortOfBanknotes(NumberOfBanknotes[i][0], _Sum);
		if ((SumOfBanknotes != 0) && (_Sum != 0))
		{
			temp = temp - (NumberOfBanknotes[i][0] * SumOfBanknotes);
			Now.ChangeInvoiceAmount(temp);
			NumberOfBanknotes[i][1] = NumberOfBanknotes[i][1] - SumOfBanknotes;
			_Sum = _Sum - (NumberOfBanknotes[i][0] * SumOfBanknotes);
		}
	}
	return Now;
}
Client BankСash::PutMoneyIntoAccount(int _Sum)//Положить наличные на счет
{
	int temp = Now.GetInvoiceAmount();
	int SumOfBanknotes = 0;
	for (int i = 0; i < 6; i++)
	{
		SumOfBanknotes = SortOfBanknotes(NumberOfBanknotes[i][0], _Sum);
		if ((SumOfBanknotes != 0) && (_Sum != 0))
		{
			temp = temp + (NumberOfBanknotes[i][0] * SumOfBanknotes);
			Now.ChangeInvoiceAmount(temp);
			NumberOfBanknotes[i][1] = NumberOfBanknotes[i][1] + SumOfBanknotes;
			_Sum = _Sum - (NumberOfBanknotes[i][0] * SumOfBanknotes);
		}
	}
	return Now;
}