#include <iostream>
#include <algorithm>
#include <unordered_map>

int build(std::unordered_map<int, int>& map)
{
    int n = 0;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        map[temp]++;
    }

    return n;
}

int main()
{
    std::ios::sync_with_stdio(false);

    std::unordered_map<int, int> m1;
    int s1 = build(m1);

    std::unordered_map<int, int> m2;
    int s2 = build(m2);

    for(const auto item : m1) {
        m2[item.first] -= item.second;
    }

    std::vector<int> data;
    data.reserve(s2 - s1);

    for(const auto item : m2) {
        if(item.second > 0) {
            data.push_back(item.first);
        }
    }

    std::sort(data.begin(), data.end());

    for(size_t i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }

    return 0;
}
