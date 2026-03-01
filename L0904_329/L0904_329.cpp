//L0904_329
//Процедура генерирования подмножеств
//ПМ-2025 Суханова Анастасия
#include "L0904_329.hpp"
#include <iostream>
#include "../L902_327/L902_327.hpp"

const int NMAX = 100;

void generate_subsets(int n)
{
    int a[NMAX];
    backtrack(a, 0, n);
}
