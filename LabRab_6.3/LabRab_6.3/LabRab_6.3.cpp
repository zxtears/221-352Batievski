#include <iostream>

using namespace std;

unsigned Div(unsigned a) {
    while (a % 2 == 0)
        a /= 2;
    while (a % 3 == 0)
        a /= 3;
    while (a % 5 == 0)
        a /= 5;
    return a;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    unsigned a = 2, count = 0, n;
    cin >> n;
    while (count < n) {
        if (Div(a) == 1) {
            cout << a << " ";
            ++count;
        }
        ++a;
    }
    return 0;
}