//L0908_332
//Процедура перечисления всех путей в графе
//Иванова Мария ПМ-201
#include <iostream>
#include "L0908_332.hpp"

void construct_candidates(int a[], int k, const ath_data* data, int c[], int* nc) {
    bool in_sol[NMAX + 1];  
    int last;               // Последняя вершина в текущем пути

    for (int i = 0; i <= NMAX; i++) {
        in_sol[i] = false;
    }

    // Отмечаем вершины, которые уже находятся в текущем решении
    for (int i = 0; i < k; i++) {
        if (a[i] <= NMAX) {
            in_sol[a[i]] = true;
        }
    }

    if (k == 0) {
        // Всегда начинаем с вершины s
        c[0] = data->s;
        *nc = 1;
    } else {
        *nc = 0;
        last = a[k - 1];  // Последняя вершина в текущем пути

        // Проверяем корректность индекса последней вершины
        if (last < data->g.adjacency_list.size()) {
            // Проходим по всем смежным вершинам
            for (int neighbor : data->g.adjacency_list[last]) {
                // Если вершина еще не в решении, добавляем ее в кандидаты
                if (neighbor <= NMAX && !in_sol[neighbor]) {
                    c[*nc] = neighbor;
                    (*nc)++;
                }
            }
        }
    }
}