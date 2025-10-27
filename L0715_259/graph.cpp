#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <unordered_map>
#include <queue>
#include "graph.hpp"
using namespace std;



    void Graph::init_graph(Graph *g, bool dir) {
    cout << "init_graph: начало" << endl;
    g->nvertices = 0;
    g->nedges = 0;
    g->dir = dir;

    // Инициализируем векторы ПЕРЕД использованием
    g->edges.resize(g->max_vertices);
    g->degree.resize(g->max_vertices);
    g->color.resize(g->max_vertices);
    g->visited.resize(g->max_vertices);
    g->processed.resize(g->max_vertices);

    // Теперь можно безопасно обращаться по индексам
    for (int i = 0; i < g->max_vertices; i++) {
        g->edges[i] = nullptr;
        g->degree[i] = 0;
        g->color[i] = 2;
        g->visited[i] = false;
        g->processed[i] = false;
    }
    cout << "init_graph: завершено (размер векторов: " << g->max_vertices << ")" << endl;
}

    void Graph::ins_edge(Graph *g, int x, int y, bool dir) {
        Edge *p;
        p = new Edge;
        p->y = y;
        p->next = g->edges[x];
        g->edges[x] = p;
        g->degree[x]++;

        if (!dir){
            ins_edge(g, y, x, 1);
        }
        else{
        g->nedges++;
        }
    }
    void Graph::read_graph(Graph *g, bool dir){  //функция считывания и создания граффа
        int m, x, y;
        
        cout << "Введите кол-во узлов в графе: ";
        cin >> g->nvertices;
        cout << "Введите кол-во ребер графа: ";
        cin >> m;
        cout << "Функция ввода графа, пишите узлы парами: x y (x->y)"<< endl;
        cout << "Для завершения введите отрицательное значение узла"<< endl;
        
        init_graph(g, dir);
        for (int i = 0 ; i < m; i++){
            cin >> x >> y;
            ins_edge(g ,x, y, dir);
            
            if (x < 1 || x > g->nvertices || y < 1 || y > g->nvertices) {
            cout << "Ошибка: вершины должны быть от 1 до " << g->nvertices << endl;
            i--; // повторяем эту итерацию
            continue;
            }         //проверка на дурака
        }
    }

    void Graph::print_graph(Graph *g){
        Edge *p;
        for (int i = 0; i < g->nvertices; i++){
            cout << i <<" ";
            p = g->edges[i];
            while (p != nullptr){
                cout << "-> "<< p->y; 
                p = p->next;
            }
        cout << endl;
        }
    }

    

    void Graph::pred_bfs(Graph *g){        
        g->visited.assign(g->nvertices, false);
        g->processed.assign(g->nvertices, false);
    }
    void Graph::bfs(Graph *g, int start){  //Обход в ширину

        queue<int> q;
        int v;
        int y;
        Edge *p;

        g->visited[start] = 1;
        q.push(start);

        while (!q.empty()) {
            v = q.front();
            q.pop();
            process_vertex_early(); //пояснение ниже
            g->processed[v] = 1;
            p = g->edges[v];
            while (p != NULL){
                y = p->y;
                if ((!g->processed[y])||(g->dir)){
                    process_edge(g, v, y); //пояснение ниже
                }
                if (!g->visited[y]){
                    q.push(y);
                    g->visited[y] = true;
                }
            p = p->next;
            }

        }
    }
    
    //process_vetrex_early и process_edge - функции обработки узла и ребра соотвественно
    //process_vetrex_early - early потому что обрабатываем при извлечении вершины из очерди
    //можем ввести process_vetrex_late после обработки всех соседей
    //эти функции мы редактируем под свои задачи, оставляем пустыми или удаляем

    void Graph::process_vertex_early(){}

    int Graph::rev(int x){  //функция обратного значения для int 
        return 1-x;
    }
    
    //в алгоритме расскраски двумя цветами нам нужно только process_edge
    //определим его 

    

    void Graph::process_edge(Graph *g, int x, int y) {
        if (g->color[x] == g->color[y]){
        cout << "Граф не является двудольным, раскраска в два цвета невозможна :"<<endl;
        return;            
        }
        g->color[y] = rev(g->color[x]);     
    }

    void Graph::two_color(Graph *g){
        for (int i = 0; i < g->nvertices; i++) g->color[i] = 2;
        pred_bfs(g);
        for (int i = 0; i < g->nvertices; i++){
            if (!g->visited[i]){
                g->color[i] = 0;
                bfs(g, i);
            }
        }
   
    }

    void Graph::print_color_graph(Graph *g){
        Edge *p;
        for (int i = 0; i < g->nvertices; i++){
            cout << "Узел "<< i <<"(Цвет: "<< g->color[i] << " ) соеденен с:";
            p = g->edges[i];
            while (p != nullptr){
                cout << " "<< p->y << "(Цвет: "<< g->color[p->y]<< ") "; 
                p = p->next;
            }
        cout << endl;
        }
}



