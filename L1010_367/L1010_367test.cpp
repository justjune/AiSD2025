#include <iostream>
#include "L1010_367.hpp"

int main() {
    // Пример инициализации первых нескольких строк и столбцов
    for (int i = 0; i <= 5; i++) {
        row_init(i);
        column_init(i);
    }

    // Вывод части таблицы для проверки
    std::cout << "Таблица m[0..5][0..5]:" << std::endl;
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) {
            std::cout << "(" << m[i][j].cost << "," << m[i][j].parent << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}