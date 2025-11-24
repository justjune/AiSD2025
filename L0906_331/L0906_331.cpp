//L0906_331
//Процедуры генерирования перестановок
//ПМ-2025 Суханова Анастасия
#include <iostream>
#include "L0906_331.hpp"

const int NMAX = 100;
void backtrack(int a[], int k, int n);

void process_solution(int a[], int k, int input) {
    for (int i = 1; i <= k; i++) {
        std::cout << " " << a[i];
    }
    std::cout << std::endl;
}

int is_a_solution(int a[], int k, int n) {
    return (k == n);
}

void generate_permutations(int n) {
    int a[NMAX];
    backtrack(a, 0, n);
}