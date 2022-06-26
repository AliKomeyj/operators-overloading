#include "..\headers\Polynomial.h"
#include <vector>
#include <fstream>
Polynomial::Polynomial(const vector<Term> &Poly)
{
    for (int i = 0; i < Poly.size(); i++)
    {
        a_polynomial.push_back(Poly[i]);
    }
}
Polynomial &Polynomial::operator=(const Polynomial &ob)
{
    a_polynomial.clear();
    for (int i = 0; i < ob.getPolynomial().size(); i++)
    {
        a_polynomial.push_back(ob.getPolynomial()[i]);
    }
    clean_and_sort();
    return *this;
}
Polynomial &Polynomial ::operator+=(const Polynomial &ob)
{

    *this = (*this + ob);
    return *this;
}

Polynomial &Polynomial::clean_and_sort()
{
    if (a_polynomial.size() <= 1)
    {
        return *this;
    }

    for (int i = 0; i < a_polynomial.size(); i++)
    {
        if (a_polynomial[i].getCoefficient() == 0)
        {
            a_polynomial.erase(a_polynomial.begin() + i);
            continue;
        }
        for (int j = i + 1; j < a_polynomial.size(); j++)
        {
            try
            {
                a_polynomial[i] += a_polynomial[j];
                a_polynomial.erase(a_polynomial.begin() + j);
            }
            catch (...)
            {
                continue;
            }
        }
    }

    for (int i = 0; i < a_polynomial.size() - 1; i++)
    {
        for (int j = i + 1; j < a_polynomial.size(); j++)
        {
            if (a_polynomial[i].getPower() < a_polynomial[j].getPower())
            {
                Term temp = a_polynomial[i];
                a_polynomial[i] = a_polynomial[j];
                a_polynomial[j] = temp;
            }
        }
    }

    return *this;
}

Polynomial &Polynomial ::operator-=(const Polynomial &ob)
{
    (*this) = ((*this) - ob);
    return *this;
}
Polynomial &Polynomial ::operator*=(const Polynomial &ob)
{
    (*this) = ((*this) * ob);
    return *this;
}
Polynomial Polynomial::operator~()
{
    Polynomial temp = (*this);
    for (int i = 0; i < a_polynomial.size(); i++)
    {
        temp.a_polynomial[i] = ~temp.a_polynomial[i];
    }
    return temp;
}
float Polynomial ::operator()(const float x)
{
    float sum = 0;
    for (int i = 0; i < a_polynomial.size(); i++)
    {
        sum += (a_polynomial[i](x));
    }
    return sum;
}
Term Polynomial::operator[](const int index) const
{
    if (index > a_polynomial.size() - 1 || index < 0)
    {
        throw 501;
    }
    Term temp;
    temp = a_polynomial[index];
    return temp;
}
Term &Polynomial::operator[](const int index)
{
    if (index > a_polynomial.size() - 1 || index < 0)
    {
        throw 501;
    }
    return a_polynomial[index];
}

Polynomial &Polynomial::operator++()
{
    Term temp;
    temp.setCoefficient(1);
    temp.setPower(0);
    Polynomial temp2 = temp;
    (*this) += temp2;
    return *this;
}
Polynomial Polynomial::operator++(int)
{
    Polynomial temp;
    temp = (*this);
    ++(*this);
    return temp;
}
Polynomial &Polynomial::operator--()
{
    Term temp;
    temp.setCoefficient(-1);
    temp.setPower(0);
    Polynomial temp2 = temp;
    (*this) += temp2;
    return *this;
}
Polynomial Polynomial::operator--(int)
{
    Polynomial temp;
    temp = (*this);
    --(*this);
    return temp;
}

