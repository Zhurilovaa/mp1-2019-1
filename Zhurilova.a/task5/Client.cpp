#include "Client.hpp"
using namespace std;
Client::Client()//Конструктор без параметров
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
Client::Client(string _NumberCard, string _Surname, string _Name, string _Patronymic, string _PinCode, int _InvoiceAmount)//Конструктор
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
void Client::ChangeInvoiceAmount(int _InvoiceAmount)//Изменить сумму на счету
{
	InvoiceAmount = _InvoiceAmount;
}
void Client::AddMistakePin()//Ошибка ввода пин-кода +1
{
	MistakePin++;
	if (MistakePin == 3)//Если уже 3 ошибки, блокировка карты
		WorkwithMoney = false;
}
string Client::GetNumberCard()//Вернуть номер карты
{
	return NumberCard;
}
string Client::GetPinCode()//Вернуть Пин-код
{
	return PinCode;
}
bool Client::GetStatusWork()//Вернуть Статус работы карты
{
	return WorkwithMoney;
}
int Client::GetMistakePin()//Вернуть количество ошибок ввода пин-кода
{
	return MistakePin;
}
int Client::GetInvoiceAmount()//Вернуть количество средств на счету
{
	return InvoiceAmount;
}
Client& Client::operator=(const Client &_C)//Оператор присваивания
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
std::ostream& operator<< (std::ostream &out, const Client &C)
{
	out << "Номер счета: " << C.NumberCard << endl << "ФИO: " << C.Surname << ' ' << C.Name << ' ' << C.Patronymic << endl;
	return out;
}