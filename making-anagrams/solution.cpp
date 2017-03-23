#include <cmath>
#include <array>
#include <string>
#include <iostream>

void build_cache(const std::string& s, std::array<int, 256>& cache)
{
    cache.fill(0);

    for(const char c : s) {
        cache[c]++;
    }
}

void solve()
{
    std::string s1;
    std::string s2;

    std::cin >> s1;
    std::cin >> s2;

    std::array<int, 256> s1_cache;
    build_cache(s1, s1_cache);

    std::array<int, 256> s2_cache;
    build_cache(s2, s2_cache);

    int change = 0;
    for(int i = 0; i < 256; i++) {
        change += std::abs( s1_cache[i] - s2_cache[i] );
    }

    std::cout << change << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
