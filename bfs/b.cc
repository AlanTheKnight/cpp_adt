#include <bits/stdc++.h>
using namespace std;


const char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

#define cell pair<int, int>


bool onBoard(int x, int y)
{
    return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}

int findLetter(char l)
{
    for (int i = 0; i < 8; i++)
    {
        if (letters[i] == l)
            return i;
    }
    return -1;
}


string getCell(int x, int y)
{
    string c;
    c += letters[x];
    c += to_string(y + 1);
    return c;
}


int main(int argc, char const *argv[])
{
    freopen("knight1.in", "r", stdin);
    freopen("knight1.out", "w", stdout);

    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

    map<cell, int> dist;
    map<cell, cell> way;

    queue<cell> q;

    cell startCell, endCell;
    string start, end;
    cin >> start;
    cin >> end;

    startCell.first = findLetter(start[0]);
    startCell.second = start[1] - '1';
    endCell.first = findLetter(end[0]);
    endCell.second = end[1] - '1';

    dist[startCell] = 0;

    q.push(startCell);

    while (!q.empty())
    {
        cell c = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int x = c.first + dx[i];
            int y = c.second + dy[i];
            cell newMove{x, y};
            if (onBoard(x, y) && !dist.count(newMove))
            {
                dist[newMove] = dist[c] + 1;
                way[newMove] = c;
                q.push(newMove);
            }
        }
    }

    vector<string> answer;

    cell index = endCell;

    answer.push_back(getCell(endCell.first, endCell.second));

    while (way[index] != startCell)
    {
        answer.push_back(getCell(way[index].first, way[index].second));
        index = way[index];
    }

    answer.push_back(getCell(startCell.first, startCell.second));

    reverse(answer.begin(), answer.end());

    for (auto u : answer)
        cout << u << '\n';

    return 0;
}
