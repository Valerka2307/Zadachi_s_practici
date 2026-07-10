#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> number(N + 1);

    for (int i = 2; i <= N; ++i) {
        number[i] = number[i - 1] + i;

        if (i % 2 == 0) {
            number[i] = std::min(number[i], number[i / 2] + i);
        }

        if (i % 3 == 0) {
            number[i] = std::min(number[i], number[i / 3] + i);
        }
    }

    std::cout << number[N] << '\n';
    return 0;
}
