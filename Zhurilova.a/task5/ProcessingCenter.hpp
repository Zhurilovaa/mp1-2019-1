#pragma once
#include "Client.hpp"
#ifndef PROCESSINGCENTER_H
#define PROCESSINGCENTER_HPP
using namespace std;
class ProcessingCenter//Класс процессинговый центр
{
protected:
	vector <Client> Base;//База клиентов
public:
	ProcessingCenter::ProcessingCenter();//Конструктор
	size_t GetSizeBase();//Получить размер(количество клиентов) в базе
	Client ProcessingCenter::GetClient(size_t i);//Вернуть клиента согласно строке, к которой он находится(Для перебора)
};
#endif // !PROCESSINGCENTER_H