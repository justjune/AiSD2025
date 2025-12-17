//L0333_099
//вставка элемента в связный список
//Быков Илья МХ-2 21.10.25
#ifndef L0333_099_CPP
#define L0333_099_CPP
#include <iostream>
#include "L0332_098.HPP"

// Определение структуры узла списка
struct List {
    int item; // Данные, хранящиеся в узле
    List* next; // Указатель на следующий узел

    List(int val) : item(val), next(nullptr) {} //Конструктор узла
};

// Функция вставки элемента в начало списка
void insert_list(List*& head, int x) {
    // Создаём новый узел
    List* newNode = new List(x);

    // Указываем новому узлу на текущую голову списка
    newNode->next = head;

    // Обновляем голову списка, указывая на новый узел
    head = newNode;
}

int main() {
    List* head = nullptr; // Изначально список пуст

    insert_list(head, 3); // Вставляем 3
    insert_list(head, 2); // Вставляем 2
    insert_list(head, 1); // Вставляем 1

    // Вывод списка
    List* current = head;
    while (current != nullptr) {
        std::cout << current->item << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Освобождаем память из-под списка
    current = head;
    while (current != nullptr) {
        List* temp = current;
        current = current->next;
        delete temp;
    }
    #endif

    return 0;
}
