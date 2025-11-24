//L0905_330
//Процедура генерирования перестановок
//ПМ-2025 Суханова Анастасия
#include <iostream>
#include "L0905_330.hpp"
const int NMAX = 100;
void construct_candidates(int a[], int k, int n, int c[], int* nc) {
    int i;
    bool in_perm[NMAX];
    
    for (i = 1; i < NMAX; i++) {
        in_perm[i] = false;
    }
    for (i = 1; i < k; i++) {
        in_perm[a[i]] = true;
    }
    *nc = 0;
    for (i = 1; i <= n; i++) { 
        if (!in_perm[i]) {
            c[*nc] = i;
            (*nc)++;
        }
    }
}