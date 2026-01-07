//Тесты для листинга 3.2, Шарапов Даниил, ПМ-201
#include <iostream>
#include "L302_087.hpp"
using namespace std;
int main(){
    setlocale(LC_ALL, "RU");
    List* head = NULL;
    for (int i = 1; i <= 50; i++){//Заполнили список элементами от 1 до 50
        head = append(head, i);
    }
    for (int i = 5; i <= 9; i++){//Тест1
        List* found = search_list(head, i);
        if (found) {cout << "Элемент " << i << " найден" <<endl;}
        else {cout << "Элемент " << i << " не найден" << endl;}
    }
    cout << endl;
    for (int i = -4; i <= 0; i++){//Тест2
        List* found = search_list(head, i);
        if (found) {cout << "Элемент " << i << " найден" <<endl;}
        else {cout << "Элемент " << i << " не найден" << endl;}
    }
    
}
