#include <iostream>
#include <queue>
#include "L0714_257.hpp"

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
void insert_edge(graph *g, int x, int y, bool directed) {
    if (x < 1 || x > g->nvertices || y < 1 || y > g->nvertices) {
        std::cout << "Ошибка: Вершины вне диапазона." << std::endl; // если вершины вне диапазона ввыводим логи
        return;
    }

    edgenode *p = new edgenode;  // Выделяем память для нового ребра
    p->y = y;			         // Устанавливаем вторую точку ребра
    p->next = g->edges[x];       // добавляем остальные ребра в p      
    g->edges[x] = p;             // добавляем новое ребро в граф
    g->degree[x]++;              // увеличиваем степень вершины

    // если граф ненаправленный то записывем данные для второй точки
    if (!directed) { 
        insert_edge(g, y, x, true);
    } else {
        g->nedges++;
    }
}


// Функции для обработки вершин и рёбер
void process_vertex_early(int v) {
    std::cout << ' ' << v ;
}

void process_vertex_late(int v) {
}

void process_edge(int v, int y) {
}

// Объявляем массивы для отслеживания состояния вершин
bool processed[MAXV + 1];    // Отмечает, обработана ли вершина
bool discovered[MAXV + 1];   // Отмечает, обнаружена ли вершина
int parent[MAXV + 1];        // Родительская вершина для каждой вершины

// Инициализация поиска
void initialize_search(graph *g) {
    for (int i = 1; i <= g->nvertices; i++) {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }


}

// Обход графа в ширину (BFS)
void bfs(graph *g, int start) {

    std::queue<int> q;          // Очередь для вершин, которые нужно обработать
    int v;                      // Текущая вершина
    int y;                      // Смежная (следующая) вершина
    edgenode *p;                // Временный указатель для обхода рёбер

    q.push(start);              // Добавляем стартовую вершину в очередь
    discovered[start] = true;   // Помечаем стартовую вершину как обнаруженную

    while (!q.empty()) {        // Пока очередь не пуста
        v = q.front();          // Извлекаем вершину из начала очереди
        q.pop();                // Удаляем вершину из очереди

        process_vertex_early(v); // Обрабатываем вершину на этапе "раннего" обхода
        processed[v] = true;     // Помечаем вершину как обработанную

        p = g->edges[v];         // Получаем список смежных вершин для текущей вершины
        while (p != nullptr) {   // Проходим по всем смежным вершинам
            y = p->y;            // Получаем идентификатор смежной вершины
            
            // Обрабатываем ребро, если смежная вершина еще не была обработана
            if (!processed[y] || g->directed) {
                process_edge(v, y);  // Обработка ребра
            }
            
            // Если смежная вершина еще не была обнаружена
            if (!discovered[y]) {
                q.push(y);          // Добавляем её в очередь
                discovered[y] = true; // Помечаем как обнаруженную
                parent[y] = v;       // Устанавливаем текущую вершину как родителя
            }
            
            p = p->next;  // Переходим к следующему ребру
        }
        
        process_vertex_late(v); // Обрабатываем вершину на этапе "позднего" обхода
    }
}

void connected_components(graph* g){
    int c;  /*Номер компонента*/
    int i;  /* Счетик */

    initialize_search(g);

    c = 0;
    for (i = 1; i <= g->nvertices; i++) {
        if (!discovered[i]) {
            c = c + 1;
            std::cout << "Component " << c << ':';
            bfs(g, i);
            std::cout << '\n';
        }
    }
}
