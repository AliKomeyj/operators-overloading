#include "..\headers\Term.h"
#include <vector>
#include <string>
class Polynomial
{
private:
    vector<Term> a_polynomial;

public:
    Polynomial(){};
    Polynomial(const Term &ob) { a_polynomial.push_back(ob); }
    Polynomial(const vector<Term> &);

    vector<Term> getPolynomial() const { return a_polynomial; }
    vector<Term> getPolynomial2() { return a_polynomial; }

    Polynomial &operator=(const Polynomial &);
    Polynomial &operator=(const Term &ob) { return *this; }
    Polynomial &operator+=(const Polynomial &ob);
    Polynomial &operator-=(const Polynomial &ob);
    Polynomial &operator*=(const Polynomial &ob);
    Polynomial operator~();
    Term operator[](const int) const;
    Term &operator[](const int);
    float operator()(const float);

    Polynomial &operator++();
    Polynomial operator++(int);
    Polynomial &operator--();
    Polynomial operator--(int);

    operator Term() { return Term(); }

    friend Polynomial operator+(const Polynomial &ob1, const Polynomial &ob2);
    friend Polynomial operator*(const Polynomial &ob1, const Polynomial &ob2);
    friend Polynomial operator-(Polynomial ob1, Polynomial ob2);
    friend vector<Term> strToPoly(string);
    friend istream &operator>>(istream &IFile, Polynomial &ob);
    friend Polynomial Loadbin();
    Polynomial &clean_and_sort();

    ~Polynomial() {}
};

Polynomial operator+(const Polynomial &ob1, const Polynomial &ob2);
Polynomial operator-(Polynomial ob1, Polynomial ob2);
Polynomial operator*(const Polynomial &ob1, const Polynomial &ob2);

bool operator>(const Polynomial &ob1, const Polynomial &ob2);
bool operator<(const Polynomial &ob1, const Polynomial &ob2);
bool operator>=(const Polynomial &ob1, const Polynomial &ob2);
bool operator<=(const Polynomial &ob1, const Polynomial &ob2);
bool operator==(Polynomial ob1, Polynomial ob2);
bool operator!=(const Polynomial &ob1, const Polynomial &ob2);

ostream &operator<<(ostream &, Polynomial &);
istream &operator>>(istream &, Polynomial &);

vector<Term> strToPoly(string);
void printPolynomial(const Polynomial &);
float returnSum(Polynomial &);
string boolTostring(bool);
Polynomial Recive();
Polynomial Loadbin();
void Compare_Polymonials(Polynomial &);
void savetxt(Polynomial &);
void savebin(Polynomial &);
void Loadtxt(Polynomial &);
void Loadtxt(Polynomial &);
