#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);

    size_t N = 0;
    std::cin >> N;    

    int plus = 0;
    int minus = 0;
    int zero = 0;

    for(size_t i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;

        if(temp > 0) {
            plus++;
        }
        else if(temp < 0) {
            minus++;
        }
        else {
            zero++;
        }
    }

    std::cout << float(plus ) / N << std::endl
              << float(minus) / N << std::endl
              << float(zero ) / N << std::endl;

    return 0;
}
