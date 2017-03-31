#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);

    int n = 0;
    int k = 0;

    std::cin >> n;
    std::cin >> k;

    std::vector<int> data;
    data.resize(n);

    for(int i = 0; i < n; i++) {
        std::cin >> data[i];
    }

    std::sort(data.begin(), data.end());

    int i = 0;
    int j = 1;

    const size_t size = data.size();

    int counter = 0;

    for(; i < size && j < size ;) {
        const int delta = data[j] - data[i];
        if( delta == k ) {
            j++;
            counter++;
        }
        else if(delta > k) {
            i++;
        }
        else {
            j++;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}
