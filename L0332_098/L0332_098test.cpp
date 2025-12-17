//Тест для листинга 3.2
#include <iostream>
#include "L0332_098.HPP"
#include "L0332_098.CPP"

int main() {
    system("chcp 65001 > nul");
    
    List<int>* head = new List<int>(1); // Вставляем 1
    head->next = new List<int>(2); // Вставляем 2
    head->next->next = new List<int>(3); // Вставляем 3

    int search_value = 2;  //Значение для поиска

    List<int>* result = search_list(head, search_value);

    if (result != nullptr) {
        std::cout << "Элемент найден, значение " << result->item << std::endl;
    } else {
        std::cout << "Элемент не найден" << std::endl;
    }
    
    //Важно убрать утечки памяти:
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
