// L025_077
// Быстрое возведение в степень
// Парфёнов Вячеслав, МЕН-243201 (ПМ-201). 30.09.2025
#include <iostream>
#include "L025_077.hpp"
using namespace std;

long long power(int a, int n) {
    // Любое число в степени 0 равно 1
    if (n == 0) {
        return 1;
    }

    // Рекурсивно вычисляется a в степени n/2
    long long x = power(a, n / 2);

    // Если степень четная
    if (n % 2 == 0) {
        return x * x;  // (a^(n/2))^2
    }
    // Если степень нечетная
    else {
        return a * x * x;  // a * (a^(n/2))^2
    }
}