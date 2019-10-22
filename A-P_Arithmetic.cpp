// A-P_Arithmetic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "Headers.h"

int main()
{

	LongInt* a = new LongInt(5);
	a->Zero();
	a->print();
	string num = "577688767";
	LongInt* b = new LongInt(num);
	b->print();
	
	return 0;
}