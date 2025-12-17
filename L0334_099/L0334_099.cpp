//L0334_099
//Поиск элемента, предшествующего удаляемому
//Быков Илья МХ-2 21.10.25
#ifndef L0334_099_CPP
#define L0334_099_CPP
#include <iostream>
#include "L0332_098.HPP"

// Функция поиска l - предшествующего элемента x
template <typename T>
List<T>* item_ahead(List<T>* l, List<T>* x) {
    if (l == nullptr || l->next == nullptr) return nullptr; // Если список пуст или l - последний элемент, возвращаем null

    if (l->next == x) return l;  // Проверяем, является ли следующий элемент за l элементом x, если да, возвращаем l

    return item_ahead(l->next, x); // Рекурсивно ищем в остальной части списка.
}

#endif
