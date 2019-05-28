#define _CRT_SECURE_NO_WARNINGS
#include "Bankomat.hpp"
using namespace std;
void main()
{
	setlocale(LC_ALL, "Rus");
	int choise0 = 0, choise1 = 0;
	int Sum = 0;
	string NumberCard;
	string PinCode;
	bool exit = false;
	bool Enter = true;
	BankСash ATM;//Банкомат
	bool TheEntry = false;
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
		if (choise0 == 2)
		{
			if (C.GetNumberCard() != "_")
			{
				cout << "Введите пин-код" << endl;
				cin >> PinCode;
				TheEntry = ATM.ControlPinCode(PinCode);
				while ((TheEntry == false) && (C.GetStatusWork() == true))
				{
					cout << "Неверно введен пин-код" << endl;
					C.AddMistakePin();
					if (C.GetMistakePin() != 3)
					{
						cout << "Введите пин-код" << endl;
						cin >> PinCode;
						TheEntry = ATM.ControlPinCode(PinCode);
					}
				}
			}
			if (C.GetStatusWork() == false)
			{
				cout << "Вы ввели пин-код неверно 3 раза! Ваша карта заблокирована" << endl;
			}
			if (C.GetStatusWork() == true)
			{
				while (Enter == true)
				{
					cout << "Желаете: Рапечатать состояние своего счёта(1);" << endl << "Снять наличные(2);" << endl << "Положить наличные(3);" << endl << "Вернуть карту(4)" << endl;
					cin >> choise1;
					while ((choise1 < 1) || (choise1 > 4))
					{
						cout << "Нет операции под таким номером! Попробуйте ещё раз." << endl;
						cin >> choise1;
					}
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
						while (((Sum > 200000) && ((Sum % 100) == 0)) || ((Sum % 100) != 0))
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
						while ((Sum < 0) || ((Sum > 200000) && ((Sum % 100) == 0)) || ((Sum % 100) != 0))
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