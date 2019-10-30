// A-P_Arithmetic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "Headers.h"

int main()
{	
	/*LongInt num1, num2;
	cin >> num1;
	cin >> num2;*/
	const int N = 100;
	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[N];
	string str;
	int i = 0;
	cout << "enter a, b, c for      ax = b(mod c)" << endl;
	while (cin >> A[i] >> B[i] >> C[i])
	{
		cout << A[i] << "x = " << B[i] << "(mod " << C[i] << ")" << endl;
		cin.clear();
		i++;
	} 
	cout << endl;
	int length = i;
	int M = 1;
	int* Meme = new int[length];
	int* Nene = new int[length];
	int* Q = new int[length];

	for (i = 0; i < length; i++)
	{
		Q[i] = 1;
		if (A[i] == 1)
		{
			break;
		}
		else
		{
			while ((B[i] % A[i]) != 0)
			{
				B[i] = B[i] + C[i];
			}
			B[i] = B[i] / A[i];
			A[i] = 1;
			
		}
		cout << A[i] << "x = " << B[i] << "(mod " << C[i] << ")" << endl;
		M = M * C[i];
	}
	/////////////////
	for (i = 0; i < length; i++)
	{
		Meme[i] = M / C[i];
		cout << "M[" << i << "] "<< "N[" << i << "] = "   << Q[i] << "(mod " << C[i] << ")" << endl;
	}
	////////////////
	for (i = 0; i < length; i++)
	{
		cout << Meme[i] << " N[" << i << "] " <<  " = " << Q[i] << "(mod " << C[i] << ")" << endl;
	}
	////////////////
	
	for (i = 0; i < length; i++)
	{
		while ((Q[i] % Meme[i]) != 0)
		{
			Q[i] = Q[i] + C[i];		
		}
		Q[i] = Q[i] / Meme[i];
	}
	cout << endl;
	for (i = 0; i < length; i++)
	{
		cout << "N[" << i << "] " << " = " << Q[i] << "(mod " << C[i] << ")" << endl;
	}
	int Xresult = 1;
	for (i = 0; i < length; i++)
	{
		Xresult += Meme[i] * Q[i] * B[i];
	}
	cout << "Xresult = " << Xresult << endl;
	int XXresult;
	cout << "XXresult ~ " << Xresult << " (mod " << M << " )" << endl;
	while (Xresult > M)
	{
		Xresult = Xresult - M;
	}
	cout << "XXresult = " << Xresult << endl;

	

	/*cout << "enter a, b, c for      ax = b(mod c)" << endl;
	try {
		cout << "num1 ^ num2 = ";
		LongInt r = num1 ^ num2;
		cout << r << endl;

	}
	catch (...) {
		cout << "error!\n";
	}
	
	*/
	

	return 0;
}

