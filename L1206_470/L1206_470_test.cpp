//Попов Николай, ПМ-201, Восхождение по холму , L1206_470
#include "L1206_470.hpp"
#include <iostream>

using namespace std;

int main(){
    cout << "3 города" << endl;
    
    tsp_instance problem;
    problem->n = 3;
    
    problem->distances = {
        {0, 10, 30},
        {10, 0, 20},
        {30, 20, 0}
    };
    
    tsp_solution solution;
    
    hill_climbing(&problem, &solution);
    
    cout << "Результат:" << endl;
    cout << "Маршрут: ";
    for(int city : solution->route) {
        cout << city << " ";
    }
    cout << endl;
    cout << "Стоимость: " << solution_cost(&solution, &problem) << endl;
    cout << "Вычислений стоимости: " << solution->count << endl;
    cout << endl;
}
