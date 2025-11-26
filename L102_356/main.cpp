//Число фибоначи с кэширования
#include <vector>
#include <iostream>


const size_t MAXN = 91;        // Наибольшее n, для которого значение F(n) помещается в тип данных long
const long long UNKNOWN = -1;    // Пустая ячейка

std::vector<long long> f(MAXN + 1, UNKNOWN);  // Массив для хранения значений fib
// массив размера 91+1 заполнен -1

long long fib_c(size_t n) {
    if (f[n] == UNKNOWN) {
        f[n] = fib_c(n - 1) + fib_c(n - 2);
    }
    return f[n];
}

long long fib_c_driver(size_t n) {
    if (n < 0 || n > MAXN) {
        std::cerr << "n must be between [0, " << MAXN << "]" << std::endl;
        return -1;
    }

    f[0] = 0;
    f[1] = 1;

    // Остальные ячейки уже инициализированы как UNKNOWN в объявлении вектора
    return fib_c(n);
}

int main
{
    return 0
}
