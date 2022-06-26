#include <iostream>
#include <fstream>
#include "headers\Polynomial.h"
using namespace std;


void PolynomialMenu(Polynomial &ob)
{
    int Polynomial_menu;
    do
    {
        system("cls");
        ob.clean_and_sort();
        cout << "Current Polynomial = ";
        printPolynomial(ob);
        cout << "\n\n";

        cout << "1- Add\n2- Subtract\n3-  Multiply\n4- Derivative\n5- Find Degree\n";
        cout << "6- Find Value for specific x\n7- Compare\n8- Save to a text file\n9- Save to a binary file";
        cout << "\n10 - Back to Main Menu\n---------------\n";
        cin >> Polynomial_menu;

        switch (Polynomial_menu)
        {
        case 1:
            ob += Recive();
            break;
        case 2:
            ob -= Recive();
            break;

        case 3:
            ob *= Recive();
            break;
        case 4:
            ob = (~ob);
            break;
        case 5:
            ob.clean_and_sort();
            cout << "\nDegree : " << ob.getPolynomial()[0].getPower() << endl;
            system("pause");
            break;
        case 6:
            cout << "\nResult : " << returnSum(ob) << endl;
            system("pause");
            break;
        case 7:
            system("cls");
            Compare_Polymonials(ob);
            system("pause");
            break;
        case 8:
            savetxt(ob);
            break;
        case 9:
            savebin(ob);
            break;
        default:
            break;
        }

    } while (Polynomial_menu != 10);
}


int main()
{
    Polynomial mainPolynomial = strToPoly("0");

    int mainMenu;

    do
    {
        system("cls");
        cout << "1- New Polynomial\n2- Load from text file\n3- Load from binary file\n4- Quit";
        cout << "\n----------------\n";
        cin >> mainMenu;
        switch (mainMenu)
        {
        case 1:
            PolynomialMenu(mainPolynomial);

            break;
        case 2:
            try
            {
                Loadtxt(mainPolynomial);
                PolynomialMenu(mainPolynomial);
            }
            catch (int err)
            {
                cout << "Error : " << err << endl;
            }

            break;
        case 3:

            try
            {
                mainPolynomial = Loadbin();
                PolynomialMenu(mainPolynomial);
            }
            catch (int err)
            {
                cout << "Error : " << err << endl;
            }

            break;
        default:
            break;
        }
    } while (mainMenu != 4);

    system("pause");
    return 0;
}

/* Error List :
114 - file could not opened
505 - the powers are not equal
501 - not found
*/