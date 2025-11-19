#include "flow_graph.h"

/*
 КОНСТРУКТОР И ДЕСТРУКТОР
 */
//                                   v-- инициализация количества вершин
FlowGraph::FlowGraph(int vertices) : nvertices(vertices)
{
    // Инициализируем массив указателей на ребра (списки смежности)
    edges.resize(nvertices, nullptr);
    // Пример: edges.resize(5, nullptr) -> edges = [nullptr, nullptr, nullptr, nullptr, nullptr]
    
    // Инициализируем вспомогательные массивы
    parent.resize(nvertices, -1);
    discovered.resize(nvertices, false);
    
    cout << "Сompleted: Создан граф с " << nvertices << " вершинами" << endl;
}

FlowGraph::~FlowGraph()
{
    // Освобождаем память от всех ребер
    for (int i = 0; i < nvertices; i++)
    {
        Edge* current = edges[i];
        while (current != nullptr)
        {
            Edge* temp = current;
            current = current->next;
            delete temp;
        }
    }
    cout << "Сompleted: Память графа освобождена" << endl;
}

/*
 ДОБАВЛЕНИЕ РЕБЕР
 */

void FlowGraph::addEdge(int from, int to, int capacity)
{
    // Проверяем корректность вершин
    if (from < 0 || from >= nvertices || to < 0 || to >= nvertices)
    {
        cerr << "Ошибка: неверные номера вершин " << from << " -> " << to << endl;
        return;
    }
    
    // Создаем прямое ребро
    Edge* forwardEdge = new Edge(to, capacity);
    forwardEdge->next = edges[from];
    edges[from] = forwardEdge;
    
    // Создаем обратное ребро с нулевой пропускной способностью
    Edge* backwardEdge = new Edge(from, 0);
    backwardEdge->next = edges[to];
    edges[to] = backwardEdge;
    
    // Связываем прямые и обратные ребра
    forwardEdge->reverse = backwardEdge;
    backwardEdge->reverse = forwardEdge;
    
    cout << " Добавлено ребро: " << from << " -> " << to << " (capacity: " << capacity << ")" << endl;
}


/*
 ВСПОМОГАТЕЛЬНЫЕ МЕТОДЫ ДЛЯ ПОИСКА
 */

void FlowGraph::initializeSearch()
{
    // Сбрасываем массивы для нового поиска
    fill(parent.begin(), parent.end(), -1);
    fill(discovered.begin(), discovered.end(), false);
    
}

void FlowGraph::bfs(int source)
{
    // Инициализируем очередь для BFS
    queue<int> q;
    
    // Начинаем с исходной вершины
    q.push(source);
    discovered[source] = true;   // <-- Отмечаем исток как посещенный
    parent[source] = -1;         // <-- У истока нет родителя
    
    
    while (!q.empty())
    {
        // Берем следующую вершину из очереди
        int current = q.front();
        q.pop();
        
        // Просматриваем всех соседей текущей вершины
        Edge* edge = edges[current];
        while (edge != nullptr)
        {
            int neighbor = edge->v;
            
            // Если вершина не посещена и остаточная пропускная способность > 0
            if (!discovered[neighbor] && edge->residual > 0)
            {
                discovered[neighbor] = true;// <-- Отмечаем соседа как посещенного
                parent[neighbor] = current; // <-- Запоминаем, откуда пришли
                q.push(neighbor);          // <-- Добавляем соседа в очередь для дальнейшего   обхода
                
            }
            edge = edge->next;
        }
    }
    
}

int FlowGraph::pathVolume(int source, int sink)
{
    // Если сток недостижим из истока, возвращаем 0
    if (!discovered[sink]) return 0;
    
    
    // Идем от стока к истоку по родительским ссылкам
    // и находим минимальную остаточную пропускную способность
    int current = sink;
    int volume = INT_MAX;
    
    // Идем обратно к истоку
    while (current != source)
    {
        int prev = parent[current];
        
        // Находим ребро от prev (родителя) к current (стоку)
        Edge* edge = edges[prev];
        while (edge != nullptr && edge->v != current)
        {
            edge = edge->next;
        }
        
        if (edge == nullptr)
        {
            cerr << " Ошибка: ребро не найдено в пути" << endl;
            return 0;
        }
        
        // Обновляем минимальную пропускную способность
        if (edge->residual < volume)
        {
            volume = edge->residual;
        }
        current = prev;
    }
    
    return volume;
}

