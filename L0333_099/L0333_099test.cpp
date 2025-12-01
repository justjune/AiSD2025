#include <iostream>

struct List {
    int item;
    List* next;
    List(int val) : item(val), next(nullptr) {}
};

void insert_list(List*& head, int x) {
    List* newNode = new List(x);
    newNode->next = head;
    head = newNode;
}

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
