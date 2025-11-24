//L0903_329
//Базовые процедуры перебора с возвратом
//ПМ-2025 Суханова Анастасия
#include <iostream>
#include "L0903_329.hpp"
int is_a_solution(int a[], int k, int n) {
    return (k == n);
}

void construct_candidates(int a[], int k, int n, int c[], int* nc) {
    c[0] = true;
    c[1] = false;
    *nc = 2;
}

void process_solution(int a[], int k, int input) {
    std::cout << "{";
    for (int i = 1; i <= k; i++) {
        if (a[i] == true) {
            std::cout << " " << i;
        }
    }
    std::cout << " }" << std::endl;
}