#include "LongInt.h"

LongInt& LongInt::operator+ (LongInt& num2)
{
	return *this;
}

LongInt& LongInt::operator- (LongInt& num2)
{
	if (num2 > * this)
	{
		 num2 - *this;
	}
		
	else
	{

	}
}

bool LongInt::operator> (LongInt& num2)
{
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
	//length
}

LongInt::LongInt(int size) {
	num = new int[size];
	length = size;
	Zero();
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

	for (int j = length - 1; j >= length; --j)
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