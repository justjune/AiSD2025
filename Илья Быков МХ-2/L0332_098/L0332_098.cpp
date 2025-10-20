//L0332_098
//рекурсивный поиск элемента в связном списке
//Быков Илья МХ-2 20.10.25
#include <iostream>

// Предполагаем, что структура List определена следующим образом:
template <typename T>
struct List {
    T item;
    List<T>* next;
    List(T val) : item(val), next(nullptr) {}
};

template <typename T>
List<T>* search_list(List<T>* l, T x) {
    // Если список пуст, возвращаем nullptr
    if (l == nullptr) {
        return nullptr;
    }

    // Если элемент текущего узла равен искомому значению
    if (l->item == x) {
        // Возвращаем указатель на текущий узел
        return l;
    } else {
        // Иначе, рекурсивно вызываем функцию поиска для следующего узла списка
        return search_list(l->next, x);
    }
}
