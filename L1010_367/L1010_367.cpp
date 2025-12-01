#include <iostream>
#include "L1010_367.hpp"

// Определение таблицы
cell m[MAXLEN + 1][MAXLEN + 1];

// Инициализация строки (верхней границы таблицы)
void row_init(int i) {
    m[0][i].cost = i;
    if (i > 0)
        m[0][i].parent = INSERT;
    else
        m[0][i].parent = -1;
}

// Инициализация столбца (левой границы таблицы)
void column_init(int i) {
    m[i][0].cost = i;
    if (i > 0)
        m[i][0].parent = DELETE;
    else
        m[i][0].parent = -1;
}