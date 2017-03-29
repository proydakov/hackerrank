#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);

    size_t N = 0;
    std::cin >> N;

    for(size_t i = 0; i < N; i++) {
        for(size_t j = i; j < N - 1; j++) {
            std::cout << ' ';
        }
        for(size_t j = N - i - 1; j < N; j++) {
            std::cout << '#';
        }
        std::cout << "\n";
    }

    return 0;
}
