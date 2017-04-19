#include <vector>
#include <iostream>
#include <algorithm>

struct item
{
    int cost;

    int n1;
    int n2;
};

bool operator<(const item& it1, const item& it2)
{
    return it1.cost < it2.cost;
}

int read(std::vector<item>& items)
{
    int N; int M;
    std::cin >> N;
    std::cin >> M;

    items.resize(M);

    for(int i = 0; i < M; i++) {
        item it;
        std::cin >> it.n1;
        std::cin >> it.n2;
        std::cin >> it.cost;

        it.n1--;
        it.n2--;

        items[i] = it;
    }

    return N;
}

int solve_kruskal(std::vector<item>& items, int n)
{
    std::sort(items.begin(), items.end());

    std::vector<std::pair<int, int>> solution;
    int cost = 0;

    std::vector<int> tree_id(n);
    for(int i = 0; i < n; i++) {
        tree_id[i] = i;
    }

    for(int i = 0; i < items.size(); i++) {
        int a = items[i].n1;
        int b = items[i].n2;
        int l = items[i].cost;

        if(tree_id[a] != tree_id[b]) {
            cost += l;
            solution.push_back(std::make_pair(a, b));
            int old_id = tree_id[a];
            int new_id = tree_id[b];
            for(int j = 0; j < n; j++) {
                if(tree_id[j] == old_id) {
                    tree_id[j] = new_id;
                }
            }
        }
    }

    return cost;
}

int main()
{
    std::ios::sync_with_stdio(false);

    std::vector<item> items;

    int n = read(items);

    int sum = solve_kruskal(items, n);

    std::cout << sum << std::endl;

    return 0;
}
