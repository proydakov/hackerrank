#include <array>
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);

    std::array<int, 5> array;

    for(int i = 0; i < 5; i++) {
        int temp;
        std::cin >> temp;
        array[i] = temp;
    }
    std::sort(array.begin(), array.end());

    const size_t sum_min = std::accumulate(array.begin() + 0, array.begin() + 4, size_t(0));
    const size_t sum_max = std::accumulate(array.begin() + 1, array.begin() + 5, size_t(0)); 

    std::cout << sum_min << " " << sum_max << std::endl;

    return 0;
}
