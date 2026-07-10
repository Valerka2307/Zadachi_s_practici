#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MAX_LENGTH = 2000000;

std::vector<int> z_function(const std::string& s) {
    int n = s.length();
    std::vector<int> z(n, 0);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    return z;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;
    std::string t = s + "#" + std::string(s.rbegin(), s.rend());
    std::vector<int> z = z_function(t);

    for (int i = s.length() + 1; i < z.size(); ++i) {
        if (i + z[i] == z.size()) {
            std::cout << z[i] << "\n";
            return 0;
        }
    }
}
