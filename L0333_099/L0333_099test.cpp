#include <iostream>
#include "L0332_098.HPP"
#include "L0333_099.CPP"

int main() {
    system("chcp 65001 > nul");
    List* head = nullptr; // start from empty list

    insert_list(head, 3); // Insert 3
    insert_list(head, 2); // Insert 2
    insert_list(head, 1); // Insert 1

    // Clean resources
    List* current = head;
    while(current){
        List *temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
