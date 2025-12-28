//L302_087
//Рекурсивный поиск элемента в связном списке 01.10.24
//ПМ-2024 Шарапов Даниил
#include <iostream>
#include "L302_087.hpp"
using namespace std;
struct List{
    int value;
    List* next;
    
    
};

List* search_list(List* l, int x){//основная функция, которая выполняет рекурсивный поиск элемента в связаном списке
    if (l == NULL) return NULL;
    if (l->value == x) return l;
    return search_list(l->next, x);
}

List* append(List* head, int value){//вспомогательная функция для тестов, которая добавляет элементы в список
    List* newList = new List{value, NULL};
    if (head == NULL) return newList;
    List* current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = newList;
    return head;
}