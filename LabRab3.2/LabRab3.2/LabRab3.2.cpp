#include <iostream>;
#include <algorithm>;
using namespace std;
int vozr(int ch) {
	int a = ch % 10;
	return a;
}
int sm(int n) {
	int t = n;
	int a = 0;
	while (t) {
		a += 1;
		t /= 10;
	}
	int c = 1;
	if (a % 2 == 0) {
		c = 0;
	}
	int s = 0;
	while (n) {
		if (c % 2 == 0) {
			s += n % 10;
		}
		c += 1;
		n /= 10;
	}
	return s;
}
int main() {
	setlocale(0, "");
	cout << "Задание 1" << endl;
	int arr_size;
	cout << "Введите количество элементов массива: ";
	cin >> arr_size;
	int* arr = new int[arr_size];
	for (int i = 0; i < arr_size; i++) {
		cout << "Введите элемент массива: ";
		cin >> arr[i];
	}
	for (int startindex = 0; startindex < arr_size; startindex++) {
		for (int currentindex = startindex + 1; currentindex < arr_size; currentindex++) {
			if (sm(arr[currentindex]) < sm(arr[startindex])) {
				swap(arr[startindex], arr[currentindex]);
			}
		}
	}
	cout << "Сортировка по сумме чисел, стоящих на четных местах: " << endl;
	for (int g = 0; g < arr_size; g++) {
		cout << arr[g] << ' ';
	}
	cout << endl;
	cout << "Задание 2" << endl;
	int size;
	cout << "Введите размер массива: ";
	cin >> size;
	int* abc = new int[size];
	for (int a = 0; a < size; a++) {
		cout << "Введите число массива: ";
		cin >> abc[a];
	}
	for (int m = 0; m < size; m++) {
		for (int g = m + 1; g < size; g++) {
			if (vozr(abc[m]) < vozr(abc[g])) {
				swap(abc[m], abc[g]);
			}
		}
	}
	cout << "Отсортированный массив по возрастанию последней цифры:" << endl;
	for (int r = 0; r < size; r++) {
		cout << abc[r] << " ";
	}
	int q = 0;
	cout << endl;
	for (int f = 0; f < size - 1; f++) {
		if (vozr(abc[f]) != vozr(abc[f + 1])) {
			break;
		}
		else {
			if (q > 0) {
				break;
			}
			cout << "Последние цифры всех чисел совпадают" << endl;
			cout << "Отсортированный массив по убыванию: " << endl;
			for (int y = 0; y < size; y++) {
				for (int x = y + 1; x < size; x++) {
					if (abc[x] > abc[y]) {
						swap(abc[x], abc[y]);
					}
				}
			}
			for (int h = 0; h < size; h++) {
				cout << abc[h] << " ";
			}
			q++;
		}
	}
	return 0;
}