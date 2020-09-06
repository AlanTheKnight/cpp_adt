#include <queue>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main(int argc, char const *argv[])
{
    freopen("bfs.in", "r", stdin);
    freopen("bfs.out", "w", stdout);
    int n, s, f;
    cin >> n >> s >> f;
    bool matrix[n][n];  // Матрица смежности
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j])
                adj[i].push_back(j);
        }
    }

    queue<int> q;
    int distance[n];

    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;  // Заполняем массив
    }

    distance[s - 1] = 0; // Начало поиска
    q.push(s - 1);  // Первую вершину в очередь

    while(!q.empty())
    {
        int cur = q.front();  // Берем первый элемент
        q.pop();  // Убираем первый элемент
        for (int i : adj[cur])
        {
            if (distance[i] != INT_MAX) continue;

            distance[i] = distance[cur] + 1;
            q.push(i);
        }
    }

    int sol = distance[f-1];
    cout << (sol != INT_MAX ? sol : 0) << endl;

    return 0;
}
