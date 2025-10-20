#include <iostream>
#include <cassert>

// Включаем функцию item_ahead и структуру List из предыдущего ответа. Например:
// #include "list_functions.h" // Если код находится в отдельном файле

struct List {
    int data;
    List* next;
    List(int val) : data(val), next(nullptr) {}
};

List* item_ahead(List* l, List* x);

int main() {
    system("chcp 65001 > nul");
    // Тест 1: Пустой список.
    List* empty_list = nullptr;
    List* node1 = new List(1);
    assert(item_ahead(empty_list, node1) == nullptr);
    delete node1;

    // Тест 2: Один элемент в списке.
    node1 = new List(1);
    List* node2 = new List(2);
    assert(item_ahead(node1, node2) == nullptr);
    delete node1;
    delete node2;

    // Тест 3: x находится сразу после l.
    node1 = new List(1);
    node2 = new List(2);
    node1->next = node2;
    assert(item_ahead(node1, node2) == node1);
    delete node1;

    return 0;
}
