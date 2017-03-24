#include <array>
#include <string>
#include <iostream>
#include <algorithm>

void solve()
{
    std::string s;
    std::getline(std::cin, s);
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);

    std::array<int, 256> cache;
    cache.fill(0);

    for(const char c : s) {
        cache[c]++;
    }

    int size = 0;
    for(int i = (int)('a'); i <= (int)('z'); i++) {
        if(cache[i]) {
            size++;
        }
    }

    const bool pangrams = size == 26;
    if(pangrams) {
        std::cout << "pangram" << std::endl;
    }
    else {
        std::cout << "not pangram" << std::endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
