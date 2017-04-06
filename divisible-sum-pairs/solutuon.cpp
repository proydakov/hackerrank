#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);

    size_t size;
    std::cin >> size;

    int val;
    std::cin >> val;

    std::vector<int> data;
    data.reserve(size);

    for(size_t i = 0; i < size; i++) {
        int temp;
        std::cin >> temp;
        data.push_back(temp);
    }

    size_t counter = 0;
    for(size_t i = 0; i < size; i++) {
        for(size_t j = i + 1; j < size; j++) {
            int sum = data[i] + data[j];
            if(sum % val == 0) {
                counter++;
            }
        }
    }

    std::cout << counter << std::endl;

    return 0;
}
