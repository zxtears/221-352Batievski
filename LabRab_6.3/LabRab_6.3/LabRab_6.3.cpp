#include <iostream> //FIFO (First-In, First-Out).
#include <queue>

using namespace std;

bool proverka(int n){
    bool mn = true;
    int i = 2;
    while (i * i <= n) {
        while (n % i == 0) {
            if (i != 2 and i != 3 and i != 5)
                mn = false;
            n /= i;
        }
        i++;
    }
    if (n != 2 and n != 3 and n != 5)
        mn = false;
    return mn;
}

void task() {
    queue <int> j;
    int n;
    cout << "VVedite chislo";
    cin >> n;
    int i = 0;
    int k = 0;
    while (i != n) {
        if (proverka(k)) {
            j.push(k);
            i++;
        }
        k++;
    }
    int m = j.size();
    for (int i = 0; i < m; i++) {
        cout << j.front() <<'\n';
        j.pop();
    }

}

int main() {
    task();
}
