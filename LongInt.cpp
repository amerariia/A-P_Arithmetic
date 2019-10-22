#include "LongInt.h"

LongInt& LongInt::operator+ (LongInt& num2)
{
	return *this;
}

LongInt::LongInt(int size) {
	num = new int[size];
	length = size;
}

LongInt::LongInt(string& number)
{
	length = number.size();
	int i = 0;
	if (number[i] == '-')
	{
		isPosit = false;
		length--;
		i++;
	}

	num = new int[length];

	for (int j = 0; j < length; ++j)
	{
		num[j] = number[i] - '0';
		i++;
	}

}

void LongInt::print()
{
	if (isPosit == false)
		cout << '-';
	for (int i = 0; i < length; ++i)
		cout << num[i];
}

void LongInt::Zero()
{
	for (int i = 0; i < length; ++i)
		num[i] = 0;
	isPosit = true;
}