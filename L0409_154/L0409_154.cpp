#include "L0409_154.hpp"
#include <utility>

void insertion_sort(std::vector<item_type>& s) {
    for (int i = 1; i < (int)s.size(); ++i) {
        int j = i;
        while (j > 0 && s[j] < s[j - 1]) {
            std::swap(s[j], s[j - 1]);
            --j;
        }
    }
}
