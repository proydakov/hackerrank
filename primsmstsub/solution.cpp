#include <limits>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

const auto INF = std::numeric_limits<int>::max();

int read(std::vector<std::vector<int>>& adjacency_matrix)
{
    int N; int M; int S;
    std::cin >> N;
    std::cin >> M;

    adjacency_matrix = std::vector<std::vector<int>>(N, std::vector<int>(N, INF));

    for(int i = 0; i < M; i++) {
        int x; int y; int r;
        std::cin >> x;
        std::cin >> y;
        std::cin >> r;

        --x;
        --y;

        adjacency_matrix[x][y] = r;
        adjacency_matrix[y][x] = r;
    }

    std::cin >> S;
    --S;

    return S;
}

int solve(std::vector<std::vector<int>>& adjacency_matrix, int start_node)
{
    const size_t n = adjacency_matrix.size();

    std::vector<int> used(n, 0);
    std::vector<int> min_dist(n, INF);
    std::vector<int> dest_node(n, -1);

    min_dist[start_node] = 0;

    int sum = 0;

    for(size_t i = 0; i < n; i++) {
        int v = -1;
        for(int j = 0; j < n; j++) {
            if(!used[j] && (v == -1 || min_dist[j] < min_dist[v])) {
                v = j;
            }
        }
        if(min_dist[v] == INF) {
            throw std::runtime_error("invalid adjacency_matrix");
        }

        used[v] = 1;

        if (dest_node[v] != -1) {
            sum += min_dist[v];
            //std::cout << "link: " << char('A' + dest_node[v])
            //          << " -> " << char('A' + v)
            //          << " cost: " << min_dist[v]
            //          << std::endl;
        }

        for(size_t to = 0; to < n; to++) {
            const int test_dist = adjacency_matrix[v][to];
            if (test_dist < min_dist[to]) {
                min_dist[to] = test_dist;
                dest_node[to] = v;
            }
        }
    }

    return sum;
}

int main()
{
    std::ios::sync_with_stdio(false);

    std::vector<std::vector<int>> adjacency_matrix;

    int start_node = read(adjacency_matrix);

    int sum = solve(adjacency_matrix, start_node);

    std::cout << sum << std::endl;

    return 0;
}
