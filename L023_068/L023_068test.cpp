//Тесты для листинга 2.3, Парфёнов Вячеслав, ПМ-201
#include <iostream>
#include <cstring>
#include <windows.h>
#include "L023_068.h"
using namespace std;

int main() {
    system("chcp 65001 > nul");

    char text[1000];
    char pattern[100];

    cout << "Введите текст: ";
    cin.getline(text, 1000);

    cout << "Введите образец для поиска: ";
    cin.getline(pattern, 100);

    int position = findmatch(pattern, text);

    if (position == -1) {
        cout << "Образец не найден в тексте" << endl;
    }
    else {
        cout << "Образец найден на позиции: " << position << endl;
        cout << "Найденная подстрока: ";

        // ПРАВИЛЬНЫЙ вывод найденной подстроки
        for (int i = 0; i < strlen(pattern); i++) {
            cout << text[position + i];
        }
        cout << endl;
    }

    return 0;
}