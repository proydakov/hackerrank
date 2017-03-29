#include <cmath>
#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);

    std::size_t N;
    std::size_t K;

    std::cin >> N;
    std::cin >> K;

    std::vector<int> data(N, 0);
    for(std::size_t i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        data[i] = temp;
    }

    std::sort(data.begin(), data.end());

    int delta = std::numeric_limits<int>::max();

    for(std::size_t i = 0; i < N - K + 1; i++) {
        const int min = data[i];
        const int max = data[i + K - 1];

        const int new_delta = max - min;
        if(new_delta < delta) {
            delta = new_delta;
        }
    }

    std::cout << delta << std::endl;

    return 0;
}
