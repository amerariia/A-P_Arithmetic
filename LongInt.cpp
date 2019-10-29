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

	try {
		num = new int[length];
	}
	catch(bad_alloc& ex)
	{
		cout << "bad_alloc\n";
		cout << ex.what();
	}
	catch (...)
	{
		cout << "pizdec!";
	}
	for (int j = length - 1; j >= 0; --j)
	{
		num[j] = number[i] - '0';
		i++;
	}

}

LongInt LongInt::sqrt() const
{
	string s0 = "0", s1 = "1";
	LongInt zero(s0);
	LongInt one(s1);
	LongInt r(s0), r2(s0);

	if (*this < zero)
		throw exception("inv_arg");

	while(r2 < *this)
	{
		r = r + one;
		r2 = r * r;
	}

	if (r2 == *this)
		return r;
	else
		return r - one;
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
				while (n1.num[j] == 9 && j < length + 1)
				{
					n1.num[j] = 0;
					j++;
				}
				n1.num[j]++;
			}
			r1.num[i] = (n1.num[i] + n2.num[i]) % 10;
		}

		for (i; i < length + 1; ++i)
			r1.num[i] = n1.num[i];

		int j = r1.length - 1;
		while (r1.num[j] == 0 && j >= 0)
			j--;

		if (j != r1.length - 1)
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

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

LongInt LongInt::operator^ (const LongInt& n2) const
{
	string str = "0";
	string str1 = "1";
	string str2 = "2";
	LongInt r(str1); //result
	LongInt odun(str1);
	LongInt dwa(str2);
	LongInt n_2(n2);	
	LongInt zero(str);
	cout << *this << n2;

	if (n_2 < zero)
	{
		throw exception();
	}
	if (this->isPosit == true)
	{
		while (n_2 > zero)
		{			
			r = r * *this;
			n_2 = n_2 - odun;
		}
		return r;
	}
	else
	{
		if (n_2 % dwa == odun)
		{
			LongInt n_1(*this);
			n_1.isPosit = true;
			r = n_1 ^ n_2;
			r.isPosit = false;
			return r;
		}
		else
		{
			LongInt n_1(*this);
			n_1.isPosit = true;
			return n_1 ^ n_2;
		}
	}

}

LongInt LongInt::operator* (const LongInt& n2) const
{
	if (this->isPosit == true && n2.isPosit == true)
	{
		string str = "0";
		string str1 = "1";
		LongInt r(str); //result
		LongInt n_1(*this);
		LongInt odun(str1);
		LongInt zero(str);
		while (n_1 > zero)
		{
			r = r + n2;
			n_1 = n_1 - odun;
		}
		return r;
	}
	
	if (this->isPosit == false && n2.isPosit == true)
	{
		LongInt n_1(*this);
		n_1.isPosit = true;
		LongInt r = n_1 * n2;
		r.isPosit = false;
		return r;
	}

	if (this->isPosit == true && n2.isPosit == false)
	{
		LongInt n_2(n2);
		n_2.isPosit = true;
		LongInt r = *this * n_2;
		r.isPosit = false;
		return r;
	}

	if (this->isPosit == false && n2.isPosit == false)
	{
		LongInt n_1(*this);
		LongInt n_2(n2);

		n_1.isPosit = true;
		n_2.isPosit = true;
		return n_2 * n_1;
	}
}

LongInt LongInt::operator/ (const LongInt& n2) const
{
	string num = "0", str1 = "1";

	LongInt result;
	LongInt left(*this);
	LongInt right(n2);
	LongInt zero(num);
	LongInt one(str1);
	
	bool sign = (left.isPosit && !right.isPosit) || (!left.isPosit && right.isPosit); //if the result is negative
	left.isPosit = true;
	right.isPosit = true;

	if (right == zero)
		throw exception("Divide by zero");
	if (right > left)
		return zero;
	else
	{
		LongInt div = zero;
		while (left > right || left == right)
		{
			div = div + one;
			left = left - right;
		}
		result = div;
 	}

	result.isPosit = !sign;
	return result;
}

LongInt LongInt::operator% (const LongInt& n2) const
{
	string s = "0";
	LongInt zero(s);
	if (n2 == zero || n2 < zero || *this < zero)
		throw exception();
	LongInt left(*this);
	LongInt right(n2);

	return left - (left / right) * right;
}

LongInt LongInt ::AddByMod(LongInt& n1, LongInt& n2, LongInt& n)
{
	string str = "1";
	LongInt one(str);
	//LongInt left(n1);
	//LongInt right(n2);
	//LongInt modul(n);

	//if (n > n1 - one || n > n2 - one)
	//	throw exception("numbers must be less or equal n-1");

	LongInt result = n1 + n2;
	return result;
	//if (result < modul)
	//	return result;
	//else
	//{
	//	return (result - modul);
	//}

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
	try {
		num = new int[length];
	}
	catch (bad_alloc& ex)
	{
		cout << ex.what();
	}
	catch (...)
	{
		cout << "pizdec!";
	}
	isPosit = num2.isPosit;
	for (int i = 0; i < length; ++i)
		num[i] = num2.num[i];

}

LongInt::LongInt(unsigned int size) 
{
	try {
		num = new int[size];
	}
	catch (bad_alloc& ex)
	{
		cout << ex.what();
	}
	catch(...)
	{
		cout << "pizdec!";
	}
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

	return os;
}

