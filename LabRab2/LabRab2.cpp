#include <iostream>
#include <locale.h>
using namespace std;

void task1() {
    cout << "Vvedite celoe chislo: ";
    int n, i, j;
    cin >> n;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= i; j++)
            cout << j;
        cout << endl;
    }
}

void task2() {
    int n, k;
    cout << "Vvedite n: ";
    cin >> n;
    cout << "Vvedite k: ";
    cin >> k;

    int nFactorial = 1;
    int kFactorial = 1;
    int difFactorial = 1;

    // n = 5 тогда от 1 до 5 мы умножаем н! на i и находим н!
    for (int i = 1; i <= n; ++i) { // <= чтобы цикл прошел 5 раз
        nFactorial *= i;
    }

    for (int i = 1; i <= k; ++i) {
        kFactorial *= i;
    }

    for (int i = 1; i <= n - k; ++i) {
        difFactorial *= i;
    }

    int result = nFactorial / (difFactorial * kFactorial);
    cout << " С = : ";
    cout << result;
}

void task3() {
    int number, count, sum;
    count = 0;
    sum = 0;
    cout << "Vvedite chisla (v konce vvedite -1 ) :";
    cin >> number;
    while (number != EOF) { // != пока не равно end of line, EOF = -1
        count++;
        sum += number;

        cin >> number;
    }
    cout << " Otvet : ";
    cout << (double(sum) / count);
}

int main()
{

    int choice = 0; // в этой переменной будет храниться выбор пользователя while 
    while (true) {
        std::cout << "\n Vaberite zadanie \n"
            << "1. number 1\n"
            << "2. number 2\n"
            << "3. number 3\n"
            << "4. exit\n"
            << " Vvedite nomer zadaniya: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            /*вызов функции для решения задания 1*/;
            task1();
            break; // если его не ставить, то после вызова task1(), начнет выполнятся task2()
        }
        case 2: {
            /*вызов функции для решения задания 1*/;
            task2();
            break;
        }
        case 3: {
            task3();
            break;
        }
        default: {
            return 0;
        }
        }
    }
}