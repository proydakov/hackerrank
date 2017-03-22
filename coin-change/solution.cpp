#include <set>
#include <vector>
#include <unordered_set>

#include <iostream>

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    const size_t size = vec.size();
    std::cout << "vec [" << size << "] ";
    for(size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    return os;
}

int read_input(std::vector<int>& coins)
{
    int number = 0;
    int count  = 0;

    std::cin >> number;
    std::cin >> count;

    coins.reserve(count);

    for(int c = 0; c < count; c++) {
        int coin;
        std::cin >> coin;

        coins.push_back(coin);
    }

    return number;
}

int main()
{
    std::vector<int> coins;
    const int number = read_input(coins);

    std::vector<size_t> solution(number + 1, 0);
    solution[0] = 1;

    //std::cout << solution << std::endl;

    for(const auto c : coins) {
        for(int i = c; i <= number; i++) {
            solution[i] += solution[i - c];
        }
        //std::cout << solution << std::endl;
    }

    std::cout << solution[number] << std::endl;

    return 0;
}