Polynomial operator+(const Polynomial &ob1, const Polynomial &ob2)
{
    Polynomial temp;
    for (int i = 0; i < ob1.getPolynomial().size(); i++)
    {
        temp.a_polynomial.push_back(ob1.getPolynomial()[i]);
    }
    for (int i = 0; i < ob2.getPolynomial().size(); i++)
    {
        temp.a_polynomial.push_back(ob2.getPolynomial()[i]);
    }
    temp.clean_and_sort();
    return Polynomial(temp.a_polynomial);
}
Polynomial operator-(Polynomial ob1, Polynomial ob2)
{

    for (int i = 0; i < ob2.getPolynomial().size(); i++)
    {
        Term negative(-1, 0);
        ob2.a_polynomial[i].setCoefficient(ob2.a_polynomial[i].getCoefficient() * -1);
    }

    return (ob1 + ob2);
}
Polynomial operator*(const Polynomial &ob1, const Polynomial &ob2)
{
    Polynomial temp;
    for (int i = 0; i < ob1.getPolynomial().size(); i++)
    {
        for (int j = 0; j < ob2.getPolynomial().size(); j++)
        {
            Term x = ob1.getPolynomial()[i] * ob2.getPolynomial()[j];
            temp.a_polynomial.push_back(x);
        }
    }
    temp.clean_and_sort();
    return temp;
}

