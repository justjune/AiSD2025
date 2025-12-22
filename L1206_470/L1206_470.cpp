//1206_470
//Процедура восхождения по выпуклой поверхности
//Попов Николай, МЕН-243201 (ПМ-201) 03.12.2025
#ifndef L1206_470_HPP
#define L1206_470_HPP
#include <iostream>
using namespace std;
void hill_climbing(tsp_instance *t, tsp_solution *s){
    double cost;
    double delta;
    int i, j;
    bool stuck
    initialize_solution(t->n, s);
    random_solution(s);
    cost = solution_cost(s, t);

    do {
        stuck = true;
        for (i = 1; i < t->n; i++){
            for(j = i + 1; j <= t->n; j++){
                delta = transition(s,t,i,j);
                if(delta<0) {
                    stuck = false;
                    cost = cost + delta;
                } else {
                    transition(s,t,j,i);
                }
                solution_count_update(s, t);
            }
        }
    } while (stuck);
}
#endif