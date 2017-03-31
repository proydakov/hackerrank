#include <cmath>
#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector< std::vector<int> > rating_map(100000 + 1);

    std::vector<int> rating;
    rating.reserve(n + 2);
    rating.push_back(std::numeric_limits<int>::max());

    for(int i = 0; i < n; i++) {
        int r;
        std::cin >> r;
        rating.push_back(r);
        rating_map[r].push_back(i + 1);
    }

    rating.push_back(std::numeric_limits<int>::max());

    std::vector<int> candies(n + 2, 1);

    for(int r = 0; r < rating_map.size(); r++) {
        const std::vector<int>& index = rating_map[r];
        for(const int i : index) {
            if( rating[i] == r ) {
                if( rating[i] > rating[i - 1] ) {
                    candies[i] = std::max(candies[i], candies[i - 1] + 1);
                }
                if( rating[i] > rating[i + 1] ) {
                    candies[i] = std::max(candies[i], candies[i + 1] + 1);
                }
            }
        }
    }

    size_t count = std::accumulate(candies.begin() + 1, candies.end() - 1, size_t(0));
    std::cout << count << std::endl;

    return 0;
}