void FlowGraph::augmentPath(int source, int sink, int volume)
{
    // Идем от стока к истоку и увеличиваем поток
    int current = sink;
    
    // Сначала выводим путь для отладки
    vector<int> path;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    
    // Выводим путь в правильном порядке (от истока к стоку)
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i > 0) cout << " -> ";
    }
    cout << " (volume: " << volume << ")" << endl;
    
    // Теперь увеличиваем поток
    current = sink;
    while (current != source)
    {
        int prev = parent[current];
        
        // Находим прямое ребро от prev к current
        Edge* forwardEdge = edges[prev];
        while (forwardEdge != nullptr && forwardEdge->v != current)
        {
            forwardEdge = forwardEdge->next;
        }
        
        // Находим обратное ребро от current к prev
        Edge* backwardEdge = edges[current];
        while (backwardEdge != nullptr && backwardEdge->v != prev)
        {
            backwardEdge = backwardEdge->next;
        }
        
        if (forwardEdge != nullptr && backwardEdge != nullptr)
        {
            // Увеличиваем поток в прямом направлении
            forwardEdge->flow += volume;
            forwardEdge->residual -= volume;
            
            // Уменьшаем поток в обратном направлении (увеличиваем residual обратного ребра)
            backwardEdge->residual += volume;
        }
        
        current = prev;
    }
    
    cout << "Поток увеличен на " << volume << endl;
}

/*
 ОСНОВНОЙ АЛГОРИТМ
 */

int FlowGraph::netflow(int source, int sink) {
    cout << " ЗАПУСК АЛГОРИТМА ПОИСКА МАКСИМАЛЬНОГО ПОТОКА " << endl;
    cout << "==============================================" << endl;
    cout << "Исток: " << source << ", Сток: " << sink << endl;
    
    
    int total_flow = 0;
    int iteration = 1;
    
    // Основной цикл алгоритма
    while (true)
    {
        cout << "\n--- Итерация " << iteration << " ---" << endl;
        
        // Инициализируем поиск и выполняем BFS
        initializeSearch();
        bfs(source);
        
        // Находим объем увеличивающего пути
        int volume = pathVolume(source, sink);
        
        // Если увеличивающего пути нет - завершаем
        if (volume == 0)
        {
            cout << "Увеличивающих путей больше нет!" << endl;
            break;
        }
        
        cout << "Найден увеличивающий путь с объемом: " << volume << endl;
        
        // Увеличиваем поток вдоль найденного пути
        augmentPath(source, sink, volume);
        
        total_flow += volume;
        cout << "Суммарный поток: " << total_flow << endl;
        
        iteration++;
        
        // Защита от бесконечного цикла
        if (iteration > 100)
        {
            cout << "Прервано по достижении максимального числа итераций" << endl;
            break;
        }
    }
    
    cout << "\n АЛГОРИТМ ЗАВЕРШЕН" << endl;
    cout << "МАКСИМАЛЬНЫЙ ПОТОК: " << total_flow << endl;
    cout << "==============================================" << endl;
    
    return total_flow;
}

/*
 МЕТОДЫ ВЫВОДА
 */

void FlowGraph::printGraph() const
{
    cout << "\n СТРУКТУРА ГРАФА:" << endl;
    cout << "==================" << endl;
    
    for (int i = 0; i < nvertices; i++)
    {
        cout << "Вершина " << i << ": ";
        Edge* current = edges[i];
        while (current != nullptr)
        {
            cout << "-> " << current->v << " (вмещает" << current->capacity << ", сейчас:" << current->flow << ", свободно:" << current->residual << ") ";
            current = current->next;
        }
        cout << endl;
    }
}

void FlowGraph::printFlows() const
{
    cout << "\n ТЕКУЩИЕ ПОТОКИ:" << endl;
    cout << "=================" << endl;
    
    for (int i = 0; i < nvertices; i++)
    {
        Edge* current = edges[i];
        while (current != nullptr)
        {
            // Выводим только прямые ребра (с положительной capacity)
            if (current->capacity > 0 && current->flow > 0)
            {
                cout << "Ребро " << i << " -> " << current->v
                     << ": поток = " << current->flow 
                     << " / " << current->capacity << endl;
            }
            current = current->next;
        }
    }
}
