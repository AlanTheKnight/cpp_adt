#include <vector>
#include <iostream>
#include <climits>
#include <queue>
using namespace std;


int main(int argc, char const *argv[])
{
    int n, k;
    // n - количество городов
    // k - количество дорог
    int colors[n];
    for (int i = 0; i < n; i++)
        cin >> colors[i];
    // colors - массив, где записывается принадлежность
    //          города к 1ому или 2ому барону

    int graph[n][n];
    // graph - матрица смежности
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = 1; // дорога туда
        graph[b-1][a-1] = 1; // дорога обратно
    }

    int start = 0, end = n;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
    }
    return 0;
}
