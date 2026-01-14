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

//Функция для задания графа
void initialize_graph(graph *g, bool directed) { // задаем пустой граф
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    for (int i = 1; i <= MAXV; i++) {
        g->degree[i] = 0;
        g->edges[i] = nullptr;
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

// Функция для чтения графа
void read_graph(graph *g, bool directed) {
    int m;  // Количество ребер
    int x, y;  // Вершины между ребром
    int w; // Вес ребра
    initialize_graph(g, directed); // Задаем граф
    std::cin >> g->nvertices >> m;  // Получаем количество вершин и ребер

    // Добавляем ребра
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y >> w; // принимаем первую и вторую точки и вес ребра
        insert_edge(g, x, y, w, directed); // добаляем ребро
    }
}

// Функуция для вывода наилучшего пути
void find_path(int start, int end, int parents[])
{
  if ((start == end) || (end == -1))
    std::cout << "\n"<< start;
  else {
    find_path(start,parents[end],parents);
    std::cout << " "<< end;
  }
}

// Функция для удаления ребра
void delete_edge(graph *g, int x, int y, bool directed) {
    edgenode *p = g->edges[x]; // получаем все ребра для данной точки x
    edgenode *p_back = nullptr; // вспомогательный указатель

    // Проходим циклом все элементы графа
    while (p != nullptr) {
        // Нашли ребро
        if (p->y == y) {
            g->degree[x]--; // уменьшаем степень вершины
            // если элемент не первый
            if (p_back != nullptr) {
                p_back->next = p->next; // переписываем элементы пропуская тот который нужно удалить
            } else {
                g->edges[x] = p->next; // пропускаем первый элемент
            }
            delete p;  // Освобождаем память

            // если граф не направленный то так же удаляем значение для второй точки
            if (!directed) {
                delete_edge(g, y, x, true);
            } else {
                g->nedges--; // уменьшаем количество ребер
            }
            return;
        } else {
            p_back = p; // двигаемся дальше для поиска ребра
            p = p->next;
        }
    }
    std::cout << "Не найдено ребро между точками (" << x << ',' << y << ')' << std::endl; // Если функция не попала в return в while, то тогда даннйо вершины нет в графе 
}
