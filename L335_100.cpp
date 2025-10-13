void deleteNode(ListNode*& head, ListNode* nodeToDelete) {
    if (!head || !nodeToDelete) return;

    // Проверяем принадлежность узла списку
    if (!isNodeInList(head, nodeToDelete)) return;

    if (head == nodeToDelete) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        ListNode* prev = findPrevious(head, nodeToDelete);
        if (prev && prev->next == nodeToDelete) {
            prev->next = nodeToDelete->next;
            delete nodeToDelete;
        }
    }
}