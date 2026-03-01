//L1001_354
//Рекурсивное вычисление числа Фибоначчи
//ПМ-2025 Суханова Анастасия
#include <iostream>
#include "L1001_354.hpp"
long fib_r(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib_r(n - 1) + fib_r(n - 2);
}