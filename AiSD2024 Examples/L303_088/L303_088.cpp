//L303_088
//Вставка элемента в однонаправленный связный список
//ПМ-2024 Шарапов Даниил, 25.09.24
#include <iostream>
#include "L303_088.hpp"
using namespace std;
struct List {
    int value;
    List* next;
};

void insert_list(List** l, int x) {//основная функция, которая вставляет элемент в однонаправленный связный список
    List* p = new List;
    p->value = x;
    p->next = *l;      
    *l = p;            
}

void print_list(List* l) {//дополнительная функция, которая выводит элементы списка
    while (l != NULL) {
        cout << l->value << " ";
        l = l->next;
    }
    cout << endl;
}