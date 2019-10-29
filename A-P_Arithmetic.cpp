// A-P_Arithmetic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "Headers.h"

int main()
{	
	LongInt num1, num2;
	cin >> num1;
	cin >> num2;
	try {
		cout << "num1 ^ num2 = ";
		LongInt r = num1 ^ num2;
		cout << r << endl;

	}
	catch (...) {
		cout << "error!\n";
	}
	
	
	

	return 0;
}

