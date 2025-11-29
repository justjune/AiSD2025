// L0723_272
// Тесты для листинга 7.23
// Гаврилюк Екатерина, МЕН-243201 (ПМ-201)
#include "L0723_272.hpp"
#include <cassert>
#include <iostream>

void test_simple_dag() {
    Graph g(4);

    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 4);

    g.topsort();
}

int main() {
    test_simple_dag();

    return 0;
}
