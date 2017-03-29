#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);

    size_t N = 0;
    std::cin >> N;

    int sum_d1 = 0;
    int sum_d2 = 0;

    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < N; j++) {
            int temp;
            std::cin >> temp;

            if(j == i) {
                sum_d1 += temp;
            }
            if(i == N - j - 1) {
                sum_d2 += temp;
            }
        }
    }

    const int abs = std::abs( sum_d1 - sum_d2 );
    std::cout << abs << std::endl;

    return 0;
}
