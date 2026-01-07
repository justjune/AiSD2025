// L025_077
// Тесты для листинга 2.5
// Парфёнов Вячеслав, МЕН-243201 (ПМ-201)
#include <iostream>
#include "L025_077.hpp"
using namespace std;

int main() {
    system("chcp 65001 > nul");

    int base, exponent;

    cout << "Введите основание: ";
    cin >> base;

    cout << "Введите показатель степени: ";
    cin >> exponent;

    long long result = power(base, exponent);

    cout << base << " ^ " << exponent << " = " << result << endl;

    return 0;
}