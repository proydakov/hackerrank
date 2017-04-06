#include <array>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);

    std::array<int, 6> cache;
    cache.fill(0);

    int size;
    std::cin >> size;

    for(int i = 0; i < size; i++) {
        int temp;
        std::cin >> temp;

        cache[temp]++; 
    }

    size_t index = 0;
    int max = cache[0];

    for(size_t i = 1; i < cache.size(); i++) {
        if(cache[i] > max) {
            index = i;
            max = cache[i];
        }
    }

    std::cout << index << std::endl;

    return 0;
}
