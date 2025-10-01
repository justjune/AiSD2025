//L023_069
//Поиск строки в тексте
//Парфёнов Вячеслав, МЕН-243201 (ПМ-201) 30.09.2025
#include <iostream>
#include <cstring>
#include "L023_069.hpp"
using namespace std;

int findmatch(char* p, char* t) {
    int i, j;
    int plen, tlen;

    plen = strlen(p);
    tlen = strlen(t);

    // Основной цикл по всем возможным позициям начала образца в тексте
    for (i = 0; i <= (tlen - plen); i = i + 1) {
        j = 0;
        // Проверка совпадения символов образца и текста
        while ((j < plen) && (t[i + j] == p[j])) {
            j = j + 1;
        }
        // Если весь образец совпал с частью текста
        if (j == plen) {
            return i;
        }
    }
    return -1;
}