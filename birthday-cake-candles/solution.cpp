#include <limits>
#include <vector>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);

    size_t N = 0;
    std::cin >> N;

    int max = std::numeric_limits<int>::min();
    int count = 0;
    for(size_t i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;

        if(temp > max) {
            max = temp;
            count = 1;
        }
        else if(temp == max) {
            count++;
        }
    }
    std::cout << count << std::endl;

    return 0;
}
