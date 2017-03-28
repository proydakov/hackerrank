#include <cmath>
#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);

    size_t size = 0;
    std::cin >> size;

    std::vector<int> data(size, 0);

    for(size_t i = 0; i < size; i++) {
        int temp;
        std::cin >> temp;
        data[i] = temp;
    }

    std::sort(data.begin(), data.end());

    size_t i = 0;
    size_t j = size - 1;

    int min = std::numeric_limits<int>::max();

    for(size_t i = 0; i < size - 1; i++) {
        int new_data = std::abs( data[i] - data[i + 1] );
        if(new_data < min) {
            min = new_data;
        }
    }

    std::cout << min << std::endl;

    return 0;
}
