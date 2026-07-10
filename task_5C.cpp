#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    if (!(std::cin >> t)) return 0;
    
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        
        std::vector<std::vector<int>> cost(n + 1, std::vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                std::cin >> cost[i][j];
            }
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= j; ++k) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - k] + cost[i][k]);
                }
            }
        }

        std::cout << dp[n][m] << '\n';
    }
    return 0;
}
