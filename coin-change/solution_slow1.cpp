#include <set>
#include <vector>

#include <iostream>

#include <algorithm>

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

struct solution_t
{
    std::vector<int> coins;

    size_t size() const {
        return coins.size();
    }
};

bool operator<(const solution_t& s1, const solution_t& s2) {
    if(s1.size() == s2.size()) {
        const size_t size = s1.size();
        for(size_t i = 0; i < size; i++) {
            if(s1.coins[i] < s2.coins[i]) {
                return true;
            }
            else if(s1.coins[i] > s2.coins[i]) {
                return false;
            }
        }
        return false;
    }
    return s1.size() < s2.size();
}

void dump_cache(const std::vector<std::set<int>>& cache, int number)
{
    for(int i = 0; i <= number; i++) {
        std::cout << "bucket [" << i << "] ";
        const auto& set = cache[i];
        for(const auto val : set) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void dump_solutions(std::set<solution_t>& solutions)
{
    for(const auto& solution : solutions) {
        for(const auto val : solution.coins) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int read_input(std::vector<int>& coins, int& max_coin)
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

        if(coin > max_coin) {
            max_coin = coin;
        }
    }

    std::sort(coins.begin(), coins.end());

    return number;
}

void build_cache(std::vector<int>& coins, int number, std::vector<std::set<int>>& cache)
{
    for(const auto c : coins) {
        cache[c].insert(c);
    }

    for(int i = 0; i < number; i++) {
        const auto& current = cache[i];

        for(auto it = current.begin(), end_it = current.end(); it != end_it; ++it) {
            for(const auto c : coins) {
                cache[i + c].insert(c);
            }
        }
    }
}

void append(std::set<solution_t>& solutions, solution_t solution,
    const std::vector<std::set<int>>& cache, int index,
    int sum, int number
)
{
    const std::set<int>& set = cache[index];
    for(const auto coin : set) {
        solution_t temp(solution);
        temp.coins.push_back(coin);

        const int new_sum = sum + coin;
        if(new_sum == number) {
            solution.coins.push_back(index);
            std::sort(solution.coins.begin(), solution.coins.end());
            solutions.insert(solution);
            continue;
        }

        else if(new_sum <= number) {
            append(solutions, temp, cache, index - coin, new_sum, number);
        }
    }
}

int main()
{
    std::vector<int> coins;
    int max_coin = 0;
    int number = read_input(coins, max_coin);

    std::vector<std::set<int>> cache(number + max_coin, std::set<int>());
    build_cache(coins, number, cache);

    //dump_cache(cache, number);

    solution_t solution;
    std::set<solution_t> solutions;
    append(solutions, solution, cache, number, 0, number);

    //dump_solutions(solutions);

    std::cout << solutions.size() << std::endl;

    return 0;
}
