//Фибоначи без рекурсии
#include <vector>
#include <iostream>

const int MAXN = 92;  // Наибольшее n, для которого значение помещается в long long

long long fib_dp(int n) {
    if (n < 0 || n > MAXN) {
        std::cerr << "Ошибка: n должно быть в диапазоне [0, " << MAXN << "]" << std::endl;
        return -1;
    }

    if (n == 0) return 0;
    if (n == 1) return 1;

    long long f[MAXN + 1] {};  // Вектор для хранения значений

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}
