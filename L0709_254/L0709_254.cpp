// Михайлова Юлия, МХ-201, Обход графа в ширину, L0709_254

#include "L0709_254.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#define MAXV 100				// Максимальное количество вершин


void process_vertex_late(int v)
{
    cout << v;
}

void bfs(Graph *g, int start) {
//////////////         Предыдущий Листинг 7.8
vector<bool> processed(MAXV+1);				// Обработанные вершины 
vector<bool> discovered(MAXV+1);			// Открытые вершины 
vector<int>  parent(MAXV+1);				// Отношения открытия

//int time = 0;

for (int i = 0; i <= g->nvertices; ++i) {
    processed[i] = false;    
    discovered[i] = false;   
    parent[i] = -1;          
    }
///////////////

    queue<int> q;			// Очередь для хранения вершин
    q.push(start);			// Добавляем начальную вершину в очередь
    discovered[start] = true;

    while (!q.empty()) {
        int v = q.front();		// Получаем текущую вершину
        q.pop();			// Удаляем её из очереди
        //process_vertex_early(v);	   Функция пред-обработки вершины
        processed[v] = true;

        for (EdgeNode* p = g->edges[v]; p != nullptr; p = p->next) {
            int y = p->y;		// Получаем соседнюю вершину
            if ((!processed[y]) || g->directed) {
                //process_edge(v, y);	   Функция обработки ребра

                if (!discovered[y]) {
                    q.push(y);          // Добавляем вершину в очередь
                    discovered[y] = true;
                    parent[y] = v;      // Устанавливаем родителя
                }
            }
        }
      process_vertex_late(v);	   // Функция пост-обработки вершины
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void initialize_graph(Graph &g, bool directed)		// Листинг 7.2 (Инициализация графа)
{
    g.nvertices = 0;
    g.nedges = 0;
    g.directed = directed;
    g.degree.resize(MAXV, 0);
    g.edges.resize(MAXV);
}

void read_graph(Graph &g, bool directed,  ifstream &cin) {      // Листинг 7.3 (Чтение графа из файла)
    int m;						
    int x, y;							
	initialize_graph(g, directed);
     cin >> g.nvertices;					
  cin >> m;							

    for (int i = 0; i < m; i++) {
        cin >> x;
        cin >> y;					
	insert_edge(&g, x, y, directed);		
    }
}


void insert_edge(Graph* g, int x, int y, bool directed) {	//Листинг 7.4 (Вставка ребра)
    EdgeNode* newEdge = new EdgeNode();  
    newEdge->y = y;
    newEdge->weight = 0;
    newEdge->next = g->edges[x];

    g->edges[x] = newEdge;
    g->degree[x]++;

    if (!directed) {
        insert_edge(g, y, x, true);
    } else {
        g->nedges++;
    }
}
