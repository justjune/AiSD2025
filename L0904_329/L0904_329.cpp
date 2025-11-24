//L0904_329
//Процедура генерирования подмножеств
//ПМ-2025 Суханова Анастасия
#include "L0904_329.hpp"
#include <iostream>

const int NMAX = 100;
void backtrack(int a[], int k, int n);

void generate_subsets(int n)
{
    int a[NMAX];
    backtrack(a, 0, n);
}