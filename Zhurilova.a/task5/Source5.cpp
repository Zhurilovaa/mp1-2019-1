#define _CRT_SECURE_NO_WARNINGS
#include<locale.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
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
	Client()//Конструктор без параметров
	{
		NumberCard = "_";
		Surname = "_";
		Name = "_";
		Patronymic = "_";
		InvoiceAmount = 15000;
		PinCode = "_";
		WorkwithMoney = true;
		MistakePin = 0;
	}
	Client(string _NumberCard, string _Surname, string _Name, string _Patronymic, string _PinCode, int _InvoiceAmount = 1000)//Конструктор
	{
		NumberCard = _NumberCard;
		Surname = _Surname;
		Name = _Name;
		Patronymic = _Patronymic;
		InvoiceAmount = _InvoiceAmount;
		PinCode = _PinCode;
		WorkwithMoney = true;
		MistakePin = 0;
	}
	void ChangeInvoiceAmount(int _InvoiceAmount)//Изменить сумму на счету
	{
		InvoiceAmount = _InvoiceAmount;

	}
	void AddMistakePin()//Ошибка ввода пин-кода +1
	{
		MistakePin++;
		if (MistakePin == 3)//Если уже 3 ошибки, блокировка карты
			WorkwithMoney = false;
	}
	string GetNumberCard()//Вернуть номер карты
	{
		return NumberCard;
	}
	string GetPinCode()//Вернуть Пин-код
	{
		return PinCode;
	}
	bool GetStatusWork()//Вернуть Статус работы карты
	{
		return WorkwithMoney;
	}
	int GetMistakePin()//Вернуть количество ошибок ввода пин-кода
	{
		return MistakePin;
	}
	int GetInvoiceAmount()//Вернуть количество средст на счету
	{
		return InvoiceAmount;
	}
	Client& operator=(const Client &_C)//Оператор присваивания
	{
		NumberCard = _C.NumberCard;
		Surname = _C.Surname;
		Name = _C.Name;
		Patronymic = _C.Patronymic;
		InvoiceAmount = _C.InvoiceAmount;
		PinCode = _C.PinCode;
		WorkwithMoney = _C.WorkwithMoney;
		return *this;
	}
	friend std::ostream& operator<< (std::ostream &out, const Client &C);
};
std::ostream& operator<< (std::ostream &out, const Client &C)
{
	out << "Номер счета: " << C.NumberCard << endl << "ФИO: " << C.Surname << ' ' << C.Name << ' ' << C.Patronymic << endl;
	return out;
}
class ProcessingCenter//Класс процессинговый центр
{
protected:
	vector <Client> Base;//База клиентов
public:
	ProcessingCenter()//Конструктор
	{
		string n[6] = { "1128","1605","0904","0509","2904","9815" };
		string pin[6] = { "0000","1111","3370","4319","8679","2420" };
		string sS[6] = { "Иванов","Васильева","Соколов","Новикова","Федорова","Алексеев" };
		string sN[6] = { "Анатолий","Агата","Михаил","Варвара","Евгения", "Леонид" };
		string sP[6] = { "Артёмович","Викторовна","Кириллович","Витальевна","Юрьевна","Дмитриевич" };
		int IA[6] = { 10000, 2569, 4876, 100000, 80548,15000 };
		Client C0(n[0], sS[0], sN[0], sP[0], pin[0], IA[0]);
		Client C1(n[1], sS[1], sN[1], sP[1], pin[1], IA[1]);
		Client C2(n[2], sS[2], sN[2], sP[2], pin[2], IA[2]);
		Client C3(n[3], sS[3], sN[3], sP[3], pin[3], IA[3]);
		Client C4(n[4], sS[4], sN[4], sP[4], pin[4], IA[4]);
		Client C5(n[5], sS[5], sN[5], sP[5], pin[5], IA[5]);
		Client C[6] = {C0,C1,C2,C3,C4, C5};
		for (int i = 0; i < 6; i++)
		{
			Base.push_back(C[i]);
		}		
	}	
};
class BankСash:public ProcessingCenter//Класс Банкомат
{
private:
	Client Now;//Клиент, с чьим счетом ведется работа в данный момент
	int NumberOfBanknotes[6][2];//Кассеты банкомата
	int SortOfBanknotes(int _NumberOfBanknotes,int _Sum)//"Сортировка" по банкнотам
	{
		int Number = 0;
		if ((_Sum / _NumberOfBanknotes) != 0)
			 Number=_Sum / _NumberOfBanknotes;
		return Number;
	}
public:
	BankСash()//Конструктор
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
	Client TakeCards(string _NumberCard)//Принять карту(Найти по номеру счета клиента)
	{
		for (size_t i = 0; i < Base.size(); i++)
		{
			if (Base[i].GetNumberCard()==_NumberCard )
			{ 
				Now = Base[i];
			}				
		}
		return Now;
	}
	bool ControlPinCode(string _PinCode)//Проверка ввода пин-кода
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
	Client WithdrawCash(int _Sum)//Снять наличные со счёта
	{
		int temp=Now.GetInvoiceAmount();
		int SumOfBanknotes = 0;
		for (int i = 0; i < 6; i++)
		{
			SumOfBanknotes = SortOfBanknotes(NumberOfBanknotes[i][0],_Sum);
			if ((SumOfBanknotes != 0) && (_Sum != 0))
			{
				temp = temp - (NumberOfBanknotes[i][0]*SumOfBanknotes);				
				Now.ChangeInvoiceAmount(temp);				
				NumberOfBanknotes[i][1] = NumberOfBanknotes[i][1] - SumOfBanknotes;				
				_Sum = _Sum - (NumberOfBanknotes[i][0] * SumOfBanknotes);				
			}			
		}
		return Now;
	}
	Client PutMoneyIntoAccount(int _Sum)//Положить наличные на счет
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
};
void main()
{
	setlocale(LC_ALL, "Rus");
	int choise0 = 0, choise1 = 0;
	int Sum=0;
	string NumberCard;
	string PinCode;
	bool exit=false;
	bool Enter=true;
	BankСash ATM;//Банкомат
	bool TheEntry=false;	
	cout << "P.S: Номера возможных карт:" << endl << "1128" << " " << "1605" << " " << "0904" << " " << "0509" << " " << "2904" << " " << "9815" << endl;
	while (exit == false)
	{
		cout << "Найти клиента(1) или Вставить карту(2)" << endl;
		cin >> choise0;
		Client C;
		while (C.GetNumberCard() == "_")
		{
			cout << "Вставьте карту(введите номер):";
			cin >> NumberCard;
			cout << endl;
			C = ATM.TakeCards(NumberCard);
			if (C.GetNumberCard() == "_")
			cout << "Карты с таким номером не существует!" << endl << "Попробуйте ещё раз" << endl;
		}		
		if (choise0 == 1)
		{
			cout << C << endl;
		}
		if(choise0 == 2)
		{
			if (C.GetNumberCard() != "_")
			{
				cout << "Введите пин-код" << endl;
				cin >> PinCode;
				TheEntry = ATM.ControlPinCode(PinCode);
				while ((C.GetMistakePin() != 3)&&(TheEntry == false))
				{
					cout << "Неверно введен пин-код" << endl;
					C.AddMistakePin();
					cout << "Введите пин-код" << endl;
					cin >> PinCode;
					TheEntry = ATM.ControlPinCode(PinCode);
				}
			}
			if (C.GetStatusWork() == false)
			{
				cout << "Вы ввели пин-код неверно 3 раза! Ваша карта заблокирована" << endl;
			}
			if (C.GetStatusWork() == true)
			{				
				while (Enter==true)
				{
					cout << "Желаете: Рапечатать состояние своего счёта(1); Снять наличные(2); Положить наличные(3); Вернуть карту(4)" << endl;
					cin >> choise1;
					if (choise1 == 1)
						cout << C << "Сумма на счету: " << C.GetInvoiceAmount() << ' ' << endl;
					if (choise1 == 2)
					{
						cout << "Введите сумму, которую хотите списать:" << endl;
						cin >> Sum;
						while ((Sum < 0) || (Sum > C.GetInvoiceAmount()))
						{
							cout << "Вводимой суммы нет на счету!" << "Попробуйте ещё раз" << endl;
							cin >> Sum;
						}
						while (((Sum > 200000) && ((Sum / 100) == 0)) || ((Sum % 100) != 0))
						{
							cout << "К сожалению, такая сумма не может быть выдана банкоматом" << endl;
							cout << "Попробуйте ещё раз" << endl;
							cin >> Sum;
						}
						C = ATM.WithdrawCash(Sum);
						cout << "Средства сняты с вашего счёта" << endl << "Текущий баланс: " << C.GetInvoiceAmount() << endl;
					}
					if (choise1 == 3)
					{
						cout << "Введите сумму, которую хотите положить на счет:" << endl;
						cin >> Sum;
						while ((Sum < 0) || ((Sum > 200000) && ((Sum / 100) == 0)) || ((Sum % 100) != 0))
						{
							cout << "Вводимую сумму нельзя зачислить на счет!" << "Попробуйте ещё раз" << endl;
							cin >> Sum;
						}
						C = ATM.PutMoneyIntoAccount(Sum);
						cout << "Средства зачислены на ваш счёт" << endl << "Текущий баланс: " << C.GetInvoiceAmount() << endl;
					}
					if (choise1 == 4)
					{
						Enter = false;
					}
				}				
			}
		}
		cout << "Желаете выйти(1) или нет(0)" << endl;
		cin >> exit;
	}
}