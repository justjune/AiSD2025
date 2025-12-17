//L0333_099
//Вставка элемента в связный список
//Быков Илья МХ-2 21.10.25
#ifndef L0333_099_CPP
#define L0333_099_CPP
#include <iostream>
#include "L0332_098.HPP"

// Функция вставки элемента в начало списка
template <typename T>
List<T>* insert_list(List<T>*& head, T x) {
    // Создаем новый узел списка с данными x
    List<T>* newNode = new List<T>(x);

    // Указываем новому узлу на текущую голову списка
    newNode->next = head;

    // Обновляем голову списка, указывая на новый узел
    head = newNode;
}

 #endif
