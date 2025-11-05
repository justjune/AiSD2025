#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <limits>
#include <iostream>

/*===============================================================================================
                                        ~ОПИСАНИЕ КЛАССА~
 ================================================================================================
 
Класс для представления графа и работы с алгоритмом Флойда-Уоршелла
Класс Graph принимающий тип T ( Тип данных для весов рёбер (int, float, double и т.д.) )
 
Этот класс хранит граф в виде матрицы смежности и предоставляет метод для нахождения кратчайших путей между всеми парами вершин
 */
template<typename T>
class Graph
{
    private:
        std::vector<std::vector<T>> weight;  // <-- Матрица весов рёбер
        int nvertices;                       // <-- Количество вершин в графе
        T infinity;                          // <-- Значение "бесконечности" для типа T

    public:
    
        Graph(int vertices);
        /* F
         Graph - Конструктор графа
         
         параметр:
         vertices - Количество вершин
         
         Создает матрицу vertices x vertices, инициализирует диагональные элементы 0,а остальные - "бесконечностью"
         */
        
        void setWeight(int from, int to, T value);
        /* F
         setWeight -  Устанавливает вес ребра между двумя вершинами
        
         параметры:
         from  - Начальная вершина
         to    - Конечная вершина
         value - Вес ребра
         */
        
        T getWeight(int from, int to) const;
        /*F
         Получает вес ребра между двумя вершинами
         
         параметры:
         from - Начальная вершина
         to   - Конечная вершина
         
         (return) -> Вес ребра или "бесконечность", если ребра нет
         */
    
        int getVerticesCount() const;
        /* F
          Возвращает количество вершин в графе
         
         (return) -> Количество вершин
         */
    
        void floyd();
        /* F
          Алгоритм Флойда-Уоршелла для нахождения кратчайших путей
          
         Находит кратчайшие расстояния между всеми парами вершин, используя динамическое программирование
         */
    
        void printWeights() const;
        /* F
          Выводит матрицу весов в читаемом формате
         */
    
};


/*===============================================================================================
                                   ~РЕАЛИЗАЦИЯ ФИНКЦИИ~
 ===============================================================================================*/

template<typename T> //         v-- Инициализация nvertices ( nvertices = vertices )
Graph<T>::Graph(int vertices) : nvertices(vertices)
{
    // Получаем "бесконечность" для типа T ( т.е. находим тип и смотрим его самое большое число,                                                             чтобы определить "бесконечность" )
    infinity = std::numeric_limits<T>::max();
    /*
     Если int    вернет 2147483647
     Если float  вернет 3.40282e+38
     Если double вернет 1.79769e+308
     */
    
    // Создаем матрицу n x n, заполненную "бесконечностями"
    weight.resize(vertices, std::vector<T>(vertices, infinity));
    
    // Расстояние от вершины до самой себя всегда 0
    for (int i = 0; i < vertices; i++)
    {
        weight[i][i] = T(0); /* <-- T(0) чтобы точно получить ноль правильного типа:
                              
                              int(0) = 0
                              float(0) = 0.0f
                              double(0) = 0.0
                              */
    }
}

template<typename T>//   откуда    куда    длина
void Graph<T>::setWeight(int from, int to, T value)
{
    // Проверяем, что индексы в допустимом диапазоне
    if (from >= 0 && from < nvertices && to >= 0 && to < nvertices)
    {
        weight[from][to] = value;
    }
}

template<typename T>//откуда    куда
T Graph<T>::getWeight(int from, int to) const
{
    if (from >= 0 && from < nvertices && to >= 0 && to < nvertices)
    {
        return weight[from][to];
    }
    return infinity; // Если точки не существуют - возвращаем "бесконечность" (т.е. дороги нету)
}

template<typename T>
int Graph<T>::getVerticesCount() const
{
    return nvertices;
}

template<typename T>
void Graph<T>::floyd() // Алгоритма Флойда-Уоршелла
{
    std::cout << "Количество вершин: " << nvertices << std::endl;
    
    // Основная тройная вложенность алгоритма
    // k - промежуточная вершина, через которую пробуем проложить путь
    for (int k = 0; k < nvertices; k++)
    {
        // i - начальная вершина пути
        for (int i = 0; i < nvertices; i++)
        {
            // j - конечная вершина пути
            for (int j = 0; j < nvertices; j++)
            {
                // Проверяем, что существует путь i→k и k→j
                // Это предотвращает переполнение при работе с "бесконечностями"
                if (weight[i][k] != infinity && weight[k][j] != infinity)
                {
                    // Вычисляем длину пути через промежуточную вершину k
                    T through_k = weight[i][k] + weight[k][j];
                    
                    // Если путь через k короче прямого пути i→j, обновляем
                    if (through_k < weight[i][j])
                    {
                        weight[i][j] = through_k;
                    }
                }
            }
        }
        
        
        /*
         Этот if не обязательный, но полезный ( Это прогресс выполнения алгоритма )
         */
        if (nvertices > 10 && k % (nvertices / 10) == 0)
        {
            std::cout << "Обработано " << (k * 100 / nvertices) << "% промежуточных вершин" << std::endl;
        }
         
        
    }
    
}

template<typename T>
void Graph<T>::printWeights() const
{
    std::cout << "Матрица кратчайших путей (" << nvertices << "x" << nvertices << "):\n";
    std::cout << "    ";
    
    // Заголовок столбцов
    for (int j = 0; j < nvertices; j++)
    {
        std::cout << "[" << j << "] ";
    }
    std::cout << std::endl;
    
    // Данные матрицы
    for (int i = 0; i < nvertices; i++)
    {
        std::cout << "[" << i << "] ";
        for (int j = 0; j < nvertices; j++)
        {
            if (weight[i][j] == infinity)
            {
                std::cout << " INF";
            }
            else
            {
                std::cout << " ";
                // Форматируем вывод в зависимости от типа
                if (weight[i][j] < 10) std::cout << " ";
                std::cout << weight[i][j];
            }
        }
        std::cout << std::endl;
    }
}

#endif // GRAPH_H
