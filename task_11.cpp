#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
            
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
            
        int max_xor = 0;
            
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                max_xor = std::max(max_xor, arr[i] ^ arr[j]);
            }
        }
            
        std::cout << max_xor << "\n";
    }
    
    return 0;
}
