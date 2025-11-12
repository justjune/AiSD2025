#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "my_qsort.h"

struct Student {
    std::string name;
    int age;
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int nums[] = {42, 7, 19, 73, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    my_qsort(nums, 0, n - 1, [](const int &a, const int &b) {
        return a < b;
    });

    std::cout << "Сортировка чисел: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n";

    Student students[] = {
        {"Иван", 22},
        {"Мария", 19},
        {"Петр", 25},
        {"Анна", 20}
    };
    int m = sizeof(students) / sizeof(students[0]);

    my_qsort(students, 0, m - 1, [](const Student &a, const Student &b) {
        return a.age < b.age;
    });

    std::cout << "Сортировка студентов по возрасту:\n";
    for (auto &s : students)
        std::cout << s.name << " (" << s.age << ")\n";

    return 0;
}
