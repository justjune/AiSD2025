// L031_099
// Объявление структуры связного списка
// Парфёнов Вячеслав, МЕН-243201 (ПМ-201). 07.10.2025
#include <iostream>
#include <windows.h>
#include "L031_099.hpp"
using namespace std;

void demonstrateLinkedList() {

    // СОЗДАНИЕ ПЕРВОГО УЗЛА
    struct list* node1 = new struct list; // Выделение памяти под первый узел
    node1->item = 100;
    node1->next = nullptr;

    // СОЗДАНИЕ ВТОРОГО УЗЛА
    struct list* node2 = new struct list; // Выделение памяти под второй узел
    node2->item = 200;
    node2->next = nullptr;

    // Связывание узлов
    node1->next = node2; // Первый узел указывает на второй

    cout << "Linked list demonstration:" << endl;
    cout << "Node 1: " << node1->item << endl; // Данные первого узла
    cout << "Node 2: " << node1->next->item << endl; // Данные второго узла через первый

    // Освобождение памяти
    delete node1;
    delete node2;
}