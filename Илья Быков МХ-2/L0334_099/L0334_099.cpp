//L0334_099
//поиск элемента, предшествующего удаляемому
//Быков Илья МХ-2 21.10.25
#include <iostream>

struct List {
    int data;
    List* next;

    List(int val) : data(val), next(nullptr) {}
};

List* item_ahead(List* l, List* x) {
    // Если список пуст или l - последний элемент, возвращаем null.
    if (l == nullptr || l->next == nullptr) return nullptr;

    // Проверяем, является ли следующий элемент за l элементом x.
    if (l->next == x) return l; // Если да, возвращаем l.

    // Рекурсивно ищем в остальной части списка.
    return item_ahead(l->next, x);
}

int main() {
    List* node1 = new List(1);
    List* node2 = new List(2);
    List* node3 = new List(3);

    node1->next = node2; // Создаем связь node1 -> node2
    node2->next = node3; // Создаем связь node2 -> node3

    List* result = item_ahead(node1, node2); // Ищем, идет ли node2 за node1
    if (result != nullptr) {
        std::cout << "Success!" << std::endl;
    } else {
        std::cout << "Failure!" << std::endl;
    }

    //Освободим память
    delete node1;
    delete node2;
    delete node3;
    return 0;
}
