#include <iostream>
using namespace std;

// Предполагаемая структура списка
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

// Функция для поиска предыдущего элемента 
ListNode* item_ahead(ListNode* head, ListNode* target) {
    if (head == nullptr || head == target) return nullptr;

    ListNode* current = head;
    while (current != nullptr && current->next != target) {
        current = current->next;
    }
    return current;
}

// Функция удаления элемента из списка
void delete_node(ListNode** head, ListNode* target) {
    if (head == nullptr || *head == nullptr || target == nullptr) {
        return; // Проверка на нулевые указатели
    }

    // Если удаляемый элемент - голова списка
    if (*head == target) {
        *head = target->next;
        delete target;
        return;
    }

    // Поиск предыдущего элемента
    ListNode* prev = item_ahead(*head, target);

    // Если элемент найден в списке
    if (prev != nullptr) {
        prev->next = target->next;
        delete target;
    }
    // Если элемент не найден, ничего не делаем
}

// Вспомогательная функция для печати списка
void print_list(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Пример использования
int main() {
    setlocale(LC_ALL, "Rus");
    // Создание списка: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Исходный список: ";
    print_list(head);

    // Удаление элемента со значением 3
    ListNode* to_delete = head->next->next;
    delete_node(&head, to_delete);

    cout << "После удаления 3: ";
    print_list(head);

    // Удаление головы
    delete_node(&head, head);

    cout << "После удаления головы: ";
    print_list(head);

    return 0;
}