#include <cmath>
#include <queue>
#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>

struct item
{
    int node;
    int cost;
};

bool operator<(const item& i1, const item& i2)
{
    return i1.cost < i2.cost;
}

std::vector<int> dijkstra_search(const std::vector<std::vector<int>>& graph, int start)
{
    const int graph_step_cost = 6;

    std::priority_queue<item> frontier;
    frontier.push(item{ start, 0 });

    std::vector<int> came_from(graph.size(), -1);
    std::vector<int> cost_so_far(graph.size(), std::numeric_limits<int>::max());

    came_from[start] = -1;
    cost_so_far[start] = 0;

    while(!frontier.empty()) {
        const auto top = frontier.top();

        const int current = top.node;
        frontier.pop();

        const size_t size = graph[current].size();
        for(size_t i = 0; i < size; i++) {
            const int next = graph[current][i];
            const int new_cost = cost_so_far[current] + graph_step_cost;
            if(new_cost < cost_so_far[next]) {
                cost_so_far[next] = new_cost;
                frontier.push(item{next, new_cost});
                came_from[next] = current;
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
    int start_node = 0;

    std::cin >> number_of_nodes;
    std::cin >> number_of_edges;

    std::vector<std::vector<int>> graph;
    graph.resize(number_of_nodes);
    for(int i = 0; i < number_of_edges; i++) {
        int node1 = 0;
        int node2 = 0;

        std::cin >> node1;
        std::cin >> node2;

        node1--;
        node2--;

        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

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
    int size = 0;
    std::cin >> size;
    for(int i = 0; i < size; i++) {
        solve();
    }
    return 0;
}
