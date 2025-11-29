#ifndef L0808_293_HPP
#define L0808_293_HPP

#include <vector>

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> size;
    int n;

public:
    // Конструктор: инициализация системы непересекающихся множеств
    UnionFind(int n);

    // Найти корень элемента x
    int find(int x);

    // Объединить два множества
    void unionSets(int s1, int s2);

    // Проверить, находятся ли элементы в одном множестве
    bool sameComponent(int s1, int s2);

    // Получить размер множества, содержащего элемент x
    int getSize(int x);

    // Получить общее количество элементов
    int getN() const;
};

#endif // L0808_293_HPP