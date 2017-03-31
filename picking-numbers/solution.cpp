#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);

    int size = 0;
    std::cin >> size;

    std::vector<int> data;
    data.resize(size);

    for(int i = 0; i < size; i++) {
        std::cin >> data[i];
    }

    std::sort(data.begin(), data.end());

    int i = 0;
    int j = 1;

    int count = 1;

    for( ; j < size ; ) {
        if( data[j] - data[i] > 1 ) {
            count = std::max(j - i, count);
            i++;
        }
        else {
            j++;
        }
    }
    count = std::max(j - i, count);

    std::cout << count << std::endl;

    return 0;
}
