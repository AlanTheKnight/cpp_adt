#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

#define FOR(I, TIMES) for (size_t I = 0; I < TIMES; I++)


int main(int argc, char const *argv[])
{
    int t;
    std::cout << "Введите количество вершин в графе: ";
    std::cin >> t;

    std::vector<std::vector<std::pair<int, int>>> graph (t);
    std::cout << "Введите вершины графа: " << std::endl;
    FOR(i, t) {
        char node, node2; int edge, edges_count;
        std::cin >> node >> edges_count;
        FOR (j, edges_count) {
            std::cin >> node2 >> edge;
            graph[node - 65].push_back({node2 - 65, edge});
        }
    }

    std::priority_queue<std::pair<int, int>> q;

    int distance[t];
    FOR (i, t) {
        distance[i] = INT_MAX - 1;
    }

    bool processed[t] = {false};
    int parents[t];

    char start, end;
    std::cout << "Введите начальную вершину пути: ";
    std::cin >> start;
    std::cout << "Введите конечную вершину пути: ";
    std::cin >> end;
    int x = start - 65; int e = end - 65;

    distance[x] = 0;
    q.push({0, x});

    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : graph[a]) {
            int b = u.first, w = u.second;
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                parents[b] = a;
                q.push({-distance[b], b});
            }
        }
    }

    if (distance[e] == INT_MAX - 1) {
        std::cout << "Такого пути не существует" << std::endl;
        return 0;
    }

    std::cout << "Минимальное расстояние от точки " << start << " до " << end << ": " << distance[e] << std::endl; 

    std::vector<int> path;
    int el = e;

    for (int v = e; v != x; v = parents[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());

    std::cout << "Путь: " << start;
    for (auto u : path) {
        std::cout << " - " << (char) ('A' + u);
    }
    std::cout << std::endl;
   

    return 0;
}

