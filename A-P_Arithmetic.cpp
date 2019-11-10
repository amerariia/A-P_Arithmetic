// A-P_Arithmetic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "Headers.h"

int main()
{	
	try
	{
		LongInt a, b, c;
		cin >> a >> b >> c;
		cout << "a + b = " << a + b;
		
		cout << "a - b = " << a - b;
		cout << "a * b = " << a * b;
		cout << "a / b = " << a / b;
		cout << "a % b = " << a % b;
		//cout << "a ^ b = " << (a ^ b);
		//cout << "sqrt(a) = " << a.sqrt();
		cout << "a > b: " << (a > b) << '\n';
		cout << "a = b: " << (a == b) << '\n';
		cout << "a < b: " << (a < b) << '\n';
		cout << "AddByMod: " << LongInt::AddByMod(a, b, c);
		cout << "SubByMod: " << LongInt::SubByMod(a, b, c);
		cout << "MultByMod: " << LongInt::MultByMod(a, b, c);
		cout << "DivByMod: " << LongInt::DivByMod(a, b, c);
		cout << "ModExp: " << LongInt::ModExp(a, b, c);
		//LongInt::porevnyanna();

	}
	catch (...)
	{
		cout << "error!\n";
	}
	
	return 0;
}

