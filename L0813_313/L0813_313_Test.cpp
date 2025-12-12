#include <iostream>
#include "L0813_313.h"

using namespace std;

void Test1()
{
    cout << " ДЕМОНСТРАЦИЯ АЛГОРИТМА МАКСИМАЛЬНОГО ПОТОКА" << endl;
    cout << "==============================================" << endl;
    
    // Создаем граф с 6 вершинами (0-5)
    FlowGraph graph(6);
    
    // Настраиваем ребра графа
    // Исток (0) соединен с вершинами 1 и 2
    graph.addEdge(0, 1, 16);  // Пропускная способность 16
    graph.addEdge(0, 2, 13);  // Пропускная способность 13
    
    // Промежуточные соединения
    graph.addEdge(1, 2, 10);  // Между 1 и 2
    graph.addEdge(1, 3, 12);  // Из 1 в 3
    graph.addEdge(2, 1, 4);   // Обратное из 2 в 1
    graph.addEdge(2, 4, 14);  // Из 2 в 4
    
    // Соединения к стоку
    graph.addEdge(3, 2, 9);   // Из 3 в 2
    graph.addEdge(3, 5, 20);  // Из 3 в сток (5)
    graph.addEdge(4, 3, 7);   // Из 4 в 3
    graph.addEdge(4, 5, 4);   // Из 4 в сток (5)
    
    // Выводим исходную структуру графа
    graph.printGraph();
    
    // Запускаем алгоритм поиска максимального потока
    // от истока (0) к стоку (5)
    int max_flow = graph.netflow(0, 5);
    
    // Выводим итоговые потоки
    graph.printFlows();
    
    cout << "\n ИТОГ: Максимальный поток = " << max_flow << endl;
}


void Test2()
{
    cout << "\n\n ДОПОЛНИТЕЛЬНЫЙ ПРИМЕР" << endl;
    cout << "======================" << endl;
    
    FlowGraph graph(4);
    
    // Простой граф с 4 вершинами
    graph.addEdge(0, 1, 3);  // Исток -> 1
    graph.addEdge(0, 2, 2);  // Исток -> 2  
    graph.addEdge(1, 2, 1);  // 1 -> 2
    graph.addEdge(1, 3, 3);  // 1 -> Сток
    graph.addEdge(2, 3, 2);  // 2 -> Сток
    
    graph.printGraph();
    int max_flow = graph.netflow(0, 3);
    graph.printFlows();
    
    cout << " Максимальный поток: " << max_flow << endl;
}

int main()
{
    cout << " АЛГОРИТМ ПОИСКА МАКСИМАЛЬНОГО ПОТОКА" << endl;
    cout << "Метод Форда-Фалкерсона с BFS (Эдмондса-Карпа)" << endl;
    cout << "==============================================" << endl;
    
    Test1();
    Test2();

    return 0;
}
