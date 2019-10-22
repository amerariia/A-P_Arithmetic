// A-P_Arithmetic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "Headers.h"

int main()
{	
	string num = "4653";
	string num2 = "302";
	LongInt a(num);
	LongInt b(num2);
	a.print();
	b.print();
	LongInt c(a - b);
	c.print();
	cout << c.length;
	

	return 0;
}