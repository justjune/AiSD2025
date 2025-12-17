//Тесты для листинга 3.4
#include <iostream>
#include <cassert>
#include "L0332_098.HPP"
#include "L0334_099.CPP"

int main() {
    system("chcp 65001 > nul");
    
    // Тест 1: Пустой список
    List* empty_list = nullptr;
    List* node1 = new List(1);
    assert(item_ahead(empty_list, node1) == nullptr);
    
    //Важно убрать утечку памяти:
    delete node1;

    // Тест 2: Один элемент в списке
    node1 = new List(1);
    List* node2 = new List(2);
    assert(item_ahead(node1, node2) == nullptr);
    
    //Важно убрать утечки памяти:
    delete node1;
    delete node2;

    // Тест 3: x находится сразу после l
    node1 = new List(1);
    node2 = new List(2);
    node1->next = node2;
    assert(item_ahead(node1, node2) == node1);
    
    //Важно убрать утечку памяти:
    delete node1;

    return 0;
}
