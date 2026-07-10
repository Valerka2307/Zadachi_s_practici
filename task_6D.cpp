#include <iostream>
#include <vector>


using ll = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<std::vector<int>> gr(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> gr[i][j];
        }
    }

    if (n == 1) {
        std::cout << 1 << "\n";
        return 0;
    }

    int max_mask = 1 << n;
    std::vector<std::vector<ll>> dp(max_mask, std::vector<ll>(n, 0));

    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 1;
    }

    for (int mask = 1; mask < max_mask; ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u)) || dp[mask][u] == 0) {
                continue;
            }

            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v)) {
                    continue;
                }

                if (gr[u][v] == 1) {
                    int next_mask = mask | (1 << v);
                    dp[next_mask][v] += dp[mask][u];
                }
            }
        }
    }

    ll ans = 0;
    int full_mask = max_mask - 1;

    for (int i = 0; i < n; ++i) {
        ans += dp[full_mask][i];
    }

    std::cout << ans << "\n";
    return 0;
}
