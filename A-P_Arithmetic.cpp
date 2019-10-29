// A-P_Arithmetic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "Headers.h"

int main()
{	
	LongInt num1, num2;
	cin >> num1;
	cin >> num2;
	cout << "1 % 2 = ";
	try {
		LongInt r = num1 % num2;
		cout << r;// num1.sqrt();
	}
	catch (...)
	{
		cout << "BAD!\n";
	}
	
	
	

	return 0;
}

