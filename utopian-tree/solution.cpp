#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> data;
    data.resize(n);

    for(int i = 0; i < n; i++) {
        std::cin >> data[i];
    }

    int max = *std::max_element(data.begin(), data.end());

    std::vector<size_t> cache(max + 1, 0);
    cache[0] = 1;

    for(int i = 1; i <= max; i++) {
        if( i % 2 == 0 ) {
            cache[i] = cache[i - 1] + 1;
        }
        else {
            cache[i] = cache[i - 1] * 2;
        }
    }

    for(const auto item : data) {
        std::cout << cache[item] << "\n";
    }

    return 0;
}
