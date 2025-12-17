#ifndef L0332_098_HPP
#define L0332_098_HPP
#include <iostream>

// Определение структуры List
template <typename T>
struct List {
    T item; // Определение типа узла
    List<T>* next; // Создание указателя на следующий узел
    List(T val) : item(val), next(nullptr) {} //Конструктор создания нового узла
}

#endif
