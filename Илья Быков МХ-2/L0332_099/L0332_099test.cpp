//Тест для листинга 3.2
#include <iostream>

template <typename T>
struct List {
    T item;
    List<T>* next;
    List(T val) : item(val), next(nullptr) {}
};

template <typename T>
List<T>* search_list(List<T>* l, T x) {
    if (l == nullptr) return nullptr; // Если список пуст, элемента нет.
    if (l->item == x) return l;       // Если текущий элемент искомый, возвращаем его.
    return search_list(l->next, x); // Ищем в остальной части списка.
}

int main() {
    system("chcp 65001 > nul");
    List<int>* head = new List<int>(1);
    head->next = new List<int>(2);
    head->next->next = new List<int>(3);

    int search_value = 2;  //Значение для поиска.

    List<int>* result = search_list(head, search_value);

    if (result != nullptr) {
        std::cout << "Элемент найден, значение " << result->item << std::endl;
    } else {
        std::cout << "Элемент не найден" << std::endl;
    }

    delete head->next->next; //Важно убрать утечки памяти
    delete head->next;
    delete head;

    return 0;
}
