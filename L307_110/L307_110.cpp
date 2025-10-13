//L307_110
//Алгоритм рекурсивного поиска произвольного элемента в двоичном дереве
//ПМ-2025 Овсянникова Анастасия
using item_type = int; // или любой другой тип

struct tree {
    item_type item;
    tree *left;
    tree *right;
};

tree* search_tree(tree* l, item_type x) {
    // Если дерево пустое или дошли до листа
    if (l == nullptr) {
        return nullptr;
    }
    // Если значение найдено в текущем узле
    if (l->item == x) {
        return l;
    }
    // Рекурсивный поиск в левом или правом поддереве
    if (x < l->item) {
        return search_tree(l->left, x);
    } else {
        return search_tree(l->right, x);
    }
}