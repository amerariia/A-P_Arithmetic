#include "LongInt.h"

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

LongInt& LongInt::operator+ (LongInt& num2)
{
	return *this;
}

LongInt::LongInt(int size) {
	num = new int[size];
	length = size;
}