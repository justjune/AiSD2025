#include "match.hpp"

int match(char c, char d) {
    if (c == d) {
        return 0; // Совпадение
    }
    return 1000; // MAXLEN - высокая стоимость замены
}