﻿#include <iostream>
#include "Array.h"

int main() {
    Array matr1;
    matr1.input();
    matr1.print();
    std::cout << matr1.trace(matr1.matr, matr1.get_s()) << std::endl;
    Array matr2;
    matr2.input();
    matr2.print();
    Array matr3;
    matr3.matrixsum(matr1.matr, matr2.matr, matr1.get_c(), matr2.get_s());
    matr3.print();
    matr3.matrixmult(matr1.matr, matr1.get_c(), matr1.get_s(), matr2.matr, matr2.get_c(), matr2.get_s());
    matr3.print();
    return 0;
}