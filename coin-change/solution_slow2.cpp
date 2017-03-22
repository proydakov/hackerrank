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

void dump_solutions(const std::set<solution_t>& solutions)
{
    for(const auto& solution : solutions) {
        for(const auto val : solution.coins) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

void dump_cache(const std::vector<std::set<solution_t>>& cache)
{
    for(size_t i = 0; i < cache.size(); i++) {
        const auto& set = cache[i];
        std::cout << "bucket [" << i << "]\n";
        dump_solutions(set);
        std::cout << std::endl;
    }
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

    std::sort(coins.begin(), coins.end());
    auto it = std::unique(coins.begin(), coins.end());
    coins.erase(it, coins.end());

    return number;
}

int main()
{
    std::vector<int> coins;
    const int number = read_input(coins);

    std::vector<std::set<solution_t>> cache(number + 1);

    for(const auto c : coins) {
        if(c > number) {
            break;
        }
        solution_t solution;
        solution.coins.push_back(c);
        cache[c].insert(solution);
    }

    //std::cout << "before" << std::endl;
    //dump_cache(cache);

    for(int i = 0; i < number; i++) {
        const auto& set = cache[i];

        for(auto it = set.begin(), end_it = set.end(); it != end_it; ++it) {
            for(const auto c : coins) {
                int index = i + c;
                if(index <= number) {
                    solution_t temp(*it);
                    temp.coins.push_back(c);
                    std::sort(temp.coins.begin(), temp.coins.end());
                    cache[index].insert(temp);
                }
            }
        }
    }

    //std::cout << "after" << std::endl;
    //dump_cache(cache);

    const auto& solutions = cache[number];

    //std::cout << "solution" << std::endl;
    //dump_solutions(solutions);

    std::cout << solutions.size() << std::endl;

    return 0;
}
