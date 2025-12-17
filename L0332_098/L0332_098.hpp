#ifndef L0332_098_HPP
#define L0332_098_HPP
#include <iostream>

template <typename T> // Предполагаем, что структура List определена следующим образом:
struct List {
    T item; // Определение типа узла
    List<T>* next; // Создание указателя на следующий узел
    List(T val) : item(val), next(nullptr) {} //Конструктор создания нового узла
}

#endif
