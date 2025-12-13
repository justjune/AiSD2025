#include <iostream>
#include "match.hpp"

int main() {
    char a = 'a';
    char b = 'b';
    
    std::cout << "match('a', 'a') = " << match(a, a) << std::endl;
    std::cout << "match('a', 'b') = " << match(a, b) << std::endl;
    std::cout << "match('X', 'X') = " << match('X', 'X') << std::endl;
    std::cout << "match('1', '2') = " << match('1', '2') << std::endl;
    
    return 0;
}