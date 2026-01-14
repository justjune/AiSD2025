#include "L0808_293.hpp"
#include <cassert>
#include <iostream>

void test_basic() {
    UnionFind uf(5);

    for (int i = 1; i <= 5; i++) {
        assert(uf.find(i) == i);
        assert(uf.getSize(i) == 1);
    }

    std::cout << "OK\n";
}

void test_union() {
    UnionFind uf(10);

    uf.unionSets(1, 2);
    uf.unionSets(2, 3);
    uf.unionSets(4, 5);

    assert(uf.sameComponent(1, 3));
    assert(!uf.sameComponent(1, 4));
    assert(uf.getSize(1) == 3);

    std::cout << "OK\n";
}

void test_chain() {
    UnionFind uf(6);

    for (int i = 1; i < 6; i++) {
        uf.unionSets(i, i + 1);
    }

    assert(uf.sameComponent(1, 6));
    assert(uf.getSize(1) == 6);

    std::cout << "OK\n";
}

int main() {
    test_basic();
    test_union();
    test_chain();

    std::cout << "Тесты пройдены\n";

    return 0;
}
