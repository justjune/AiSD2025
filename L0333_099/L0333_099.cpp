//L0333_099
//Вставка элемента в связный список
//Быков Илья МХ-2 21.10.25
#ifndef L0333_099_CPP
#define L0333_099_CPP
#include <iostream>
#include "L0332_098.HPP"

// Функция вставки элемента в начало списка
void insert_list(List*& head, int x) {
    // Создаём новый узел
    List* newNode = new List(x);

    // Указываем новому узлу на текущую голову списка
    newNode->next = head;

    // Обновляем голову списка, указывая на новый узел
    head = newNode;
}
 #endif
