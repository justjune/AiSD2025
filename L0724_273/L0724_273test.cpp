// L0724_273
// Тесты для листинга 7.24
// Гаврилюк Екатерина, МЕН-243201 (ПМ-201)
#include "L0724_273.hpp"
#include <iostream>

void test_transpose() {
    Graph g(3);

    g.insert_edge(1, 2);
    g.insert_edge(2, 3);
    g.insert_edge(1, 3);

    Graph* gt = g.transpose();

    delete gt;
}

int main() {
    test_transpose();

    return 0;
}
