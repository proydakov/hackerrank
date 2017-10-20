#include <cmath>
#include <queue>
#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>

struct edge
{
    int to;
    int cost;
};

struct item
{
    int node;
    int cost;
};

bool operator<(const item& i1, const item& i2)
{
    return i1.cost > i2.cost;
}

std::vector<int> dijkstra_search(const std::vector<std::vector<edge>>& graph, int start)
{
    std::priority_queue<item> frontier;
    frontier.push(item{ start, 0 });

    std::vector<int> cost_so_far(graph.size(), std::numeric_limits<int>::max());

    cost_so_far[start] = 0;

    while(!frontier.empty()) {
        const auto top = frontier.top();

        const int current = top.node;
        frontier.pop();

        if (top.cost > cost_so_far[current]) {
            continue;
        }

        for(const auto& e : graph[current]) {
            const int next = e.to;
            const int cost = e.cost;
            const int new_cost = cost_so_far[current] + cost;
            if(new_cost < cost_so_far[next]) {
                cost_so_far[next] = new_cost;
                frontier.push(item{next, new_cost});
            }
        }
    }

    for(size_t i = 0; i < cost_so_far.size(); i++) {
        if(std::numeric_limits<int>::max() == cost_so_far[i]) {
            cost_so_far[i] = -1;
        }
    }

    return cost_so_far;
}

void solve()
{
    int number_of_nodes = 0;
    int number_of_edges = 0;

    std::cin >> number_of_nodes;
    std::cin >> number_of_edges;

    std::vector<std::vector<edge>> graph(number_of_nodes);
    for(int i = 0; i < number_of_edges; i++) {
        int node1;
        int node2;
        int cost;

        std::cin >> node1;
        std::cin >> node2;
        std::cin >> cost;

        node1--;
        node2--;

        graph[node1].push_back(edge{node2, cost});
        graph[node2].push_back(edge{node1, cost});
    }

    int start_node = 0;

    std::cin >> start_node;
    start_node--;

    std::vector<int> solution = dijkstra_search(graph, start_node);

    for(size_t i = 0; i < solution.size(); i++) {
        if(i != start_node) {
            std::cout << solution[i] << " ";
        }
    }
    std::cout << std::endl;
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
