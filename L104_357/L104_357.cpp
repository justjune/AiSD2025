//Улучшенная версия числа Фибоначи
#include <iostream>
#include <vector>

long long fib_ultimate(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    long long back2 = 0;  // F(n-2)
    long long back1 = 1;  // F(n-1)
    
    for (int i = 2; i < n; i++) {
        long long next = back1 + back2;
        back2 = back1;
        back1 = next;
    }
    
    return back1 + back2;
}
