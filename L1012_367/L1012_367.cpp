//1012_357
//Функция определения местонахождения целевой ячейки
//Попов Николай, МЕН-243201 (ПМ-201) 03.12.2025
#ifndef L1012_367_HPP
#define L1012_367_HPP
#include <iostream>
using namespace std;
void goal_cell(char *s, char *t, int *i, int *j){
    *i = strlen(s) - 1;
    *j = strlen(t) - 1;
}
#endif