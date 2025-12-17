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
    List<T>* newNode = new List<T>(x); // Создаем новый узел списка с данными x
    newNode->next = head; // Указываем новому узлу на текущую голову списка
    head = newNode; // Обновляем голову списка, указывая на новый узел
}

 #endif