bool operator>(const Polynomial &ob1, const Polynomial &ob2)
{
    bool equal = true;

    for (int i = 0; i < ob1.getPolynomial().size() && i < ob2.getPolynomial().size(); i++)
    {
        if (ob1.getPolynomial()[i] > ob2.getPolynomial()[i])
        {
            return true;
        }
        if (ob1.getPolynomial()[i] != ob2.getPolynomial()[i])
        {
            equal = false;
        }
    }

    if (equal)
    {
        if (ob1.getPolynomial().size() > ob2.getPolynomial().size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
bool operator<(const Polynomial &ob1, const Polynomial &ob2)
{
    return (ob2 > ob1);
}
bool operator==(Polynomial ob1, Polynomial ob2)
{
    ob1.clean_and_sort();
    ob2.clean_and_sort();
    if (ob1.getPolynomial().size() == ob2.getPolynomial().size())
    {
        for (int i = 0; i < ob1.getPolynomial().size(); i++)
        {
            if (ob1.getPolynomial()[i] != ob2.getPolynomial()[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
bool operator!=(const Polynomial &ob1, const Polynomial &ob2)
{
    return (!(ob1 == ob2));
}
bool operator<=(const Polynomial &ob1, const Polynomial &ob2)
{
    return ((ob1 < ob2) || (ob1 == ob2));
}
bool operator>=(const Polynomial &ob1, const Polynomial &ob2)
{
    return ((ob1 > ob2) || (ob1 == ob2));
}

ostream &operator<<(ostream &OFile, Polynomial &ob)
{
    if (OFile)
    {
        for (int i = 0; i < ob.getPolynomial().size(); i++)
        {
            OFile << ob.getPolynomial()[i];
            OFile << "\n";
        }
    }
    else
    {
        throw 114;
    }
    return OFile;
}
istream &operator>>(istream &IFile, Polynomial &ob)
{
    if (IFile)
    {

        while (!IFile.eof())
        {
            Term temp;
            IFile >> temp;
            ob.a_polynomial.push_back(temp);
        }
        ob.a_polynomial.pop_back();
        ob.clean_and_sort();
    }
    else
    {
        throw 114;
    }
    return IFile;
}

vector<Term> strToPoly(string polynomial)
{
    int countPlus = 0;
    for (int i = 0; i < polynomial.size(); i++)
    {
        if (polynomial[i] == '+')
        {
            countPlus++;
        }
    }
    vector<Term> converted;
    for (int i = 0; i <= countPlus; i++)
    {
        string str = polynomial;
        size_t foundx = str.find_first_of("x");
        Term temp;
        string::size_type sz;
        if (countPlus == i)
        {
            size_t find = str.find("x");
            if (find == string::npos)
            {
                temp.setCoefficient(stod(str, &sz));
                temp.setPower(0);
            }
            else
            {
                temp.setCoefficient(stod(str, &sz));
                str.erase(0, foundx + 2);
                temp.setPower(stod(str, &sz));
            }
            converted.push_back(temp);
            polynomial.erase(0, 300);
        }
        else
        {
            size_t foundplus = str.find_first_of("+");
            str.erase(foundplus, 300);
            size_t find = str.find("x");
            if (find == string::npos)
            {
                temp.setCoefficient(stod(str, &sz));
                temp.setPower(0);
            }
            else
            {
                temp.setCoefficient(stod(str, &sz));
                str.erase(0, foundx + 2);
                temp.setPower(stod(str, &sz));
            }
            converted.push_back(temp);
            polynomial.erase(0, foundplus + 1);
        }
    }

    return converted;
}

void printPolynomial(const Polynomial &ob)
{

    for (int i = 0; i < ob.getPolynomial().size(); i++)
    {
        cout << ob.getPolynomial()[i].getCoefficient();
        if (ob.getPolynomial()[i].getPower() == 0)
        {
            if (i != ob.getPolynomial().size() - 1)
            {

                cout << " + ";
            }

            continue;
        }
        cout << "x^" << ob.getPolynomial()[i].getPower();
        if (i != ob.getPolynomial().size() - 1)
        {

            cout << " + ";
        }
    }
    cout << endl;
}

float returnSum(Polynomial &ob)
{
    float x;
    cout << "Enter 'x' value : ";
    cin >> x;
    return ob(x);
}

Polynomial Recive()
{
    string str;
    cout << "Enter Plynomial : ";
    cin >> str;
    Polynomial temp = strToPoly(str);
    return temp;
}

string boolTostring(bool BOOl)
{
    if (BOOl == 1)
    {
        return "true";
    }
    else
    {
        return "false";
    }
}

void Compare_Polymonials(Polynomial &current)
{

    Polynomial other;
    other = Recive();
    cout << "\nCurrent Polynomial = ";
    printPolynomial(current);
    cout << "Other Polymonial : ";
    printPolynomial(other);

    bool temp1 = current > other;
    cout << "\nCurrent Polynomial > Other Polymonial : " << boolTostring(temp1) << endl;
    bool temp2 = (current >= other);
    cout << "Current Polynomial >= Other Polymonial : " << boolTostring(temp2) << endl;
    bool temp3 = (current < other);
    cout << "Current Polynomial < Other Polymonial : " << boolTostring(temp3) << endl;
    bool temp4 = (current <= other);
    cout << "Current Polynomial <= Other Polymonial : " << boolTostring(temp4) << endl;
    bool temp5 = (current == other);
    cout << "Current Polynomial == Other Polymonial : " << boolTostring(temp5) << endl;
}

void savetxt(Polynomial &ob)
{
    string filename;
    cout << "Enter file name(example.txt) : ";
    cin >> filename;
    ofstream Ofile(filename, ios::trunc);
    if (Ofile)
    {
        Ofile << ob;
        cout << "Done\n";
    }
    else
    {
        throw 114;
    }
}

void savebin(Polynomial &ob)
{
    string filename;
    cout << "Enter file name(example.bin) : ";
    cin >> filename;
    ofstream o("binary_out_test.bin", ios_base::binary);
    if (o)
    {
        unsigned size = ob.getPolynomial().size();
        o.write(reinterpret_cast<char *>(&size), sizeof(unsigned));

        o.write(reinterpret_cast<char *>(&ob.getPolynomial2()[0]), ob.getPolynomial2().size() * sizeof(Term));

        o.close();
    }
    else
    {
        throw 114;
    }
}

void Loadtxt(Polynomial &ob)
{
    string filename;
    cout << "Enter file name(example.txt) : ";
    cin >> filename;
    ifstream f1(filename);
    if (f1)
    {

        f1 >> ob;
        f1.close();
    }
    else
    {
        throw 114;
    }
}

Polynomial Loadbin()
{
    Polynomial ob;
    string filename;
    cout << "Enter file name(example.bin) : ";
    cin >> filename;
    ifstream in("binary_out_test.bin", ios_base::binary);
    if (in)
    {
        unsigned vsize;
        in.read(reinterpret_cast<char *>(&vsize), sizeof(unsigned));
        vector<Term> temp(vsize);
        in.read(reinterpret_cast<char *>(&temp[0]), vsize * sizeof(Term));
        for (int i = 0; i < vsize; i++)
        {
            ob.a_polynomial.push_back(temp[i]);
        }

        in.close();
        return ob;
    }
    else
    {
        throw 114;
    }
}
