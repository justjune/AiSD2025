#include "L0808_293.hpp"
//Барановой Дарьи пм-201
// Конструктор: инициализация системы непересекающихся множеств
UnionFind::UnionFind(int n) : n(n) {
    parent.resize(n + 1);
    size.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

// Найти корень элемента x с сжатием пути
int UnionFind::find(int x) {
    if (parent[x] == x) {
        return x;
    }
    // Сжатие пути для оптимизации
    parent[x] = find(parent[x]);
    return parent[x];
}

// Объединить два множества
void UnionFind::unionSets(int s1, int s2) {
    int r1 = find(s1);  // Корень первого множества
    int r2 = find(s2);  // Корень второго множества

    if (r1 == r2) {
        return;  // Уже находятся в одном множестве
    }

    // Объединение по размеру (ранговая эвристика)
    if (size[r1] >= size[r2]) {
        size[r1] += size[r2];
        parent[r2] = r1;
    } else {
        size[r2] += size[r1];
        parent[r1] = r2;
    }
}

// Проверить, находятся ли элементы в одном множестве
bool UnionFind::sameComponent(int s1, int s2) {
    return find(s1) == find(s2);
}

// Получить размер множества, содержащего элемент x
int UnionFind::getSize(int x) {
    return size[find(x)];
}

// Получить общее количество элементов
int UnionFind::getN() const {
    return n;
}

