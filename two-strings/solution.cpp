#include <array>
#include <string>
#include <iostream>

void solve()
{
    std::string s1;
    std::string s2;

    std::cin >> s1;
    std::cin >> s2;

    std::array<int, 256> check;
    check.fill(0);

    for(const char c : s1) {
        check[c] = 1;
    }
    for(const char c : s2) {
        if(check[c]) {
            std::cout << "YES" << std::endl;
            return;
        }
    }
    std::cout << "NO" << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int size = 0;
    std::cin >> size;

    for(int i = 0; i < size; i++) {
        solve();
    }
    return 0;
}
