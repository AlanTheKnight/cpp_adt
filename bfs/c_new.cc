#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


// Check that new move is valid
bool checkMove(string move)
{
    return (
        move[0] <= 'h' && move[0] >= 'a' &&
        move[2] <= 'h' && move[2] >= 'a' &&
        move[1] <= '8' && move[1] >= '1' &&
        move[3] <= '8' && move[3] >= '1'
    );
}


pair<int, int> getNewCoords(int i) {
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
    return make_pair(dx[i], dy[i]);
}


void showAnswer(map<string, string> prev, string end) {
    vector<string> way;
    while (!end.empty())
    {
        way.push_back(end);
        end = (prev.count(end) != 0) ? prev[end] : "";
    }
    if (prev[end] != "")
        way.push_back(prev[end]);
    reverse(way.begin(), way.end());

    for (int i = 0; i < way.size() - 1; i++) {
        if (way[i][0] != way[i+1][0]) {
            cout << "1 " << way[i+1][0] << way[i+1][1] << '\n';
        } else {
            cout << "2 " << way[i+1][2] << way[i+1][3] << '\n';
        }
    }
}


void bfs(string start, string end) {
    map<string, string> prev;
    map<string, int> dist;

    dist[start] = 0;
    
    queue<string> q;
    q.push(start);

    while(!q.empty())
    {
        string current = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            string newMove = current;
            auto newCoords = getNewCoords(i);
            newMove[0] += newCoords.first;
            newMove[1] += newCoords.second;

            if (
                checkMove(newMove) && dist.count(newMove) == 0 && 
                newMove[0] != newMove[2] && newMove[1] != newMove[3]
                ) {
                    dist[newMove] = dist[current] + 1;
                    prev[newMove] = current;
                    q.push(newMove);
                }

            newMove = current;
            newCoords = getNewCoords(i);
            newMove[2] += newCoords.first;
            newMove[3] += newCoords.second;

            if (
                checkMove(newMove) && dist.count(newMove) == 0 && 
                newMove[0] != newMove[2] && newMove[1] != newMove[3]
                ) {
                    dist[newMove] = dist[current] + 1;
                    prev[newMove] = current;
                    q.push(newMove);
                }
        }
    }

    showAnswer(prev, end);
}


int main(int argc, char const *argv[])
{
    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);
    string s1, s2, e1, e2;
    cin >> s1 >> s2 >> e1 >> e2;
    s1 += s2;
    e1 += e2;
    bfs(s1, e1);
    return 0;
}

