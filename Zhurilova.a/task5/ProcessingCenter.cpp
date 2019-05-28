#include "ProcessingCenter.hpp"
using namespace std;
ProcessingCenter::ProcessingCenter()//Конструктор
{
	string n[6] = { "1128","1605","0904","0509","2904","9815" };
	string pin[6] = { "9876","3254","3370","4319","8679","2420" };
	string sS[6] = { "Иванов","Васильева","Соколов","Новикова","Федорова","Алексеев" };
	string sN[6] = { "Анатолий","Агата","Михаил","Варвара","Евгения", "Леонид" };
	string sP[6] = { "Артёмович","Викторовна","Кириллович","Витальевна","Юрьевна","Дмитриевич" };
	int IA[6] = { 10000, 2569, 4876, 100000, 80548, 15000 };
	Client C0(n[0], sS[0], sN[0], sP[0], pin[0], IA[0]);
	Client C1(n[1], sS[1], sN[1], sP[1], pin[1], IA[1]);
	Client C2(n[2], sS[2], sN[2], sP[2], pin[2], IA[2]);
	Client C3(n[3], sS[3], sN[3], sP[3], pin[3], IA[3]);
	Client C4(n[4], sS[4], sN[4], sP[4], pin[4], IA[4]);
	Client C5(n[5], sS[5], sN[5], sP[5], pin[5], IA[5]);
	Client C[6] = { C0,C1,C2,C3,C4, C5 };
	for (int i = 0; i < 6; i++)
	{
		Base.push_back(C[i]);
	}
}
size_t ProcessingCenter::GetSizeBase()//Получить размер(количество клиентов) в базе
{
	return Base.size();
}
Client ProcessingCenter::GetClient(size_t i)//Вернуть клиента согласно строке, к которой он находится(Для перебора)
{
	return Base[i];
}