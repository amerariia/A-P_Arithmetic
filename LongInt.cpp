#include "LongInt.h"

LongInt& LongInt::operator+ (LongInt& num2)
{
	return *this;
}

LongInt& LongInt::operator- (LongInt& num2)
{
	cout << "oper-\n";
	if (num2 > *this)
	{
		cout << "minus\n";
		LongInt res(num2 - *this);
		res.isPosit = false;
		return res;
	}
	else
	{
		cout << "norm\n";
		LongInt res(length);
		res.print();
		//bool odin = false;
		for (int i = 0; i < length; ++i)
		{
			if (num[i] < num2.num[i])
			{
				res.num[i] = num[i] + 10 - num2.num[i];
				int j = 1;
				while (num[i + j] == 0)
				{
					num[i + j] = 9;
					j++;
				}
				num[i + j]--;

			}
			else
				res.num[i] = num[i] - num2.num[i];
		}
		cout << "length in op-: " << res.length << endl;

		cout << "print in op-\n";
		res.print();
		return res;
	}
}

bool LongInt::operator> (LongInt& num2)
{
	cout << "oper>\n";
	if (length > num2.length)
		return true;
	if (length < num2.length)
		return false;
	int i = length;

	while (i >= 0)
	{
		if (num[i] > num2.num[i])
			return true;
		if (num[i] < num2.num[i])
			return false;
		i--;
	}
	return false;
}

LongInt::LongInt(LongInt& num2)
{
	cout << "constr copy\n";
	cout << "length = " << num2.length << endl;

	length = num2.length;
	num = new int[length];
	isPosit = num2.isPosit;
	for (int i = 0; i < length; ++i)
		num[i] = num2.num[i];
	cout << "end of c c\n";

}

LongInt::LongInt(int size) {
	num = new int[size];
	length = size;
	Zero();
}

LongInt::LongInt(string& number)
{
	cout << "CONSTR string\n";
	length = number.size();
	int i = 0;
	if (number[i] == '-')
	{
		isPosit = false;
		length--;
		i++;
	}

	num = new int[length];

	for (int j = length - 1; j >= 0; --j)
	{
		//cout << "constr: " << int(number[i] - '0') << endl;
		num[j] = number[i] - '0';
		i++;
	}

}

void LongInt::print()
{
	cout << "print\n";
	cout << "length: " << length << endl;
	if (isPosit == false)
		cout << '-';
	for (int i = length-1; i >= 0; --i)
		cout << num[i];
	cout << endl;
}

void LongInt::Zero()
{
	for (int i = 0; i < length; ++i)
		num[i] = 0;
	isPosit = true;
}