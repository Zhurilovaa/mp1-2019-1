#define _CRT_SECURE_NO_WARNINGS
#include<locale.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class Client//����� ������ ���������
{
private:
	string NumberCard;//����� �����
	string Surname;//�������
	string Name;//���
	string Patronymic;//��������
	int InvoiceAmount;//����� �� �����
	string PinCode;//���-���	
	bool WorkwithMoney;//������ ����������� �����
	int MistakePin;//������ ����� ���-����
public:
	Client()//����������� ��� ����������
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
	Client(string _NumberCard, string _Surname, string _Name, string _Patronymic, string _PinCode, int _InvoiceAmount = 1000)//�����������
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
	void ChangeInvoiceAmount(int _InvoiceAmount)//�������� ����� �� �����
	{
		InvoiceAmount = _InvoiceAmount;

	}
	void AddMistakePin()//������ ����� ���-���� +1
	{
		MistakePin++;
		if (MistakePin == 3)//���� ��� 3 ������, ���������� �����
			WorkwithMoney = false;
	}
	string GetNumberCard()//������� ����� �����
	{
		return NumberCard;
	}
	string GetPinCode()//������� ���-���
	{
		return PinCode;
	}
	bool GetStatusWork()//������� ������ ������ �����
	{
		return WorkwithMoney;
	}
	int GetMistakePin()//������� ���������� ������ ����� ���-����
	{
		return MistakePin;
	}
	int GetInvoiceAmount()//������� ���������� ������ �� �����
	{
		return InvoiceAmount;
	}
	Client& operator=(const Client &_C)//�������� ������������
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
	out << "����� �����: " << C.NumberCard << endl << "��O: " << C.Surname << ' ' << C.Name << ' ' << C.Patronymic << endl;
	return out;
}
class ProcessingCenter//����� �������������� �����
{
protected:
	vector <Client> Base;//���� ��������
public:
	ProcessingCenter()//�����������
	{
		string n[6] = { "1128","1605","0904","0509","2904","9815" };
		string pin[6] = { "0000","1111","3370","4319","8679","2420" };
		string sS[6] = { "������","���������","�������","��������","��������","��������" };
		string sN[6] = { "��������","�����","������","�������","�������", "������" };
		string sP[6] = { "��������","����������","����������","����������","�������","����������" };
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
class Bank�ash:public ProcessingCenter//����� ��������
{
private:
	Client Now;//������, � ���� ������ ������� ������ � ������ ������
	int NumberOfBanknotes[6][2];//������� ���������
	int SortOfBanknotes(int _NumberOfBanknotes,int _Sum)//"����������" �� ���������
	{
		int Number = 0;
		if ((_Sum / _NumberOfBanknotes) != 0)
			 Number=_Sum / _NumberOfBanknotes;
		return Number;
	}
public:
	Bank�ash()//�����������
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
	Client TakeCards(string _NumberCard)//������� �����(����� �� ������ ����� �������)
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
	bool ControlPinCode(string _PinCode)//�������� ����� ���-����
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
	Client WithdrawCash(int _Sum)//����� �������� �� �����
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
	Client PutMoneyIntoAccount(int _Sum)//�������� �������� �� ����
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
	Bank�ash ATM;//��������
	bool TheEntry=false;	
	cout << "P.S: ������ ��������� ����:" << endl << "1128" << " " << "1605" << " " << "0904" << " " << "0509" << " " << "2904" << " " << "9815" << endl;
	while (exit == false)
	{
		cout << "����� �������(1) ��� �������� �����(2)" << endl;
		cin >> choise0;
		Client C;
		while (C.GetNumberCard() == "_")
		{
			cout << "�������� �����(������� �����):";
			cin >> NumberCard;
			cout << endl;
			C = ATM.TakeCards(NumberCard);
			if (C.GetNumberCard() == "_")
			cout << "����� � ����� ������� �� ����������!" << endl << "���������� ��� ���" << endl;
		}		
		if (choise0 == 1)
		{
			cout << C << endl;
		}
		if(choise0 == 2)
		{
			if (C.GetNumberCard() != "_")
			{
				cout << "������� ���-���" << endl;
				cin >> PinCode;
				TheEntry = ATM.ControlPinCode(PinCode);
				while ((C.GetMistakePin() != 3)&&(TheEntry == false))
				{
					cout << "������� ������ ���-���" << endl;
					C.AddMistakePin();
					cout << "������� ���-���" << endl;
					cin >> PinCode;
					TheEntry = ATM.ControlPinCode(PinCode);
				}
			}
			if (C.GetStatusWork() == false)
			{
				cout << "�� ����� ���-��� ������� 3 ����! ���� ����� �������������" << endl;
			}
			if (C.GetStatusWork() == true)
			{				
				while (Enter==true)
				{
					cout << "�������: ���������� ��������� ������ �����(1); ����� ��������(2); �������� ��������(3); ������� �����(4)" << endl;
					cin >> choise1;
					if (choise1 == 1)
						cout << C << "����� �� �����: " << C.GetInvoiceAmount() << ' ' << endl;
					if (choise1 == 2)
					{
						cout << "������� �����, ������� ������ �������:" << endl;
						cin >> Sum;
						while ((Sum < 0) || (Sum > C.GetInvoiceAmount()))
						{
							cout << "�������� ����� ��� �� �����!" << "���������� ��� ���" << endl;
							cin >> Sum;
						}
						while (((Sum > 200000) && ((Sum / 100) == 0)) || ((Sum % 100) != 0))
						{
							cout << "� ���������, ����� ����� �� ����� ���� ������ ����������" << endl;
							cout << "���������� ��� ���" << endl;
							cin >> Sum;
						}
						C = ATM.WithdrawCash(Sum);
						cout << "�������� ����� � ������ �����" << endl << "������� ������: " << C.GetInvoiceAmount() << endl;
					}
					if (choise1 == 3)
					{
						cout << "������� �����, ������� ������ �������� �� ����:" << endl;
						cin >> Sum;
						while ((Sum < 0) || ((Sum > 200000) && ((Sum / 100) == 0)) || ((Sum % 100) != 0))
						{
							cout << "�������� ����� ������ ��������� �� ����!" << "���������� ��� ���" << endl;
							cin >> Sum;
						}
						C = ATM.PutMoneyIntoAccount(Sum);
						cout << "�������� ��������� �� ��� ����" << endl << "������� ������: " << C.GetInvoiceAmount() << endl;
					}
					if (choise1 == 4)
					{
						Enter = false;
					}
				}				
			}
		}
		cout << "������� �����(1) ��� ���(0)" << endl;
		cin >> exit;
	}
}