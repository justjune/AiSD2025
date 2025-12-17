//Тест для листинга 3.3
#include <iostream>
#include "L0332_098.HPP"
#include "L0333_099.CPP"

int main() {
    system("chcp 65001 > nul");
    
    List* head = nullptr; // Начинаем с пустого списка

    insert_list(head, 3); // Вставляем 3
    insert_list(head, 2); // Вставляем 1
    insert_list(head, 1); // Вставляем 1

    // Очищаем память:
    List* current = head;
    while(current){
        List *temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
