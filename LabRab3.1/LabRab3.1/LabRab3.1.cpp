#include <iostream>;
#include < algorithm>;
using namespace std;
void task1() {
	int size;
	cout << "Введите длину массива: ";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "Введите число: ";
		cin >> arr[i];
	}
	for (int j = 0; j < size; j++) {
		for (int k = j + 1; k < size; k++) {
			if (arr[j] > arr[k]) {
				swap(arr[j], arr[k]);
			}
		}
	}
	for (int t = 0; t < size; t++) {
		cout << arr[t] << " ";
	}
}
void task2(char* m, int n) {
	int kollraz = 26;
	int j;
	int p[26] = { 0 };
	for (int i = 0; i < n; i++) {
		j = int(m[i] - 'a');
		p[j]++;
	}
	int i = 0;
	for (j = 0; j < 26;) {
		if (p[j] > 0) {
			m[i] = char(int('a') + j);
			i++;
			p[j]--;
		}
		else j++;
	}
	for (int t = 0; t < n; t++) {
		cout << m[t] << " ";
	}
}
void Merge(int* A, int first, int last)
{
	int middle, start, final, j;
	int* mas = new int[100];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}
	for (j = first; j <= last; j++) A[j] = mas[j];
	delete[]mas;
}
void MergeSort(int* A, int first, int last)
{
	{
		if (first < last)
		{
			MergeSort(A, first, (first + last) / 2);
			MergeSort(A, (first + last) / 2 + 1, last);
			Merge(A, first, last);
		}
	}
}
void task3()
{
	int i, n;
	int* A = new int[100];
	cout << "Размер массива: "; cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << i << " Элемент массива:  "; cin >> A[i];
	}
	MergeSort(A, 1, n);
	cout << "Упорядоченный массив: ";
	for (i = 1; i <= n; i++) cout << A[i] << " ";
}
int main() {
	setlocale(0, "");
	int choice = 0;
	while (true) {
		cout << "1.Алгоритм сортировки пузырьком" << endl;
		cout << "2.Алгоритм сортировки подсчетом" << endl;
		cout << "3.Алгоритм сортировки слиянием" << endl;
		cout << "4.Выход" << endl;
		cout << "Введите номер задания, которое хотите выполнить: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			task1();
			break;
		}
		case 2: {
			int razmer;
			cout << "Введите размер массива: ";
			cin >> razmer;
			char k[1000];
			for (int r = 0; r < razmer; r++) {
				cout << "Введите символ массива: ";
				cin >> k[r];
			}
			task2(k, razmer);
			break;
		}
		case 3: {
			task3();
		}
		default: {
			return 0;
		}



		}
	}
}