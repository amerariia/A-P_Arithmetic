// A-P_Arithmetic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "Headers.h"

int main()
{	
	LongInt num1, num2, num3;
	cin >> num1;
	cin >> num2;
	cin >> num3;
	cout << "num1 * num2 = ";
	LongInt r;
	//LongInt res =  r.AddByMod(num1, num2, num3);
	//cout << res;
	cout << r.AddByMod(num1, num2, num3);
	
	
	

	return 0;
}

