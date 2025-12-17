//L0334_099
//поиск элемента, предшествующего удаляемому
//Быков Илья МХ-2 21.10.25
#ifndef L0334_099_CPP
#define L0334_099_CPP
#include <iostream>
#include "L0332_098.HPP"

template <typename T>
List<T>* item_ahead(List<T>* l, List<T>* x) {
    // Если список пуст или l - последний элемент, возвращаем null.
    if (l == nullptr || l->next == nullptr) return nullptr;

    // Проверяем, является ли следующий элемент за l элементом x.
    if (l->next == x) return l;  // Если да, возвращаем l..

    // Рекурсивно ищем в остальной части списка.
    return item_ahead(l->next, x);
}


#endif
