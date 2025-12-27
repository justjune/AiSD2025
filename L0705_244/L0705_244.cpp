#include "L0705_244.hpp"
#include <iostream>

//Функция для вывода графа 
void print_graph(graph *g) {
    for (int i = 1; i <= g->nvertices; i++) {
        std::cout << i << ": "; // выводим номер вершины
        edgenode *p = g->edges[i]; // берем все ребра для i-ой вершины
        // проходим по всем ребрам i-ой вершины
        while (p != nullptr) {
            std::cout << ' ' << p->y; // выводим точку соединенную с i-ой вершиной
            p = p->next;              // идем в следующее ребро
        }
        std::cout << std::endl;
    }
}


//Функция для добавления ребра
void insert_edge(graph *g, int x, int y, int w, bool directed) {
    if (x < 1 || x > g->nvertices || y < 1 || y > g->nvertices) {
        std::cout << "Ошибка: Вершины вне диапазона." << std::endl; // если вершины вне диапазона ввыводим логи
        return;
    }

    edgenode *p = new edgenode;  // Выделяем память для нового ребра
    p->weight = w;               // Устанавливаем вес
    p->y = y;               // Устанавливаем вторую точку ребра
    p->next = g->edges[x];       // добавляем остальные ребра в p      
    g->edges[x] = p;             // добавляем новое ребро в граф
    g->degree[x]++;              // увеличиваем степень вершины

    // если граф ненаправленный то записывем данные для второй точки
    if (!directed) { 
        insert_edge(g, y, x, w, true);
    } else {
        g->nedges++;
    }
}