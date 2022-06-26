#include "..\headers\Term.h"
#include <cmath>
Term operator+(Term &ob1, Term &ob2)
{
	if (ob1.getPower() == ob2.getPower())
	{
		float C = ob1.getCoefficient() + ob2.getCoefficient();
		return Term(C, ob1.getPower());
	}
	throw 505;
}
Term operator-(Term &ob1, Term &ob2)
{
	if (ob1.getPower() == ob2.getPower())
	{
		float C = ob1.getCoefficient() - ob2.getCoefficient();
		return Term(C, ob1.getPower());
	}
	throw 505;
}
Term operator/(Term &ob1, Term &ob2)
{
	if (ob2.getCoefficient() == 0)
	{
		throw 505;
	}
	if (ob1.getCoefficient() == 0)
	{
		return Term(0, 0);
	}

	float C = ob1.getCoefficient() / ob2.getCoefficient();
	int P = ob1.getPower() - ob2.getPower();
	return Term(C, P);
}
Term operator*(Term &ob1, Term &ob2)
{
	float C = ob1.getCoefficient() * ob2.getCoefficient();
	int P = ob1.getPower() + ob2.getPower();
	return Term(C, P);
}

bool operator>(Term &ob1, Term &ob2)
{
	if (ob1.getPower() > ob2.getPower())
	{
		return true;
	}
	else if (ob1.getPower() == ob2.getPower())
	{
		if (ob1.getCoefficient() > ob2.getCoefficient())
		{
			return true;
		}
	}
	return false;
}
bool operator<(Term &ob1, Term &ob2)
{
	if (ob1.getPower() < ob2.getPower())
	{
		return true;
	}
	else if (ob1.getPower() == ob2.getPower())
	{
		if (ob1.getCoefficient() < ob2.getCoefficient())
		{
			return true;
		}
	}
	return false;
}
bool operator==(Term &ob1, Term &ob2)
{
	if ((ob1.getPower() == ob2.getPower()) && (ob1.getCoefficient() == ob2.getCoefficient()))
	{
		return true;
	}
	return false;
}
bool operator!=(Term &ob1, Term &ob2)
{
	if (!(ob1 == ob2))
	{
		return true;
	}
	return false;
}
bool operator<=(Term &ob1, Term &ob2)
{
	if ((ob1 < ob2) || (ob1 == ob2))
	{
		return true;
	}
	return false;
}
bool operator>=(Term &ob1, Term &ob2)
{
	if ((ob1 > ob2) || (ob1 == ob2))
	{
		return true;
	}
	return false;
}

Term &Term::operator=(const Term &ob)
{
	power = ob.power;
	coefficient = ob.coefficient;
	return *this;
}
Term &Term::operator+=(Term &ob)
{
	if (ob.power == power)
	{
		coefficient += ob.coefficient;
		return *this;
	}
	else
	{
		throw 505;
	}
}
Term &Term::operator-=(Term &ob)
{
	if (ob.power = power)
	{
		coefficient -= ob.coefficient;
		return *this;
	}
	else
	{
		throw 505;
	}
}
Term &Term::operator*=(Term &ob)
{
	power += ob.power;
	coefficient *= ob.coefficient;
	return *this;
}
Term &Term::operator/=(Term &ob)
{
	if (ob.coefficient == 0)
	{
		throw 505;
	}
	power -= ob.power;
	coefficient /= ob.coefficient;
	return *this;
}
Term Term::operator~()
{
	Term temp = (*this);
	if (temp.getPower() == 0)
	{
		return Term(0, 0);
	}

	temp.coefficient *= temp.power;
	temp.power--;
	return temp;
}
float Term::operator()(float x)
{
	float result = 0;
	result = coefficient * (pow(x, power));
	return result;
}
Term &Term::operator++()
{
	if (power == 0)
	{
		coefficient++;
		return *this;
	}
	throw 505;
}
Term Term::operator++(int)
{
	if (power == 0)
	{
		Term ob;
		ob = *this;
		coefficient++;
		return ob;
	}
	throw 505;
}
Term &Term::operator--()
{
	if (power == 0)
	{
		coefficient--;
		return *this;
	}
	throw 505;
}
Term Term::operator--(int)
{
	if (power == 0)
	{
		Term ob;
		ob = *this;
		coefficient--;
		return ob;
	}
	throw 505;
}
ostream &operator<<(ostream &OFile, Term &ob)
{
	if (OFile)
	{
		OFile << ob.getCoefficient();
		OFile << "\t";
		OFile << ob.getPower();
	}
	else
	{
		throw 114;
	}

	return OFile;
}
istream &operator>>(istream &IFile, Term &ob)
{
	int P;
	float C;
	if (IFile)
	{
		IFile >> C;
		ob.setCoefficient(C);
		IFile >> P;
		ob.setPower(P);
	}
	else
	{
		throw 114;
	}

	return IFile;
}