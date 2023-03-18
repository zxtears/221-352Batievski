#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    string word;
    int n;
    cout << "Введите колличество символов" << endl;
    cin >> n;
    map<string, int> mm;
    while (cin >> word) // конец ввода ctrl^z потом enter
        mm[word]++; // считаем слова
    map<string, int>::iterator it;
    for (it = mm.begin(); it != mm.end(); ++it)
        cout << it->first << ':' << it->second*100/n <<"%"<< endl;
    system("pause");
    return 0;
}
