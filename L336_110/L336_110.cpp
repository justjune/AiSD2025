template<typename T>
struct Tree {
    T item;                    // Элемент данных
    Tree<T>* parent;           // Указатель на родительский узел
    Tree<T>* left;             // Указатель на левый дочерний узел
    Tree<T>* right;            // Указатель на правый дочерний узел

    // Конструктор для удобства инициализации
    Tree(const T& value = T(), Tree<T>* p = nullptr, Tree<T>* l = nullptr, Tree<T>* r = nullptr)
        : item(value), parent(p), left(l), right(r) {
    }
};