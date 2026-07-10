#include <iostream>
#include <deque>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        std::deque<long long> dq;
        long long left_dmg = (k + 1) / 2;
        long long right_dmg = k / 2;
        
        long long total_health = 0;

        for (long long i = 0; i < n; ++i) {
            long long x;
            std::cin >> x;
            total_health += x;
            dq.push_back(x);
        }

        if (total_health <= k) {
            std::cout << n << "\n";
            continue;
        }

        while (left_dmg > 0) {
            if (!dq.empty() && dq.front() <= left_dmg) {
                left_dmg -= dq.front();
                dq.pop_front();
            } else {
                break;
            } 
        }
        
        while (right_dmg > 0) {
            if (!dq.empty() && dq.back() <= right_dmg) {
                right_dmg -= dq.back();
                dq.pop_back();
            } else {
                break;
            } 
        }
        
        std::cout << n - dq.size() << "\n";
    }

    return 0;
}
