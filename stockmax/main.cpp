#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void calc()
{
    int items = 0;
    std::cin >> items;
    std::vector<int> data(items, 0);

    for(size_t i = 0; i < items; i++) {
        int temp;
        std::cin >> temp;
        data[i] = temp;
    }

    std::vector<int> data_max(items, 0);
    data_max[items - 1] = data[items - 1];
    for(int i = items - 2; i >= 0; i--) {
        data_max[i] = std::max( data_max[i + 1], data[i] );
    }

    size_t sum = 0;
    for(size_t i = 0; i < items; i++) {
        int temp = data_max[i] - data[i];
        if(temp > 0) {
            sum += temp;
        }
    }

    std::cout << sum << std::endl;
}

int main()
{
    size_t iters = 0;
    std::cin >> iters;
    for(size_t i = 0; i < iters; i++) {
        calc();
    }
    return 0;
}
