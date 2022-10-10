#include <iostream>
#include <locale>
#include <bitset>
using namespace std;

int main()
{
    cout << "Batievski Stepan Ilich 211-352" << endl;

    cout << "min int= " << int(0b10000000000000000000000000000000)
        << ", max int = " << int(0b01111111111111111111111111111111)
        << ", size of int = " << sizeof(int) << endl;

    cout << "min unsigned int = " << unsigned int(0b00000000000000000000000000000000)
        << ", max unsigned int = " << unsigned int(0b11111111111111111111111111111111)
        << ", size of unsigned int = " << sizeof(unsigned int) << endl;

    cout << "min short = " << short(0b1000000000000000)
        << ", max short = " << short(0b0111111111111111)
        << ", size of  short = " << sizeof(short) << endl;

    cout << "min unsigned short = " << unsigned short(0b0000000000000000)
        << ", max unsigned short = " << unsigned short(0b1111111111111111)
        << ", size of unsigned short = " << sizeof(unsigned short) << endl;

    cout << "min long = " << long(0b1000000000000000000000000000000000000000000000000000000000000000)
        << ", max long = " << long(0b0111111111111111111111111111111111111111111111111111111111111111)
        << ", size of  long = " << sizeof(long) << endl;

    cout << "min long long = " << long long(0b1000000000000000000000000000000000000000000000000000000000000000)
        << ", max long long = " << long long(0b0111111111111111111111111111111111111111111111111111111111111111)
        << ", size of  long long = " << sizeof(long long) << endl;

    cout << "min double = " << double(0b1000000000000000000000000000000000000000000000000000000000000000)
        << ", max double = " << double(0b0111111111111111111111111111111111111111111111111111111111111111)
        << ", size of  double = " << sizeof(double) << endl;


    cout << "min char = " << char(0b10000000)
        << ", max char = " << char(0b01111111)
        << ", size of  char = " << sizeof(char) << endl;

    cout << "min bool = " << bool(0b00000000)
        << ", max bool = " << bool(0b00000001)
        << ", size of  bool = " << sizeof(bool) << endl;

    cout << endl;
    int chislo;
    cout << "Vvedite chislo"; cin >> chislo;
    cout << "Dvoichniy vid" << bitset<8 * sizeof(chislo) >(chislo) << endl;
}

