// L724_273
// Тесты для листинга 7.24
// Гаврилюк Екатерина, МЕН-243201 (ПМ-201)
#include "L724_273.hpp"
using namespace std;

int main() {
    Graph g(4, true);
    g.insert_edge(1, 2, true);
    g.insert_edge(1, 3, true);
    g.insert_edge(3, 4, true);

    cout << "Исходный граф:\n";
    g.print();

    Graph gt = g.transpose();
    cout << "\nТранспонированный граф:\n";
    gt.print();

    return 0;
}