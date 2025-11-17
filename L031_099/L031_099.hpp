#ifndef L031_099_H
#define L031_099_H
typedef int item_type;
struct list {
    item_type item;
    struct list* next;
};
void demonstrateLinkedList();
#endif