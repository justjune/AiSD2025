template<typename T>
struct TreeNode {
    T item;                    // Элемент данных
    TreeNode<T>* parent;       // Указатель на родительский узел
    TreeNode<T>* left;         // Указатель на левый дочерний узел
    TreeNode<T>* right;        // Указатель на правый дочерний узел

    // Конструктор
    TreeNode(const T& value, TreeNode<T>* p = nullptr)
        : item(value), parent(p), left(nullptr), right(nullptr) {
    }
};