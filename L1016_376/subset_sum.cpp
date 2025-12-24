#include "subset_sum.hpp"

bool subset_sum(const std::vector<int>& numbers, int target_sum) {
    int n = numbers.size();
    
    // Создаем таблицу DP: sum[i][j] - можно ли получить сумму j используя первые i элементов
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target_sum + 1, false));
    
    // Базовый случай: сумма 0 всегда достижима (пустое подмножество)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    
    // Заполняем таблицу DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target_sum; j++) {
            // Если текущий элемент больше текущей суммы, не можем его использовать
            if (numbers[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Иначе проверяем два варианта:
                // 1. Не использовать текущий элемент
                // 2. Использовать текущий элемент
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - numbers[i - 1]];
            }
        }
    }
    
    return dp[n][target_sum];
}