#include <iostream>
#include <fstream>
using namespace std;

class Term
{
private:
    int power;
    float coefficient;

public:
    Term(const float &C) { power = 0, coefficient = C; }
    Term(float C = 0, int P = 0) : coefficient(C), power(P) {}

    int getPower() { return power; }
    float getCoefficient() { return coefficient; }

    void setPower(int P) { power = P; }
    void setCoefficient(int C) { coefficient = C; }

    Term &operator=(const float &x) { return *this; }
    Term &operator=(const Term &ob);
    Term &operator+=(Term &ob1);
    Term &operator-=(Term &ob1);
    Term &operator*=(Term &ob1);
    Term &operator/=(Term &ob1);
    Term operator~();
    Term &operator++();
    Term operator++(int);
    Term &operator--();
    Term operator--(int);
    float operator()(float);

    ~Term() {}
};
Term operator+(Term &ob1, Term &ob2);
Term operator-(Term &ob1, Term &ob2);
Term operator/(Term &ob1, Term &ob2);
Term operator*(Term &ob1, Term &ob2);
bool operator>(Term &ob1, Term &ob2);
bool operator<(Term &ob1, Term &ob2);
bool operator>=(Term &ob1, Term &ob2);
bool operator<=(Term &ob1, Term &ob2);
bool operator==(Term &ob1, Term &ob2);
bool operator!=(Term &ob1, Term &ob2);

ostream &operator<<(ostream &, Term &);
istream &operator>>(istream &, Term &);