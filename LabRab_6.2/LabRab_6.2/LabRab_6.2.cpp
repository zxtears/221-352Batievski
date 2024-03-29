﻿#include <iostream>
#include <deque>

using std::cout;
using std::cin;
using std::endl;
using std::deque;

bool Palindrom(deque<char> deq) {
	bool checkPolindrom = true;
	for (int i = 0, j = deq.size() - 1; i < j; i++, j--) {
		if (deq.at(i) == ' ') {
			i++;
		}
		if (deq.at(j) == ' ') {
			j--;
		}
		if (tolower(deq.at(i)) != tolower(deq.at(j))) { // перевод в один регистр, если условие даст true, то строка НЕ является палиндромом
			checkPolindrom = false;
			break;
		}
	}
	return checkPolindrom;
}

int rotate(int* A, int* B, int* C) {
	return (B[0] - A[0]) * (C[1] - B[1]) - (B[1] - A[1]) * (C[0] - B[0]);
}

deque<int> grahamscan(int(*A)[2], int n) {
	//шаг 1
	deque<int> P;  // список номеров точек
	for (int i = 0; i < n; i++) {
		P.push_back(i);
	}
	for (int i = 1; i < n; i++) {
		if (A[P.at(i)][0] < A[P.at(0)][0]) { // если P[i] - ая точка лежит левее P[0] - ой точк
			// меняем местами номера этих точек
			int t = P[i];
			P[i] = P[0];
			P[0] = t;
		}
	}

	//шаг 2
	for (int i = 2; i < n; i++) { // сортировка вставкой
		int j = i;
		while (j > 1 && (rotate(A[P[0]], A[P[j - 1]], A[P[j]]) < 0)) {
			int t = P[j];
			P[j] = P[j - 1];
			P[j - 1] = t;
			j -= 1;
		}
	}

	//шаг 3
	deque<int> S = { P[0], P[1] }; // создаем дек
	int sizeS = 2;
	for (int i = 2; i < n; i++) {
		while (rotate(A[S[sizeS - 2]], A[S[sizeS - 1]], A[P[i]]) < 0) {
			S.pop_back();
			sizeS--;
		}
		S.push_back(P[i]);
		sizeS++;
	}
	return S;
}

int main() {
	// 1
	cout << "1" << endl;
	char input;
	deque<char> deq;

	cout << "Break: 1" << endl;
	while (cin >> input) {
		if (input == '1') {
			break;
		}
		deq.push_back(input);
	}

	if (Palindrom(deq)) {
		cout << "Polindrom" << endl;
	}
	else {
		cout << "Not Polindrom" << endl;
	}
	//2
	cout << "2" << endl;
	int A[12][2] = { {3, 3}, {2, 1}, {6, 2}, {5, 4}, {7, 5},
		{4, 9}, {1, 6}, {10, 7}, {8, 8}, {9, 10}, {-1, -3}, {-5, -10} };
	for (int i : grahamscan(A, 12)) {
		cout << (i + 1) << " ";
	}
}