#include <vector>
#include <numeric>
#include <iostream>

void solve()
{
    int size = 0;
    std::cin >> size;

    std::vector<int> data(size);
    for(int i = 0; i < size; i++) {
        int temp;
        std::cin >> temp;
        data[i] = temp;
    }

    if(size == 1) {
        std::cout << "YES" << std::endl;
        return;
    }
    if(size == 2) {
        std::cout << "NO" << std::endl;
        return;
    }

    size_t sum_left = std::accumulate(data.begin(), data.end() - 1, 0);
    size_t sum_right = data[size - 1];

    bool yes = false;

    for(int i = size - 2; i > 0; i--) {
        const int test_item = data[i];
        sum_left  -= test_item;
        if(sum_left == sum_right) {
            yes = true;
            break;
        }
        sum_right += test_item;
    }

    if(yes) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n = 0;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        solve();
    }

    return 0;
}
