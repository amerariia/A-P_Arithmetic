#include "Headers.h"

LongInt::LongInt()
{
	//cout << "empty constr\n";
	num = nullptr;
	length = 0;
}

LongInt::~LongInt()
{
	if (num != nullptr)
		delete[] num;
}

LongInt::LongInt(string& number)
{
	//cout << "CONSTR string\n";
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
		num[j] = number[i] - '0';
		i++;
	}

}

LongInt LongInt::operator+ (const LongInt& n2) const
{
	if (this->isPosit == true && n2.isPosit == false)
	{
		LongInt n(n2);
		n.isPosit = true;
		return *this - n;
	}
	if (this->isPosit == false && n2.isPosit == true)
	{
		LongInt n(*this);
		n.isPosit = true;
		return n2 - n;
	}

	if (this->isPosit == true && n2.isPosit == true)
	{
		if (*this < n2)
			return n2 + *this;
		LongInt r1(this->length + 1);
		LongInt n1(this->length + 1);
		for (int i = 0; i < length; ++i)
			n1.num[i] = this->num[i];

		int i;
		for (i = 0; i < n2.length; ++i)
		{
			if (n1.num[i] + n2.num[i] > 9)
			{
				int j = i + 1;
				while (n1.num[j] == 9 && j < length)
				{
					n1.num[j] = 0;
					j++;
				}
				n1.num[j]++;
			}
			r1.num[i] = (n1.num[i] + n2.num[i]) % 10;
		}

		for (i; i < length; ++i)
			r1.num[i] = n1.num[i];

		int j = length;
		while (r1.num[j] == 0 && j > 0)
			j--;

		if (j != length)
		{
			r1.length = j + 1;
			LongInt r(r1);
			return r;
		}

		return r1;

	}

	if (this->isPosit == false && n2.isPosit == false)
	{
		LongInt n_1(*this);
		n_1.isPosit = true;
		LongInt n_2(n2);
		n_2.isPosit = true;
		LongInt r = n_1 + n_2;
		r.isPosit = false;
		return r;
	}

	LongInt n = n2;
	return n;
}

LongInt LongInt::operator- (const LongInt& n2) const
{
	if (this->isPosit == true && n2.isPosit == false)
	{
		LongInt n(n2);
		n.isPosit = true;
		return *this + n;
	}

	if (this->isPosit == false && n2.isPosit == true)
	{
		LongInt n(*this);
		n.isPosit = true;
		LongInt r = n + n2;
		r.isPosit = false;
		return r;
	}

	if (this->isPosit == true && n2.isPosit == true)
	{
		if (*this < n2)
		{
			LongInt r = n2 - *this;
			r.isPosit = false;
			return r;
		}
		else
			if (*this == n2)
			{
				string str = "0";
				LongInt r(str);
				return r;
			}
		// n1 > n2

		LongInt r1(this->length);
		LongInt n1(*this);
		int i;
		for (i = 0; i < n2.length; ++i)
		{
			if (n1.num[i] < n2.num[i])
			{
				n1.num[i] += 10;
				int j = i + 1;
				while (n1.num[j] == 0 && j < length)
				{
					n1.num[j] = 9;
					j++;
				}
				n1.num[j]--;
			}
			r1.num[i] = n1.num[i] - n2.num[i];
		}

		for (i; i < length; ++i)
			r1.num[i] = n1.num[i];

		int j = length - 1;
		while (r1.num[j] == 0 && j > 0)
			j--;

		if (j != length - 1)
		{
			r1.length = j + 1;
			LongInt r(r1);
			return r;
		}

		return r1;
		
	}

	if (this->isPosit == false && n2.isPosit == false)
	{
		LongInt n_1(*this);
		LongInt n_2(n2);

		n_1.isPosit = true;
		n_2.isPosit = true;
		return n_2 - n_1;
	}	
}

bool LongInt::operator> (const LongInt& n2) const
{
	if (this->isPosit == true && n2.isPosit == false)	//+ > -
		return true;
	if (this->isPosit == false && n2.isPosit == true)	//- > +
		return false;

	bool answer = true;			// + +
	if (this->isPosit == false)	// - -
		answer = false;

	if (length > n2.length)		// +____ > +__
		return answer;
	if (length < n2.length)		// +__ > +____
		return !answer;

	int i = length - 1;

	while (i >= 0)
	{
		if (num[i] > n2.num[i])
			return answer;
		if (num[i] < n2.num[i])
			return !answer;
		i--;
	}
	return false;
}

bool LongInt::operator== (const LongInt& n2) const
{
	if (this->isPosit != n2.isPosit || this->length != n2.length)
		return false;

	int i = length - 1;

	while (i >= 0)
	{
		if (num[i] != n2.num[i])
			return false;
		i--;
	}

	return true;
}

bool LongInt::operator< (const LongInt& n2) const
{
	if (*this == n2)
		return false;
	return !(*this > n2);
}


LongInt::LongInt(const LongInt& num2)
{
	//cout << "constr copy\n";

	length = num2.length;
	num = new int[length];
	isPosit = num2.isPosit;
	for (int i = 0; i < length; ++i)
		num[i] = num2.num[i];

}

LongInt::LongInt(unsigned int size) {
	num = new int[size];
	length = size;
	Zero();
}


void LongInt::Zero()
{
	for (int i = 0; i < length; ++i)
		num[i] = 0;
	isPosit = true;
}

LongInt& LongInt::operator= (LongInt const& n)
{
	//cout << "operator= \n";
	if (this != &n)
		LongInt(n).swap(*this);
	
	return *this;
}

istream& operator >> (istream& is, LongInt& n)
{
	cout << "Enter a number: ";
	string str;
	cin >> str;
	n = LongInt(str);
	return is;
}

ostream& operator << (ostream& os, const LongInt& n)
{
	if (n.isPosit == false)
		os << '-';
	for (int i = n.length - 1; i >= 0; --i)
		os << n.num[i];
	os << '\n';
	//os << "Length = " << n.length << '\n';

	return os;
}

